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

func lastEvenDigitsSum(n int) int {
	if n < 0 {
		n = -n
	}
	total, found := 0, 0
	for ; n > 0 && found < 2; n /= 10 {
		if d := n % 10; d%2 == 0 {
			total += d
			found++
		}
	}
	return total
}

func main() {
	out := applyMemo([]int{2468, 1357, 8642, 2048, 9876}, lastEvenDigitsSum)
	if len(out) >= 2 {
		for i := 0; i < len(out)-1; i++ {
			out[i] = (out[i+1] - out[i]) * 3
		}
		out = out[:len(out)-1]
	}
	show(out)
}
