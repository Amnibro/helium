// bintrees: arena binary trees. Nodes are index pairs in one array; each tree is built
// bottom-up into the arena after the long-lived tree and released by resetting the top.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
static int32_t *L, *R;
static int32_t top;
static int32_t build(int d) {
	int32_t i = top++;
	if (d > 0) { int32_t l = build(d - 1); int32_t r = build(d - 1); L[i] = l; R[i] = r; }
	else { L[i] = -1; R[i] = -1; }
	return i;
}
static long check(int32_t i) { return L[i] < 0 ? 1 : 1 + check(L[i]) + check(R[i]); }
int main(int argc, char **argv) {
	int maxd = argc > 1 ? atoi(argv[1]) : 10;
	if (maxd < 6) maxd = 6;
	long cap = (2L << (maxd + 1)) + (2L << maxd);
	L = malloc(cap * sizeof(int32_t)); R = malloc(cap * sizeof(int32_t));
	top = 0;
	int32_t s = build(maxd + 1);
	printf("stretch tree of depth %d\t check: %ld\n", maxd + 1, check(s));
	top = 0;
	int32_t lived = build(maxd);
	int32_t mark = top;
	for (int d = 4; d <= maxd; d += 2) {
		long iters = 1L << (maxd - d + 4), c = 0;
		for (long k = 0; k < iters; k++) { top = mark; c += check(build(d)); }
		printf("%ld\t trees of depth %d\t check: %ld\n", iters, d, c);
	}
	printf("long lived tree of depth %d\t check: %ld\n", maxd, check(lived));
	return 0;
}
