// matmul: n x n f64 matrix product, i-k-j loop order. Prints the sum and one element.
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 100;
	double *a = malloc(n * n * sizeof(double)), *b = malloc(n * n * sizeof(double)), *c = calloc(n * n, sizeof(double));
	for (long i = 0; i < n; i++)
		for (long j = 0; j < n; j++) {
			a[i * n + j] = (double)((i * 31 + j * 17) % 100) / 100.0;
			b[i * n + j] = (double)((i * 13 + j * 29) % 100) / 50.0 - 1.0;
		}
	for (long i = 0; i < n; i++)
		for (long k = 0; k < n; k++) {
			double aik = a[i * n + k];
			for (long j = 0; j < n; j++) c[i * n + j] += aik * b[k * n + j];
		}
	double s = 0;
	for (long i = 0; i < n * n; i++) s += c[i];
	printf("%.6f %.9f\n", s, c[(n / 2) * n + n / 3]);
	return 0;
}
