# bintrees: arena binary trees. Nodes are index pairs in one array; each tree is built
# bottom-up into the arena after the long-lived tree and released by resetting the top.
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
sys.setrecursionlimit(10000)
top = 0
def build(d):
    global top
    i = top; top += 1
    if d > 0:
        l = build(d - 1); r = build(d - 1); L[i] = l; R[i] = r
    else:
        L[i] = -1; R[i] = -1
    return i
def check(i): return 1 if L[i] < 0 else 1 + check(L[i]) + check(R[i])
maxd = max(6, N(10))
cap = (2 << (maxd + 1)) + (2 << maxd)
L = [0] * cap; R = [0] * cap
s = build(maxd + 1)
print("stretch tree of depth %d\t check: %d" % (maxd + 1, check(s)))
top = 0
lived = build(maxd)
mark = top
for d in range(4, maxd + 1, 2):
    iters = 1 << (maxd - d + 4); c = 0
    for _ in range(iters):
        top = mark; c += check(build(d))
    print("%d\t trees of depth %d\t check: %d" % (iters, d, c))
print("long lived tree of depth %d\t check: %d" % (maxd, check(lived)))
