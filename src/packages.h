// Goose compiler — packages (docs/design/packages.md §4): what a sourced
// import, `import name from "source";`, names, and where that package's
// files are. A path source is a directory used in place, relative to the
// file that wrote it; a git source is fetched into GOOSE_HOME (§4.6).
#pragma once

namespace goose {

// In main.cpp.
string RelativeTo(const string &path, const string &dir);

struct PackageSource {
    string text;        // As written.
    bool ispath = false;
    string dir;         // A path source: the package's root, absolute, forward slashes, trailing /.
    string url, ref;    // A git source: what git clones, and the tag, branch or commit.
};

inline string ForwardSlashes(string path) {
    for (auto &c : path) if (c == '\\') c = '/';
    return path;
}

// `dir` absolute, with forward slashes and one trailing slash.
inline string PackageDir(const string &dir) {
    auto abs = ForwardSlashes(AbsolutePath(dir));
    while (abs.size() > 1 && abs.back() == '/') abs.pop_back();
    return abs + "/";
}

inline bool IsPathSource(const string &text) {
    return text.rfind("./", 0) == 0 || text.rfind("../", 0) == 0 || text.rfind(".\\", 0) == 0 ||
           text.rfind("..\\", 0) == 0 || text[0] == '/' || text[0] == '\\' ||
           (text.size() > 1 && text[1] == ':');
}

// Reads a source as written in a file in `fromdir`. A path is resolved from
// there; a git source is `host/owner/repo@ref`, `owner/repo@ref` for
// GitHub, or any URL git takes with `@ref` behind it. Throws for a shape
// that is neither.
inline PackageSource ParsePackageSource(const string &text, const string &fromdir) {
    PackageSource s;
    s.text = text;
    if (text.empty()) throw CompileError { "a package source is a path or a git repository" };
    if (IsPathSource(text)) {
        s.ispath = true;
        auto absolute = text[0] == '/' || text[0] == '\\' || (text.size() > 1 && text[1] == ':');
        s.dir = PackageDir(absolute ? text : cat(fromdir, text));
        return s;
    }
    auto at = text.rfind('@');
    // A `user@host:` prefix is part of the URL, not the ref.
    if (at == string::npos || at == 0 || text.find(':', at) != string::npos)
        throw CompileError { cat("the git source ", text, " needs a ref: host/owner/repo@tag, "
                                 "@branch or @commit") };
    s.ref = text.substr(at + 1);
    auto repo = text.substr(0, at);
    if (repo.find("://") != string::npos || repo.find('@') != string::npos) {
        s.url = repo;
    } else {
        auto slashes = (int)std::count(repo.begin(), repo.end(), '/');
        if (slashes == 1) s.url = cat("https://github.com/", repo);
        else if (slashes >= 2) s.url = cat("https://", repo);
        else throw CompileError { cat("the git source ", text, " is not owner/repo@ref, "
                                      "host/owner/repo@ref or a URL") };
    }
    if (s.ref.empty() || s.url.empty())
        throw CompileError { cat("the git source ", text, " needs a repository and a ref") };
    return s;
}

// Whether two sources name the same place: the same directory, or the same
// repository (refs aside).
inline bool SameSource(const PackageSource &a, const PackageSource &b) {
    if (a.ispath != b.ispath) return false;
    return a.ispath ? a.dir == b.dir : a.url == b.url;
}

// The root directory of the package `name` from `source`: the directory
// itself for a path, which must hold `<name>.goose`. Fetching from git
// comes with §4.6.
inline string PackageRoot(const PackageSource &source, const string &name) {
    if (!source.ispath)
        throw CompileError { cat("fetching the package ", name, " from ", source.text,
                                 " is not supported yet: give a path to a checkout") };
    std::error_code ec;
    if (!filesystem::is_directory(filesystem::path(source.dir), ec))
        throw CompileError { cat("the package ", name, "'s source ", source.text,
                                 " is not a directory (", source.dir, ")") };
    if (!PathExists(cat(source.dir, name, ".goose")))
        throw CompileError { cat("the package ", name, " at ", source.dir, " has no ", name,
                                 ".goose") };
    return source.dir;
}

// The source as the root file in `rootdir` would write it, for the error
// that tells the root what to add: a path relative to there where that can
// be said, else as it is.
inline string SourceForRoot(const PackageSource &source, const string &rootdir) {
    if (!source.ispath) return source.text;
    auto rel = ForwardSlashes(RelativeTo(source.dir.substr(0, source.dir.size() - 1),
                                         PackageDir(rootdir.empty() ? string(".") : rootdir)));
    if (rel == source.dir.substr(0, source.dir.size() - 1)) return rel;   // No relative form.
    if (rel.rfind("../", 0) != 0 && rel.rfind("./", 0) != 0) rel = cat("./", rel);
    return rel;
}

}  // namespace goose
