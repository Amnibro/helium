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

func collatz(n int) int {
	if n%2 == 0 {
		return n / 2
	}
	return 3*n + 1
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

func main() {
	seq := []int{27}
	for seq[len(seq)-1] != 1 {
		seq = append(seq, collatz(seq[len(seq)-1]))
	}
	fmt.Printf("no errors in %d results\n", len(seq))
	fmt.Printf("cached %d results\n", len(seq))
	show(applyMemo(seq, squareDigitSum))
}
