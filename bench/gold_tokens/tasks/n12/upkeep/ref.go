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
	for _, x := range []int{40, 15, 70, 25, 90} {
		if x >= -30 && x <= 30 {
			kept = append(kept, x)
		}
	}
	fmt.Printf("cached %d results\n", len(kept))
	show(kept)
}
