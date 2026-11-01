import sys
def main(n):
    m = {}; x = 1
    for _ in range(n):
        x = (x * 1103515245 + 12345) & 0x7fffffff
        k = "key%d" % (x % 200000)
        m[k] = m.get(k, 0) + 1
    s = sum(m.get("key%d" % j, 0) for j in range(1000))
    print(len(m), max(m.values()), s)
main(int(sys.argv[1]) if len(sys.argv) > 1 else 1000)
