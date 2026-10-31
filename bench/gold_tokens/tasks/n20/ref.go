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

func gapsWithin(xs []int, limit int) bool {
	for i := 1; i < len(xs); i++ {
		if d := xs[i] - xs[i-1]; d > limit || -d > limit {
			return false
		}
	}
	return true
}

func main() {
	xs := []int{12, 18, -3, 25, 140, 33}
	for i, x := range xs {
		xs[i] = min(max(x, 0), 100)
	}
	deltas := make([]int, len(xs)-1)
	for i := range deltas {
		deltas[i] = xs[i+1] - xs[i]
	}
	if gapsWithin(deltas, 50) {
		fmt.Printf("no errors in %d results\n", len(deltas))
	} else {
		fmt.Println("error: gap exceeds limit (1 total)")
	}
	show(deltas)
}
