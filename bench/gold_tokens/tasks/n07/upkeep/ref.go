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
	xs := []int{21, 23, 22, 30, 29, 18}
	var deltas []int
	for i := 1; i < len(xs); i++ {
		if d := xs[i] - xs[i-1]; d > 0 {
			deltas = append(deltas, d)
		}
	}
	show(deltas)
}
