package main

import (
	"fmt"
	"strconv"
	"strings"
)

func show(xs []int) {
	s := make([]string, len(xs))
	for i, x := range xs {
		s[i] = strconv.Itoa(x)
	}
	fmt.Println("results: " + strings.Join(s, ","))
}

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

func smallDivisors(n int) int {
	if n < 0 {
		n = -n
	}
	count := 0
	for d := 1; d <= min(n, 10); d++ {
		if n%d == 0 {
			count++
		}
	}
	return count
}

func main() {
	seen := map[int]bool{}
	var unique []int
	for _, x := range applyMemo([]int{6, 12, 18}, smallDivisors) {
		if !seen[x] {
			seen[x] = true
			unique = append(unique, x)
		}
	}
	show(append(unique, unique...))
}
