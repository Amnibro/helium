#include <math.h>
#include <stdio.h>
#include <stdlib.h>
static double A(long i, long j) { return 1.0 / (double)((i + j) * (i + j + 1) / 2 + i + 1); }
static void mulAv(long n, const double *v, double *av) { for (long i = 0; i < n; i++) { double s = 0; for (long j = 0; j < n; j++) s += A(i, j) * v[j]; av[i] = s; } }
static void mulAtv(long n, const double *v, double *atv) { for (long i = 0; i < n; i++) { double s = 0; for (long j = 0; j < n; j++) s += A(j, i) * v[j]; atv[i] = s; } }
static void mulAtAv(long n, const double *v, double *out, double *tmp) { mulAv(n, v, tmp); mulAtv(n, tmp, out); }
int main(int argc, char **argv) {
  long n = argc > 1 ? atol(argv[1]) : 100;
  double *u = malloc(n * sizeof(double)), *v = malloc(n * sizeof(double)), *tmp = malloc(n * sizeof(double));
  for (long i = 0; i < n; i++) u[i] = 1.0;
  for (int k = 0; k < 10; k++) { mulAtAv(n, u, v, tmp); mulAtAv(n, v, u, tmp); }
  double vBv = 0, vv = 0;
  for (long i = 0; i < n; i++) { vBv += u[i] * v[i]; vv += v[i] * v[i]; }
  printf("%.9f\n", sqrt(vBv / vv));
  free(u); free(v); free(tmp);
  return 0;
}
