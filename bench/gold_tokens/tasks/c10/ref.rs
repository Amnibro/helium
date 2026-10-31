fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let xs = [10, 25, 18, 40, 32];
    let gaps: Vec<i64> = xs.windows(2).map(|w| w[1] - w[0]).collect();
    let ranks: Vec<i64> = gaps
        .iter()
        .map(|&x| 1 + gaps.iter().filter(|&&g| g < x).count() as i64)
        .collect();
    show(&ranks);
}
