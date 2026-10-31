fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let lengths: Vec<i64> = "a bb ccc dddd"
        .split_whitespace()
        .filter(|w| w.len() >= 2)
        .map(|w| w.len() as i64)
        .collect();
    show(&lengths);
}
