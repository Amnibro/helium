# spectral: power method on A(i,j) = 1/((i+j)(i+j+1)/2+i+1), 10 rounds of v = AtA u.
import math
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
def a(i, j): return 1.0 / ((i + j) * (i + j + 1) // 2 + i + 1)
def mul_av(v, out):
    n = len(v)
    for i in range(n):
        s = 0.0
        for j in range(n): s += a(i, j) * v[j]
        out[i] = s
def mul_atv(v, out):
    n = len(v)
    for i in range(n):
        s = 0.0
        for j in range(n): s += a(j, i) * v[j]
        out[i] = s
def main():
    n = N(100)
    u = [1.0] * n; v = [0.0] * n; t = [0.0] * n
    for _ in range(10):
        mul_av(u, t); mul_atv(t, v); mul_av(v, t); mul_atv(t, u)
    vbv = vv = 0.0
    for i in range(n): vbv += u[i] * v[i]; vv += v[i] * v[i]
    print("%.9f" % math.sqrt(vbv / vv))
main()
