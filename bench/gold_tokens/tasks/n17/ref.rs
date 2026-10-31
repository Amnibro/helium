fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let text = "retry loop".to_lowercase();
    let counts: Vec<i64> = "aeiou"
        .chars()
        .map(|v| text.matches(v).count() as i64)
        .collect();
    show(&counts);
}
