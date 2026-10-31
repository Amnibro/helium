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

fn last_nonzero_digit(n: i64) -> i64 {
    let mut n = n.abs();
    while n != 0 && n % 10 == 0 {
        n /= 10;
    }
    n % 10
}

fn main() {
    let out: Vec<i64> = apply_memo(&[120, 4500, 70, 89, 105], last_nonzero_digit)
        .into_iter()
        .filter(|&x| x > 4)
        .collect();
    println!("no errors in {} results", out.len());
    show(&out);
}
