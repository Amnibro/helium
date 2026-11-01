#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  int n = argc > 1 ? atoi(argv[1]) : 7;
  int perm[32], perm1[32], count[32];
  int maxFlips = 0, checksum = 0, permCount = 0, r = n;
  for (int i = 0; i < n; i++) perm1[i] = i;
  for (;;) {
    while (r != 1) { count[r - 1] = r; r--; }
    for (int i = 0; i < n; i++) perm[i] = perm1[i];
    int flips = 0, k;
    while ((k = perm[0]) != 0) {
      int k2 = (k + 1) >> 1;
      for (int i = 0; i < k2; i++) { int t = perm[i]; perm[i] = perm[k - i]; perm[k - i] = t; }
      flips++;
    }
    if (flips > maxFlips) maxFlips = flips;
    checksum += (permCount % 2 == 0) ? flips : -flips;
    for (;;) {
      if (r == n) { printf("%d\nPfannkuchen(%d) = %d\n", checksum, n, maxFlips); return 0; }
      int p0 = perm1[0];
      for (int i = 0; i < r; i++) perm1[i] = perm1[i + 1];
      perm1[r] = p0;
      count[r]--;
      if (count[r] > 0) break;
      r++;
    }
    permCount++;
  }
}
