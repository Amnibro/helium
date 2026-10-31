public class nbody {
    static final double PI = 3.141592653589793, SM = 4 * PI * PI, DPY = 365.24;
    static double[][] b = {
        {0, 0, 0, 0, 0, 0, 1},
        {4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04},
        {8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04},
        {1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05},
        {1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05}};
    static final class Body { double x, y, z, vx, vy, vz, mass; }
    static Body[] bodies = new Body[5];
    static double energy() {
        double e = 0;
        for (int i = 0; i < 5; i++) {
            Body p = bodies[i];
            e += 0.5 * p.mass * (p.vx * p.vx + p.vy * p.vy + p.vz * p.vz);
            for (int j = i + 1; j < 5; j++) { Body q = bodies[j]; double dx = p.x - q.x, dy = p.y - q.y, dz = p.z - q.z; e -= p.mass * q.mass / Math.sqrt(dx * dx + dy * dy + dz * dz); }
        }
        return e;
    }
    static void advance(double dt) {
        for (int i = 0; i < 5; i++) {
            Body p = bodies[i];
            for (int j = i + 1; j < 5; j++) {
                Body q = bodies[j];
                double dx = p.x - q.x, dy = p.y - q.y, dz = p.z - q.z, d2 = dx * dx + dy * dy + dz * dz, mag = dt / (d2 * Math.sqrt(d2));
                double mi = p.mass * mag, mj = q.mass * mag;
                p.vx -= dx * mj; p.vy -= dy * mj; p.vz -= dz * mj;
                q.vx += dx * mi; q.vy += dy * mi; q.vz += dz * mi;
            }
        }
        for (Body p : bodies) { p.x += dt * p.vx; p.y += dt * p.vy; p.z += dt * p.vz; }
    }
    public static void main(String[] a) {
        long n = a.length > 0 ? Long.parseLong(a[0]) : 1000;
        for (int i = 0; i < 5; i++) { Body p = new Body(); double[] r = b[i]; p.x = r[0]; p.y = r[1]; p.z = r[2]; p.vx = r[3] * DPY; p.vy = r[4] * DPY; p.vz = r[5] * DPY; p.mass = r[6] * SM; bodies[i] = p; }
        double px = 0, py = 0, pz = 0;
        for (Body p : bodies) { px += p.vx * p.mass; py += p.vy * p.mass; pz += p.vz * p.mass; }
        bodies[0].vx = -px / SM; bodies[0].vy = -py / SM; bodies[0].vz = -pz / SM;
        System.out.printf("%.9f%n", energy());
        for (long i = 0; i < n; i++) advance(0.01);
        System.out.printf("%.9f%n", energy());
    }
}
