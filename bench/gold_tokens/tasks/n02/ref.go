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

func topUnique(xs []int, k int) []int {
	seen := map[int]bool{}
	var unique []int
	for _, x := range xs {
		if !seen[x] {
			seen[x] = true
			unique = append(unique, x)
		}
	}
	slices.Sort(unique)
	slices.Reverse(unique)
	return unique[:min(k, len(unique))]
}

func main() {
	show(topUnique([]int{72, 95, 60, 88, 95, 41}, 3))
}
