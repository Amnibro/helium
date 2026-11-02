// sort: bottom-up merge sort of n xorshift32 values. Prints a position-weighted checksum
// modulo 1e9+7 and whether the result is ordered.
public class sort {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static int rs = (int) 2463534242L;
	static long rnd() { rs ^= rs << 13; rs ^= rs >>> 17; rs ^= rs << 5; return rs & 0xFFFFFFFFL; }
	public static void main(String[] args) {
		int n = (int) argN(args, 1000);
		long[] src = new long[n], dst = new long[n];
		for (int i = 0; i < n; i++) src[i] = rnd();
		for (int w = 1; w < n; w *= 2) {
			for (int lo = 0; lo < n; lo += 2 * w) {
				int mid = Math.min(lo + w, n), hi = (int) Math.min((long) lo + 2L * w, n);
				int i = lo, j = mid, k = lo;
				while (i < mid && j < hi) dst[k++] = src[i] <= src[j] ? src[i++] : src[j++];
				while (i < mid) dst[k++] = src[i++];
				while (j < hi) dst[k++] = src[j++];
			}
			long[] t = src; src = dst; dst = t;
		}
		long h = 0; int ok = 1;
		for (int i = 0; i < n; i++) { h = (h + src[i] * (i % 1000 + 1)) % 1000000007L; if (i > 0 && src[i - 1] > src[i]) ok = 0; }
		System.out.println(h + " " + ok);
	}
}
