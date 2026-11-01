// mandelbrot: n x n grid over [-1.5,0.5]x[-1,1], 50 iterations, escape |z|^2 > 4.
// Prints the number of points inside and a hash of the row-packed bitmap.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char **argv) {
	long n = argc > 1 ? atol(argv[1]) : 200;
	long inside = 0;
	uint32_t h = 2166136261u;
	for (long y = 0; y < n; y++) {
		double ci = 2.0 * (double)y / (double)n - 1.0;
		uint32_t bits = 0; int nb = 0;
		for (long x = 0; x < n; x++) {
			double cr = 2.0 * (double)x / (double)n - 1.5;
			double zr = 0, zi = 0;
			int in = 1;
			for (int i = 0; i < 50; i++) {
				double tr = zr * zr - zi * zi + cr;
				double ti = 2.0 * zr * zi + ci;
				zr = tr; zi = ti;
				if (zr * zr + zi * zi > 4.0) { in = 0; break; }
			}
			bits = (bits << 1) | (uint32_t)in; nb++;
			inside += in;
			if (nb == 8) { h = (h ^ bits) * 16777619u; bits = 0; nb = 0; }
		}
		if (nb > 0) { h = (h ^ (bits << (8 - nb))) * 16777619u; }
	}
	printf("%ld %u\n", inside, h);
	return 0;
}
