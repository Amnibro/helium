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
	xs := []int{25, 20, 15, 4, 2}
	sum := 0
	for _, x := range xs {
		sum += x
	}
	avg := sum / len(xs)
	var kept []int
	for _, x := range xs {
		if x < avg {
			break
		}
		for x > 0 && x < 40 {
			x *= 2
		}
		kept = append(kept, x)
	}
	show(kept)
}
