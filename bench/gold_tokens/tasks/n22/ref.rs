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

fn cap_running_sum(xs: &[i64], limit: i64) -> Vec<i64> {
    let mut total = 0;
    xs.iter()
        .copied()
        .take_while(|&x| {
            total += x;
            total <= limit
        })
        .collect()
}

fn main() {
    let mut xs = vec![20, 35, 15, 40, 10];
    remove_last_max(&mut xs);
    let sums: Vec<i64> = cap_running_sum(&xs, 60)
        .iter()
        .scan(0, |acc, &x| {
            *acc += x;
            Some(*acc)
        })
        .collect();
    show(&sums);
}
