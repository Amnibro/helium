// Matmul: the product of two n x n matrices, with the second one transposed
// first so both operands of every dot product are rows.

import std;
import os;

extern "goose_notify_start" fn notify_start(variant: const u8[:]);
extern "goose_notify_stop" fn notify_stop();

// A matrix is an array of rows. An array cannot hold growable arrays, so the
// rows are runs of one pool, which the caller owns, laid end to end.
fn new_mat(pool: f64[>..]&, x: i64, y: i64) -> (f64[:])[>..] {
    var m: (f64[:])[>..] = [];
    for i in x { m.push(pool.alloc_slice(y)); }
    return m;
}

fn mat_gen(pool: f64[>..]&, n: i64, seed: f64) -> (f64[:])[>..] {
    var m = new_mat(pool, n, n);
    let tmp = seed / n / n;
    for row, i in m {
        for &x, j in row { x = tmp * (i - j) * (i + j); }
    }
    return m;
}

fn mat_mul(pool: f64[>..]&, a: (f64[:])[:], b: (f64[:])[:]) -> (f64[:])[>..] {
    let m = a.len;
    let n = a[0].len;
    let p = b[0].len;

    var b2 = new_mat(pool, n, p);
    for row, i in b {
        for x, j in row { b2[j][i] = x; }
    }

    var c = new_mat(pool, m, p);
    for ci, i in c {
        let a_row = a[i];
        for &cij, j in ci {
            let b2j = b2[j];
            assert(b2j.len == a_row.len);
            var s = 0.0;
            for x, k in a_row { s += x * b2j[k]; }
            cij = s;
        }
    }
    return c;
}

fn calc(n: i64) -> f64 {
    let size = n / 2 * 2;
    reusable[] var pool: f64[>..] = [];
    let a = mat_gen(pool, size, 1.0);
    let b = mat_gen(pool, size, 2.0);
    let c = mat_mul(pool, a, b);
    return c[size / 2][size / 2];
}

fn main() {
    let argv = args();
    var n = 100;
    if argv.len > 1 {
        let v, ok = parse_int(argv[1]);
        if ok { n = v; }
    }

    let left = calc(101);
    let right = -18.67;
    if abs(left - right) > 0.1 { abort(str(left, " != ", right)); }

    notify_start("");
    let results = calc(n);
    notify_stop();

    print(results);
}
