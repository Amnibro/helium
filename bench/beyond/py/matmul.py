# matmul: n x n f64 matrix product, i-k-j loop order. Prints the sum and one element.
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
def main():
    n = N(100)
    a = [((i * 31 + j * 17) % 100) / 100.0 for i in range(n) for j in range(n)]
    b = [((i * 13 + j * 29) % 100) / 50.0 - 1.0 for i in range(n) for j in range(n)]
    c = [0.0] * (n * n)
    for i in range(n):
        ri = i * n
        for k in range(n):
            aik = a[ri + k]; rk = k * n
            for j in range(n): c[ri + j] += aik * b[rk + j]
    s = 0.0
    for v in c: s += v
    print("%.6f %.9f" % (s, c[(n // 2) * n + n // 3]))
main()
