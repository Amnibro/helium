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
#include <setjmp.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
typedef struct { uint8_t *p; int64_t n; } hsl;
typedef struct { uint8_t *b; int64_t n; int64_t top; int64_t *fl; int64_t fln, flc; } hrv;
#ifdef GS_STACK_RESERVE
#define HR_RSZ ((int64_t)(GS_STACK_RESERVE) & ~(int64_t)4095)
#else
#define HR_RSZ ((int64_t)1 << 34)
#endif
#define HR_LIKELY(x) __builtin_expect(!!(x), 1)
#define HR_UNLIKELY(x) __builtin_expect(!!(x), 0)
static int hr_argc; static char **hr_argv;
static __thread uint8_t **hr_free; static __thread int64_t hr_nfree, hr_cfree;
static __thread uint8_t *hr_vbase, *hr_vtop;
static __thread hrv hr_ob;
static __thread int hr_lr;
static void hr_flush(void);
static __attribute__((noreturn, cold)) void hr_die(const char *m, const char *loc) { hr_flush(); fprintf(stderr, "helium runtime error: %s (%s)\n", m, loc); exit(1); }
static inline int64_t hr_rget(void *q, int sz) { return sz == 1 ? *(int8_t*)q : sz == 2 ? *(int16_t*)q : sz == 4 ? *(int32_t*)q : *(int64_t*)q; }
static inline void *hr_rldv(void *q, int sz, int opt) { int64_t d = hr_rget(q, sz); return opt && !d ? (void*)0 : (void*)((char*)q + d); }
static inline void hr_rstv(void *q, int sz, void *p, int opt) { int64_t d = p ? (char*)p - (char*)q : 0; if (p && opt && d == 0) hr_die("a relative reference would encode as null", "store"); if (sz < 8 && (d < -(1LL << (sz * 8 - 1)) || d >= (1LL << (sz * 8 - 1)))) hr_die("relative reference offset out of range", "store"); if (sz == 1) *(int8_t*)q = (int8_t)d; else if (sz == 2) *(int16_t*)q = (int16_t)d; else if (sz == 4) *(int32_t*)q = (int32_t)d; else *(int64_t*)q = d; }
#define hr_rld(q, opt) hr_rldv((void*)(q), (int)sizeof *(q), (opt))
#define hr_rst(q, p, opt, bits) hr_rstv((void*)(q), (int)sizeof *(q), (p), (opt))
static __attribute__((noreturn, cold)) void hr_oob(int64_t i, int64_t n, const char *loc) { char b[96]; snprintf(b, sizeof b, "index %lld out of bounds (length %lld)", (long long)i, (long long)n); hr_die(b, loc); }
static __attribute__((noreturn, cold)) void hr_slerr(int64_t a, int64_t b, int64_t n, const char *loc) { char m[128]; snprintf(m, sizeof m, "slice %lld..%lld out of bounds (length %lld)", (long long)a, (long long)b, (long long)n); hr_die(m, loc); }
static inline int64_t hr_ix(int64_t i, int64_t n, const char *loc) { if (HR_UNLIKELY((uint64_t)i >= (uint64_t)n)) hr_oob(i, n, loc); return i; }
static uint8_t *hr_take(void) {
	if (hr_nfree) return hr_free[--hr_nfree];
	void *p = mmap(NULL, HR_RSZ + 65536, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
	if (p == MAP_FAILED) { fprintf(stderr, "helium runtime error: out of address space\n"); exit(1); }
	mprotect((uint8_t *)p + HR_RSZ, 65536, PROT_NONE);
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
static inline void hr_rfree(hrv *v, int64_t esz) { if (v->fl) free(v->fl); hr_give(v->b, v->top ? v->top : v->n * esz); *v = (hrv){0}; }
static __thread hrv hr_ds; static __thread int64_t hr_dsk;
static inline void hr_dsr(int64_t *m) { hr_ds.n = *m; }
static inline void hr_dsf(int64_t *m) { hr_ds.n = *m + hr_dsk; hr_dsk = 0; }
static inline int64_t hr_vget(const uint8_t *p, int w) { return w == 1 ? *p : w == 2 ? *(const uint16_t*)p : w == 4 ? *(const uint32_t*)p : *(const int64_t*)p; }
static inline void hr_vput(uint8_t *p, int w, int64_t v) { if (w == 1) *p = (uint8_t)v; else if (w == 2) *(uint16_t*)p = (uint16_t)v; else if (w == 4) *(uint32_t*)p = (uint32_t)v; else *(int64_t*)p = v; }
static inline hsl hr_vsl(uint8_t *p, int w, int lim) { return (hsl){ p + (lim ? 2 * w : w), hr_vget(p + (lim ? w : 0), w) }; }
static inline void hr_resize(hrv *v, int64_t n, int64_t esz) { hr_rinit(v); if (n > v->n) memset(v->b + v->n * esz, 0, (size_t)((n - v->n) * esz)); v->n = n; }
static inline uint8_t *hr_vmk(int64_t n, int64_t cap, int w, int lim, int64_t esz) { if (n < 0 || cap < n) hr_die("array count out of range", "construct"); if (w < 8 && (uint64_t)cap >> (w * 8)) hr_die("too many elements for the array's length field", "construct"); int64_t hb = (int64_t)w * (lim + 1); uint8_t *p = hr_grow(&hr_ds, hb + cap * esz, 1); if (lim) { hr_vput(p, w, cap); hr_vput(p + w, w, n); } else hr_vput(p, w, n); return p; }
static inline uint8_t *hr_vfrom(hsl s, int w, int lim, int64_t esz) { uint8_t *p = hr_vmk(s.n, s.n, w, lim, esz); memcpy(p + (int64_t)w * (lim + 1), s.p, (size_t)(s.n * esz)); return p; }
static inline uint8_t *hr_dsmv(uint8_t *p, int64_t m, int64_t sz) { hr_rinit(&hr_ds); memmove(hr_ds.b + m, p, (size_t)sz); hr_dsk = sz; return hr_ds.b + m; }
static inline int64_t hr_vszf(const uint8_t *p, int w, int lim, int64_t esz) { return (int64_t)w * (lim + 1) + hr_vget(p, w) * esz; }
static inline uint8_t *hr_seqpush(hrv *v, const uint8_t *x, int64_t sz) { hr_rinit(v); if (HR_UNLIKELY(v->top + sz > HR_RSZ)) hr_die("array grew past its reservation", "push"); uint8_t *d = v->b + v->top; memmove(d, x, (size_t)sz); v->top += sz; v->n++; return d; }
static inline void hr_vplace(int64_t c, uint8_t *f, int64_t sz) { hr_rinit(&hr_ds); uint8_t *d = hr_ds.b + c; if (f != d) memmove(d, f, (size_t)sz); hr_ds.n = c + sz; }
static inline void hr_append(hrv *v, const void *p, int64_t k, int64_t esz) { if (k <= 0) return; uint8_t *d = hr_grow(v, k, esz); memmove(d, p, (size_t)(k * esz)); }
static inline hsl hr_sl(hrv v) { return (hsl){ v.b, v.n }; }
static inline uint8_t *hr_vmark(void) { if (HR_UNLIKELY(!hr_vbase)) hr_vbase = hr_vtop = hr_take(); return hr_vtop; }
static inline uint8_t *hr_valloc(int64_t n) { hr_vmark(); uint8_t *p = hr_vtop; hr_vtop += (n + 7) & ~7; return p; }
static inline int64_t hr_uleb_size(const uint8_t *p) {
	if (HR_LIKELY(!(*p & 0x80))) return 1;
	int64_t n = 1; while (*p++ & 0x80) n++; return n;
}
static inline uint64_t hr_uleb_read(const uint8_t *p) {
	if (HR_LIKELY(!(*p & 0x80))) return *p;
	uint64_t v = 0; int s = 0; uint8_t b;
	do { b = *p++; v |= (uint64_t)(b & 0x7f) << s; s += 7; } while (b & 0x80);
	return v;
}
static inline int64_t hr_uleb_write(uint8_t *p, uint64_t v) {
	if (HR_LIKELY(v < 0x80)) { *p = (uint8_t)v; return 1; }
	uint8_t *q = p;
	while (v >= 0x80) { *q++ = (uint8_t)(v | 0x80); v >>= 7; }
	*q++ = (uint8_t)v;
	return q - p;
}
static inline int64_t hr_zig_read(const uint8_t *p) {
	uint64_t u = hr_uleb_read(p);
	return (int64_t)((u >> 1) ^ -(u & 1));
}
static inline int64_t hr_zig_write(uint8_t *p, int64_t v) {
	uint64_t u = ((uint64_t)v << 1) ^ (uint64_t)(v >> 63);
	return hr_uleb_write(p, u);
}
static inline int64_t hr_uleb_check(const uint8_t *p, const uint8_t *e, uint64_t *out) {
	if (p >= e) return 0;
	if (HR_LIKELY(!(*p & 0x80))) { *out = *p; return 1; }
	uint64_t v = 0; int s = 0; const uint8_t *q = p;
	while (q < e) {
		uint8_t b = *q++;
		if (s == 63 && b > 1) return 0;
		v |= (uint64_t)(b & 0x7f) << s;
		if (!(b & 0x80)) {
			if (b == 0) return 0;
			*out = v;
			return q - p;
		}
		s += 7;
		if (s > 63) return 0;
	}
	return 0;
}
static inline int64_t hr_zig_check(const uint8_t *p, const uint8_t *e, int64_t *out) {
	uint64_t u = 0;
	int64_t k = hr_uleb_check(p, e, &u);
	if (!k) return 0;
	*out = (int64_t)((u >> 1) ^ -(u & 1));
	return k;
}
static inline int64_t hr_pool_claim(hrv *v, int64_t esz, int64_t *is_new) {
	hr_rinit(v);
	if (v->fln > 0) { *is_new = 0; return v->fl[--v->fln]; }
	*is_new = 1;
	int64_t iv = v->n;
	if (HR_UNLIKELY((iv + 1) * esz > HR_RSZ)) hr_die("array grew past 16 GiB", "alloc");
	return iv;
}
static inline void hr_pool_free(hrv *v, int64_t idx, const char *loc) {
	if (HR_UNLIKELY((uint64_t)idx >= (uint64_t)v->n)) hr_oob(idx, v->n, loc);
	if (v->fln == v->flc) { v->flc = v->flc ? v->flc * 2 : 64; v->fl = realloc(v->fl, (size_t)v->flc * sizeof(int64_t)); }
	v->fl[v->fln++] = idx;
}
static void hr_span_free(hrv *v, int64_t idx, int64_t len) {
	if (len <= 0) return;
	int64_t n = v->fln, pos = 0;
	while (pos < n && v->fl[2 * pos] < idx) pos++;
	if (pos > 0 && v->fl[2 * (pos - 1)] + v->fl[2 * (pos - 1) + 1] == idx) {
		v->fl[2 * (pos - 1) + 1] += len;
		if (pos < n && v->fl[2 * (pos - 1)] + v->fl[2 * (pos - 1) + 1] == v->fl[2 * pos]) {
			v->fl[2 * (pos - 1) + 1] += v->fl[2 * pos + 1];
			memmove(&v->fl[2 * pos], &v->fl[2 * (pos + 1)], (size_t)(2 * (n - pos - 1)) * sizeof(int64_t));
			v->fln--;
		}
		return;
	}
	if (pos < n && idx + len == v->fl[2 * pos]) {
		v->fl[2 * pos] = idx;
		v->fl[2 * pos + 1] += len;
		return;
	}
	if (2 * (n + 1) > v->flc) { v->flc = v->flc ? v->flc * 2 : 64; v->fl = realloc(v->fl, (size_t)v->flc * sizeof(int64_t)); }
	memmove(&v->fl[2 * (pos + 1)], &v->fl[2 * pos], (size_t)(2 * (n - pos)) * sizeof(int64_t));
	v->fl[2 * pos] = idx;
	v->fl[2 * pos + 1] = len;
	v->fln++;
}
static int64_t hr_span_alloc(hrv *v, int64_t len) {
	if (len <= 0) return 0;
	int64_t best = -1;
	for (int64_t i = 0; i < v->fln; i++) {
		int64_t sl = v->fl[2 * i + 1];
		if (sl >= len && (best < 0 || sl < v->fl[2 * best + 1])) best = i;
	}
	if (best < 0) return v->n;
	int64_t idx = v->fl[2 * best];
	if (v->fl[2 * best + 1] == len) {
		memmove(&v->fl[2 * best], &v->fl[2 * (best + 1)], (size_t)(2 * (v->fln - best - 1)) * sizeof(int64_t));
		v->fln--;
	} else {
		v->fl[2 * best] += len;
		v->fl[2 * best + 1] -= len;
	}
	return idx;
}
static int64_t hr_span_regrow(hrv *v, int64_t idx, int64_t ol, int64_t nl) {
	int64_t need = nl - ol;
	for (int64_t i = 0; i < v->fln; i++) {
		if (v->fl[2 * i] == idx + ol) {
			int64_t sl = v->fl[2 * i + 1];
			if (sl >= need || idx + ol + sl == v->n) {
				int64_t take = sl < need ? sl : need;
				if (sl == take) {
					memmove(&v->fl[2 * i], &v->fl[2 * (i + 1)], (size_t)(2 * (v->fln - i - 1)) * sizeof(int64_t));
					v->fln--;
				} else {
					v->fl[2 * i] += take;
					v->fl[2 * i + 1] -= take;
				}
				return idx;
			}
			break;
		}
	}
	hr_span_free(v, idx, ol);
	return hr_span_alloc(v, nl);
}
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
static uint64_t hr_p5i[342][2], hr_p5[326][2];
static inline int hr_p5b(int e) { return (int)(((uint32_t)e * 1217359) >> 19) + 1; }
static void hr_bx(const uint32_t *b, int nl, int s, uint64_t *o) { unsigned __int128 r = 0; for (int k = nl - 1; k >= 0; k--) { int p = 32 * k - s; if (p >= 128 || p <= -32) continue; r |= p >= 0 ? (unsigned __int128)b[k] << p : (unsigned __int128)(b[k] >> -p); } o[0] = (uint64_t)r; o[1] = (uint64_t)(r >> 64); }
__attribute__((constructor)) static void hr_ryu_init(void) {
	uint32_t a[34] = {1}, d[34] = {0}; int na = 1; d[32] = 1;
	for (int i = 0; i < 342; i++) {
		if (i < 326) hr_bx(a, na, hr_p5b(i) - 125, hr_p5[i]);
		hr_bx(d, 33, 1024 - (hr_p5b(i) - 1 + 125), hr_p5i[i]); hr_p5i[i][0]++; if (!hr_p5i[i][0]) hr_p5i[i][1]++;
		uint64_t c = 0; for (int k = 0; k < na; k++) { c += (uint64_t)a[k] * 5; a[k] = (uint32_t)c; c >>= 32; } if (c) a[na++] = (uint32_t)c;
		uint64_t r = 0; for (int k = 32; k >= 0; k--) { r = (r << 32) | d[k]; d[k] = (uint32_t)(r / 5); r %= 5; }
	}
}
static inline uint64_t hr_ms64(uint64_t m, const uint64_t *mul, int j) { unsigned __int128 b0 = (unsigned __int128)m * mul[0], b2 = (unsigned __int128)m * mul[1]; return (uint64_t)(((b0 >> 64) + b2) >> (j - 64)); }
static inline int hr_p5f(uint64_t v) { int c = 0; while (v % 5 == 0) { v /= 5; c++; } return c; }
static inline uint32_t hr_l10p2(int e) { return ((uint32_t)e * 78913) >> 18; }
static inline uint32_t hr_l10p5(int e) { return ((uint32_t)e * 732923) >> 20; }
static uint64_t hr_d2d(uint64_t bits, int *ex) {
	uint64_t ma = bits & ((1ULL << 52) - 1); uint32_t ie = (uint32_t)(bits >> 52) & 0x7ff;
	int e2; uint64_t m2;
	if (ie == 0) { e2 = 1 - 1023 - 52 - 2; m2 = ma; } else { e2 = (int)ie - 1023 - 52 - 2; m2 = (1ULL << 52) | ma; }
	int ab = (m2 & 1) == 0; uint64_t mv = 4 * m2; uint32_t mms = ma != 0 || ie <= 1;
	uint64_t vr, vp, vm; int e10; int vmt = 0, vrt = 0;
	if (e2 >= 0) {
		uint32_t q = hr_l10p2(e2) - (e2 > 3); e10 = (int)q;
		int k = 125 + hr_p5b((int)q) - 1, i = -e2 + (int)q + k;
		vr = hr_ms64(mv, hr_p5i[q], i); vp = hr_ms64(mv + 2, hr_p5i[q], i); vm = hr_ms64(mv - 1 - mms, hr_p5i[q], i);
		if (q <= 21) { if (mv % 5 == 0) vrt = hr_p5f(mv) >= (int)q; else if (ab) vmt = hr_p5f(mv - 1 - mms) >= (int)q; else vp -= hr_p5f(mv + 2) >= (int)q; }
	} else {
		uint32_t q = hr_l10p5(-e2) - (-e2 > 1); e10 = (int)q + e2;
		int i = -e2 - (int)q, k = hr_p5b(i) - 125, j = (int)q - k;
		vr = hr_ms64(mv, hr_p5[i], j); vp = hr_ms64(mv + 2, hr_p5[i], j); vm = hr_ms64(mv - 1 - mms, hr_p5[i], j);
		if (q <= 1) { vrt = 1; if (ab) vmt = mms == 1; else --vp; } else if (q < 63) vrt = (mv & ((1ULL << q) - 1)) == 0;
	}
	int rm = 0; uint8_t ld = 0; uint64_t out;
	if (vmt || vrt) {
		for (;;) { uint64_t pd = vp / 10, md = vm / 10; if (pd <= md) break; vmt &= vm % 10 == 0; vrt &= ld == 0; ld = (uint8_t)(vr % 10); vr /= 10; vp = pd; vm = md; rm++; }
		if (vmt) for (;;) { if (vm % 10 != 0) break; vrt &= ld == 0; ld = (uint8_t)(vr % 10); vr /= 10; vp /= 10; vm /= 10; rm++; }
		if (vrt && ld == 5 && vr % 2 == 0) ld = 4;
		out = vr + ((vr == vm && (!ab || !vmt)) || ld >= 5);
	} else {
		int up = 0;
		if (vp / 100 > vm / 100) { up = vr % 100 >= 50; vr /= 100; vp /= 100; vm /= 100; rm += 2; }
		for (;;) { uint64_t pd = vp / 10, md = vm / 10; if (pd <= md) break; up = vr % 10 >= 5; vr /= 10; vp = pd; vm = md; rm++; }
		out = vr + (vr == vm || up);
	}
	*ex = e10 + rm; return out;
}
static inline uint32_t hr_ms32(uint32_t m, uint64_t f, int sh) { uint64_t b0 = (uint64_t)m * (uint32_t)f, b1 = (uint64_t)m * (f >> 32); return (uint32_t)((((b0 >> 32) + b1)) >> (sh - 32)); }
static inline uint32_t hr_p5ii(uint32_t m, uint32_t q, int j) { return hr_ms32(m, hr_p5i[q][1] + 1, j); }
static inline uint32_t hr_p5d(uint32_t m, uint32_t i, int j) { return hr_ms32(m, hr_p5[i][1], j); }
static uint64_t hr_f2d(uint32_t bits, int *ex) {
	uint32_t ma = bits & ((1u << 23) - 1), ie = (bits >> 23) & 0xff;
	int e2; uint32_t m2;
	if (ie == 0) { e2 = 1 - 127 - 23 - 2; m2 = ma; } else { e2 = (int)ie - 127 - 23 - 2; m2 = (1u << 23) | ma; }
	int ab = (m2 & 1) == 0; uint32_t mv = 4 * m2, mp = 4 * m2 + 2, mms = ma != 0 || ie <= 1, mm = 4 * m2 - 1 - mms;
	uint32_t vr, vp, vm; int e10; int vmt = 0, vrt = 0; uint8_t ld = 0;
	if (e2 >= 0) {
		uint32_t q = hr_l10p2(e2); e10 = (int)q;
		int k = 61 + hr_p5b((int)q) - 1, i = -e2 + (int)q + k;
		vr = hr_p5ii(mv, q, i); vp = hr_p5ii(mp, q, i); vm = hr_p5ii(mm, q, i);
		if (q != 0 && (vp - 1) / 10 <= vm / 10) { int l = 61 + hr_p5b((int)q - 1) - 1; ld = (uint8_t)(hr_p5ii(mv, q - 1, -e2 + (int)q - 1 + l) % 10); }
		if (q <= 9) { if (mv % 5 == 0) vrt = hr_p5f(mv) >= (int)q; else if (ab) vmt = hr_p5f(mm) >= (int)q; else vp -= hr_p5f(mp) >= (int)q; }
	} else {
		uint32_t q = hr_l10p5(-e2); e10 = (int)q + e2;
		int i = -e2 - (int)q, k = hr_p5b(i) - 61, j = (int)q - k;
		vr = hr_p5d(mv, (uint32_t)i, j); vp = hr_p5d(mp, (uint32_t)i, j); vm = hr_p5d(mm, (uint32_t)i, j);
		if (q != 0 && (vp - 1) / 10 <= vm / 10) { j = (int)q - 1 - (hr_p5b(i + 1) - 61); ld = (uint8_t)(hr_p5d(mv, (uint32_t)(i + 1), j) % 10); }
		if (q <= 1) { vrt = 1; if (ab) vmt = mms == 1; else --vp; } else if (q < 31) vrt = (mv & ((1u << (q - 1)) - 1)) == 0;
	}
	int rm = 0; uint32_t out;
	if (vmt || vrt) {
		while (vp / 10 > vm / 10) { vmt &= vm % 10 == 0; vrt &= ld == 0; ld = (uint8_t)(vr % 10); vr /= 10; vp /= 10; vm /= 10; rm++; }
		if (vmt) while (vm % 10 == 0) { vrt &= ld == 0; ld = (uint8_t)(vr % 10); vr /= 10; vp /= 10; vm /= 10; rm++; }
		if (vrt && ld == 5 && vr % 2 == 0) ld = 4;
		out = vr + ((vr == vm && (!ab || !vmt)) || ld >= 5);
	} else {
		while (vp / 10 > vm / 10) { ld = (uint8_t)(vr % 10); vr /= 10; vp /= 10; vm /= 10; rm++; }
		out = vr + (vr == vm || ld >= 5);
	}
	*ex = e10 + rm; return out;
}
static void hr_fflt(hrv *o, double v, int f32) {
	if (v != v) { hr_fc(o, "nan"); return; }
	if (isinf(v)) { hr_fc(o, v > 0 ? "inf" : "-inf"); return; }
	char dig[24]; int n = 0, x = 0, neg = signbit(v) != 0;
	if (v == 0) { dig[0] = '0'; n = 1; }
	else {
		int e; uint64_t u;
		if (f32) { float f = (float)v; uint32_t b; memcpy(&b, &f, 4); u = hr_f2d(b, &e); } else { uint64_t b; memcpy(&b, &v, 8); u = hr_d2d(b, &e); }
		char t[24]; int k = 0; while (u) { t[k++] = (char)('0' + u % 10); u /= 10; }
		for (int i = 0; i < k; i++) dig[i] = t[k - 1 - i];
		n = k; x = e + k - 1;
	}
	while (n > 1 && dig[n - 1] == '0') n--;
	if (neg) hr_fb(o, '-');
	if (x < -4 || x >= (n > 15 ? n : 15)) { char tb[48]; char *q = tb; *q++ = dig[0]; if (n > 1) { *q++ = '.'; memcpy(q, dig + 1, (size_t)(n - 1)); q += n - 1; } int ax = x < 0 ? -x : x; *q++ = 'e'; *q++ = x < 0 ? '-' : '+'; if (ax >= 100) *q++ = (char)('0' + ax / 100); *q++ = (char)('0' + ax / 10 % 10); *q++ = (char)('0' + ax % 10); hr_append(o, tb, q - tb, 1); return; }
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
static inline void hr_rdrop(hrv *v) { if (v->fl) free(v->fl); hr_give(v->b, 0); *v = (hrv){0}; }
static inline void hr_rgive(hrv v) { if (v.fl) free(v.fl); hr_give(v.b, 0); }
static inline hrv *hr_tmp(hrv *t, hrv v) { if (t->fl) free(t->fl); hr_give(t->b, 0); *t = v; return t; }
static inline void hr_rset(hrv *d, hrv v) { if (d->fl) free(d->fl); hr_give(d->b, 0); *d = v; }
static inline hrv hr_rfrom(hsl s, int64_t esz) { hrv r = {0}; if (s.n) hr_append(&r, s.p, s.n, esz); return r; }
static inline hrv hr_rdup(hrv v, int64_t esz) { return hr_rfrom((hsl){ v.b, v.n }, esz); }
static inline hrv hr_rdup_var(hrv v) { hrv r = {0}; if (v.top > 0) { hr_rinit(&r); memcpy(r.b, v.b, (size_t)v.top); r.n = v.n; r.top = v.top; } return r; }
static __attribute__((noreturn, cold)) void hr_ovf(const char *loc) { hr_die("integer overflow", loc); }
static __attribute__((noreturn, cold)) void hr_castf(const char *loc) { hr_die("cast changes the value", loc); }
#ifdef GS_DEBUG
#define HR_SADD(T, a, b, loc) ({ T _ha = (a), _hb = (b), _hr; if (__builtin_add_overflow(_ha, _hb, &_hr)) hr_ovf(loc); _hr; })
#define HR_SSUB(T, a, b, loc) ({ T _ha = (a), _hb = (b), _hr; if (__builtin_sub_overflow(_ha, _hb, &_hr)) hr_ovf(loc); _hr; })
#define HR_SMUL(T, a, b, loc) ({ T _ha = (a), _hb = (b), _hr; if (__builtin_mul_overflow(_ha, _hb, &_hr)) hr_ovf(loc); _hr; })
#define HR_SNEG(T, a, loc) ({ T _ha = (a), _hr; if (__builtin_sub_overflow((T)0, _ha, &_hr)) hr_ovf(loc); _hr; })
#define HR_SINC(T, p, d, loc) ({ T *_hp = (p), _hr; if (__builtin_add_overflow(*_hp, (T)(d), &_hr)) hr_ovf(loc); *_hp = _hr; })
#define HR_CF2I(T, x, loc) ({ double _hv = (x); T _hr = (T)hr_f2i(_hv); if (!(_hv == (double)_hr)) hr_castf(loc); _hr; })
#define HR_CI2I(T, x, loc) ({ __typeof__(x) _hv = (x); T _hr = (T)_hv; if ((__int128)_hv != (__int128)_hr) hr_castf(loc); _hr; })
#define HR_DBG 1
#else
#define HR_SADD(T, a, b, loc) ((T)((int64_t)(a) + (int64_t)(b)))
#define HR_SSUB(T, a, b, loc) ((T)((int64_t)(a) - (int64_t)(b)))
#define HR_SMUL(T, a, b, loc) ((T)((int64_t)(a) * (int64_t)(b)))
#define HR_SNEG(T, a, loc) ((T)(0 - (uint64_t)(a)))
#define HR_SINC(T, p, d, loc) ((void)(*(p) += (d)))
#define HR_CF2I(T, x, loc) ((T)hr_f2i(x))
#define HR_CI2I(T, x, loc) ((T)(x))
#define HR_DBG 0
#endif
#define HR_SDIV(T, a, b, loc) ({ T _da = (a), _db = (b); if (HR_UNLIKELY(_db == 0)) hr_die("division by zero", loc); if (sizeof(T) == 8 && HR_UNLIKELY(_db == -1 && _da == (T)((uint64_t)1 << 63))) hr_die("division overflow", loc); if (HR_DBG && sizeof(T) < 8 && _db == -1 && _da == (T)((uint64_t)1 << (sizeof(T) * 8 - 1))) hr_ovf(loc); (T)(_db == -1 ? (T)(0 - (uint64_t)_da) : _da / _db); })
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
typedef struct hr_qmsg { struct hr_qmsg *next; int64_t sz; uint8_t d[]; } hr_qmsg;
typedef struct { pthread_mutex_t mu; pthread_cond_t cv, cv_put; hr_qmsg *head, *tail; int64_t count, limit; bool init, closed; } hr_queue;
static pthread_mutex_t hr_qinit_mu = PTHREAD_MUTEX_INITIALIZER;
static hr_queue hr_qs[512];
static hr_queue *hr_get_q(int qid) {
	hr_queue *q = &hr_qs[qid & 511];
	if (HR_UNLIKELY(!q->init)) {
		pthread_mutex_lock(&hr_qinit_mu);
		if (!q->init) { pthread_mutex_init(&q->mu, 0); pthread_cond_init(&q->cv, 0); pthread_cond_init(&q->cv_put, 0); q->init = true; }
		pthread_mutex_unlock(&hr_qinit_mu);
	}
	return q;
}
static void hr_qput(int qid, const void *p, int64_t sz) {
	hr_queue *q = hr_get_q(qid);
	hr_qmsg *m = malloc(sizeof(hr_qmsg) + (size_t)sz);
	m->next = 0; m->sz = sz; if (sz > 0) memcpy(m->d, p, (size_t)sz);
	pthread_mutex_lock(&q->mu);
	while (q->limit > 0 && q->count >= q->limit && !q->closed) pthread_cond_wait(&q->cv_put, &q->mu);
	if (q->tail) q->tail->next = m; else q->head = m;
	q->tail = m; q->count++;
	pthread_cond_signal(&q->cv);
	pthread_mutex_unlock(&q->mu);
}
static bool hr_qget_raw(int qid, bool wait, void *fixed_out, int64_t fixed_sz, uint8_t **bytes_out) {
	hr_queue *q = hr_get_q(qid);
	pthread_mutex_lock(&q->mu);
	while (!q->head && wait && !q->closed) pthread_cond_wait(&q->cv, &q->mu);
	hr_qmsg *m = q->head;
	if (!m) { pthread_mutex_unlock(&q->mu); return false; }
	q->head = m->next; if (!q->head) q->tail = 0;
	q->count--;
	if (q->limit > 0) pthread_cond_signal(&q->cv_put);
	pthread_mutex_unlock(&q->mu);
	if (bytes_out) { uint8_t *dst = hr_valloc(m->sz); memcpy(dst, m->d, (size_t)m->sz); *bytes_out = dst; }
	else if (fixed_out && fixed_sz > 0) memcpy(fixed_out, m->d, (size_t)fixed_sz);
	free(m);
	return true;
}
static void hr_qlimit(int qid, int64_t lim) { hr_queue *q = hr_get_q(qid); pthread_mutex_lock(&q->mu); q->limit = lim; pthread_cond_broadcast(&q->cv_put); pthread_mutex_unlock(&q->mu); }
static void hr_qclose(int qid) { hr_queue *q = hr_get_q(qid); pthread_mutex_lock(&q->mu); q->closed = true; pthread_cond_broadcast(&q->cv); pthread_cond_broadcast(&q->cv_put); pthread_mutex_unlock(&q->mu); }
typedef struct { void (*fn)(uint8_t *); uint8_t *pkt; } hr_targ;
static pthread_mutex_t hr_tmu = PTHREAD_MUTEX_INITIALIZER;
static pthread_t *hr_tids; static int64_t hr_ntids, hr_ctids;
static void *hr_tstart(void *arg) {
	hr_targ a = *(hr_targ *)arg; free(arg);
	a.fn(a.pkt);
	free(a.pkt);
	if (hr_vbase) munmap(hr_vbase, HR_RSZ + 65536);
	for (int64_t i = 0; i < hr_nfree; i++) munmap(hr_free[i], HR_RSZ + 65536);
	free(hr_free);
	return 0;
}
static int64_t hr_thread_spawn(void (*fn)(uint8_t *), const void *pkt, int64_t sz) {
	hr_targ *a = malloc(sizeof *a); a->fn = fn;
	a->pkt = sz > 0 ? malloc((size_t)sz) : 0;
	if (sz > 0) memcpy(a->pkt, pkt, (size_t)sz);
	pthread_t th;
	if (pthread_create(&th, 0, hr_tstart, a) != 0) hr_die("pthread_create failed", "thread_spawn");
	pthread_mutex_lock(&hr_tmu);
	if (hr_ntids == hr_ctids) { hr_ctids = hr_ctids ? hr_ctids * 2 : 64; hr_tids = realloc(hr_tids, (size_t)hr_ctids * sizeof *hr_tids); }
	int64_t id = hr_ntids++;
	hr_tids[id] = th;
	pthread_mutex_unlock(&hr_tmu);
	return id;
}
static void hr_thread_wait(int64_t id) {
	pthread_mutex_lock(&hr_tmu);
	pthread_t th = hr_tids[id];
	pthread_mutex_unlock(&hr_tmu);
	pthread_join(th, 0);
}
static int64_t hr_hardware_threads(void) {
	long n = sysconf(_SC_NPROCESSORS_ONLN);
	return n > 0 ? (int64_t)n : 1;
}
static void hr_main(void);
static void hr_init_globals(void);
int main(int argc, char **argv) { hr_argc = argc; hr_argv = argv; hr_init_globals(); hr_main(); hr_flush(); return 0; }
