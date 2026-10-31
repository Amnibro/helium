fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn cap_running_sum(xs: &[i64], limit: i64) -> Vec<i64> {
    let mut total = 0;
    xs.iter()
        .copied()
        .take_while(|&x| {
            total += x;
            total <= limit
        })
        .collect()
}

fn main() {
    let kept = cap_running_sum(&[30, 25, 40, 10, 50], 150);
    println!("no errors in {} results", kept.len());
    show(&kept);
}
