use std::collections::HashMap;
use std::fmt::Write;
fn main() {
    let n: u64 = std::env::args().nth(1).map(|s| s.parse().unwrap()).unwrap_or(1000);
    let mut m: HashMap<String, i64> = HashMap::new();
    let mut x: u64 = 1; let mut buf = String::with_capacity(32);
    for _ in 0..n {
        x = (x.wrapping_mul(1103515245) + 12345) & 0x7fffffff;
        buf.clear(); write!(buf, "key{}", x % 200000).unwrap();
        if let Some(v) = m.get_mut(buf.as_str()) { *v += 1; } else { m.insert(buf.clone(), 1); }
    }
    let maxc = m.values().copied().max().unwrap_or(0);
    let mut sum = 0;
    for j in 0..1000 { buf.clear(); write!(buf, "key{}", j).unwrap(); if let Some(v) = m.get(buf.as_str()) { sum += v; } }
    println!("{} {} {}", m.len(), maxc, sum);
}
