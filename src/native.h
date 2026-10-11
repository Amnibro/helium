// Goose compiler — a package's native part (docs/design/packages.md §5): the
// C its sidecar names, built once per toolchain into what an AOT program
// links (its objects and system libraries, in a response file) and the
// shared library a JIT run loads, which exports one table of the functions
// the package's extern fns name (§5.3). The program itself is package 0 and
// may have a native part of its own.
#pragma once

namespace goose {

// The packages whose native parts a program needs, in link order: its own
// (package 0) when it has one, and those an extern fn it calls (`used`,
// codegen's) was declared in, a package before the ones it requires.
inline vector<int> NativePackagesUsed(const Ast &ast, const vector<FnSpec *> &used) {
    set<int> needed;
    if (ast.packages[0].HasNative()) needed.insert(0);
    for (auto sp : used) {
        auto pkg = ast.filepkg[sp->sf->line.fileidx];
        if (ast.packages[pkg].HasNative()) needed.insert(pkg);
    }
    // A package's depth is one more than the deepest it requires; deeper
    // links first. A cycle of requirements gets whatever depth the walk
    // reaches, which is all an order can mean there.
    map<int, int> depth;
    std::function<int(int)> depthof = [&](int pkg) -> int {
        auto it = depth.find(pkg);
        if (it != depth.end()) return it->second;
        depth[pkg] = 0;
        auto d = 0;
        for (auto req : ast.packages[pkg].required) d = std::max(d, depthof(req) + 1);
        depth[pkg] = d;
        return d;
    };
    vector<int> order(needed.begin(), needed.end());
    std::stable_sort(order.begin(), order.end(),
                     [&](int a, int b) { return depthof(a) > depthof(b); });
    return order;
}

struct NativeBuild {
    string dir;       // Where it was built.
    string rsp;       // The response file an AOT link takes.
    string jitlib;    // The shared library a JIT run loads.
};

// Where the package `pkg`'s native part is built for the toolchain `tc`:
// under the program's build directory for the program itself, under
// GOOSE_HOME/build/pkg for a package, by its checkout or its path.
inline string NativeBuildDir(const Ast &ast, int pkg, const string &rootfile, const Toolchain &tc) {
    auto &p = ast.packages[pkg];
    if (pkg == 0) return cat(ProgramBuildDir(rootfile), "/native/", tc.id);
    if (!p.cachekey.empty()) return cat(GooseHome(), "/build/pkg/", p.cachekey, "/", tc.id);
    return cat(GooseHome(), "/build/pkg/local/", Hex8(p.root), "/", tc.id);
}

// The C symbols a file's extern fns name: `extern "sym" fn f` gives sym,
// `extern fn f` or `extern fn ns::f` gives the leaf name (§7.10). Read by
// the lexer alone, since this is asked of files the program never parsed.
inline void ExternNamesIn(const string &path, const string &text, set<string> &names) {
    Lexer lex(path, text.c_str());
    while (lex.tok != T_EOF) {
        if (lex.tok != T_EXTERN) {
            lex.Next();
            continue;
        }
        lex.Next();
        string cname;
        if (lex.tok == T_STRLIT) {
            cname = lex.sval;
            lex.Next();
        }
        if (lex.tok != T_FN) continue;
        lex.Next();
        if (lex.tok == T_IDENT) {
            string leaf(lex.attr);
            lex.Next();
            if (lex.tok == T_COLONCOLON) {
                lex.Next();
                if (lex.tok == T_IDENT) leaf = string(lex.attr);
            }
            if (cname.empty()) cname = leaf;
        }
        if (!cname.empty()) names.insert(cname);
    }
}

// Every C symbol the package's extern fns name: for the program, those of
// the files it parsed; for a library, those of every .goose file under its
// root, so that the library built once serves whatever modules a program
// imports from it.
inline vector<string> PackageExternNames(const Ast &ast, int pkg) {
    set<string> names;
    if (pkg == 0) {
        for (size_t i = 0; i < ast.sources.size(); i++)
            if (ast.filepkg[i] == pkg) {
                try {
                    ExternNamesIn(ast.sources[i].first, *ast.sources[i].second, names);
                } catch (CompileError &) {}
            }
    } else {
        std::error_code ec;
        for (auto &e : filesystem::recursive_directory_iterator(filesystem::path(ast.packages[pkg].root), ec)) {
            if (!e.is_regular_file() || e.path().extension() != ".goose") continue;
            auto path = ForwardSlashes(e.path().string());
            string text;
            if (!LoadSource(path, text)) continue;
            try {
                ExternNamesIn(path, text, names);
            } catch (CompileError &) {}   // A file that does not lex has no externs to offer.
        }
    }
    return vector<string>(names.begin(), names.end());
}

// goose_symbols.c: the one exported function of a package's JIT library,
// handing out the table of its functions by name. Taking a function's
// address needs no signature, so each is declared `void f(void)`.
inline string SymbolTableSource(const string &pkgname, const vector<string> &names) {
    string s = cat("/* Generated by the Goose compiler for the package ", pkgname,
                   ": the C functions its\n   extern fns name, which a JIT run looks up through "
                   "goose_symbols. Do not edit. */\n\n"
                   "typedef struct { const char *name; const void *addr; } goose_symbol;\n\n");
    for (auto &n : names) Append(s, "void ", n, "(void);\n");
    Append(s, "\n#ifdef _WIN32\n__declspec(dllexport)\n#endif\n"
              "const goose_symbol *goose_symbols(void) {\n"
              "    static const goose_symbol table[] = {\n");
    for (auto &n : names) Append(s, "        { \"", n, "\", (const void *)&", n, " },\n");
    s += "        { 0, 0 }\n    };\n    return table;\n}\n";
    return s;
}

inline int64_t NewestMtime(const vector<string> &paths) {
    int64_t newest = 0;
    for (auto &p : paths) {
        std::error_code ec;
        auto t = filesystem::last_write_time(filesystem::path(p), ec);
        if (!ec) newest = std::max(newest, (int64_t)t.time_since_epoch().count());
    }
    return newest;
}

inline string ReadStamp(const string &path) {
    string s;
    LoadFile(path, s);
    return s;
}

// Builds the package's native part for `b`'s toolchain, unless the build
// there is up to date with its inputs (the sidecar, the C sources, the
// toolchain), and names what was built in `out`. The JIT library is built
// only when `wantjit`. False after a failed command, which the builder
// reports; a dry run prints the commands and reports success.
inline bool BuildNativePart(const Ast &ast, int pkg, const string &rootfile, const Builder &b,
                            bool wantjit, NativeBuild &out) {
    auto &p = ast.packages[pkg];
    if (!p.cmake_target.empty())
        throw CompileError { cat("the package ", p.name, " builds with CMake (cmake_target in ",
                                 p.sidecar, "), which is not supported yet") };
    auto dir = NativeBuildDir(ast, pkg, rootfile, b.tc);
    out.dir = dir;
    out.rsp = cat(dir, "/link-", b.tc.style, ".rsp");
    #ifdef _WIN32
        auto jitext = ".dll";
    #elif defined(__APPLE__)
        auto jitext = ".dylib";
    #else
        auto jitext = ".so";
    #endif
    out.jitlib = cat(dir, "/goose_jit_", p.name, jitext);
    auto inputs = p.csources;
    inputs.push_back(p.sidecar);
    string sidecartext;
    LoadFile(p.sidecar, sidecartext);
    auto stampwant = cat(b.tc.id, "\n", NewestMtime(inputs), "\n", Hex8(sidecartext), "\n",
                         wantjit ? "jit" : "aot", "\n");
    auto stampfile = cat(dir, "/stamp");
    auto have = ReadStamp(stampfile);
    // A JIT build holds everything an AOT build has, and more.
    auto fresh = have == stampwant || (!wantjit && have == cat(stampwant.substr(0, stampwant.size() - 4), "jit\n"));
    if (fresh && PathExists(out.rsp) && (!wantjit || PathExists(out.jitlib)) && !b.opts.dryrun)
        return true;
    std::error_code ec;
    filesystem::create_directories(filesystem::path(dir), ec);
    // The flags the package's C compiles with: its includes, defines and
    // flags for this style; position independent where a shared library
    // needs it.
    vector<string> flags;
    auto msvc = b.tc.style == "msvc";
    for (auto &i : p.cincludes) flags.push_back(cat(msvc ? "/I" : "-I", i));
    for (auto &d : p.cdefines) flags.push_back(cat(msvc ? "/D" : "-D", d));
    for (auto &f : msvc ? p.cflags_msvc : p.cflags_cc) flags.push_back(f);
    #ifndef _WIN32
        if (!msvc) flags.push_back("-fPIC");
    #endif
    vector<string> objects;
    for (auto &src : p.csources) {
        auto obj = cat(dir, "/", PathStem(src), msvc ? ".obj" : ".o");
        if (!b.CompileObject(src, obj, cat("compiling ", src, " for the package ", p.name),
                             cat(dir, "/", PathStem(src), ".cc.log"), flags))
            return false;
        objects.push_back(obj);
    }
    vector<string> libs;
    for (auto &l : p.clibs) libs.push_back(b.LibFlag(l));
    string rsp;
    for (auto &o : objects) Append(rsp, "\"", o, "\"\n");
    for (auto &l : libs) Append(rsp, l, "\n");
    if (!b.opts.dryrun && !WriteFileMakingDirs(out.rsp, rsp))
        throw CompileError { cat("cannot write ", out.rsp) };
    if (wantjit) {
        auto symsrc = cat(dir, "/goose_symbols.c");
        auto symobj = cat(dir, "/goose_symbols", msvc ? ".obj" : ".o");
        if (!b.opts.dryrun &&
            !WriteFileMakingDirs(symsrc, SymbolTableSource(p.name, PackageExternNames(ast, pkg))))
            throw CompileError { cat("cannot write ", symsrc) };
        // Warnings off: a C library's function declared `void f(void)` here
        // is what the compiler knows as a builtin with another shape.
        vector<string> symflags = { msvc ? "/w" : "-w" };
        #ifndef _WIN32
            if (!msvc) symflags.push_back("-fPIC");
        #endif
        if (!b.CompileObject(symsrc, symobj, cat("compiling the symbol table of the package ", p.name),
                             cat(dir, "/goose_symbols.cc.log"), symflags))
            return false;
        objects.push_back(symobj);
        if (!b.LinkShared(objects, libs, out.jitlib, dir, cat(dir, "/jit.cc.log"),
                          cat("building the package ", p.name, "'s library for the JIT")))
            return false;
    }
    if (!b.opts.dryrun) WriteFileMakingDirs(stampfile, stampwant);
    return true;
}

}  // namespace goose
