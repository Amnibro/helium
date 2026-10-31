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

func squareDigitSum(n int) int {
	if n < 0 {
		n = -n
	}
	s := 0
	for ; n > 0; n /= 10 {
		d := n % 10
		s += d * d
	}
	return s
}

func checkErrors(errs []string, n int) {
	if len(errs) > 0 {
		fmt.Printf("error: %s (%d total)\n", errs[len(errs)-1], len(errs))
	} else {
		fmt.Printf("no errors in %d results\n", n)
	}
}

func main() {
	out := applyMemo([]int{19, 7, 12, 23}, func(n int) int { return squareDigitSum(squareDigitSum(n)) })
	var errs []string
	if len(out) < 2 {
		errs = append(errs, "not enough items to pair")
	} else {
		pairs := make([]int, len(out)/2)
		for i := range pairs {
			pairs[i] = out[2*i] + out[2*i+1]
		}
		out = pairs
	}
	checkErrors(errs, len(out))
	show(out)
}
