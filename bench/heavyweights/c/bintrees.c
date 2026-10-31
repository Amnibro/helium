#include <stdio.h>
#include <stdlib.h>
typedef struct Node { struct Node *l, *r; } Node;
static Node *make(int d) {
  Node *n = malloc(sizeof(Node));
  if (d > 0) { n->l = make(d - 1); n->r = make(d - 1); } else { n->l = n->r = NULL; }
  return n;
}
static long check(Node *n) { return n->l ? 1 + check(n->l) + check(n->r) : 1; }
static void release(Node *n) { if (n->l) { release(n->l); release(n->r); } free(n); }
int main(int argc, char **argv) {
  int n = argc > 1 ? atoi(argv[1]) : 10, mind = 4, maxd = n < mind + 2 ? mind + 2 : n;
  Node *s = make(maxd + 1);
  printf("stretch tree of depth %d\t check: %ld\n", maxd + 1, check(s));
  release(s);
  Node *longlived = make(maxd);
  for (int d = mind; d <= maxd; d += 2) {
    long it = 1L << (maxd - d + mind), chk = 0;
    for (long i = 0; i < it; i++) { Node *t = make(d); chk += check(t); release(t); }
    printf("%ld\t trees of depth %d\t check: %ld\n", it, d, chk);
  }
  printf("long lived tree of depth %d\t check: %ld\n", maxd, check(longlived));
  release(longlived);
  return 0;
}
