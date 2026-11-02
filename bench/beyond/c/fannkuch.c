// fannkuch: pancake flips over all permutations (permutation index order), checksum and max flips.
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	int n = argc > 1 ? atoi(argv[1]) : 7;
	int perm[16], perm1[16], count[16];
	for (int i = 0; i < n; i++) perm1[i] = i;
	int r = n, maxf = 0, perm_count = 0;
	long checksum = 0;
	for (;;) {
		while (r != 1) { count[r - 1] = r; r--; }
		for (int i = 0; i < n; i++) perm[i] = perm1[i];
		int flips = 0, k = perm[0];
		while (k != 0) {
			int i = 0, j = k;
			while (i < j) { int t = perm[i]; perm[i] = perm[j]; perm[j] = t; i++; j--; }
			flips++;
			k = perm[0];
		}
		if (flips > maxf) maxf = flips;
		checksum += (perm_count % 2 == 0) ? flips : -flips;
		for (;;) {
			if (r == n) { printf("%ld\nPfannkuchen(%d) = %d\n", checksum, n, maxf); return 0; }
			int p0 = perm1[0];
			for (int i = 0; i < r; i++) perm1[i] = perm1[i + 1];
			perm1[r] = p0;
			count[r]--;
			if (count[r] > 0) break;
			r++;
		}
		perm_count++;
	}
}
