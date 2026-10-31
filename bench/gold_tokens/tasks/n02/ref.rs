use std::collections::HashSet;

fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
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
    show(&top_unique(&[72, 95, 60, 88, 95, 41], 3));
}
