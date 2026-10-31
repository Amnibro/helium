// Variant of bintrees.c that allocates each tree from a bump arena instead of
// one malloc per node, to match the allocation strategy of helium/bintrees.amni.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node { struct Node *l, *r; } Node;
typedef struct { Node *mem; size_t used, cap; } Arena;
static Arena arena_new(int depth) { Arena a; a.cap = ((size_t)1 << (depth + 1)); a.used = 0; a.mem = malloc(a.cap * sizeof(Node)); return a; }
static Node *make(Arena *a, int d) {
  Node *n = &a->mem[a->used++];
  if (d > 0) { n->l = make(a, d - 1); n->r = make(a, d - 1); } else { n->l = n->r = NULL; }
  return n;
}
static long check(Node *n) { return n->l ? 1 + check(n->l) + check(n->r) : 1; }
static long tree_check(int d) { Arena a = arena_new(d); long c = check(make(&a, d)); free(a.mem); return c; }
int main(int argc, char **argv) {
  int n = argc > 1 ? atoi(argv[1]) : 10, mind = 4, maxd = n < mind + 2 ? mind + 2 : n;
  printf("stretch tree of depth %d\t check: %ld\n", maxd + 1, tree_check(maxd + 1));
  Arena la = arena_new(maxd);
  Node *longlived = make(&la, maxd);
  for (int d = mind; d <= maxd; d += 2) {
    long it = 1L << (maxd - d + mind), chk = 0;
    for (long i = 0; i < it; i++) chk += tree_check(d);
    printf("%ld\t trees of depth %d\t check: %ld\n", it, d, chk);
  }
  printf("long lived tree of depth %d\t check: %ld\n", maxd, check(longlived));
  free(la.mem);
  return 0;
}
