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
	xs := []int{10, 20, 30, 40, 5}
	last := xs[len(xs)-1]
	for i := range xs {
		xs[i] -= last
	}
	for i := 0; i < min(2, len(xs)/2); i++ {
		j := len(xs) - 1 - i
		xs[i], xs[j] = xs[j], xs[i]
	}
	show(xs)
}
