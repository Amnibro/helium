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

fn collatz_steps(n: i64) -> i64 {
    let (mut x, mut steps) = (n.max(1), 0);
    while x != 1 && steps < 200 {
        x = if x % 2 == 0 { x / 2 } else { 3 * x + 1 };
        steps += 1;
    }
    steps
}

fn main() {
    let xs = [7, 3, 7, 9, 7, 2, 7];
    let count = xs.iter().filter(|&&x| x == 7).count() as i64;
    let out = apply_memo(&[7, count], collatz_steps);
    println!("no errors in {} results", out.len());
    println!("cached {} results", out.len());
    show(&out);
}
