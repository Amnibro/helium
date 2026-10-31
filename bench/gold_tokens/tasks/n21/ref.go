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

func collatz(n int) int {
	if n%2 == 0 {
		return n / 2
	}
	return 3*n + 1
}

func main() {
	seq := []int{27}
	for seq[len(seq)-1] <= 1000 {
		seq = append(seq, collatz(seq[len(seq)-1]))
	}
	var kept []int
	for _, x := range seq {
		if x >= -50 && x <= 50 {
			kept = append(kept, x)
		}
	}
	fmt.Printf("cached %d results\n", len(kept))
	show(kept)
}
