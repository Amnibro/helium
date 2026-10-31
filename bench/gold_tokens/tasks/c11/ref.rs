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

fn digit_sum(n: i64) -> i64 {
    n.abs().to_string().bytes().map(|b| (b - b'0') as i64).sum()
}

fn main() {
    let mut xs: Vec<i64> = [25, 12, 8, 30, 15, 40]
        .into_iter()
        .filter(|&x| x <= 25)
        .collect();
    xs.sort();
    show(&apply_memo(&xs, digit_sum));
}
