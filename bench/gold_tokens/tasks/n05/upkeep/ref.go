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
	xs := []int{1, 2, 3, 4, 5, 6, 7}
	var sums []int
	for i := 0; i < len(xs); i += 4 {
		s := 0
		for _, x := range xs[i:min(i+4, len(xs))] {
			s += x
		}
		sums = append(sums, s)
	}
	show(sums)
}
