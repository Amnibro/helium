fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let codes: Vec<i64> = "Helium".bytes().step_by(2).map(|b| b as i64).collect();
    show(&codes);
}
