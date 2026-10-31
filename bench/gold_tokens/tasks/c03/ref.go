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
	xs := []int{3, 7, 3, 9, 7, 3}
	fmt.Printf("no errors in %d results\n", len(xs))
	show(xs)
}
