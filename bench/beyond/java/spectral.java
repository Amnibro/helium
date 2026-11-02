// spectral: power method on A(i,j) = 1/((i+j)(i+j+1)/2+i+1), 10 rounds of v = AtA u.
public class spectral {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static double a(int i, int j) { return 1.0 / (double) ((long) (i + j) * (i + j + 1) / 2 + i + 1); }
	static void mulAv(double[] v, double[] out) { int n = v.length; for (int i = 0; i < n; i++) { double s = 0; for (int j = 0; j < n; j++) s += a(i, j) * v[j]; out[i] = s; } }
	static void mulAtv(double[] v, double[] out) { int n = v.length; for (int i = 0; i < n; i++) { double s = 0; for (int j = 0; j < n; j++) s += a(j, i) * v[j]; out[i] = s; } }
	static void mulAtAv(double[] v, double[] out, double[] tmp) { mulAv(v, tmp); mulAtv(tmp, out); }
	public static void main(String[] args) {
		int n = (int) argN(args, 100);
		double[] u = new double[n], v = new double[n], t = new double[n];
		java.util.Arrays.fill(u, 1.0);
		for (int k = 0; k < 10; k++) { mulAtAv(u, v, t); mulAtAv(v, u, t); }
		double vbv = 0, vv = 0;
		for (int i = 0; i < n; i++) { vbv += u[i] * v[i]; vv += v[i] * v[i]; }
		System.out.printf("%.9f%n", Math.sqrt(vbv / vv));
	}
}
