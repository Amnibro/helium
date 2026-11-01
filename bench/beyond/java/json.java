// json: generate a JSON array of n records, then parse it with a generic recursive-descent
// parser. Prints the sum of all numbers, total string bytes, trues, objects and arrays.
public class json {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static int rs = (int) 2463534242L;
	static long rnd() { rs ^= rs << 13; rs ^= rs >>> 17; rs ^= rs << 5; return rs & 0xFFFFFFFFL; }
	static byte[] D; static int P; static long nums, strs, trues, objs, arrs;
	static void ws() { while (P < D.length && (D[P] == ' ' || D[P] == '\n' || D[P] == '\t' || D[P] == '\r')) P++; }
	static void str() { P++; int s = P; while (D[P] != '"') { if (D[P] == '\\') P++; P++; } strs += P - s; P++; }
	static void value() {
		ws();
		byte c = D[P];
		if (c == '{') {
			objs++; P++; ws();
			if (D[P] == '}') { P++; return; }
			for (;;) { ws(); str(); ws(); P++; value(); ws(); if (D[P] == ',') { P++; continue; } P++; return; }
		} else if (c == '[') {
			arrs++; P++; ws();
			if (D[P] == ']') { P++; return; }
			for (;;) { value(); ws(); if (D[P] == ',') { P++; continue; } P++; return; }
		} else if (c == '"') str();
		else if (c == 't') { trues++; P += 4; }
		else if (c == 'f') P += 5;
		else if (c == 'n') P += 4;
		else {
			boolean neg = false; if (D[P] == '-') { neg = true; P++; }
			long v = 0; while (P < D.length && D[P] >= '0' && D[P] <= '9') { v = v * 10 + (D[P] - '0'); P++; }
			nums += neg ? -v : v;
		}
	}
	public static void main(String[] args) {
		long n = argN(args, 1000);
		StringBuilder sb = new StringBuilder("[");
		for (long i = 0; i < n; i++) {
			if (i > 0) sb.append(",\n");
			sb.append("{\"id\":").append(i).append(",\"name\":\"item").append(i);
			sb.append("\",\"tags\":[\"t").append(rnd() % 100).append("\",\"t").append(rnd() % 100);
			sb.append("\"],\"pos\":{\"x\":").append(rnd() % 10000).append(",\"y\":").append(rnd() % 10000 - 5000);
			sb.append("},\"ok\":").append((rnd() & 1) != 0 ? "true" : "false").append('}');
		}
		sb.append(']');
		D = sb.toString().getBytes(java.nio.charset.StandardCharsets.ISO_8859_1);
		P = 0;
		value();
		System.out.println(D.length + " " + nums + " " + strs + " " + trues + " " + objs + " " + arrs);
	}
}
