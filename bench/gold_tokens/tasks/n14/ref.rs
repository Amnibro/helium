fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let xs = [4, 9];
    if xs.len() < 3 {
        println!("error: list shorter than minimum (1 total)");
    } else {
        println!("no errors in {} results", xs.len());
    }
    show(&xs);
}
