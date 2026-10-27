#pragma once
namespace goose {
inline const char *WASI_SDK_TAG = "wasi-sdk-34";
inline const char *WASI_SDK_VER = "34.0";
inline string WebFirstDir(const string &dir, const string &prefix) {
    std::error_code ec;
    string best;
    for (auto &de : filesystem::directory_iterator(filesystem::path(dir), ec))
        if (de.is_directory() && de.path().filename().string().starts_with(prefix) && de.path().string() > best) best = de.path().string();
    return best;
}
inline bool WebToolchain(const Builder &b, const string &clang, string &sysroot, string &resource) {
    auto env = getenv("HELIUM_WASI");
    auto dir = env && *env ? string(env) : cat(GooseHome(), "/toolchains/wasi-", string(WASI_SDK_VER).substr(0, string(WASI_SDK_VER).find('.')));
    sysroot = WebFirstDir(dir, "wasi-sysroot");
    auto rt = WebFirstDir(dir, "libclang_rt");
    if (sysroot.empty() || rt.empty()) {
        if (env && *env) return ProgressPrint(cat("HELIUM_WASI=", dir, " holds no wasi-sysroot-* and libclang_rt-* directories\n")), false;
        std::error_code ec;
        filesystem::create_directories(filesystem::path(dir), ec);
        auto base = cat("https://github.com/WebAssembly/wasi-sdk/releases/download/", WASI_SDK_TAG, "/");
        for (auto name : { cat("wasi-sysroot-", WASI_SDK_VER, ".tar.gz"), cat("libclang_rt-", WASI_SDK_VER, ".tar.gz") }) {
            auto file = cat(dir, "/", name);
            if (!b.Run({ "curl", "-fsSL", "--retry", "3", "-o", file, cat(base, name) }, cat("fetching ", name, " for the web target"), "")) return false;
            if (!b.Run({ "tar", "xzf", file, "-C", dir }, cat("unpacking ", name), "")) return false;
            filesystem::remove(filesystem::path(file), ec);
        }
        sysroot = WebFirstDir(dir, "wasi-sysroot");
        rt = WebFirstDir(dir, "libclang_rt");
        if (sysroot.empty() || rt.empty()) return ProgressPrint(cat("the WASI toolchain in ", dir, " is incomplete\n")), false;
    }
    resource = cat(dir, "/resource");
    auto inc = cat(resource, "/include");
    if (!filesystem::exists(filesystem::path(cat(inc, "/stddef.h")))) {
        auto r = RunProcess({ clang, "-print-resource-dir" });
        auto sys = r.output;
        while (!sys.empty() && isspace((unsigned char)sys.back())) sys.pop_back();
        if (!r.started || r.code || sys.empty()) return ProgressPrint("clang -print-resource-dir failed\n"), false;
        std::error_code ec;
        filesystem::create_directories(filesystem::path(cat(resource, "/lib")), ec);
        filesystem::remove(filesystem::path(inc), ec);
        filesystem::create_directory_symlink(filesystem::path(cat(sys, "/include")), filesystem::path(inc), ec);
        if (ec) filesystem::copy(filesystem::path(cat(sys, "/include")), filesystem::path(inc), filesystem::copy_options::recursive, ec);
        for (auto &de : filesystem::directory_iterator(filesystem::path(rt), ec)) {
            auto to = filesystem::path(cat(resource, "/lib/", de.path().filename().string()));
            std::error_code e2;
            filesystem::remove_all(to, e2);
            filesystem::create_directory_symlink(de.path(), to, e2);
            if (e2) filesystem::copy(de.path(), to, filesystem::copy_options::recursive, e2);
        }
    }
    return true;
}
inline int BuildWeb(const string &rootfile, const string &cfile, const string &builddir, const BuildOptions &opts, FILE *msgs, const vector<string> &exports, const vector<string> &stdlibdirs) {
    auto clang = FindOnPath("clang", InheritedPath());
    if (clang.empty()) return fprintf(stderr, "the web target needs clang on PATH (with the wasm32 target)\n"), 1;
    Toolchain tc;
    tc.name = "clang";
    tc.cc = clang;
    tc.style = "cc";
    Builder b { tc, opts, msgs };
    string sysroot, resource;
    if (!WebToolchain(b, clang, sysroot, resource)) return 1;
    auto wasm = opts.exe.empty() ? cat(DirOf(AbsolutePath(rootfile)), PathStem(rootfile), ".wasm") : opts.exe;
    vector<string> argv = { clang, "--target=wasm32-wasip1", cat("--sysroot=", sysroot), "-resource-dir", resource };
    for (auto &f : b.CFlags()) argv.push_back(f);
    for (auto f : { "-mexec-model=reactor", "-mllvm", "-wasm-enable-sjlj", "-mllvm", "-wasm-use-legacy-eh=true", "-mbulk-memory", "-mnontrapping-fptoint", "-msign-ext", "-w" }) argv.push_back(f);
    argv.push_back(cfile);
    for (auto f : { "-lsetjmp", "-Wl,--allow-undefined", "-Wl,-z,stack-size=8388608", "-Wl,--export=goose_init" }) argv.push_back(f);
    for (auto &e : exports) argv.push_back(cat("-Wl,--export=", e));
    if (!opts.debug) argv.push_back("-Wl,--strip-debug");
    argv.push_back("-o");
    argv.push_back(wasm);
    if (!b.Run(argv, cat("building ", wasm), cat(builddir, "/web-link.log"))) return 1;
    string host, have;
    for (auto &d : stdlibdirs) if (LoadFile(cat(d, "web.js"), host)) break;
    if (host.empty()) return fprintf(stderr, "cannot find web.js in the standard library\n"), 1;
    auto hostpath = cat(DirOf(AbsolutePath(wasm)), "helium.js");
    if (!opts.dryrun && (!LoadFile(hostpath, have) || have != host) && !WriteFileMakingDirs(hostpath, host)) return fprintf(stderr, "cannot write %s\n", hostpath.c_str()), 1;
    if (!opts.dryrun) fprintf(msgs, "built %s\n", wasm.c_str());
    return 0;
}
}
