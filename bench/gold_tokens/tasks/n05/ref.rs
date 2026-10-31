fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let sums: Vec<i64> = [1, 2, 3, 4, 5, 6, 7]
        .chunks(3)
        .map(|c| c.iter().sum())
        .collect();
    show(&sums);
}
