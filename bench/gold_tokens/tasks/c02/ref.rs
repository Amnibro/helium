fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let mut xs = vec![10, 20, 30, 40, 5];
    let last = *xs.last().unwrap();
    xs.iter_mut().for_each(|x| *x -= last);
    let n = xs.len();
    for i in 0..2.min(n / 2) {
        xs.swap(i, n - 1 - i);
    }
    show(&xs);
}
