// regex: backtracking matcher for literals . * + ? ^ $ (Pike style, leftmost, any match),
// run over n generated lines for six patterns. Prints the match count of each pattern.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
static uint32_t rs = 2463534242u;
static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 17; rs ^= rs << 5; return rs; }
static const char *re; static int rl; static const char *tx; static int tl;
static int here(int r, int t);
static int one(char c, int t) { return t < tl && (c == '.' || c == tx[t]); }
static int star(char c, int r, int t) {
	for (;;) { if (here(r, t)) return 1; if (!one(c, t)) return 0; t++; }
}
static int here(int r, int t) {
	if (r == rl) return 1;
	if (r + 1 < rl && re[r + 1] == '*') return star(re[r], r + 2, t);
	if (r + 1 < rl && re[r + 1] == '+') return one(re[r], t) && star(re[r], r + 2, t + 1);
	if (r + 1 < rl && re[r + 1] == '?') { if (one(re[r], t) && here(r + 2, t + 1)) return 1; return here(r + 2, t); }
	if (re[r] == '$' && r + 1 == rl) return t == tl;
	if (one(re[r], t)) return here(r + 1, t + 1);
	return 0;
}
static int match(void) {
	if (rl > 0 && re[0] == '^') return here(1, 0);
	for (int t = 0; t <= tl; t++) if (here(0, t)) return 1;
	return 0;
}
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 1000;
	static const char *pats[6] = {"ab*c", "^a.*f$", "c.d.e", "fa+b?c", "e.*e.*e.*a", "dd*ee*ff*a$"};
	char *buf = malloc(n * 60); int *off = malloc((n + 1) * sizeof(int));
	int pos = 0;
	for (long i = 0; i < n; i++) {
		off[i] = pos;
		int k = 20 + (int)(rnd() % 40);
		for (int j = 0; j < k; j++) buf[pos++] = (char)('a' + rnd() % 6);
	}
	off[n] = pos;
	long counts[6] = {0};
	for (int q = 0; q < 6; q++) {
		re = pats[q]; rl = (int)strlen(re);
		for (long i = 0; i < n; i++) { tx = buf + off[i]; tl = off[i + 1] - off[i]; counts[q] += match(); }
	}
	printf("%ld %ld %ld %ld %ld %ld\n", counts[0], counts[1], counts[2], counts[3], counts[4], counts[5]);
	return 0;
}
