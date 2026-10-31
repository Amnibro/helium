fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn digit_sum(n: i64) -> i64 {
    n.abs().to_string().bytes().map(|b| (b - b'0') as i64).sum()
}

fn main() {
    let mut xs = vec![19, 28, 37, 8, 40];
    for x in xs.iter_mut().take_while(|x| **x >= 10) {
        *x = digit_sum(*x);
    }
    show(&xs);
}
