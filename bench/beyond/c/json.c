// json: generate a JSON array of n records, then parse it with a generic recursive-descent
// parser. Prints the sum of all numbers, total string bytes, trues, objects and arrays.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
static uint32_t rs = 2463534242u;
static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 17; rs ^= rs << 5; return rs; }
static char *doc; static size_t len, cap;
static void put(const char *s) { size_t k = strlen(s); if (len + k > cap) { while (len + k > cap) cap *= 2; doc = realloc(doc, cap); } memcpy(doc + len, s, k); len += k; }
static void put_int(long v) { char t[24]; snprintf(t, sizeof t, "%ld", v); put(t); }
typedef struct { long nums, strs, trues, objs, arrs; } Stats;
static const char *p, *end;
static Stats st;
static void ws(void) { while (p < end && (*p == ' ' || *p == '\n' || *p == '\t' || *p == '\r')) p++; }
static void string(void) {
	p++;
	const char *s = p;
	while (*p != '"') { if (*p == '\\') p++; p++; }
	st.strs += p - s;
	p++;
}
static void value(void) {
	ws();
	char c = *p;
	if (c == '{') {
		st.objs++; p++; ws();
		if (*p == '}') { p++; return; }
		for (;;) { ws(); string(); ws(); p++; value(); ws(); if (*p == ',') { p++; continue; } p++; return; }
	} else if (c == '[') {
		st.arrs++; p++; ws();
		if (*p == ']') { p++; return; }
		for (;;) { value(); ws(); if (*p == ',') { p++; continue; } p++; return; }
	} else if (c == '"') { string(); }
	else if (c == 't') { st.trues++; p += 4; }
	else if (c == 'f') { p += 5; }
	else if (c == 'n') { p += 4; }
	else {
		int neg = 0; if (*p == '-') { neg = 1; p++; }
		long v = 0; while (p < end && *p >= '0' && *p <= '9') { v = v * 10 + (*p - '0'); p++; }
		st.nums += neg ? -v : v;
	}
}
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 1000;
	cap = 64; len = 0; doc = malloc(cap);
	put("[");
	for (long i = 0; i < n; i++) {
		if (i > 0) put(",\n");
		put("{\"id\":"); put_int(i);
		put(",\"name\":\"item"); put_int(i);
		put("\",\"tags\":[\"t"); put_int(rnd() % 100); put("\",\"t"); put_int(rnd() % 100);
		put("\"],\"pos\":{\"x\":"); put_int(rnd() % 10000); put(",\"y\":"); put_int((long)(rnd() % 10000) - 5000);
		put("},\"ok\":"); put(rnd() & 1 ? "true" : "false"); put("}");
	}
	put("]");
	p = doc; end = doc + len;
	value();
	printf("%zu %ld %ld %ld %ld %ld\n", len, st.nums, st.strs, st.trues, st.objs, st.arrs);
	return 0;
}
