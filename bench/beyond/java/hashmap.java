// hashmap: n inserts of xorshift32 keys mod n/2 (value += i), then n lookups of keys mod n.
// Prints entry count, sum of found values and miss count. Uses java.util.HashMap.
import java.util.HashMap;
public class hashmap {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static int rs = (int) 2463534242L;
	static long rnd() { rs ^= rs << 13; rs ^= rs >>> 17; rs ^= rs << 5; return rs & 0xFFFFFFFFL; }
	public static void main(String[] args) {
		long n = argN(args, 1000);
		HashMap<Long, Long> m = new HashMap<>();
		long half = n / 2;
		for (long i = 0; i < n; i++) m.merge(rnd() % half, i, Long::sum);
		long sum = 0, miss = 0;
		for (long i = 0; i < n; i++) { Long v = m.get(rnd() % n); if (v != null) sum += v; else miss++; }
		System.out.println(m.size() + " " + sum + " " + miss);
	}
}
