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

fn last_even_digits_sum(n: i64) -> i64 {
    let (mut n, mut total, mut found) = (n.abs(), 0, 0);
    while n > 0 && found < 2 {
        let d = n % 10;
        if d % 2 == 0 {
            total += d;
            found += 1;
        }
        n /= 10;
    }
    total
}

fn main() {
    let mut out = apply_memo(&[2468, 1357, 8642, 2048, 9876], last_even_digits_sum);
    if out.len() >= 2 {
        out = out.windows(2).map(|w| (w[1] - w[0]) * 3).collect();
    }
    show(&out);
}
