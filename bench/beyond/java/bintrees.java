// bintrees: arena binary trees. Nodes are index pairs in one array; each tree is built
// bottom-up into the arena after the long-lived tree and released by resetting the top.
public class bintrees {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static int[] L, R; static int top;
	static int build(int d) {
		int i = top++;
		if (d > 0) { int l = build(d - 1); int r = build(d - 1); L[i] = l; R[i] = r; } else { L[i] = -1; R[i] = -1; }
		return i;
	}
	static long check(int i) { return L[i] < 0 ? 1 : 1 + check(L[i]) + check(R[i]); }
	public static void main(String[] args) {
		int maxd = Math.max(6, (int) argN(args, 10));
		int cap = (2 << (maxd + 1)) + (2 << maxd);
		L = new int[cap]; R = new int[cap];
		int s = build(maxd + 1);
		System.out.println("stretch tree of depth " + (maxd + 1) + "\t check: " + check(s));
		top = 0;
		int lived = build(maxd);
		int mark = top;
		for (int d = 4; d <= maxd; d += 2) {
			long iters = 1L << (maxd - d + 4), c = 0;
			for (long k = 0; k < iters; k++) { top = mark; c += check(build(d)); }
			System.out.println(iters + "\t trees of depth " + d + "\t check: " + c);
		}
		System.out.println("long lived tree of depth " + maxd + "\t check: " + check(lived));
	}
}
