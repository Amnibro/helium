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

fn square_digit_sum(n: i64) -> i64 {
    n.abs()
        .to_string()
        .bytes()
        .map(|b| ((b - b'0') as i64).pow(2))
        .sum()
}

fn main() {
    let mut out = apply_memo(&[19, 7, 12, 23], |n| square_digit_sum(square_digit_sum(n)));
    let mut errors: Vec<&str> = Vec::new();
    if out.len() < 2 {
        errors.push("not enough items to pair");
    } else {
        out = out.chunks_exact(2).map(|p| p[0] + p[1]).collect();
    }
    match errors.last() {
        Some(e) => println!("error: {} ({} total)", e, errors.len()),
        None => println!("no errors in {} results", out.len()),
    }
    show(&out);
}
