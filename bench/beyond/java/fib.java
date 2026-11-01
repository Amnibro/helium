// fib: naive doubly recursive Fibonacci (call overhead).
public class fib {
	static long argN(String[] a, long d) { return a.length > 0 ? Long.parseLong(a[0]) : d; }
	static long fib(long n) { return n < 2 ? n : fib(n - 1) + fib(n - 2); }
	public static void main(String[] a) { System.out.println(fib(argN(a, 30))); }
}
