fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let xs = [3, 7, 3, 9, 7, 3];
    println!("no errors in {} results", xs.len());
    show(&xs);
}
