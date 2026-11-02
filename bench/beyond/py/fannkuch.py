# fannkuch: pancake flips over all permutations (permutation index order), checksum and max flips.
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
def main():
    n = N(7)
    perm = [0] * 16; perm1 = list(range(16)); count = [0] * 16
    r = n; maxf = 0; pc = 0; checksum = 0
    while True:
        while r != 1:
            count[r - 1] = r; r -= 1
        perm[:n] = perm1[:n]
        flips = 0; k = perm[0]
        while k != 0:
            i = 0; j = k
            while i < j:
                perm[i], perm[j] = perm[j], perm[i]; i += 1; j -= 1
            flips += 1
            k = perm[0]
        if flips > maxf: maxf = flips
        checksum += flips if pc % 2 == 0 else -flips
        while True:
            if r == n:
                print("%d\nPfannkuchen(%d) = %d" % (checksum, n, maxf)); return
            p0 = perm1[0]
            for i in range(r): perm1[i] = perm1[i + 1]
            perm1[r] = p0
            count[r] -= 1
            if count[r] > 0: break
            r += 1
        pc += 1
main()
