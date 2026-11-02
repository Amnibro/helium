// fib: naive doubly recursive Fibonacci (call overhead).
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
function fib(n) { return n < 2 ? n : fib(n - 1) + fib(n - 2); }
console.log(String(fib(N(30))));
