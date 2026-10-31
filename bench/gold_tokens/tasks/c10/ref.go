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
	xs := []int{10, 25, 18, 40, 32}
	gaps := make([]int, len(xs)-1)
	for i := range gaps {
		gaps[i] = xs[i+1] - xs[i]
	}
	ranks := make([]int, len(gaps))
	for i, x := range gaps {
		ranks[i] = 1
		for _, g := range gaps {
			if g < x {
				ranks[i]++
			}
		}
	}
	show(ranks)
}
