public class fannkuch {
    public static void main(String[] a) {
        int n = a.length > 0 ? Integer.parseInt(a[0]) : 7;
        int[] perm = new int[32], perm1 = new int[32], count = new int[32];
        int maxFlips = 0, checksum = 0, permCount = 0, r = n;
        for (int i = 0; i < n; i++) perm1[i] = i;
        for (;;) {
            while (r != 1) { count[r - 1] = r; r--; }
            System.arraycopy(perm1, 0, perm, 0, n);
            int flips = 0, k;
            while ((k = perm[0]) != 0) { int k2 = (k + 1) >> 1; for (int i = 0; i < k2; i++) { int t = perm[i]; perm[i] = perm[k - i]; perm[k - i] = t; } flips++; }
            if (flips > maxFlips) maxFlips = flips;
            checksum += (permCount % 2 == 0) ? flips : -flips;
            for (;;) {
                if (r == n) { System.out.println(checksum + "\nPfannkuchen(" + n + ") = " + maxFlips); return; }
                int p0 = perm1[0];
                for (int i = 0; i < r; i++) perm1[i] = perm1[i + 1];
                perm1[r] = p0;
                if (--count[r] > 0) break;
                r++;
            }
            permCount++;
        }
    }
}
