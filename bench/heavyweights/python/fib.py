import sys
sys.setrecursionlimit(10000)
def fib(n): return n if n < 2 else fib(n - 1) + fib(n - 2)
print(fib(int(sys.argv[1]) if len(sys.argv) > 1 else 30))
