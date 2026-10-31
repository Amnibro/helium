package main

import (
	"fmt"
)

func digitSum(n int) int {
	if n < 0 {
		n = -n
	}
	s := 0
	for ; n > 0; n /= 10 {
		s += n % 10
	}
	return s
}

func main() {
	seen := map[int]bool{}
	total := 0
	for _, x := range []int{12, 25, 30, 45, 18} {
		v := digitSum(digitSum(x))
		if !seen[v] {
			seen[v] = true
			total += v
		}
	}
	fmt.Printf("results: %d\n", total)
}
