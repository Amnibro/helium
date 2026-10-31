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

func parseNumbers(text string) []int {
	var nums []int
	for _, w := range strings.Fields(text) {
		if n, err := strconv.Atoi(w); err == nil {
			nums = append(nums, n)
		}
	}
	return nums
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
	show(topUnique(parseNumbers("code 500 retry 3 code 200 code 500 retry 1"), 2))
}
