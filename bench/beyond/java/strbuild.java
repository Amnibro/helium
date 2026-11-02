// strbuild: write n numbers (xorshift32 % 1000000) comma separated into one string,
// then split it on commas and parse every field back. Prints length, count and sum.
public class strbuild {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static int rs = (int) 2463534242L;
	static long rnd() { rs ^= rs << 13; rs ^= rs >>> 17; rs ^= rs << 5; return rs & 0xFFFFFFFFL; }
	public static void main(String[] args) {
		long n = argN(args, 1000);
		StringBuilder sb = new StringBuilder();
		for (long i = 0; i < n; i++) { if (i > 0) sb.append(','); sb.append(rnd() % 1000000); }
		String s = sb.toString();
		long count = 0, sum = 0;
		for (String f : s.split(",")) { sum += Long.parseLong(f); count++; }
		System.out.println(s.length() + " " + count + " " + sum);
	}
}
