fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn gaps_within(xs: &[i64], limit: i64) -> bool {
    xs.windows(2).all(|w| (w[1] - w[0]).abs() <= limit)
}

fn main() {
    let xs = [10, 14, 19, 31, 33];
    if gaps_within(&xs, 10) {
        println!("no errors in {} results", xs.len());
    } else {
        println!("error: gap exceeds limit (1 total)");
    }
    show(&xs);
}
