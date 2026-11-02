# strbuild: write n numbers (xorshift32 % 1000000) comma separated into one string,
# then split it on commas and parse every field back. Prints length, count and sum.
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
    s = ",".join([str(rnd() % 1000000) for _ in range(n)])
    count = 0; total = 0
    for f in s.split(","):
        total += int(f); count += 1
    print(len(s), count, total)
main()
