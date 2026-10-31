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

func main() {
	xs := []int{-5, 12, 48, 103, 7}
	for i, x := range xs {
		xs[i] = min(max(x, 0), 50)
	}
	fmt.Printf("no errors in %d results\n", len(xs))
	show(xs)
}
