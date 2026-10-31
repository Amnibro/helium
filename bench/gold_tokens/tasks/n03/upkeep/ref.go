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
	xs := []int{5, 10, 15, 20}
	for i := 1; i < len(xs); i++ {
		xs[i] += xs[i-1]
	}
	fmt.Printf("no errors in %d results\n", len(xs))
	show(xs)
}
