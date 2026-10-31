fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let mut lengths: Vec<i64> = "parse the config file then retry"
        .split_whitespace()
        .map(|w| w.len() as i64)
        .collect();
    for i in 1..lengths.len() {
        lengths[i] += lengths[i - 1];
    }
    show(&lengths);
}
