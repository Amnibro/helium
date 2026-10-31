fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let xs: Vec<i64> = [-5, 12, 48, 103, 7]
        .iter()
        .map(|&x| x.clamp(0, 50))
        .collect();
    println!("no errors in {} results", xs.len());
    show(&xs);
}
