import sys
def make(d): return (make(d - 1), make(d - 1)) if d > 0 else (None, None)
def check(n): return 1 if n[0] is None else 1 + check(n[0]) + check(n[1])
n = int(sys.argv[1]) if len(sys.argv) > 1 else 10
mind = 4; maxd = max(mind + 2, n)
print("stretch tree of depth %d\t check: %d" % (maxd + 1, check(make(maxd + 1))))
lng = make(maxd)
for d in range(mind, maxd + 1, 2):
    it = 1 << (maxd - d + mind); chk = 0
    for _ in range(it): chk += check(make(d))
    print("%d\t trees of depth %d\t check: %d" % (it, d, chk))
print("long lived tree of depth %d\t check: %d" % (maxd, check(lng)))
