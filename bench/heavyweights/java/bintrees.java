public class bintrees {
    static final class Node { Node l, r; Node(Node l, Node r) { this.l = l; this.r = r; } }
    static Node make(int d) { return d > 0 ? new Node(make(d - 1), make(d - 1)) : new Node(null, null); }
    static long check(Node n) { return n.l == null ? 1 : 1 + check(n.l) + check(n.r); }
    public static void main(String[] a) {
        int n = a.length > 0 ? Integer.parseInt(a[0]) : 10, mind = 4, maxd = Math.max(mind + 2, n);
        System.out.println("stretch tree of depth " + (maxd + 1) + "\t check: " + check(make(maxd + 1)));
        Node lng = make(maxd);
        for (int d = mind; d <= maxd; d += 2) {
            long it = 1L << (maxd - d + mind), chk = 0;
            for (long i = 0; i < it; i++) chk += check(make(d));
            System.out.println(it + "\t trees of depth " + d + "\t check: " + chk);
        }
        System.out.println("long lived tree of depth " + maxd + "\t check: " + check(lng));
    }
}
