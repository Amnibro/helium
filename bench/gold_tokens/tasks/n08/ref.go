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
	var sums []int
	total := 0
	for _, x := range []int{3, 8, 12, 5, 6} {
		if x%2 == 0 {
			total += x
			sums = append(sums, total)
		}
	}
	show(sums)
}
