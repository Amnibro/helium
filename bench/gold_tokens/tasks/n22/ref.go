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

func removeLastMax(xs []int) []int {
	i := len(xs) - 1
	for j := len(xs) - 1; j >= 0; j-- {
		if xs[j] > xs[i] {
			i = j
		}
	}
	return append(xs[:i], xs[i+1:]...)
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
	xs := capRunningSum(removeLastMax([]int{20, 35, 15, 40, 10}), 60)
	for i := 1; i < len(xs); i++ {
		xs[i] += xs[i-1]
	}
	show(xs)
}
