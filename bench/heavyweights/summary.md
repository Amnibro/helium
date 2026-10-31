| Program | Helium (hcn) | C (gcc -O2) | C (clang -O2) | Rust (rustc -O3) | Zig (ReleaseFast) | Go | Java (OpenJDK) | Node.js | Python (CPython) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| fib | 190 ms | 75 ms | 169 ms | 170 ms | 170 ms | 305 ms | 200 ms | 634 ms | 6017 ms |
| nbody | 368 ms | 371 ms | 386 ms | 250 ms | 243 ms | 516 ms | 409 ms | 440 ms | 30.5 s |
| spectral | 287 ms | 273 ms | 286 ms | 274 ms | 268 ms | 290 ms | 353 ms | 404 ms | 34.4 s |
| bintrees | 129 ms | 683 ms | 759 ms | 1148 ms | 759 ms | 912 ms | 326 ms | 661 ms | 3740 ms |
| fannkuch | 1816 ms | 1800 ms | 1956 ms | 1822 ms | 2058 ms | 1790 ms | 2044 ms | 1857 ms | 64.0 s |
| mandelbrot | 656 ms | 602 ms | 656 ms | 614 ms | 625 ms | 630 ms | 691 ms | 676 ms | 31.6 s |
| strmap | 793 ms | 731 ms | 1114 ms | 779 ms | 215 ms | 801 ms | 535 ms | 2869 ms | 2406 ms |
| geomean vs C (gcc) | 0.93× | 1.00× | 1.26× | 1.16× | 0.92× | 1.37× | 1.08× | 1.82× | 31.09× |
| geomean without bintrees | 1.21× | 1.00× | 1.28× | 1.09× | 0.89× | 1.38× | 1.24× | 2.02× | 41.53× |
