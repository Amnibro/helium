// Goose compiler — other processes (process.h), over subprocess.h. This is
// the one translation unit besides main.cpp, kept apart so that the platform
// headers it needs stay out of the compiler's.

#include "includes.h"
#include "utils.h"
#include "process.h"

#ifdef _MSC_VER
    #pragma warning(push, 0)
#endif
#include "subprocess.h"
#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define NOMINMAX
    #include <windows.h>
    #include <io.h>
#else
    #include <unistd.h>
#endif

namespace goose {

ProcessResult RunProcess(const vector<string> &argv, const string &cwd, bool echo) {
    ProcessResult r;
    vector<const char *> args;
    for (auto &a : argv) args.push_back(a.c_str());
    args.push_back(nullptr);
    // Everything the program prints comes back through one pipe, in order,
    // which is also what keeps it from filling the other one while this
    // process reads the first. Async mode is what makes the output readable
    // as it comes rather than only after the exit.
    auto options = subprocess_option_combined_stdout_stderr | subprocess_option_inherit_environment |
                   subprocess_option_search_user_path | subprocess_option_enable_async |
                   subprocess_option_no_window;
    subprocess_s p;
    if (subprocess_create_ex(args.data(), options, nullptr, cwd.empty() ? nullptr : cwd.c_str(),
                             &p)) {
        r.output = cat("cannot start ", argv.empty() ? string("(nothing)") : argv[0], ": ",
                       strerror(errno));
        return r;
    }
    r.started = true;
    char buf[4096];
    for (;;) {
        auto n = subprocess_read_stdout(&p, buf, sizeof buf);
        if (!n) break;
        r.output.append(buf, n);
        if (echo) fwrite(buf, 1, n, stderr);
    }
    int code = -1;
    if (subprocess_join(&p, &code)) code = -1;
    subprocess_destroy(&p);
    r.code = code;
    return r;
}

static bool IsFile(const string &path) {
    #ifdef _WIN32
        auto attr = GetFileAttributesA(path.c_str());
        return attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY);
    #else
        return access(path.c_str(), X_OK) == 0;
    #endif
}

string FindOnPath(const string &name) {
    if (name.find_first_of("/\\") != string::npos) return IsFile(name) ? name : "";
    vector<string> exts = { "" };
    #ifdef _WIN32
        constexpr char sep = ';';
        if (name.find('.') == string::npos) {
            auto pathext = getenv("PATHEXT");
            string list = pathext ? pathext : ".COM;.EXE;.BAT;.CMD";
            for (size_t i = 0; i < list.size();) {
                auto end = list.find(';', i);
                if (end == string::npos) end = list.size();
                auto ext = list.substr(i, end - i);
                for (auto &c : ext) c = (char)tolower((unsigned char)c);
                if (!ext.empty()) exts.push_back(ext);
                i = end + 1;
            }
        }
    #else
        constexpr char sep = ':';
    #endif
    auto path = getenv("PATH");
    if (!path) return "";
    string dirs = path;
    for (size_t i = 0; i <= dirs.size();) {
        auto end = dirs.find(sep, i);
        if (end == string::npos) end = dirs.size();
        auto dir = dirs.substr(i, end - i);
        i = end + 1;
        if (dir.empty()) continue;
        for (auto &ext : exts) {
            #ifdef _WIN32
                const char *slash = "\\";
            #else
                const char *slash = "/";
            #endif
            auto cand = cat(dir, dir.back() == '/' || dir.back() == '\\' ? "" : slash, name, ext);
            if (IsFile(cand)) return cand;
        }
    }
    return "";
}

void SetEnvVar(const string &name, const string &value) {
    #ifdef _WIN32
        // Both the C runtime's copy, which getenv reads, and the process's
        // own block, which a started process inherits.
        _putenv_s(name.c_str(), value.c_str());
        SetEnvironmentVariableA(name.c_str(), value.c_str());
    #else
        setenv(name.c_str(), value.c_str(), 1);
    #endif
}

string CommandLineText(const vector<string> &argv) {
    string s;
    for (auto &a : argv) {
        if (!s.empty()) s += ' ';
        if (!a.empty() && a.find_first_of(" \t\"'&|<>^();$`\\") == string::npos) {
            s += a;
            continue;
        }
        s += '"';
        for (auto c : a) {
            if (c == '"' || c == '\\') s += '\\';
            s += c;
        }
        s += '"';
    }
    return s;
}

}  // namespace goose
