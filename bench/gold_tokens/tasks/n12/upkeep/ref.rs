fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let kept: Vec<i64> = [40, 15, 70, 25, 90]
        .into_iter()
        .filter(|x: &i64| x.abs() <= 30)
        .collect();
    println!("cached {} results", kept.len());
    show(&kept);
}
