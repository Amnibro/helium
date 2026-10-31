use std::collections::{HashMap, HashSet};

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

fn small_divisors(n: i64) -> i64 {
    let n = n.abs();
    (1..=n.min(10)).filter(|d| n % d == 0).count() as i64
}

fn main() {
    let mut seen = HashSet::new();
    let unique: Vec<i64> = apply_memo(&[6, 12, 18], small_divisors)
        .into_iter()
        .filter(|x| seen.insert(*x))
        .collect();
    show(&unique.repeat(2));
}
