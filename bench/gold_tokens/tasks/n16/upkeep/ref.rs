fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let kept: Vec<i64> = [3, 18, 7, 25, 12]
        .into_iter()
        .filter(|x| (10..=30).contains(x))
        .collect();
    show(&kept);
}
