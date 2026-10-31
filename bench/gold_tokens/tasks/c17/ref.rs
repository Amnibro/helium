fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn is_prime(n: i64) -> bool {
    n >= 2 && (2..).take_while(|d| d * d <= n).all(|d| n % d != 0)
}

fn main() {
    let text = "AbCdEfGh";
    let mut codes: Vec<i64> = text[text.len() / 2..]
        .bytes()
        .map(|b| {
            let mut n = b as i64;
            if is_prime(n) {
                n += 1;
                while !is_prime(n) {
                    n += 1;
                }
            }
            n
        })
        .collect();
    codes.sort();
    codes.retain(|&c| c >= 65);
    show(&codes);
}
