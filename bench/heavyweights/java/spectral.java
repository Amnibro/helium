public class spectral {
    static double A(int i, int j) { return 1.0 / ((long) (i + j) * (i + j + 1) / 2 + i + 1); }
    static void mulAv(double[] v, double[] av) { int n = v.length; for (int i = 0; i < n; i++) { double s = 0; for (int j = 0; j < n; j++) s += A(i, j) * v[j]; av[i] = s; } }
    static void mulAtv(double[] v, double[] atv) { int n = v.length; for (int i = 0; i < n; i++) { double s = 0; for (int j = 0; j < n; j++) s += A(j, i) * v[j]; atv[i] = s; } }
    public static void main(String[] a) {
        int n = a.length > 0 ? Integer.parseInt(a[0]) : 100;
        double[] u = new double[n], v = new double[n], t = new double[n];
        java.util.Arrays.fill(u, 1.0);
        for (int k = 0; k < 10; k++) { mulAv(u, t); mulAtv(t, v); mulAv(v, t); mulAtv(t, u); }
        double vbv = 0, vv = 0;
        for (int i = 0; i < n; i++) { vbv += u[i] * v[i]; vv += v[i] * v[i]; }
        System.out.printf("%.9f%n", Math.sqrt(vbv / vv));
    }
}
