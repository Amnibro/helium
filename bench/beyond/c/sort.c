// sort: bottom-up merge sort of n xorshift32 values. Prints a position-weighted checksum
// modulo 1e9+7 and whether the result is ordered.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
static uint32_t rs = 2463534242u;
static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 17; rs ^= rs << 5; return rs; }
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 1000;
	uint32_t *src = malloc(n * 4), *dst = malloc(n * 4);
	for (long i = 0; i < n; i++) src[i] = rnd();
	for (long w = 1; w < n; w *= 2) {
		for (long lo = 0; lo < n; lo += 2 * w) {
			long mid = lo + w < n ? lo + w : n, hi = lo + 2 * w < n ? lo + 2 * w : n;
			long i = lo, j = mid, k = lo;
			while (i < mid && j < hi) dst[k++] = src[i] <= src[j] ? src[i++] : src[j++];
			while (i < mid) dst[k++] = src[i++];
			while (j < hi) dst[k++] = src[j++];
		}
		uint32_t *t = src; src = dst; dst = t;
	}
	long h = 0; int ok = 1;
	for (long i = 0; i < n; i++) {
		h = (h + (long)src[i] * (i % 1000 + 1)) % 1000000007L;
		if (i > 0 && src[i - 1] > src[i]) ok = 0;
	}
	printf("%ld %d\n", h, ok);
	return 0;
}
