import java.util.HashMap;
public class strmap {
    public static void main(String[] a) {
        long n = a.length > 0 ? Long.parseLong(a[0]) : 1000;
        HashMap<String, Integer> m = new HashMap<>();
        long x = 1;
        for (long i = 0; i < n; i++) { x = (x * 1103515245L + 12345) & 0x7fffffffL; m.merge("key" + (x % 200000), 1, Integer::sum); }
        int maxc = 0; for (int v : m.values()) if (v > maxc) maxc = v;
        long sum = 0; for (int j = 0; j < 1000; j++) { Integer v = m.get("key" + j); if (v != null) sum += v; }
        System.out.println(m.size() + " " + maxc + " " + sum);
    }
}
