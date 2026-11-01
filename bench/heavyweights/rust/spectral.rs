fn a(i: usize, j: usize) -> f64 { 1.0 / (((i + j) * (i + j + 1) / 2 + i + 1) as f64) }
fn mul_av(v: &[f64], av: &mut [f64]) { let n = v.len(); for i in 0..n { let mut s = 0.0; for j in 0..n { s += a(i, j) * v[j]; } av[i] = s; } }
fn mul_atv(v: &[f64], atv: &mut [f64]) { let n = v.len(); for i in 0..n { let mut s = 0.0; for j in 0..n { s += a(j, i) * v[j]; } atv[i] = s; } }
fn mul_atav(v: &[f64], out: &mut [f64], tmp: &mut [f64]) { mul_av(v, tmp); mul_atv(tmp, out); }
fn main() {
    let n: usize = std::env::args().nth(1).map(|s| s.parse().unwrap()).unwrap_or(100);
    let (mut u, mut v, mut tmp) = (vec![1.0; n], vec![0.0; n], vec![0.0; n]);
    for _ in 0..10 { mul_atav(&u, &mut v, &mut tmp); mul_atav(&v, &mut u, &mut tmp); }
    let (mut vbv, mut vv) = (0.0, 0.0);
    for i in 0..n { vbv += u[i] * v[i]; vv += v[i] * v[i]; }
    println!("{:.9}", (vbv / vv).sqrt());
}
