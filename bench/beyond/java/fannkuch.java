// fannkuch: pancake flips over all permutations (permutation index order), checksum and max flips.
public class fannkuch {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	public static void main(String[] args) {
		int n = (int) argN(args, 7);
		int[] perm = new int[16], perm1 = new int[16], count = new int[16];
		for (int i = 0; i < n; i++) perm1[i] = i;
		int r = n, maxf = 0, pc = 0; long checksum = 0;
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
			checksum += pc % 2 == 0 ? flips : -flips;
			for (;;) {
				if (r == n) { System.out.println(checksum + "\nPfannkuchen(" + n + ") = " + maxf); return; }
				int p0 = perm1[0];
				for (int i = 0; i < r; i++) perm1[i] = perm1[i + 1];
				perm1[r] = p0;
				count[r]--;
				if (count[r] > 0) break;
				r++;
			}
			pc++;
		}
	}
}
