fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let sums: Vec<i64> = [3, 8, 12, 5, 6]
        .iter()
        .filter(|&&x| x % 2 == 0)
        .scan(0, |acc, &x| {
            *acc += x;
            Some(*acc)
        })
        .collect();
    show(&sums);
}
