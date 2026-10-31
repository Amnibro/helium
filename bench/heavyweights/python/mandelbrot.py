import sys
def main(n):
    count = 0
    for y in range(n):
        ci = 2.0 * y / n - 1.0
        for x in range(n):
            cr = 2.0 * x / n - 1.5
            zr = zi = tr = ti = 0.0
            i = 0
            while i < 50 and tr + ti <= 4.0:
                zi = 2.0 * zr * zi + ci; zr = tr - ti + cr; tr = zr * zr; ti = zi * zi; i += 1
            if tr + ti <= 4.0: count += 1
    print(count)
main(int(sys.argv[1]) if len(sys.argv) > 1 else 200)
