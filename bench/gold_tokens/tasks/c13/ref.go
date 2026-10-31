package main

import (
	"fmt"
	"slices"
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

func lastNonzeroDigit(n int) int {
	if n < 0 {
		n = -n
	}
	for n != 0 && n%10 == 0 {
		n /= 10
	}
	return n % 10
}

func main() {
	out := applyMemo([]int{120, 4500, 70, 89, 105, 60}, lastNonzeroDigit)
	slices.Sort(out)
	var kept []int
	for _, x := range out {
		if x >= 6 {
			kept = append(kept, x)
		}
	}
	show(kept)
}
