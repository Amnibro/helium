// hashmap: n inserts of xorshift32 keys mod n/2 (value += i), then n lookups of keys mod n.
// Prints entry count, sum of found values and miss count. Open addressing, linear probing.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
static uint32_t rs = 2463534242u;
static uint32_t rnd(void) { rs ^= rs << 13; rs ^= rs >> 17; rs ^= rs << 5; return rs; }
typedef struct { uint32_t *k; int64_t *v; uint8_t *used; uint64_t mask; long count; } Map;
static uint64_t hmix(uint64_t x) { x ^= x >> 33; x *= 0xff51afd7ed558ccdULL; x ^= x >> 33; return x; }
static void grow(Map *m);
static int64_t *slot(Map *m, uint32_t key) {
	if ((m->count + 1) * 4 > (long)(m->mask + 1) * 3) grow(m);
	uint64_t i = hmix(key) & m->mask;
	while (m->used[i]) { if (m->k[i] == key) return &m->v[i]; i = (i + 1) & m->mask; }
	m->used[i] = 1; m->k[i] = key; m->v[i] = 0; m->count++;
	return &m->v[i];
}
static int64_t *find(Map *m, uint32_t key) {
	uint64_t i = hmix(key) & m->mask;
	while (m->used[i]) { if (m->k[i] == key) return &m->v[i]; i = (i + 1) & m->mask; }
	return NULL;
}
static void init(Map *m, uint64_t cap) { m->k = malloc(cap * 4); m->v = malloc(cap * 8); m->used = calloc(cap, 1); m->mask = cap - 1; m->count = 0; }
static void grow(Map *m) {
	Map o = *m; init(m, (o.mask + 1) * 2);
	for (uint64_t i = 0; i <= o.mask; i++) if (o.used[i]) *slot(m, o.k[i]) = o.v[i];
	free(o.k); free(o.v); free(o.used);
}
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 1000;
	Map m; init(&m, 16);
	uint32_t half = (uint32_t)(n / 2);
	for (long i = 0; i < n; i++) *slot(&m, rnd() % half) += i;
	int64_t sum = 0; long miss = 0;
	for (long i = 0; i < n; i++) { int64_t *p = find(&m, rnd() % (uint32_t)n); if (p) sum += *p; else miss++; }
	printf("%ld %ld %ld\n", m.count, (long)sum, miss);
	return 0;
}
