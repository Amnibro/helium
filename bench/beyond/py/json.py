# json: generate a JSON array of n records, then parse it with a generic recursive-descent
# parser. Prints the sum of all numbers, total string bytes, trues, objects and arrays.
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
sys.setrecursionlimit(10000)
def main():
    n = N(1000)
    parts = ["["]
    for i in range(n):
        if i > 0: parts.append(",\n")
        a = rnd() % 100; b = rnd() % 100; x = rnd() % 10000; y = rnd() % 10000 - 5000; ok = rnd() & 1
        parts.append('{"id":%d,"name":"item%d","tags":["t%d","t%d"],"pos":{"x":%d,"y":%d},"ok":%s}' % (i, i, a, b, x, y, "true" if ok else "false"))
    parts.append("]")
    D = "".join(parts).encode()
    L = len(D)
    st = [0, 0, 0, 0, 0]
    P = 0
    def ws():
        nonlocal P
        while P < L and D[P] in (32, 10, 9, 13): P += 1
    def string():
        nonlocal P
        P += 1; s = P
        while D[P] != 34:
            if D[P] == 92: P += 1
            P += 1
        st[1] += P - s; P += 1
    def value():
        nonlocal P
        ws()
        c = D[P]
        if c == 123:
            st[3] += 1; P += 1; ws()
            if D[P] == 125: P += 1; return
            while True:
                ws(); string(); ws(); P += 1; value(); ws()
                if D[P] == 44: P += 1; continue
                P += 1; return
        elif c == 91:
            st[4] += 1; P += 1; ws()
            if D[P] == 93: P += 1; return
            while True:
                value(); ws()
                if D[P] == 44: P += 1; continue
                P += 1; return
        elif c == 34: string()
        elif c == 116: st[2] += 1; P += 4
        elif c == 102: P += 5
        elif c == 110: P += 4
        else:
            neg = False
            if D[P] == 45: neg = True; P += 1
            v = 0
            while P < L and 48 <= D[P] <= 57: v = v * 10 + (D[P] - 48); P += 1
            st[0] += -v if neg else v
    value()
    print(L, st[0], st[1], st[2], st[3], st[4])
main()
