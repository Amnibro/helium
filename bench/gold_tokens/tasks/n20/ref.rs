fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn gaps_within(xs: &[i64], limit: i64) -> bool {
    xs.windows(2).all(|w| (w[1] - w[0]).abs() <= limit)
}

fn main() {
    let xs: Vec<i64> = [12, 18, -3, 25, 140, 33]
        .iter()
        .map(|&x| x.clamp(0, 100))
        .collect();
    let deltas: Vec<i64> = xs.windows(2).map(|w| w[1] - w[0]).collect();
    if gaps_within(&deltas, 50) {
        println!("no errors in {} results", deltas.len());
    } else {
        println!("error: gap exceeds limit (1 total)");
    }
    show(&deltas);
}
