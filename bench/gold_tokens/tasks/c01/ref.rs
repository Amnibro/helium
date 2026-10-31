fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn collatz(n: i64) -> i64 {
    if n % 2 == 0 {
        n / 2
    } else {
        3 * n + 1
    }
}

fn main() {
    let mut seq = vec![5];
    while *seq.last().unwrap() != 1 {
        seq.push(collatz(*seq.last().unwrap()));
    }
    println!("no errors in {} results", seq.len());
    show(&seq);
}
