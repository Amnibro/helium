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
	xs := []int{10, 14, 19, 31, 33}
	if gapsWithin(xs, 10) {
		fmt.Printf("no errors in %d results\n", len(xs))
	} else {
		fmt.Println("error: gap exceeds limit (1 total)")
	}
	show(xs)
}
