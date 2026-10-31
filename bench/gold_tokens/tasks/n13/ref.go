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

func main() {
	var lengths []int
	for _, w := range strings.Fields("parse the config file then retry") {
		lengths = append(lengths, len(w))
	}
	show(removeLastMax(lengths))
}
