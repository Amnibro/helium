// matmul: n x n f64 matrix product, i-k-j loop order. Prints the sum and one element.
public class matmul {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	public static void main(String[] args) {
		int n = (int) argN(args, 100);
		double[] a = new double[n * n], b = new double[n * n], c = new double[n * n];
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			a[i * n + j] = (double) ((i * 31 + j * 17) % 100) / 100.0;
			b[i * n + j] = (double) ((i * 13 + j * 29) % 100) / 50.0 - 1.0;
		}
		for (int i = 0; i < n; i++) for (int k = 0; k < n; k++) {
			double aik = a[i * n + k];
			for (int j = 0; j < n; j++) c[i * n + j] += aik * b[k * n + j];
		}
		double s = 0; for (double v : c) s += v;
		System.out.printf("%.6f %.9f%n", s, c[(n / 2) * n + n / 3]);
	}
}
