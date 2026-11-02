# mandelbrot: n x n grid over [-1.5,0.5]x[-1,1], 50 iterations, escape |z|^2 > 4.
# Prints the number of points inside and a hash of the row-packed bitmap.
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
def main():
    n = N(200)
    inside = 0; h = 2166136261
    for y in range(n):
        ci = 2.0 * y / n - 1.0
        bits = 0; nb = 0
        for x in range(n):
            cr = 2.0 * x / n - 1.5
            zr = zi = 0.0
            inn = 1
            for _ in range(50):
                tr = zr * zr - zi * zi + cr
                ti = 2.0 * zr * zi + ci
                zr = tr; zi = ti
                if zr * zr + zi * zi > 4.0:
                    inn = 0; break
            bits = ((bits << 1) | inn) & 0xFFFFFFFF; nb += 1
            inside += inn
            if nb == 8:
                h = ((h ^ bits) * 16777619) & 0xFFFFFFFF; bits = 0; nb = 0
        if nb > 0: h = ((h ^ ((bits << (8 - nb)) & 0xFFFFFFFF)) * 16777619) & 0xFFFFFFFF
    print(inside, h)
main()
