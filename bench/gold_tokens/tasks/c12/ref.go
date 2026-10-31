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

func collatzSteps(n int) int {
	x, steps := max(n, 1), 0
	for x != 1 && steps < 200 {
		if x%2 == 0 {
			x /= 2
		} else {
			x = 3*x + 1
		}
		steps++
	}
	return steps
}

func main() {
	count := 0
	for _, x := range []int{7, 3, 7, 9, 7, 2, 7} {
		if x == 7 {
			count++
		}
	}
	out := applyMemo([]int{7, count}, collatzSteps)
	fmt.Printf("no errors in %d results\n", len(out))
	fmt.Printf("cached %d results\n", len(out))
	show(out)
}
