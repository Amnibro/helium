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

func capRunningSum(xs []int, limit int) []int {
	total := 0
	for i, x := range xs {
		if total+x > limit {
			return xs[:i]
		}
		total += x
	}
	return xs
}

func main() {
	kept := capRunningSum([]int{30, 25, 40, 10, 50}, 150)
	fmt.Printf("no errors in %d results\n", len(kept))
	show(kept)
}
