fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn remove_last_max(xs: &mut Vec<i64>) {
    if let Some(max) = xs.iter().max().copied() {
        let i = xs.iter().rposition(|&x| x == max).unwrap();
        xs.remove(i);
    }
}

fn main() {
    let mut lengths: Vec<i64> = "parse the config file then retry"
        .split_whitespace()
        .map(|w| w.len() as i64)
        .collect();
    remove_last_max(&mut lengths);
    show(&lengths);
}
