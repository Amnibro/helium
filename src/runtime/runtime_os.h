/* Goose runtime: the OS primitives behind stdlib/os.goose (spec §7.10), as
   runtime_ext.h declares them, which this follows. */

#include <time.h>
#ifndef _WIN32
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <dlfcn.h>
#include <sys/stat.h>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif
#endif

/* Paths are UTF-8 on every platform, and reach the C APIs NUL-terminated in
   a buffer of GS_OS_PATH_MAX characters. A path that would not fit, that
   holds a NUL byte (where C would end it) or, on Windows, that is not UTF-8
   is refused: cut short or read another way, it could name another file. */
#define GS_OS_PATH_MAX 4096

#ifdef _WIN32
/* Windows names files in UTF-16, which its wide APIs take as it is; the
   narrow ones read their bytes in the ANSI code page. */
typedef wchar_t gs_os_char;
#define gs_os_fopen(p, mode) _wfopen(p, L##mode)
/* Vista's; TinyCC's winnls.h predates it. */
#ifndef WC_ERR_INVALID_CHARS
#define WC_ERR_INVALID_CHARS 0x80
#endif
#else
typedef char gs_os_char;
#define gs_os_fopen(p, mode) fopen(p, mode)
#endif

/* The native form of a path, or of an environment variable's name, in buf
   (GS_OS_PATH_MAX characters): its length, or -1 where it is refused. */
static int gs_os_native(sl_u8 s, gs_os_char *buf) {
    if (s.len >= GS_OS_PATH_MAX || (s.len > 0 && memchr(s.data, 0, (size_t)s.len)))
        return -1;
    int n = (int)s.len;
#ifdef _WIN32
    /* A UTF-16 path has no more units than its UTF-8 form has bytes. */
    if (n > 0) {
        n = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, (const char *)s.data, n, buf,
                                GS_OS_PATH_MAX - 1);
        if (n == 0) return -1;
    }
#else
    gs_memcpy(buf, s.data, (size_t)n);
#endif
    buf[n] = 0;
    return n;
}

#ifdef _WIN32
/* Appends n UTF-16 units as UTF-8; where they are not valid UTF-16, appends
   nothing and returns 0. */
static int gs_os_append_wide(gs_rref out, const wchar_t *w, int n) {
    if (n <= 0) return 1;
    int k = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w, n, NULL, 0, NULL, NULL);
    char *s = k > 0 ? (char *)malloc((size_t)k) : NULL;
    int ok = s && WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w, n, s, k, NULL, NULL) == k;
    if (ok) gs_bld_append(out, s, k);
    free(s);
    return ok;
}

/* Moves `from` to `to`, replacing `to` if there is one, in one step.
   Another process, such as a virus scanner reading a file just written, can
   hold either open for a moment: while `to` is open anywhere it cannot be
   replaced (ERROR_ACCESS_DENIED), nor `from` moved while it is open without
   delete sharing (ERROR_SHARING_VIOLATION). Those failures are tried again
   for about a second, unless `to` is a directory or read-only, which no
   wait changes. */
static int gs_os_replace(const wchar_t *from, const wchar_t *to) {
    for (DWORD wait = 0;; wait = wait ? wait * 2 : 1) {
        if (MoveFileExW(from, to, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) return 1;
        DWORD e = GetLastError(), a = GetFileAttributesW(to);
        if ((e != ERROR_ACCESS_DENIED && e != ERROR_SHARING_VIOLATION) || wait > 512 ||
            (a != INVALID_FILE_ATTRIBUTES && (a & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_READONLY))))
            return 0;
        Sleep(wait);
    }
}
#else
/* An fsync that reaches the disk: on macOS a plain one stops at the drive's
   cache. */
static int gs_os_fsync(int fd) {
    #ifdef F_FULLFSYNC
        if (fcntl(fd, F_FULLFSYNC) == 0) return 1;
    #endif
    return fsync(fd) == 0;
}

/* A rename is on the disk once the directory holding the new name is (what
   MOVEFILE_WRITE_THROUGH waits for on Windows). Best effort: the rename has
   happened either way. */
static void gs_os_sync_dir(const char *path) {
    char dir[GS_OS_PATH_MAX];
    const char *slash = strrchr(path, '/');
    size_t n = slash ? (size_t)(slash - path) : 0;
    if (slash && n == 0) n = 1;
    if (n) memcpy(dir, path, n);
    else dir[n++] = '.';
    dir[n] = 0;
    int fd = open(dir, O_RDONLY);
    if (fd < 0) return;
    gs_os_fsync(fd);
    close(fd);
}
#endif

/* What a native path names: 0 nothing that can be reached, 1 something
   other than a directory, 2 a directory. */
static int gs_os_kind(const gs_os_char *p) {
#ifdef _WIN32
    DWORD a = GetFileAttributesW(p);
    if (a == INVALID_FILE_ATTRIBUTES) return 0;
    return (a & FILE_ATTRIBUTE_DIRECTORY) ? 2 : 1;
#else
    struct stat st;
    if (stat(p, &st) != 0) return 0;
    return S_ISDIR(st.st_mode) ? 2 : 1;
#endif
}

/* Appends the whole file; on a failure, nothing. */
GS_API uint8_t gs_os_read_file(sl_u8 path, gs_rref out) {
    gs_os_char p[GS_OS_PATH_MAX];
    if (gs_os_native(path, p) < 0) return 0;
    FILE *f = gs_os_fopen(p, "rb");
    if (!f) return 0;
    int64_t len = out.hdr->len;
    uint8_t *top = out.stk->top;
    uint8_t buf[65536];
    for (;;) {
        size_t n = fread(buf, 1, sizeof buf, f);
        if (n == 0) break;
        gs_bld_append(out, buf, (int64_t)n);
    }
    int bad = ferror(f);
    fclose(f);
    if (bad) {
        out.hdr->len = len;
        out.stk->top = top;
        return 0;
    }
    return 1;
}

/* write_file and append_file. */
static uint8_t gs_os_put_file(sl_u8 path, sl_u8 data, int append) {
    gs_os_char p[GS_OS_PATH_MAX];
    if (gs_os_native(path, p) < 0) return 0;
    FILE *f = append ? gs_os_fopen(p, "ab") : gs_os_fopen(p, "wb");
    if (!f) return 0;
    size_t n = (size_t)(data.len < 0 ? 0 : data.len);
    int ok = fwrite(data.data, 1, n, f) == n;
    if (fclose(f) != 0) ok = 0;
    return ok ? 1 : 0;
}

GS_API uint8_t gs_os_write_file(sl_u8 path, sl_u8 data) { return gs_os_put_file(path, data, 0); }

GS_API uint8_t gs_os_append_file(sl_u8 path, sl_u8 data) { return gs_os_put_file(path, data, 1); }

GS_API uint8_t gs_os_file_exists(sl_u8 path) {
    gs_os_char p[GS_OS_PATH_MAX];
    return gs_os_native(path, p) >= 0 && gs_os_kind(p) == 1;
}

GS_API uint8_t gs_os_remove_file(sl_u8 path) {
    gs_os_char p[GS_OS_PATH_MAX];
    if (gs_os_native(path, p) < 0) return 0;
#ifdef _WIN32
    return DeleteFileW(p) != 0;
#else
    /* Not remove, which takes an empty directory as well. */
    return unlink(p) == 0;
#endif
}

/* Replaces `to` if it exists, in one step: `to` names the old file or the
   moved one, never neither. */
GS_API uint8_t gs_os_rename_file(sl_u8 from, sl_u8 to) {
    gs_os_char f[GS_OS_PATH_MAX], t[GS_OS_PATH_MAX];
    if (gs_os_native(from, f) < 0 || gs_os_native(to, t) < 0) return 0;
#ifdef _WIN32
    return gs_os_replace(f, t);
#else
    if (rename(f, t) != 0) return 0;
    gs_os_sync_dir(t);
    return 1;
#endif
}

/* Writes data to a new file beside path, flushes it to the disk and renames
   it over path, so that path holds either its old contents or all of the
   new ones whatever happens meanwhile; on a failure the new file is removed.
   Its name is path's with a random tag and ".tmp" added, created only if
   nothing has that name already: one that does belongs to someone else, and
   another tag is drawn. */
GS_API uint8_t gs_os_write_file_atomic(sl_u8 path, sl_u8 data) {
    gs_os_char p[GS_OS_PATH_MAX], t[GS_OS_PATH_MAX + 21];
    int n = gs_os_native(path, p);
    if (n <= 0) return 0;
    const uint8_t *d = data.data;
    int64_t left = data.len;
    for (int tries = 0; tries < 8; tries++) {
        uint64_t tag = gs_os_random_u64();
        int k = n;
        memcpy(t, p, (size_t)n * sizeof *t);
        t[k++] = '.';
        for (int s = 60; s >= 0; s -= 4) t[k++] = "0123456789abcdef"[(tag >> s) & 15];
        t[k++] = '.';
        t[k++] = 't';
        t[k++] = 'm';
        t[k++] = 'p';
        t[k] = 0;
        int ok = 1;
#ifdef _WIN32
        HANDLE h = CreateFileW(t, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
        if (h == INVALID_HANDLE_VALUE) {
            if (GetLastError() == ERROR_FILE_EXISTS) continue;
            return 0;
        }
        while (ok && left > 0) {
            DWORD chunk = left > (1 << 30) ? (DWORD)1 << 30 : (DWORD)left, wrote = 0;
            ok = WriteFile(h, d, chunk, &wrote, NULL) && wrote == chunk;
            d += chunk;
            left -= chunk;
        }
        ok = ok && FlushFileBuffers(h);
        if (!CloseHandle(h)) ok = 0;
        ok = ok && gs_os_replace(t, p);
        if (!ok) DeleteFileW(t);
#else
        int fd = open(t, O_WRONLY | O_CREAT | O_EXCL, 0666);
        if (fd < 0) {
            if (errno == EEXIST) continue;
            return 0;
        }
        /* The permissions of the file it replaces, which write_file leaves
           as they are, rather than the umask's. */
        struct stat st;
        if (stat(p, &st) == 0) ok = fchmod(fd, st.st_mode & 0777) == 0;
        while (ok && left > 0) {
            ssize_t w = write(fd, d, left > (1 << 30) ? (size_t)1 << 30 : (size_t)left);
            if (w < 0 && errno == EINTR) continue;
            ok = w > 0;
            if (ok) {
                d += w;
                left -= w;
            }
        }
        ok = ok && gs_os_fsync(fd);
        if (close(fd) != 0) ok = 0;
        ok = ok && rename(t, p) == 0;
        if (ok) gs_os_sync_dir(p);
        else unlink(t);
#endif
        return ok ? 1 : 0;
    }
    return 0;
}

/* True where path is a directory afterwards, one that was there already
   included. */
GS_API uint8_t gs_os_make_dir(sl_u8 path) {
    gs_os_char p[GS_OS_PATH_MAX];
    if (gs_os_native(path, p) < 0) return 0;
#ifdef _WIN32
    if (CreateDirectoryW(p, NULL)) return 1;
#else
    if (mkdir(p, 0777) == 0) return 1;
#endif
    return gs_os_kind(p) == 2;
}

GS_API uint8_t gs_os_is_dir(sl_u8 path) {
    gs_os_char p[GS_OS_PATH_MAX];
    return gs_os_native(path, p) >= 0 && gs_os_kind(p) == 2;
}

/* An empty directory. */
GS_API uint8_t gs_os_remove_dir(sl_u8 path) {
    gs_os_char p[GS_OS_PATH_MAX];
    if (gs_os_native(path, p) < 0) return 0;
#ifdef _WIN32
    return RemoveDirectoryW(p) != 0;
#else
    return rmdir(p) == 0;
#endif
}

/* The names a listing collects before sorting them: NUL-terminated, one
   after another. */
typedef struct {
    char *text;
    size_t len, cap, count;
} gs_os_names;

/* A name with a newline in it cannot be a line of the listing, and is left
   out. */
static int gs_os_names_add(gs_os_names *ns, const char *name, size_t n) {
    if (memchr(name, '\n', n)) return 1;
    if (ns->len + n + 1 > ns->cap) {
        size_t cap = ns->cap ? ns->cap * 2 : 4096;
        while (cap < ns->len + n + 1) cap *= 2;
        char *text = (char *)realloc(ns->text, cap);
        if (!text) return 0;
        ns->text = text;
        ns->cap = cap;
    }
    memcpy(ns->text + ns->len, name, n);
    ns->text[ns->len + n] = 0;
    ns->len += n + 1;
    ns->count++;
    return 1;
}

static int gs_os_name_order(const void *a, const void *b) {
    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

/* Appends the names in bytewise order, each followed by a newline. */
static int gs_os_names_put(gs_os_names *ns, gs_rref out) {
    if (!ns->count) return 1;
    const char **v = (const char **)malloc(ns->count * sizeof *v);
    if (!v) return 0;
    size_t i = 0;
    for (size_t at = 0; at < ns->len; at += strlen(ns->text + at) + 1) v[i++] = ns->text + at;
    qsort(v, ns->count, sizeof *v, gs_os_name_order);
    for (i = 0; i < ns->count; i++) {
        gs_bld_append(out, v[i], (int64_t)strlen(v[i]));
        gs_bld_append(out, "\n", 1);
    }
    free(v);
    return 1;
}

/* Appends the name of every entry of a directory but "." and "..", sorted
   so that a listing does not depend on the file system; on a failure
   appends nothing. */
GS_API uint8_t gs_os_list_dir(sl_u8 path, gs_rref out) {
    gs_os_char p[GS_OS_PATH_MAX + 2];
    int n = gs_os_native(path, p);
    if (n <= 0) return 0;
    gs_os_names ns = { 0 };
    int ok = 1;
#ifdef _WIN32
    /* FindFirstFileW takes a pattern, which "*" after the directory makes
       every entry. */
    int dirlen = n;
    if (p[n - 1] != '/' && p[n - 1] != '\\' && p[n - 1] != ':') p[n++] = '\\';
    p[n++] = '*';
    p[n] = 0;
    WIN32_FIND_DATAW e;
    HANDLE h = FindFirstFileW(p, &e);
    if (h == INVALID_HANDLE_VALUE) {
        /* No entry at all, not even "." and "..": the empty root of a drive. */
        int empty = GetLastError() == ERROR_FILE_NOT_FOUND;
        p[dirlen] = 0;
        return empty && gs_os_kind(p) == 2;
    }
    do {
        const wchar_t *w = e.cFileName;
        if (w[0] == '.' && (!w[1] || (w[1] == '.' && !w[2]))) continue;
        /* A name that is not valid UTF-16 has no UTF-8 spelling, and is left
           out. */
        char name[1024];
        int k = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, w, -1, name, sizeof name,
                                    NULL, NULL);
        if (k > 1 && !gs_os_names_add(&ns, name, (size_t)k - 1)) ok = 0;
    } while (ok && FindNextFileW(h, &e));
    if (ok && GetLastError() != ERROR_NO_MORE_FILES) ok = 0;
    FindClose(h);
#else
    DIR *d = opendir(p);
    if (!d) return 0;
    for (;;) {
        errno = 0;
        struct dirent *e = readdir(d);
        if (!e) {
            ok = errno == 0;
            break;
        }
        const char *w = e->d_name;
        if (w[0] == '.' && (!w[1] || (w[1] == '.' && !w[2]))) continue;
        if (!gs_os_names_add(&ns, w, strlen(w))) {
            ok = 0;
            break;
        }
    }
    closedir(d);
#endif
    ok = ok && gs_os_names_put(&ns, out);
    free(ns.text);
    return ok ? 1 : 0;
}

GS_API void gs_os_write_stdout(sl_u8 s) {
    if (s.len > 0) fwrite(s.data, 1, (size_t)s.len, stdout);
}

GS_API void gs_os_write_stderr(sl_u8 s) {
    if (s.len > 0) fwrite(s.data, 1, (size_t)s.len, stderr);
}

GS_API void gs_os_flush_stdout(void) { fflush(stdout); }

/* One line of stdin, without its newline or a carriage return before it;
   false at end of input. */
GS_API uint8_t gs_os_read_line(gs_rref out) {
    int c = fgetc(stdin);
    if (c == EOF) return 0;
    int64_t start = out.hdr->len;
    while (c != EOF && c != '\n') {
        uint8_t b = (uint8_t)c;
        gs_bld_append(out, &b, 1);
        c = fgetc(stdin);
    }
    if (out.hdr->len > start && out.hdr->base[out.hdr->len - 1] == '\r') {
        out.hdr->len--;
        out.stk->top--;
    }
    return 1;
}

/* All of stdin. */
GS_API void gs_os_read_stdin(gs_rref out) {
    uint8_t buf[65536];
    for (;;) {
        size_t n = fread(buf, 1, sizeof buf, stdin);
        if (n == 0) break;
        gs_bld_append(out, buf, (int64_t)n);
    }
}

GS_API int64_t gs_os_arg_count(void) { return gs_argc; }

/* The application's resource directory (resource_dir(), below) in native
   form with its final separator, NUL-terminated in buf (GS_OS_PATH_MAX
   characters): its length, or 0 where it is not known. JIT supplies its
   entry source directory; AOT discovers the running executable. */
static int gs_os_resource_native(gs_os_char *buf) {
#ifdef GS_JIT_RESOURCE_DIR
    sl_u8 dir = { (uint8_t *)GS_JIT_RESOURCE_DIR, (int64_t)strlen(GS_JIT_RESOURCE_DIR) };
    int n = gs_os_native(dir, buf);
    return n < 0 ? 0 : n;
#elif defined(_WIN32)
    DWORD n = GetModuleFileNameW(NULL, buf, GS_OS_PATH_MAX);
    if (!n || n >= GS_OS_PATH_MAX) return 0;
    while (n && buf[n - 1] != L'\\' && buf[n - 1] != L'/') --n;
    buf[n] = 0;
    return (int)n;
#else
    char *path = buf;
    size_t n;
    #ifdef __APPLE__
        uint32_t capacity = GS_OS_PATH_MAX;
        if (_NSGetExecutablePath(path, &capacity) != 0) return 0;
        /* Resolve the loader's possible relative path and symlinks. */
        char *resolved = realpath(path, NULL);
        if (!resolved) return 0;
        n = strlen(resolved);
        if (n >= (size_t)GS_OS_PATH_MAX) { free(resolved); return 0; }
        memcpy(path, resolved, n + 1);
        free(resolved);
    #elif defined(__linux__)
        ssize_t count = readlink("/proc/self/exe", path, (size_t)GS_OS_PATH_MAX);
        if (count <= 0 || (size_t)count >= (size_t)GS_OS_PATH_MAX) return 0;
        n = (size_t)count;
    #else
        return 0;
    #endif
    while (n && path[n - 1] != '/') --n;
    if (!n) return 0;
    #ifdef __APPLE__
        const char suffix[] = ".app/Contents/MacOS/";
        size_t suffixlen = sizeof suffix - 1;
        if (n >= suffixlen && !memcmp(path + n - suffixlen, suffix, suffixlen)) {
            n -= sizeof "MacOS/" - 1;
            if (n + sizeof "Resources/" - 1 >= (size_t)GS_OS_PATH_MAX) return 0;
            memcpy(path + n, "Resources/", sizeof "Resources/" - 1);
            n += sizeof "Resources/" - 1;
        }
    #endif
    path[n] = 0;
    return (int)n;
#endif
}

/* Application resources, independent of cwd and argv[0]. Append only on
   success, including a final path separator. */
GS_API uint8_t gs_os_resource_dir(gs_rref out) {
    gs_os_char path[GS_OS_PATH_MAX];
    int n = gs_os_resource_native(path);
    if (!n) return 0;
#ifdef _WIN32
    return gs_os_append_wide(out, path, n);
#else
    gs_bld_append(out, path, (int64_t)n);
    return 1;
#endif
}

/* ---- Dynamic externs: the libraries the program's extern blocks name ---- */

/* The spelling this platform opens for a library, UTF-8 in buf (GS_OS_PATH_MAX
   bytes): the sidecar's for the platform, else the block's name. A last
   component without a dot takes the platform's library form (SDL2 is
   SDL2.dll, libSDL2.dylib, libSDL2.so); a spelling with a separator, unless
   absolute, is under the resource directory; a bare one goes to the loader's
   search as it is. 0 where it does not fit or the resource directory is not
   known. */
static int gs_dl_spelling(const gs_dllib *lib, char *buf) {
#ifdef _WIN32
    const char *s = lib->onwindows, *prefix = "", *suffix = ".dll";
#elif defined(__APPLE__)
    const char *s = lib->onmacos, *prefix = "lib", *suffix = ".dylib";
#else
    const char *s = lib->onlinux, *prefix = "lib", *suffix = ".so";
#endif
    if (!s) s = lib->name;
    size_t len = strlen(s), dir = 0;
    for (size_t i = 0; i < len; i++) {
        int sep = s[i] == '/';
#ifdef _WIN32
        sep = sep || s[i] == '\\';
#endif
        if (sep) dir = i + 1;
    }
    const char *leaf = s + dir;
    int bare = !strchr(leaf, '.');
    int absolute = s[0] == '/';
#ifdef _WIN32
    int drive = (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z');
    absolute = absolute || s[0] == '\\' || (len >= 2 && drive && s[1] == ':');
#endif
    char root[GS_OS_PATH_MAX];
    root[0] = 0;
    if (dir && !absolute) {
        gs_os_char native[GS_OS_PATH_MAX];
        int n = gs_os_resource_native(native);
        if (!n) return 0;
#ifdef _WIN32
        n = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, native, n, root, GS_OS_PATH_MAX - 1,
                                NULL, NULL);
        if (n <= 0) return 0;
        root[n] = 0;
#else
        memcpy(root, native, (size_t)n + 1);
#endif
    }
    int n = snprintf(buf, GS_OS_PATH_MAX, "%s%.*s%s%s%s", root, (int)dir, s, bare ? prefix : "",
                     leaf, bare ? suffix : "");
    return n > 0 && n < GS_OS_PATH_MAX ? n : 0;
}

GS_API void gs_dl_bind(const gs_dllib *libs, int64_t nlibs, const gs_dlbind *binds,
                       int64_t nbinds) {
    for (int64_t l = 0; l < nlibs; l++) {
        char spelling[GS_OS_PATH_MAX], msg[GS_OS_PATH_MAX + 512];
        if (!gs_dl_spelling(&libs[l], spelling)) {
            snprintf(msg, sizeof msg, "cannot load %s: its path does not fit or is not known",
                     libs[l].name);
            gs_panic(msg);
        }
#ifdef _WIN32
        sl_u8 utf8 = { (uint8_t *)spelling, (int64_t)strlen(spelling) };
        wchar_t wide[GS_OS_PATH_MAX];
        HMODULE h = NULL;
        if (gs_os_native(utf8, wide) >= 0) {
            /* A path, the resource directory's or an absolute one: the
               libraries it depends on are looked for beside it first, as
               a library shipped with its dependencies under lib/ needs.
               That search wants backslashes. A bare name keeps the
               loader's own search. */
            int path = 0;
            for (wchar_t *c = wide; *c; c++)
                if (*c == L'/' || *c == L'\\') { *c = L'\\'; path = 1; }
            h = path ? LoadLibraryExW(wide, NULL, LOAD_WITH_ALTERED_SEARCH_PATH) : LoadLibraryW(wide);
        }
        if (!h) {
            snprintf(msg, sizeof msg, "cannot load %s (%s): Windows error %u", libs[l].name,
                     spelling, (unsigned)GetLastError());
            gs_panic(msg);
        }
#else
        void *h = dlopen(spelling, RTLD_NOW | RTLD_LOCAL);
        if (!h) {
            const char *why = dlerror();
            snprintf(msg, sizeof msg, "cannot load %s (%s): %s", libs[l].name, spelling,
                     why ? why : "unknown error");
            gs_panic(msg);
        }
#endif
        for (int64_t b = 0; b < nbinds; b++) {
            if (binds[b].lib != l) continue;
#ifdef _WIN32
            void *f = (void *)GetProcAddress(h, binds[b].sym);
#else
            void *f = dlsym(h, binds[b].sym);
#endif
            if (!f) {
                snprintf(msg, sizeof msg, "%s (%s) has no symbol %s", libs[l].name, spelling,
                         binds[b].sym);
                gs_panic(msg);
            }
            *binds[b].slot = f;
        }
    }
}

GS_API void gs_os_arg(int64_t i, gs_rref out) {
    if (i < 0 || i >= gs_argc) return;
    const char *a = gs_argv[i];
#ifdef _WIN32
    /* main's argv is in the ANSI code page. The program gets it in UTF-8,
       the encoding of its paths, by way of UTF-16, which holds every
       character of the code page. */
    int n = MultiByteToWideChar(CP_ACP, 0, a, -1, NULL, 0);
    wchar_t *w = n > 0 ? (wchar_t *)malloc((size_t)n * sizeof *w) : NULL;
    int ok = w && MultiByteToWideChar(CP_ACP, 0, a, -1, w, n) == n &&
             gs_os_append_wide(out, w, n - 1);
    free(w);
    if (ok) return;
#endif
    gs_bld_append(out, a, (int64_t)strlen(a));
}

GS_API uint8_t gs_os_getenv(sl_u8 name, gs_rref out) {
    gs_os_char nm[GS_OS_PATH_MAX];
    if (gs_os_native(name, nm) < 0) return 0;
#ifdef _WIN32
    /* The environment holds UTF-16, which getenv would hand out in the ANSI
       code page. A value can change size between the calls. */
    wchar_t small[512], *v = small;
    DWORD cap = 512, len;
    for (;;) {
        SetLastError(0);
        len = GetEnvironmentVariableW(nm, v, cap);
        if (len < cap) break;
        if (v != small) free(v);
        cap = len;
        v = (wchar_t *)malloc(cap * sizeof *v);
        if (!v) return 0;
    }
    /* Zero is also the length of an empty value. */
    int ok = (len > 0 || GetLastError() != ERROR_ENVVAR_NOT_FOUND) &&
             gs_os_append_wide(out, v, (int)len);
    if (v != small) free(v);
    return ok ? 1 : 0;
#else
    const char *v = getenv(nm);
    if (!v) return 0;
    gs_bld_append(out, v, (int64_t)strlen(v));
    return 1;
#endif
}

/* Wall-clock time in nanoseconds since the Unix epoch. */
GS_API int64_t gs_os_time_ns(void) {
    /* Neither branch uses C11's timespec_get: the Microsoft C runtime tcc
       links against does not have it, and glibc hides it from a compiler
       announcing C99, which tcc also is. */
#ifdef _WIN32
    /* Windows counts 100 ns ticks from 1601; the offset to the Unix epoch is
       a constant. */
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);
    uint64_t t = ((uint64_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    return (int64_t)(t - 116444736000000000ull) * 100;
#else
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (int64_t)ts.tv_sec * 1000000000 + ts.tv_nsec;
#endif
}

/* A monotonic clock in nanoseconds, for measuring intervals. */
GS_API int64_t gs_os_clock_ns(void) {
#ifdef _WIN32
    LARGE_INTEGER f, c;
    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&c);
    return (int64_t)((double)c.QuadPart * (1000000000.0 / (double)f.QuadPart));
#else
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (int64_t)ts.tv_sec * 1000000000 + ts.tv_nsec;
#endif
}

GS_API void gs_os_sleep_ms(int64_t ms) {
    if (ms <= 0) return;
#ifdef _WIN32
    /* Sleep takes 32 bits, the largest of them meaning INFINITE: a longer
       sleep goes in parts. */
    while (ms > 0) {
        DWORD part = ms > 0x7fffffff ? 0x7fffffff : (DWORD)ms;
        Sleep(part);
        ms -= part;
    }
#else
    struct timespec ts;
    ts.tv_sec = (time_t)(ms / 1000);
    ts.tv_nsec = (long)((ms % 1000) * 1000000);
    nanosleep(&ts, NULL);
#endif
}

/* Entropy for seeding a PRNG (not cryptographic): /dev/urandom where there
   is one; on Windows a splitmix64 mix of the clocks, the process id and an
   address, which needs no library beyond the runtime's. */
static uint64_t gs_os_mix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15u;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9u;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebu;
    return x ^ (x >> 31);
}

GS_API uint64_t gs_os_random_u64(void) {
#ifndef _WIN32
    FILE *f = fopen("/dev/urandom", "rb");
    if (f) {
        uint64_t v = 0;
        size_t n = fread(&v, 1, sizeof v, f);
        fclose(f);
        if (n == sizeof v) return v;
    }
#endif
    /* Which call this is, counted atomically: workers calling at once each
       get a count of their own. */
#ifdef _WIN32
    static volatile LONG64 counter;
    uint64_t count = (uint64_t)InterlockedIncrement64(&counter);
#else
    static uint64_t counter;
    uint64_t count = __atomic_add_fetch(&counter, 1, __ATOMIC_SEQ_CST);
#endif
    uint64_t seed = (uint64_t)gs_os_time_ns();
    seed = gs_os_mix64(seed ^ (uint64_t)gs_os_clock_ns());
#ifdef _WIN32
    seed = gs_os_mix64(seed ^ (uint64_t)GetCurrentProcessId());
#endif
    seed = gs_os_mix64(seed ^ (uint64_t)(uintptr_t)&counter);
    return gs_os_mix64(seed ^ count);
}

#if !defined(__TINYC__) && defined(__has_include)
#if __has_include(<vulkan/vulkan.h>)
#define GS_HAVE_VK 1
#endif
#endif
#ifdef GS_HAVE_VK
#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>
static struct {
    int state;
    void *lib;
    VkInstance inst;
    VkPhysicalDevice phys;
    VkDevice dev;
    VkQueue queue;
    uint32_t qfam;
    VkPhysicalDeviceMemoryProperties mem;
    PFN_vkGetDeviceProcAddr gdpa;
} gs_vk;
#define GS_VKI(n) PFN_##n n = (PFN_##n)gipa(gs_vk.inst, #n)
#define GS_VKD(n) PFN_##n n = (PFN_##n)gs_vk.gdpa(gs_vk.dev, #n)
static int gs_vk_init(void) {
    if (gs_vk.state) return gs_vk.state > 0;
    gs_vk.state = -1;
    const char *want = getenv("HELIUM_GPU");
    if (want && !strcmp(want, "off")) return 0;
#if defined(__linux__)
    if (!getenv("VK_LOADER_DRIVERS_SELECT") && !getenv("VK_DRIVER_FILES") && !getenv("VK_ICD_FILENAMES")) {
        char sel[64] = "", path[64], id[16];
        for (int c = 0; c < 16; c++) {
            snprintf(path, sizeof path, "/sys/class/drm/card%d/device/vendor", c);
            FILE *f = fopen(path, "r");
            if (!f) continue;
            const char *g = fgets(id, sizeof id, f) ? (!strncmp(id, "0x1002", 6) ? "*radeon*" : !strncmp(id, "0x8086", 6) ? "*intel*" : !strncmp(id, "0x10de", 6) ? "*nvidia*" : NULL) : NULL;
            fclose(f);
            if (g && !strstr(sel, g) && strlen(sel) + strlen(g) + 2 < sizeof sel) strcat(strcat(sel, *sel ? "," : ""), g);
        }
        if (*sel) setenv("VK_LOADER_DRIVERS_SELECT", sel, 0);
    }
    setenv("MESA_VK_IGNORE_CONFORMANCE_WARNING", "1", 0);
#endif
#ifdef _WIN32
    gs_vk.lib = (void *)LoadLibraryA("vulkan-1.dll");
    PFN_vkGetInstanceProcAddr gipa = gs_vk.lib ? (PFN_vkGetInstanceProcAddr)GetProcAddress((HMODULE)gs_vk.lib, "vkGetInstanceProcAddr") : NULL;
#else
    gs_vk.lib = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
#ifdef __APPLE__
    if (!gs_vk.lib) gs_vk.lib = dlopen("libvulkan.1.dylib", RTLD_NOW | RTLD_LOCAL);
#endif
    PFN_vkGetInstanceProcAddr gipa = gs_vk.lib ? (PFN_vkGetInstanceProcAddr)dlsym(gs_vk.lib, "vkGetInstanceProcAddr") : NULL;
#endif
    if (!gipa) return 0;
    PFN_vkCreateInstance vkCreateInstance = (PFN_vkCreateInstance)gipa(NULL, "vkCreateInstance");
    VkApplicationInfo app = { VK_STRUCTURE_TYPE_APPLICATION_INFO, NULL, "helium", 1, "helium", 1, VK_API_VERSION_1_1 };
    VkInstanceCreateInfo ici = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, NULL, 0, &app, 0, NULL, 0, NULL };
    if (!vkCreateInstance || vkCreateInstance(&ici, NULL, &gs_vk.inst) != VK_SUCCESS) return 0;
    GS_VKI(vkEnumeratePhysicalDevices); GS_VKI(vkGetPhysicalDeviceProperties); GS_VKI(vkGetPhysicalDeviceFeatures);
    GS_VKI(vkGetPhysicalDeviceQueueFamilyProperties); GS_VKI(vkGetPhysicalDeviceMemoryProperties); GS_VKI(vkCreateDevice);
    gs_vk.gdpa = (PFN_vkGetDeviceProcAddr)gipa(gs_vk.inst, "vkGetDeviceProcAddr");
    VkPhysicalDevice devs[16];
    uint32_t nd = 16;
    if (vkEnumeratePhysicalDevices(gs_vk.inst, &nd, devs) < 0 || !nd) return 0;
    VkPhysicalDeviceType pref = want && (!strcmp(want, "discrete") || !strcmp(want, "dgpu")) ? VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU : VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU;
    int pick = -1;
    for (uint32_t i = 0; i < nd; i++) {
        VkPhysicalDeviceProperties p;
        VkPhysicalDeviceFeatures f;
        vkGetPhysicalDeviceProperties(devs[i], &p);
        vkGetPhysicalDeviceFeatures(devs[i], &f);
        if (!f.shaderInt64 || !f.robustBufferAccess || p.deviceType == VK_PHYSICAL_DEVICE_TYPE_CPU) continue;
        if (pick < 0 || p.deviceType == pref) pick = (int)i;
        if (p.deviceType == pref) break;
    }
    if (pick < 0) return 0;
    gs_vk.phys = devs[pick];
    uint32_t nq = 16;
    VkQueueFamilyProperties qf[16];
    vkGetPhysicalDeviceQueueFamilyProperties(gs_vk.phys, &nq, qf);
    gs_vk.qfam = UINT32_MAX;
    for (uint32_t i = 0; i < nq; i++) if (qf[i].queueFlags & VK_QUEUE_COMPUTE_BIT) { gs_vk.qfam = i; break; }
    if (gs_vk.qfam == UINT32_MAX) return 0;
    float prio = 1.0f;
    VkDeviceQueueCreateInfo qci = { VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO, NULL, 0, gs_vk.qfam, 1, &prio };
    VkPhysicalDeviceFeatures en;
    memset(&en, 0, sizeof en);
    en.shaderInt64 = VK_TRUE;
    en.robustBufferAccess = VK_TRUE;
    VkDeviceCreateInfo dci = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO, NULL, 0, 1, &qci, 0, NULL, 0, NULL, &en };
    if (vkCreateDevice(gs_vk.phys, &dci, NULL, &gs_vk.dev) != VK_SUCCESS) return 0;
    vkGetPhysicalDeviceMemoryProperties(gs_vk.phys, &gs_vk.mem);
    GS_VKD(vkGetDeviceQueue);
    vkGetDeviceQueue(gs_vk.dev, gs_vk.qfam, 0, &gs_vk.queue);
    gs_vk.state = 1;
    return 1;
}
static int gs_vk_buffer(VkDeviceSize size, VkBuffer *buf, VkDeviceMemory *mem, void **map) {
    GS_VKD(vkCreateBuffer); GS_VKD(vkGetBufferMemoryRequirements); GS_VKD(vkAllocateMemory); GS_VKD(vkBindBufferMemory); GS_VKD(vkMapMemory);
    VkBufferCreateInfo bci = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO, NULL, 0, size, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_SHARING_MODE_EXCLUSIVE, 0, NULL };
    if (vkCreateBuffer(gs_vk.dev, &bci, NULL, buf) != VK_SUCCESS) return 0;
    VkMemoryRequirements rq;
    vkGetBufferMemoryRequirements(gs_vk.dev, *buf, &rq);
    VkMemoryPropertyFlags need = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    uint32_t t = UINT32_MAX;
    for (uint32_t i = 0; i < gs_vk.mem.memoryTypeCount && t == UINT32_MAX; i++)
        if ((rq.memoryTypeBits & (1u << i)) && (gs_vk.mem.memoryTypes[i].propertyFlags & need) == need) t = i;
    if (t == UINT32_MAX) return 0;
    VkMemoryAllocateInfo mai = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, NULL, rq.size, t };
    if (vkAllocateMemory(gs_vk.dev, &mai, NULL, mem) != VK_SUCCESS) return 0;
    return vkBindBufferMemory(gs_vk.dev, *buf, *mem, 0) == VK_SUCCESS && vkMapMemory(gs_vk.dev, *mem, 0, size, 0, map) == VK_SUCCESS;
}
#endif
GS_API uint8_t gs_gpu_fill(sl_u8 spv, gs_rref outr, int64_t n, int64_t cpu_ns) {
#ifdef GS_HAVE_VK
    int64_t gs_t0 = gs_os_clock_ns();
    const char *mn = getenv("HELIUM_GPU_MIN_MS");
    if (cpu_ns < (mn ? atoll(mn) : 30) * 1000000 || n <= 0 || spv.len < 20 || (spv.len & 3) || !gs_vk_init()) return 0;
    int64_t gs_t1 = gs_os_clock_ns(), gs_t2 = gs_t1;
    GS_VKD(vkCreateShaderModule); GS_VKD(vkCreateDescriptorSetLayout); GS_VKD(vkCreatePipelineLayout); GS_VKD(vkCreateComputePipelines);
    GS_VKD(vkCreateDescriptorPool); GS_VKD(vkAllocateDescriptorSets); GS_VKD(vkUpdateDescriptorSets); GS_VKD(vkCreateCommandPool);
    GS_VKD(vkAllocateCommandBuffers); GS_VKD(vkBeginCommandBuffer); GS_VKD(vkCmdBindPipeline); GS_VKD(vkCmdBindDescriptorSets);
    GS_VKD(vkCmdPushConstants); GS_VKD(vkCmdDispatch); GS_VKD(vkEndCommandBuffer); GS_VKD(vkQueueSubmit); GS_VKD(vkQueueWaitIdle);
    GS_VKD(vkResetCommandBuffer); GS_VKD(vkDestroyBuffer); GS_VKD(vkFreeMemory); GS_VKD(vkDestroyPipeline); GS_VKD(vkDestroyPipelineLayout);
    GS_VKD(vkDestroyDescriptorPool); GS_VKD(vkDestroyDescriptorSetLayout); GS_VKD(vkDestroyShaderModule); GS_VKD(vkDestroyCommandPool);
    uint8_t ok = 0;
    VkBuffer vb = VK_NULL_HANDLE, fb = VK_NULL_HANDLE;
    VkDeviceMemory vm = VK_NULL_HANDLE, fm = VK_NULL_HANDLE;
    void *vp = NULL, *fp = NULL;
    VkShaderModule sm = VK_NULL_HANDLE;
    VkDescriptorSetLayout dsl = VK_NULL_HANDLE;
    VkPipelineLayout pl = VK_NULL_HANDLE;
    VkPipeline pipe = VK_NULL_HANDLE;
    VkDescriptorPool dp = VK_NULL_HANDLE;
    VkCommandPool cp = VK_NULL_HANDLE;
    if (!gs_vk_buffer((VkDeviceSize)n * 8, &vb, &vm, &vp) || !gs_vk_buffer((VkDeviceSize)n * 4, &fb, &fm, &fp)) goto done;
    VkShaderModuleCreateInfo smi = { VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO, NULL, 0, (size_t)spv.len, (const uint32_t *)spv.data };
    if (vkCreateShaderModule(gs_vk.dev, &smi, NULL, &sm) != VK_SUCCESS) goto done;
    VkDescriptorSetLayoutBinding bd[2] = { { 0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1, VK_SHADER_STAGE_COMPUTE_BIT, NULL }, { 1, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1, VK_SHADER_STAGE_COMPUTE_BIT, NULL } };
    VkDescriptorSetLayoutCreateInfo dli = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO, NULL, 0, 2, bd };
    if (vkCreateDescriptorSetLayout(gs_vk.dev, &dli, NULL, &dsl) != VK_SUCCESS) goto done;
    VkPushConstantRange pr = { VK_SHADER_STAGE_COMPUTE_BIT, 0, 8 };
    VkPipelineLayoutCreateInfo pli = { VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO, NULL, 0, 1, &dsl, 1, &pr };
    if (vkCreatePipelineLayout(gs_vk.dev, &pli, NULL, &pl) != VK_SUCCESS) goto done;
    VkComputePipelineCreateInfo cpi = { VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO, NULL, 0, { VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO, NULL, 0, VK_SHADER_STAGE_COMPUTE_BIT, sm, "main", NULL }, pl, VK_NULL_HANDLE, -1 };
    if (vkCreateComputePipelines(gs_vk.dev, VK_NULL_HANDLE, 1, &cpi, NULL, &pipe) != VK_SUCCESS) goto done;
    VkDescriptorPoolSize ps = { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 2 };
    VkDescriptorPoolCreateInfo dpi = { VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO, NULL, 0, 1, 1, &ps };
    if (vkCreateDescriptorPool(gs_vk.dev, &dpi, NULL, &dp) != VK_SUCCESS) goto done;
    VkDescriptorSet ds;
    VkDescriptorSetAllocateInfo dai = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO, NULL, dp, 1, &dsl };
    if (vkAllocateDescriptorSets(gs_vk.dev, &dai, &ds) != VK_SUCCESS) goto done;
    VkDescriptorBufferInfo bi[2] = { { vb, 0, VK_WHOLE_SIZE }, { fb, 0, VK_WHOLE_SIZE } };
    VkWriteDescriptorSet w[2] = { { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET, NULL, ds, 0, 0, 1, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, NULL, &bi[0], NULL },
                                  { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET, NULL, ds, 1, 0, 1, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, NULL, &bi[1], NULL } };
    vkUpdateDescriptorSets(gs_vk.dev, 2, w, 0, NULL);
    VkCommandPoolCreateInfo cpci = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO, NULL, VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT, gs_vk.qfam };
    if (vkCreateCommandPool(gs_vk.dev, &cpci, NULL, &cp) != VK_SUCCESS) goto done;
    VkCommandBuffer cb;
    VkCommandBufferAllocateInfo cbi = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, NULL, cp, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1 };
    if (vkAllocateCommandBuffers(gs_vk.dev, &cbi, &cb) != VK_SUCCESS) goto done;
    gs_t2 = gs_os_clock_ns();
    for (int64_t base = 0; base < n; base += 16384) {
        uint32_t pc[2] = { (uint32_t)base, (uint32_t)n };
        int64_t cnt = n - base < 16384 ? n - base : 16384;
        VkCommandBufferBeginInfo bgi = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, NULL, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, NULL };
        vkResetCommandBuffer(cb, 0);
        if (vkBeginCommandBuffer(cb, &bgi) != VK_SUCCESS) goto done;
        vkCmdBindPipeline(cb, VK_PIPELINE_BIND_POINT_COMPUTE, pipe);
        vkCmdBindDescriptorSets(cb, VK_PIPELINE_BIND_POINT_COMPUTE, pl, 0, 1, &ds, 0, NULL);
        vkCmdPushConstants(cb, pl, VK_SHADER_STAGE_COMPUTE_BIT, 0, 8, pc);
        vkCmdDispatch(cb, (uint32_t)((cnt + 63) / 64), 1, 1);
        if (vkEndCommandBuffer(cb) != VK_SUCCESS) goto done;
        VkSubmitInfo si = { VK_STRUCTURE_TYPE_SUBMIT_INFO, NULL, 0, NULL, NULL, 1, &cb, 0, NULL };
        if (vkQueueSubmit(gs_vk.queue, 1, &si, VK_NULL_HANDLE) != VK_SUCCESS || vkQueueWaitIdle(gs_vk.queue) != VK_SUCCESS) goto done;
    }
    gs_bld_append(outr, (const uint8_t *)vp, n * 8);
    gs_bld_append(outr, (const uint8_t *)fp, n * 4);
    ok = 1;
    if (getenv("HELIUM_GPU_LOG")) {
        int64_t nf = 0;
        for (int64_t i = 0; i < n; i++) nf += ((const uint32_t *)fp)[i] != 0;
        fprintf(stderr, "gpu fill %lld entries (%lld left to the CPU): device %.1f ms, pipeline %.1f ms, run %.1f ms\n", (long long)n, (long long)nf, (gs_t1 - gs_t0) / 1e6, (gs_t2 - gs_t1) / 1e6, (gs_os_clock_ns() - gs_t2) / 1e6);
    }
done:
    if (cp) vkDestroyCommandPool(gs_vk.dev, cp, NULL);
    if (dp) vkDestroyDescriptorPool(gs_vk.dev, dp, NULL);
    if (pipe) vkDestroyPipeline(gs_vk.dev, pipe, NULL);
    if (pl) vkDestroyPipelineLayout(gs_vk.dev, pl, NULL);
    if (dsl) vkDestroyDescriptorSetLayout(gs_vk.dev, dsl, NULL);
    if (sm) vkDestroyShaderModule(gs_vk.dev, sm, NULL);
    if (vb) vkDestroyBuffer(gs_vk.dev, vb, NULL);
    if (fb) vkDestroyBuffer(gs_vk.dev, fb, NULL);
    if (vm) vkFreeMemory(gs_vk.dev, vm, NULL);
    if (fm) vkFreeMemory(gs_vk.dev, fm, NULL);
    return ok;
#else
    (void)spv; (void)outr; (void)n; (void)cpu_ns;
    return 0;
#endif
}
