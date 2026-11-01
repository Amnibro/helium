# hashmap: n inserts of xorshift32 keys mod n/2 (value += i), then n lookups of keys mod n.
# Prints entry count, sum of found values and miss count. Uses dict.
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
    m = {}
    half = n // 2
    for i in range(n):
        k = rnd() % half
        m[k] = m.get(k, 0) + i
    s = 0; miss = 0
    for i in range(n):
        v = m.get(rnd() % n)
        if v is None: miss += 1
        else: s += v
    print(len(m), s, miss)
main()
