fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let sums: Vec<i64> = [5, 10, 15, 20]
        .iter()
        .scan(0, |acc, &x| {
            *acc += x;
            Some(*acc)
        })
        .collect();
    println!("no errors in {} results", sums.len());
    show(&sums);
}
