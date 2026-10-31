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
	seq := []int{14}
	for seq[len(seq)-1] != 1 {
		seq = append(seq, collatz(seq[len(seq)-1]))
	}
	peaks := []int{seq[0]}
	for _, x := range seq[1:] {
		if x > peaks[len(peaks)-1] {
			peaks = append(peaks, x)
		}
	}
	show(peaks)
}
