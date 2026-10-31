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

fn collatz(n: i64) -> i64 {
    if n % 2 == 0 {
        n / 2
    } else {
        3 * n + 1
    }
}

fn digit_sum(n: i64) -> i64 {
    n.abs().to_string().bytes().map(|b| (b - b'0') as i64).sum()
}

fn main() {
    let mut seq = vec![7];
    while *seq.last().unwrap() <= 50 {
        seq.push(collatz(*seq.last().unwrap()));
    }
    println!("no errors in {} results", seq.len());
    show(&apply_memo(&seq, digit_sum));
}
