import sys
from math import sqrt
def A(i, j): return 1.0 / ((i + j) * (i + j + 1) // 2 + i + 1)
def mul_av(v, out):
    n = len(v)
    for i in range(n):
        s = 0.0
        for j in range(n): s += A(i, j) * v[j]
        out[i] = s
def mul_atv(v, out):
    n = len(v)
    for i in range(n):
        s = 0.0
        for j in range(n): s += A(j, i) * v[j]
        out[i] = s
n = int(sys.argv[1]) if len(sys.argv) > 1 else 100
u = [1.0] * n; v = [0.0] * n; t = [0.0] * n
for _ in range(10):
    mul_av(u, t); mul_atv(t, v); mul_av(v, t); mul_atv(t, u)
vbv = sum(u[i] * v[i] for i in range(n)); vv = sum(x * x for x in v)
print("%.9f" % sqrt(vbv / vv))
