// regex: backtracking matcher for literals . * + ? ^ $ (Pike style, leftmost, any match),
// run over n generated lines for six patterns. Prints the match count of each pattern.
public class regex {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static int rs = (int) 2463534242L;
	static long rnd() { rs ^= rs << 13; rs ^= rs >>> 17; rs ^= rs << 5; return rs & 0xFFFFFFFFL; }
	static byte[] re, B; static int T0, TL;
	static boolean one(byte c, int t) { return t < TL && (c == '.' || c == B[T0 + t]); }
	static boolean star(byte c, int r, int t) { for (;;) { if (here(r, t)) return true; if (!one(c, t)) return false; t++; } }
	static boolean here(int r, int t) {
		int rl = re.length;
		if (r == rl) return true;
		if (r + 1 < rl && re[r + 1] == '*') return star(re[r], r + 2, t);
		if (r + 1 < rl && re[r + 1] == '+') return one(re[r], t) && star(re[r], r + 2, t + 1);
		if (r + 1 < rl && re[r + 1] == '?') { if (one(re[r], t) && here(r + 2, t + 1)) return true; return here(r + 2, t); }
		if (re[r] == '$' && r + 1 == rl) return t == TL;
		if (one(re[r], t)) return here(r + 1, t + 1);
		return false;
	}
	static boolean match() {
		if (re.length > 0 && re[0] == '^') return here(1, 0);
		for (int t = 0; t <= TL; t++) if (here(0, t)) return true;
		return false;
	}
	public static void main(String[] args) {
		int n = (int) argN(args, 1000);
		String[] pats = {"ab*c", "^a.*f$", "c.d.e", "fa+b?c", "e.*e.*e.*a", "dd*ee*ff*a$"};
		B = new byte[n * 60]; int[] off = new int[n + 1];
		int pos = 0;
		for (int i = 0; i < n; i++) { off[i] = pos; int k = 20 + (int) (rnd() % 40); for (int j = 0; j < k; j++) B[pos++] = (byte) ('a' + rnd() % 6); }
		off[n] = pos;
		StringBuilder out = new StringBuilder();
		for (int q = 0; q < 6; q++) {
			re = pats[q].getBytes(); int c = 0;
			for (int i = 0; i < n; i++) { T0 = off[i]; TL = off[i + 1] - off[i]; if (match()) c++; }
			if (q > 0) out.append(' ');
			out.append(c);
		}
		System.out.println(out);
	}
}
