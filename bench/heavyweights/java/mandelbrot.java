public class mandelbrot {
    public static void main(String[] a) {
        int n = a.length > 0 ? Integer.parseInt(a[0]) : 200; long count = 0;
        for (int y = 0; y < n; y++) {
            double ci = 2.0 * y / n - 1.0;
            for (int x = 0; x < n; x++) {
                double cr = 2.0 * x / n - 1.5, zr = 0, zi = 0, tr = 0, ti = 0; int i = 0;
                while (i < 50 && tr + ti <= 4.0) { zi = 2.0 * zr * zi + ci; zr = tr - ti + cr; tr = zr * zr; ti = zi * zi; i++; }
                if (tr + ti <= 4.0) count++;
            }
        }
        System.out.println(count);
    }
}
