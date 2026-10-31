public class fib {
    static long f(long n) { return n < 2 ? n : f(n - 1) + f(n - 2); }
    public static void main(String[] a) { long n = a.length > 0 ? Long.parseLong(a[0]) : 30; System.out.println(f(n)); }
}
