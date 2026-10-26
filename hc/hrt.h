#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
typedef struct { uint8_t *p; int64_t n; } hsl;
typedef struct { uint8_t *b; int64_t n; int64_t top; } hrv;
#define HR_RSZ ((int64_t)1 << 34)
#define HR_LIKELY(x) __builtin_expect(!!(x), 1)
#define HR_UNLIKELY(x) __builtin_expect(!!(x), 0)
static int hr_argc; static char **hr_argv;
static __thread uint8_t **hr_free; static __thread int64_t hr_nfree, hr_cfree;
static __thread uint8_t *hr_vbase, *hr_vtop;
static __thread hrv hr_ob;
static __thread int hr_lr;
static void hr_flush(void);
static __attribute__((noreturn, cold)) void hr_die(const char *m, const char *loc) { hr_flush(); fprintf(stderr, "helium runtime error: %s (%s)\n", m, loc); exit(1); }
static __attribute__((noreturn, cold)) void hr_oob(int64_t i, int64_t n, const char *loc) { char b[96]; snprintf(b, sizeof b, "index %lld out of bounds (length %lld)", (long long)i, (long long)n); hr_die(b, loc); }
static __attribute__((noreturn, cold)) void hr_slerr(int64_t a, int64_t b, int64_t n, const char *loc) { char m[128]; snprintf(m, sizeof m, "slice %lld..%lld out of bounds (length %lld)", (long long)a, (long long)b, (long long)n); hr_die(m, loc); }
static inline int64_t hr_ix(int64_t i, int64_t n, const char *loc) { if (HR_UNLIKELY((uint64_t)i >= (uint64_t)n)) hr_oob(i, n, loc); return i; }
static uint8_t *hr_take(void) {
	if (hr_nfree) return hr_free[--hr_nfree];
	void *p = mmap(NULL, HR_RSZ, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
	if (p == MAP_FAILED) { fprintf(stderr, "helium runtime error: out of address space\n"); exit(1); }
	return p;
}
static void hr_give(uint8_t *b, int64_t used) {
	if (!b) return;
	if (used > (1 << 20)) madvise(b + 65536, (size_t)(used - 65536 + 4095) & ~(size_t)4095, MADV_DONTNEED);
	if (hr_nfree == hr_cfree) { hr_cfree = hr_cfree ? hr_cfree * 2 : 64; hr_free = realloc(hr_free, (size_t)hr_cfree * sizeof *hr_free); }
	hr_free[hr_nfree++] = b;
}
static inline void hr_rinit(hrv *v) { if (HR_UNLIKELY(!v->b)) v->b = hr_take(); }
static inline uint8_t *hr_grow(hrv *v, int64_t k, int64_t esz) { hr_rinit(v); uint8_t *p = v->b + v->n * esz; v->n += k; if (HR_UNLIKELY(v->n * esz > HR_RSZ)) hr_die("array grew past 16 GiB", "push"); return p; }
static inline void hr_rfree(hrv *v, int64_t esz) { hr_give(v->b, v->n * esz); v->b = 0; v->n = 0; }
static inline void hr_resize(hrv *v, int64_t n, int64_t esz) { hr_rinit(v); if (n > v->n) memset(v->b + v->n * esz, 0, (size_t)((n - v->n) * esz)); v->n = n; }
static inline void hr_append(hrv *v, const void *p, int64_t k, int64_t esz) { if (k <= 0) return; uint8_t *d = hr_grow(v, k, esz); memmove(d, p, (size_t)(k * esz)); }
static inline hsl hr_sl(hrv v) { return (hsl){ v.b, v.n }; }
static inline uint8_t *hr_vmark(void) { if (HR_UNLIKELY(!hr_vbase)) hr_vbase = hr_vtop = hr_take(); return hr_vtop; }
static inline uint8_t *hr_valloc(int64_t n) { hr_vmark(); uint8_t *p = hr_vtop; hr_vtop += (n + 7) & ~7; return p; }
static inline bool hr_memeq(const void *a, const void *b, int64_t n) { return n == 0 || memcmp(a, b, (size_t)n) == 0; }
static inline bool hr_streq(hsl a, hsl b) { return a.n == b.n && hr_memeq(a.p, b.p, a.n); }
static inline hsl hr_str(const char *s, int64_t n) { return (hsl){ (uint8_t *)s, n }; }
static inline void hr_ob_put(const void *p, int64_t n) { hr_append(&hr_ob, p, n, 1); if (hr_ob.n > 65536) hr_flush(); }
static void hr_flush(void) { int64_t o = 0; while (o < hr_ob.n) { ssize_t w = write(1, hr_ob.b + o, (size_t)(hr_ob.n - o)); if (w <= 0) break; o += w; } hr_ob.n = 0; }
static inline void hr_fb(hrv *o, uint8_t c) { *hr_grow(o, 1, 1) = c; }
static inline void hr_fs(hrv *o, hsl s) { hr_append(o, s.p, s.n, 1); }
static inline void hr_fc(hrv *o, const char *s) { hr_append(o, s, (int64_t)strlen(s), 1); }
static void hr_fu(hrv *o, uint64_t v) { char b[24]; int i = 24; do { b[--i] = (char)('0' + v % 10); v /= 10; } while (v); hr_append(o, b + i, 24 - i, 1); }
static void hr_fi(hrv *o, int64_t v) { if (v < 0) { hr_fb(o, '-'); hr_fu(o, (uint64_t)0 - (uint64_t)v); } else hr_fu(o, (uint64_t)v); }
static int hr_ftry(char *buf, int nd, const char *dig, int x, int neg, double v, int f32, long double *err) {
	char *q = buf; if (neg) *q++ = '-'; *q++ = dig[0]; if (nd > 1) { *q++ = '.'; memcpy(q, dig + 1, (size_t)(nd - 1)); q += nd - 1; }
	sprintf(q, "e%+03d", x);
	double r = strtod(buf, 0);
	if (f32 ? (float)r != (float)v : r != v) return 0;
	*err = fabsl(strtold(buf, 0) - (f32 ? (long double)(float)v : (long double)v)); return 1;
}
static void hr_fflt(hrv *o, double v, int f32) {
	if (v != v) { hr_fc(o, "nan"); return; }
	if (isinf(v)) { hr_fc(o, v > 0 ? "inf" : "-inf"); return; }
	char buf[48], best[48] = ""; char dig[24]; int n = 0, x = 0, neg = signbit(v) != 0;
	for (int p = 1; p <= 17 && !best[0]; p++) {
		snprintf(buf, sizeof buf, "%.*e", p - 1, fabs(v));
		char *e = strchr(buf, 'e'); int k = 0;
		for (char *q = buf; q != e; q++) if (*q != '.') dig[k++] = *q;
		int ex = atoi(e + 1); long double be = 1e300L, er; int bev = 0;
		for (int d = -1; d <= 1; d++) {
			char cd[24]; memcpy(cd, dig, (size_t)k); int cx = ex, i = k - 1, cn = k;
			if (d == 1) { while (i >= 0 && cd[i] == '9') cd[i--] = '0'; if (i < 0) { memmove(cd + 1, cd, (size_t)k); cd[0] = '1'; cx++; cn = k; } else cd[i]++; }
			if (d == -1) { while (i >= 0 && cd[i] == '0') cd[i--] = '9'; if (i < 0 || (i == 0 && cd[0] == '1' && k == 1)) continue; cd[i]--; if (cd[0] == '0') continue; }
			char tb[48];
			if (hr_ftry(tb, cn, cd, cx, neg, v, f32, &er)) { int ev = ((cd[cn - 1] - '0') & 1) == 0; int tie = best[0] && fabsl(er - be) <= be * 1e-12L; if (!best[0] || (tie ? ev && !bev : er < be)) { be = er; bev = ev; strcpy(best, tb); memcpy(dig, cd, (size_t)cn); n = cn; x = cx; } }
		}
	}
	while (n > 1 && dig[n - 1] == '0') n--;
	if (x < -4 || x >= (n > 15 ? n : 15)) { char tb[48]; hr_ftry(tb, n, dig, x, neg, v, f32, &(long double){0}); hr_fc(o, tb); return; }
	if (neg) hr_fb(o, '-');
	if (x < 0) { hr_fc(o, "0."); for (int i = 0; i < -x - 1; i++) hr_fb(o, '0'); hr_append(o, dig, n, 1); return; }
	for (int i = 0; i <= x; i++) hr_fb(o, i < n ? (uint8_t)dig[i] : '0');
	hr_fb(o, '.');
	if (n > x + 1) hr_append(o, dig + x + 1, n - x - 1, 1); else hr_fb(o, '0');
}
static inline void hr_fd(hrv *o, double v) { hr_fflt(o, v, 0); }
static inline void hr_ff(hrv *o, float v) { hr_fflt(o, v, 1); }
static void hr_fq(hrv *o, hsl s) { hr_fb(o, '"'); hr_fs(o, s); hr_fb(o, '"'); }
static inline void hr_println(void) { hr_fb(&hr_ob, '\n'); if (hr_ob.n > 65536) hr_flush(); }
static inline int64_t hr_mod(int64_t a, int64_t b) { int64_t r = a % b; return r < 0 ? (b < 0 ? r - b : r + b) : r; }
static inline int64_t hr_div(int64_t a, int64_t b) { return a / b; }
static inline uint64_t hr_umod(uint64_t a, uint64_t b) { return a % b; }
static __attribute__((noreturn)) void hr_abort(hsl m) { hr_flush(); fprintf(stderr, "abort: %.*s\n", (int)m.n, (const char *)m.p); exit(1); }
static __attribute__((noreturn)) void hr_exit(int64_t c) { hr_flush(); exit((int)c); }
static void hr_assert_fail(const char *loc) { hr_die("assertion failed", loc); }
static int64_t hr_os_arg_count(void) { return hr_argc; }
static void hr_os_arg(int64_t i, hrv *out) { if (i >= 0 && i < hr_argc) hr_append(out, hr_argv[i], (int64_t)strlen(hr_argv[i]), 1); }
static char *hr_cstr(hsl s, char *buf, int64_t cap) { char *c = s.n < cap ? buf : malloc((size_t)s.n + 1); memcpy(c, s.p, (size_t)s.n); c[s.n] = 0; return c; }
#define HR_CS(name, s) char name##_b[512]; char *name = hr_cstr(s, name##_b, 512)
#define HR_CSF(name) if (name != name##_b) free(name)
static bool hr_os_getenv(hsl n, hrv *out) { HR_CS(c, n); char *v = getenv(c); HR_CSF(c); if (!v) return false; hr_append(out, v, (int64_t)strlen(v), 1); return true; }
static bool hr_os_read_file(hsl path, hrv *out) {
	HR_CS(c, path); int fd = open(c, O_RDONLY); HR_CSF(c);
	if (fd < 0) return false;
	struct stat st; if (fstat(fd, &st) == 0 && S_ISDIR(st.st_mode)) { close(fd); return false; }
	for (;;) { hr_rinit(out); ssize_t r = read(fd, out->b + out->n, 1 << 20); if (r < 0) { close(fd); return false; } if (r == 0) break; out->n += r; }
	close(fd); return true;
}
static bool hr_wfile(hsl path, hsl data, int flags) {
	HR_CS(c, path); int fd = open(c, O_WRONLY | O_CREAT | flags, 0644); HR_CSF(c);
	if (fd < 0) return false;
	int64_t o = 0; while (o < data.n) { ssize_t w = write(fd, data.p + o, (size_t)(data.n - o)); if (w <= 0) { close(fd); return false; } o += w; }
	return close(fd) == 0;
}
static bool hr_os_write_file(hsl p, hsl d) { return hr_wfile(p, d, O_TRUNC); }
static bool hr_os_append_file(hsl p, hsl d) { return hr_wfile(p, d, O_APPEND); }
static bool hr_os_write_file_atomic(hsl p, hsl d) {
	char tb[600]; if (p.n > 500) return hr_wfile(p, d, O_TRUNC);
	memcpy(tb, p.p, (size_t)p.n); memcpy(tb + p.n, ".tmp~", 6);
	if (!hr_wfile((hsl){ (uint8_t *)tb, p.n + 5 }, d, O_TRUNC)) return false;
	HR_CS(c, p); bool ok = rename(tb, c) == 0; HR_CSF(c); return ok;
}
static bool hr_os_file_exists(hsl p) { HR_CS(c, p); struct stat st; bool r = stat(c, &st) == 0 && !S_ISDIR(st.st_mode); HR_CSF(c); return r; }
static bool hr_os_is_dir(hsl p) { HR_CS(c, p); struct stat st; bool r = stat(c, &st) == 0 && S_ISDIR(st.st_mode); HR_CSF(c); return r; }
static int64_t hr_os_file_mtime(hsl p) { HR_CS(c, p); struct stat st; int64_t r = stat(c, &st) == 0 ? (int64_t)st.st_mtime : -1; HR_CSF(c); return r; }
static bool hr_os_remove_file(hsl p) { HR_CS(c, p); bool r = unlink(c) == 0; HR_CSF(c); return r; }
static bool hr_os_remove_dir(hsl p) { HR_CS(c, p); bool r = rmdir(c) == 0; HR_CSF(c); return r; }
static bool hr_os_rename_file(hsl a, hsl b) { HR_CS(x, a); HR_CS(y, b); bool r = rename(x, y) == 0; HR_CSF(x); HR_CSF(y); return r; }
static bool hr_os_make_dir(hsl p) { HR_CS(c, p); bool r = mkdir(c, 0755) == 0 || errno == EEXIST; HR_CSF(c); return r; }
static int hr_cmpstr(const void *a, const void *b) { return strcmp(*(char *const *)a, *(char *const *)b); }
static bool hr_os_list_dir(hsl p, hrv *out) {
	HR_CS(c, p); DIR *d = opendir(c); HR_CSF(c);
	if (!d) return false;
	char **names = 0; int64_t n = 0, cap = 0; struct dirent *e;
	while ((e = readdir(d))) { if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue; if (n == cap) { cap = cap ? cap * 2 : 32; names = realloc(names, (size_t)cap * sizeof *names); } names[n++] = strdup(e->d_name); }
	closedir(d);
	qsort(names, (size_t)n, sizeof *names, hr_cmpstr);
	for (int64_t i = 0; i < n; i++) { hr_append(out, names[i], (int64_t)strlen(names[i]), 1); hr_fb(out, '\n'); free(names[i]); }
	free(names); return true;
}
static bool hr_os_read_line(hrv *out) { hr_flush(); int c, any = 0; while ((c = getchar()) != EOF) { any = 1; if (c == '\n') break; hr_fb(out, (uint8_t)c); } if (out->n && out->b[out->n - 1] == '\r') out->n--; return any; }
static void hr_os_read_stdin(hrv *out) { hr_flush(); for (;;) { hr_rinit(out); ssize_t r = read(0, out->b + out->n, 1 << 20); if (r <= 0) break; out->n += r; } }
static void hr_os_write_stdout(hsl s) { hr_ob_put(s.p, s.n); }
static void hr_os_write_stderr(hsl s) { hr_flush(); fwrite(s.p, 1, (size_t)s.n, stderr); }
static void hr_os_flush_stdout(void) { hr_flush(); }
static int64_t hr_os_time_ns(void) { struct timespec t; clock_gettime(CLOCK_REALTIME, &t); return (int64_t)t.tv_sec * 1000000000 + t.tv_nsec; }
static int64_t hr_os_clock_ns(void) { struct timespec t; clock_gettime(CLOCK_MONOTONIC, &t); return (int64_t)t.tv_sec * 1000000000 + t.tv_nsec; }
static void hr_os_sleep_ms(int64_t ms) { struct timespec t = { ms / 1000, (ms % 1000) * 1000000 }; nanosleep(&t, 0); }
static uint64_t hr_os_random_u64(void) { uint64_t v = 0; int fd = open("/dev/urandom", O_RDONLY); if (fd >= 0) { if (read(fd, &v, 8) != 8) v = (uint64_t)hr_os_time_ns(); close(fd); } return v; }
static bool hr_trim_memory(void) { return true; }
static bool hr_os_resource_dir(hrv *out) { (void)out; return false; }
static int64_t hr_popcount(uint64_t x) { return __builtin_popcountll(x); }
static int64_t hr_clz(uint64_t x) { return x ? __builtin_clzll(x) : 64; }
static int64_t hr_ctz(uint64_t x) { return x ? __builtin_ctzll(x) : 64; }
static uint32_t hr_f32_bits(float x) { uint32_t b; memcpy(&b, &x, 4); return b; }
static float hr_f32_from_bits(uint32_t b) { float x; memcpy(&x, &b, 4); return x; }
static uint64_t hr_f64_bits(double x) { uint64_t b; memcpy(&b, &x, 8); return b; }
static double hr_f64_from_bits(uint64_t b) { double x; memcpy(&x, &b, 8); return x; }
typedef uint8_t hr_unit;
static inline int64_t hr_f2i(double x) { if (x != x) return 0; x = trunc(x); if (x >= -9223372036854775808.0 && x < 9223372036854775808.0) return (int64_t)x; double m = fmod(x, 18446744073709551616.0); if (m < 0) m += 18446744073709551616.0; return (int64_t)(uint64_t)m; }
static inline void hr_rdrop(hrv *v) { hr_give(v->b, 0); v->b = 0; v->n = 0; }
static inline void hr_rgive(hrv v) { hr_give(v.b, 0); }
static inline hrv *hr_tmp(hrv *t, hrv v) { hr_give(t->b, 0); *t = v; return t; }
static inline void hr_rset(hrv *d, hrv v) { hr_give(d->b, 0); *d = v; }
static inline hrv hr_rfrom(hsl s, int64_t esz) { hrv r = {0}; if (s.n) hr_append(&r, s.p, s.n, esz); return r; }
static inline hrv hr_rdup(hrv v, int64_t esz) { return hr_rfrom((hsl){ v.b, v.n }, esz); }
#define HR_SDIV(T, a, b, loc) ({ T _da = (a), _db = (b); if (HR_UNLIKELY(_db == 0)) hr_die("division by zero", loc); if (sizeof(T) == 8 && HR_UNLIKELY(_db == -1 && _da == (T)((uint64_t)1 << 63))) hr_die("division overflow", loc); (T)(_db == -1 ? (T)(0 - (uint64_t)_da) : _da / _db); })
#define HR_UDIV(T, a, b, loc) ({ T _da = (a), _db = (b); if (HR_UNLIKELY(_db == 0)) hr_die("division by zero", loc); (T)(_da / _db); })
#define HR_UDIV_MOD(T, a, b, loc) ({ T _da = (a), _db = (b); if (HR_UNLIKELY(_db == 0)) hr_die("division by zero", loc); (T)(_da % _db); })
#define HR_SMOD(T, a, b, loc) ({ T _da = (a), _db = (b); if (HR_UNLIKELY(_db == 0)) hr_die("division by zero", loc); T _dr = _db == -1 ? 0 : (T)(_da % _db); (T)(_dr < 0 ? (_db < 0 ? _dr - _db : _dr + _db) : _dr); })
#define hr_sqrt sqrt
#define hr_sqrtf sqrtf
#define hr_sin sin
#define hr_sinf sinf
#define hr_cos cos
#define hr_cosf cosf
#define hr_tan tan
#define hr_tanf tanf
#define hr_asin asin
#define hr_asinf asinf
#define hr_acos acos
#define hr_acosf acosf
#define hr_atan atan
#define hr_atanf atanf
#define hr_atan2 atan2
#define hr_atan2f atan2f
#define hr_exp exp
#define hr_expf expf
#define hr_log log
#define hr_logf logf
#define hr_log2 log2
#define hr_log2f log2f
#define hr_log10 log10
#define hr_log10f log10f
#define hr_pow pow
#define hr_powf powf
static int64_t hr_find_any(hsl s, const void *set) { const bool *m = set; for (int64_t i = 0; i < s.n; i++) if (m[s.p[i]]) return i; return -1; }
static int64_t hr_find_pair(hsl s, const void *a, int64_t d, const void *b) { const bool *x = a, *y = b; for (int64_t i = 0; i + d < s.n; i++) if (x[s.p[i]] && y[s.p[i + d]]) return i; return -1; }
static bool hr_ffi_cstr(uint64_t p, hrv *out) { if (!p) return false; hr_append(out, (const void *)(uintptr_t)p, (int64_t)strlen((const char *)(uintptr_t)p), 1); return true; }
static bool hr_ffi_bytes(uint64_t p, int64_t n, hrv *out) { if (!p || n < 0) return false; hr_append(out, (const void *)(uintptr_t)p, n, 1); return true; }
static void hr_main(void);
static void hr_init_globals(void);
int main(int argc, char **argv) { hr_argc = argc; hr_argv = argv; hr_init_globals(); hr_main(); hr_flush(); return 0; }
