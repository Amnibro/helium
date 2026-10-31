package main

import (
	"fmt"
	"slices"
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
	var xs []int
	for _, x := range []int{8, 3, 12, 1, 9, 4} {
		if x > 5 {
			xs = append(xs, x)
		}
	}
	slices.Sort(xs)
	show(xs)
}
