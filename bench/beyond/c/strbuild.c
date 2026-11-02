// strbuild: write n numbers (xorshift32 % 1000000) comma separated into one string,
// then split it on commas and parse every field back. Prints length, count and sum.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
static uint32_t rs = 2463534242u;
static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 17; rs ^= rs << 5; return rs; }
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 1000;
	size_t cap = 16, len = 0;
	char *s = malloc(cap);
	for (long i = 0; i < n; i++) {
		char tmp[16];
		int k = snprintf(tmp, sizeof tmp, "%u", rnd() % 1000000u);
		if (len + k + 1 > cap) { cap *= 2; s = realloc(s, cap); }
		if (i > 0) s[len++] = ',';
		memcpy(s + len, tmp, k); len += k;
	}
	long count = 0, sum = 0;
	size_t start = 0;
	for (size_t i = 0; i <= len; i++) {
		if (i == len || s[i] == ',') {
			long v = 0;
			for (size_t j = start; j < i; j++) v = v * 10 + (s[j] - '0');
			sum += v; count++; start = i + 1;
		}
	}
	printf("%zu %ld %ld\n", len, count, sum);
	return 0;
}
