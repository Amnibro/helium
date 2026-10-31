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
	var kept []int
	for _, x := range []int{3, 18, 7, 25, 12} {
		if x >= 5 && x <= 20 {
			kept = append(kept, x)
		}
	}
	show(kept)
}
