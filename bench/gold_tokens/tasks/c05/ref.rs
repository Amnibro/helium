use std::collections::HashSet;

fn digit_sum(n: i64) -> i64 {
    n.abs().to_string().bytes().map(|b| (b - b'0') as i64).sum()
}

fn main() {
    let unique: HashSet<i64> = [12, 25, 30, 45, 18]
        .iter()
        .map(|&x| digit_sum(digit_sum(x)))
        .collect();
    println!("results: {}", unique.iter().sum::<i64>());
}
