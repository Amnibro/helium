fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn parse_numbers(text: &str) -> Vec<i64> {
    text.split_whitespace()
        .filter_map(|w| w.parse().ok())
        .collect()
}

fn main() {
    let nums = parse_numbers("order 12 qty 7 price 30 tax 3");
    println!("no errors in {} results", nums.len());
    show(&nums);
}
