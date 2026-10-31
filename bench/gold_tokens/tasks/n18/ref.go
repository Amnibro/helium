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
	var lengths []int
	for _, w := range strings.Fields("a bb ccc dddd") {
		if len(w) >= 2 {
			lengths = append(lengths, len(w))
		}
	}
	show(lengths)
}
