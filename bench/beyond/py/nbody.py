# nbody: 5 bodies, symplectic Euler, dt 0.01. Prints energy before and after.
import math
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
NB = 5
def main():
    pi = 3.141592653589793; dpy = 365.24; s = 4 * pi * pi
    d = [
        [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0],
        [4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04],
        [8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04],
        [1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05],
        [1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05]]
    X = [r[0] for r in d]; Y = [r[1] for r in d]; Z = [r[2] for r in d]
    VX = [r[3] * dpy for r in d]; VY = [r[4] * dpy for r in d]; VZ = [r[5] * dpy for r in d]; M = [r[6] * s for r in d]
    px = py = pz = 0.0
    for i in range(NB):
        px += VX[i] * M[i]; py += VY[i] * M[i]; pz += VZ[i] * M[i]
    VX[0] = -px / s; VY[0] = -py / s; VZ[0] = -pz / s
    def energy():
        e = 0.0
        for i in range(NB):
            e += 0.5 * M[i] * (VX[i] * VX[i] + VY[i] * VY[i] + VZ[i] * VZ[i])
            for j in range(i + 1, NB):
                dx = X[i] - X[j]; dy = Y[i] - Y[j]; dz = Z[i] - Z[j]
                e -= M[i] * M[j] / math.sqrt(dx * dx + dy * dy + dz * dz)
        return e
    print("%.9f" % energy())
    pairs = [(i, j) for i in range(NB) for j in range(i + 1, NB)]
    dt = 0.01
    sqrt = math.sqrt
    for _ in range(N(1000)):
        for i, j in pairs:
            dx = X[i] - X[j]; dy = Y[i] - Y[j]; dz = Z[i] - Z[j]
            d2 = dx * dx + dy * dy + dz * dz
            mag = dt / (d2 * sqrt(d2))
            mj = M[j] * mag; mi = M[i] * mag
            VX[i] -= dx * mj; VY[i] -= dy * mj; VZ[i] -= dz * mj
            VX[j] += dx * mi; VY[j] += dy * mi; VZ[j] += dz * mi
        for i in range(NB):
            X[i] += dt * VX[i]; Y[i] += dt * VY[i]; Z[i] += dt * VZ[i]
    print("%.9f" % energy())
main()
