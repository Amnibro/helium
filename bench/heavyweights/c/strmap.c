#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Open addressing, linear probing, FNV-1a, doubling at 1/2 load; keys are copied on insert. */
typedef struct { char *key; uint32_t len; long val; } Slot;
static Slot *slots; static size_t cap = 1024, used = 0;
static uint64_t fnv(const char *s, size_t n) { uint64_t h = 1469598103934665603ULL; for (size_t i = 0; i < n; i++) { h ^= (unsigned char)s[i]; h *= 1099511628211ULL; } return h; }
static Slot *find(const char *s, size_t n) {
  size_t i = fnv(s, n) & (cap - 1);
  while (slots[i].key && !(slots[i].len == n && memcmp(slots[i].key, s, n) == 0)) i = (i + 1) & (cap - 1);
  return &slots[i];
}
static void grow(void) {
  Slot *old = slots; size_t oc = cap; cap *= 2; slots = calloc(cap, sizeof(Slot));
  for (size_t i = 0; i < oc; i++) if (old[i].key) *find(old[i].key, old[i].len) = old[i];
  free(old);
}
int main(int argc, char **argv) {
  long n = argc > 1 ? atol(argv[1]) : 1000;
  slots = calloc(cap, sizeof(Slot));
  uint64_t x = 1; char buf[32];
  for (long i = 0; i < n; i++) {
    x = (x * 1103515245 + 12345) & 0x7fffffff;
    int len = snprintf(buf, sizeof buf, "key%lu", (unsigned long)(x % 200000));
    Slot *s = find(buf, len);
    if (s->key) s->val++;
    else { s->key = memcpy(malloc(len), buf, len); s->len = len; s->val = 1; if (++used * 2 > cap) grow(); }
  }
  long maxc = 0, sum = 0;
  for (size_t i = 0; i < cap; i++) if (slots[i].key && slots[i].val > maxc) maxc = slots[i].val;
  for (long j = 0; j < 1000; j++) { int len = snprintf(buf, sizeof buf, "key%ld", j); Slot *s = find(buf, len); if (s->key) sum += s->val; }
  printf("%zu %ld %ld\n", used, maxc, sum);
  return 0;
}
