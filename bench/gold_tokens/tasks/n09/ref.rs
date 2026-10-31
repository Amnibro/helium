fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn is_prime(n: i64) -> bool {
    n >= 2 && (2..).take_while(|d| d * d <= n).all(|d| n % d != 0)
}

fn main() {
    let mut xs = vec![1];
    xs.extend((2..=30).filter(|&n| is_prime(n)));
    show(&xs);
}
