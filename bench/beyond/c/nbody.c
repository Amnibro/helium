// nbody: 5 bodies, symplectic Euler, dt 0.01. Prints energy before and after.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NB 5
static double X[NB], Y[NB], Z[NB], VX[NB], VY[NB], VZ[NB], M[NB];
static const double PI = 3.141592653589793, DPY = 365.24;
static void init(void) {
	double s = 4 * PI * PI;
	double d[NB][7] = {
		{0, 0, 0, 0, 0, 0, 1},
		{4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04},
		{8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04},
		{1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05},
		{1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05}};
	for (int i = 0; i < NB; i++) {
		X[i] = d[i][0]; Y[i] = d[i][1]; Z[i] = d[i][2];
		VX[i] = d[i][3] * DPY; VY[i] = d[i][4] * DPY; VZ[i] = d[i][5] * DPY; M[i] = d[i][6] * s;
	}
	double px = 0, py = 0, pz = 0;
	for (int i = 0; i < NB; i++) { px += VX[i] * M[i]; py += VY[i] * M[i]; pz += VZ[i] * M[i]; }
	VX[0] = -px / s; VY[0] = -py / s; VZ[0] = -pz / s;
}
static double energy(void) {
	double e = 0;
	for (int i = 0; i < NB; i++) {
		e += 0.5 * M[i] * (VX[i] * VX[i] + VY[i] * VY[i] + VZ[i] * VZ[i]);
		for (int j = i + 1; j < NB; j++) {
			double dx = X[i] - X[j], dy = Y[i] - Y[j], dz = Z[i] - Z[j];
			e -= M[i] * M[j] / sqrt(dx * dx + dy * dy + dz * dz);
		}
	}
	return e;
}
static void advance(double dt) {
	for (int i = 0; i < NB; i++) {
		for (int j = i + 1; j < NB; j++) {
			double dx = X[i] - X[j], dy = Y[i] - Y[j], dz = Z[i] - Z[j];
			double d2 = dx * dx + dy * dy + dz * dz;
			double mag = dt / (d2 * sqrt(d2));
			double mj = M[j] * mag, mi = M[i] * mag;
			VX[i] -= dx * mj; VY[i] -= dy * mj; VZ[i] -= dz * mj;
			VX[j] += dx * mi; VY[j] += dy * mi; VZ[j] += dz * mi;
		}
	}
	for (int i = 0; i < NB; i++) { X[i] += dt * VX[i]; Y[i] += dt * VY[i]; Z[i] += dt * VZ[i]; }
}
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 1000;
	init();
	printf("%.9f\n", energy());
	for (long k = 0; k < n; k++) advance(0.01);
	printf("%.9f\n", energy());
	return 0;
}
