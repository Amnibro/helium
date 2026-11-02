# sort: bottom-up merge sort of n xorshift32 values. Prints a position-weighted checksum
# modulo 1e9+7 and whether the result is ordered.
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
rs = 2463534242
def rnd():
    global rs
    x = rs
    x ^= (x << 13) & 0xFFFFFFFF
    x ^= x >> 17
    x ^= (x << 5) & 0xFFFFFFFF
    rs = x
    return x
def main():
    n = N(1000)
    src = [rnd() for _ in range(n)]; dst = [0] * n
    w = 1
    while w < n:
        lo = 0
        while lo < n:
            mid = min(lo + w, n); hi = min(lo + 2 * w, n)
            i = lo; j = mid; k = lo
            while i < mid and j < hi:
                if src[i] <= src[j]: dst[k] = src[i]; i += 1
                else: dst[k] = src[j]; j += 1
                k += 1
            while i < mid: dst[k] = src[i]; i += 1; k += 1
            while j < hi: dst[k] = src[j]; j += 1; k += 1
            lo += 2 * w
        src, dst = dst, src
        w *= 2
    h = 0; ok = 1
    for i in range(n):
        h = (h + src[i] * (i % 1000 + 1)) % 1000000007
        if i > 0 and src[i - 1] > src[i]: ok = 0
    print(h, ok)
main()
