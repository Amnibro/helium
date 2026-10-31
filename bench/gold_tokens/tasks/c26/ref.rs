fn show(xs: &[i64]) {
    let s: Vec<String> = xs.iter().map(|x| x.to_string()).collect();
    println!("results: {}", s.join(","));
}

fn main() {
    let xs = [25, 20, 15, 4, 2];
    let avg = xs.iter().sum::<i64>() / xs.len() as i64;
    let kept: Vec<i64> = xs
        .iter()
        .take_while(|&&x| x >= avg)
        .map(|&x| {
            let mut x = x;
            while x > 0 && x < 40 {
                x *= 2;
            }
            x
        })
        .collect();
    show(&kept);
}
