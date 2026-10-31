#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  long n = argc > 1 ? atol(argv[1]) : 200, count = 0;
  for (long y = 0; y < n; y++) {
    double ci = 2.0 * (double)y / (double)n - 1.0;
    for (long x = 0; x < n; x++) {
      double cr = 2.0 * (double)x / (double)n - 1.5;
      double zr = 0, zi = 0, tr = 0, ti = 0;
      int i = 0;
      while (i < 50 && tr + ti <= 4.0) { zi = 2.0 * zr * zi + ci; zr = tr - ti + cr; tr = zr * zr; ti = zi * zi; i++; }
      if (tr + ti <= 4.0) count++;
    }
  }
  printf("%ld\n", count);
  return 0;
}
