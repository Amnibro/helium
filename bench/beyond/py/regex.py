# regex: backtracking matcher for literals . * + ? ^ $ (Pike style, leftmost, any match),
# run over n generated lines for six patterns. Prints the match count of each pattern.
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
def make(re, tx):
    rl = len(re); tl = len(tx)
    def one(c, t): return t < tl and (c == 46 or c == tx[t])
    def star(c, r, t):
        while True:
            if here(r, t): return True
            if not one(c, t): return False
            t += 1
    def here(r, t):
        if r == rl: return True
        if r + 1 < rl and re[r + 1] == 42: return star(re[r], r + 2, t)
        if r + 1 < rl and re[r + 1] == 43: return one(re[r], t) and star(re[r], r + 2, t + 1)
        if r + 1 < rl and re[r + 1] == 63:
            if one(re[r], t) and here(r + 2, t + 1): return True
            return here(r + 2, t)
        if re[r] == 36 and r + 1 == rl: return t == tl
        if one(re[r], t): return here(r + 1, t + 1)
        return False
    if rl > 0 and re[0] == 94: return here(1, 0)
    for t in range(tl + 1):
        if here(0, t): return True
    return False
def main():
    n = N(1000)
    pats = [b"ab*c", b"^a.*f$", b"c.d.e", b"fa+b?c", b"e.*e.*e.*a", b"dd*ee*ff*a$"]
    lines = []
    for i in range(n):
        k = 20 + rnd() % 40
        lines.append(bytes([97 + rnd() % 6 for _ in range(k)]))
    print(" ".join(str(sum(1 for t in lines if make(p, t))) for p in pats))
main()
