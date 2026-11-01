// fib: naive doubly recursive Fibonacci (call overhead).
package main

import ("fmt"; "os"; "strconv")

func argN(d int64) int64 {
	if len(os.Args) > 1 {
		if v, err := strconv.ParseInt(os.Args[1], 10, 64); err == nil {
			return v
		}
	}
	return d
}

func fib(n int64) int64 { if n < 2 { return n }; return fib(n-1) + fib(n-2) }

func main() { fmt.Println(fib(argN(30))) }
