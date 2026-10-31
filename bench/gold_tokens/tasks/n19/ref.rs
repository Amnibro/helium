use std::collections::HashSet;

fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn parse_numbers(text: &str) -> Vec<i64> {
    text.split_whitespace()
        .filter_map(|w| w.parse().ok())
        .collect()
}

fn top_unique(xs: &[i64], k: usize) -> Vec<i64> {
    let mut unique: Vec<i64> = xs
        .iter()
        .copied()
        .collect::<HashSet<_>>()
        .into_iter()
        .collect();
    unique.sort_unstable_by(|a, b| b.cmp(a));
    unique.truncate(k);
    unique
}

fn main() {
    show(&top_unique(
        &parse_numbers("code 500 retry 3 code 200 code 500 retry 1"),
        2,
    ));
}
