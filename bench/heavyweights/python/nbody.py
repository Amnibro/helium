import sys
from math import sqrt, pi
SM = 4 * pi * pi
DPY = 365.24
B = [
    [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0],
    [4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04],
    [8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04],
    [1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05],
    [1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05]]
bodies = [[r[0], r[1], r[2], r[3] * DPY, r[4] * DPY, r[5] * DPY, r[6] * SM] for r in B]
pairs = [(bodies[i], bodies[j]) for i in range(5) for j in range(i + 1, 5)]
def energy():
    e = 0.0
    for i in range(5):
        p = bodies[i]
        e += 0.5 * p[6] * (p[3] * p[3] + p[4] * p[4] + p[5] * p[5])
        for j in range(i + 1, 5):
            q = bodies[j]
            dx, dy, dz = p[0] - q[0], p[1] - q[1], p[2] - q[2]
            e -= p[6] * q[6] / sqrt(dx * dx + dy * dy + dz * dz)
    return e
def advance(n, dt):
    for _ in range(n):
        for p, q in pairs:
            dx, dy, dz = p[0] - q[0], p[1] - q[1], p[2] - q[2]
            d2 = dx * dx + dy * dy + dz * dz
            mag = dt / (d2 * sqrt(d2))
            mi, mj = p[6] * mag, q[6] * mag
            p[3] -= dx * mj; p[4] -= dy * mj; p[5] -= dz * mj
            q[3] += dx * mi; q[4] += dy * mi; q[5] += dz * mi
        for p in bodies:
            p[0] += dt * p[3]; p[1] += dt * p[4]; p[2] += dt * p[5]
px = sum(p[3] * p[6] for p in bodies); py = sum(p[4] * p[6] for p in bodies); pz = sum(p[5] * p[6] for p in bodies)
bodies[0][3] = -px / SM; bodies[0][4] = -py / SM; bodies[0][5] = -pz / SM
n = int(sys.argv[1]) if len(sys.argv) > 1 else 1000
print("%.9f" % energy())
advance(n, 0.01)
print("%.9f" % energy())
