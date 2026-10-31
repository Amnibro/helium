package main

import (
	"fmt"
)

func applyMemo(xs []int, f func(int) int) []int {
	memo := map[int]int{}
	hits := 0
	out := make([]int, len(xs))
	for i, x := range xs {
		if v, ok := memo[x]; ok {
			hits++
			out[i] = v
		} else {
			memo[x] = f(x)
			out[i] = memo[x]
		}
	}
	fmt.Printf("subfunction ran on %d results, %d memo hits\n", len(out), hits)
	return out
}

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
	out := applyMemo([]int{99, 18, 1234}, digitSum)
	fmt.Printf("cached %d results\n", len(out))
	seen := map[int]bool{}
	total := 0
	for _, x := range out {
		if !seen[x] {
			seen[x] = true
			total += x
		}
	}
	fmt.Printf("results: %d\n", total)
}
