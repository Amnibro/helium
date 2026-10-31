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
	deltas := make([]int, len(xs)-1)
	for i := range deltas {
		deltas[i] = xs[i+1] - xs[i]
	}
	show(deltas)
}
