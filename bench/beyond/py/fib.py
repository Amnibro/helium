# fib: naive doubly recursive Fibonacci (call overhead).
import sys
def N(d): return int(sys.argv[1]) if len(sys.argv) > 1 else d
def fib(n): return n if n < 2 else fib(n - 1) + fib(n - 2)
print(fib(N(30)))
