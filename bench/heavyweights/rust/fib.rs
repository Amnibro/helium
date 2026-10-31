fn fib(n: i64) -> i64 { if n < 2 { n } else { fib(n - 1) + fib(n - 2) } }
fn main() { let n: i64 = std::env::args().nth(1).map(|s| s.parse().unwrap()).unwrap_or(30); println!("{}", fib(n)); }
