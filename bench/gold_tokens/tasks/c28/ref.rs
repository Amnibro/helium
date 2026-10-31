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

fn digit_records(n: i64) -> i64 {
    let mut best = -1;
    let mut count = 0;
    for b in n.abs().to_string().bytes() {
        let d = (b - b'0') as i64;
        if d > best {
            best = d;
            count += 1;
        }
    }
    count
}

fn main() {
    let mut out = apply_memo(&[142, 365, 876], digit_records);
    let value = out.len() as i64;
    let mut i = out.len();
    while i > 0 && out[i - 1] > value {
        i -= 1;
    }
    out.insert(i, value);
    show(&out);
}
