fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let mut xs: Vec<i64> = [8, 3, 12, 1, 9, 4].into_iter().filter(|&x| x > 5).collect();
    xs.sort();
    show(&xs);
}
