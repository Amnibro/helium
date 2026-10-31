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

func parseNumbers(text string) []int {
	var nums []int
	for _, w := range strings.Fields(text) {
		if n, err := strconv.Atoi(w); err == nil {
			nums = append(nums, n)
		}
	}
	return nums
}

func main() {
	nums := parseNumbers("order 12 qty 7 price 30 tax 3")
	fmt.Printf("no errors in %d results\n", len(nums))
	show(nums)
}
