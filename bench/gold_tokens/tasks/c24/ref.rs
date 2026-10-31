use std::collections::HashMap;

fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn apply_memo(xs: &[i64], f: impl Fn(i64) -> i64) -> Vec<i64> {
    let mut memo = HashMap::new();
    let mut hits = 0;
    let out: Vec<i64> = xs
        .iter()
        .map(|&x| {
            if let Some(&v) = memo.get(&x) {
                hits += 1;
                v
            } else {
                *memo.entry(x).or_insert(f(x))
            }
        })
        .collect();
    println!(
        "subfunction ran on {} results, {} memo hits",
        out.len(),
        hits
    );
    out
}

fn doubling_sum(n: i64) -> i64 {
    let (mut cur, mut total) = (n.max(1), 0);
    while cur <= 50 {
        total += cur;
        cur *= 2;
    }
    total
}

fn main() {
    let out = apply_memo(&[3, 5, 7], doubling_sum);
    println!("cached {} results", out.len());
    show(&out);
}
