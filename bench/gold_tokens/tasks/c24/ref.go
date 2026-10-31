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

func doublingSum(n int) int {
	total := 0
	for cur := max(n, 1); cur <= 50; cur *= 2 {
		total += cur
	}
	return total
}

func main() {
	out := applyMemo([]int{3, 5, 7}, doublingSum)
	fmt.Printf("cached %d results\n", len(out))
	show(out)
}
