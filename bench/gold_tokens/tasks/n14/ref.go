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
	xs := []int{4, 9}
	if len(xs) < 3 {
		fmt.Println("error: list shorter than minimum (1 total)")
	} else {
		fmt.Printf("no errors in %d results\n", len(xs))
	}
	show(xs)
}
