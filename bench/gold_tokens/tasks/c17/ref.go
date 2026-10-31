package main

import (
	"fmt"
	"slices"
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

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	for d := 2; d*d <= n; d++ {
		if n%d == 0 {
			return false
		}
	}
	return true
}

func main() {
	text := "AbCdEfGh"
	var codes []int
	for _, c := range text[len(text)/2:] {
		n := int(c)
		if isPrime(n) {
			n++
			for !isPrime(n) {
				n++
			}
		}
		codes = append(codes, n)
	}
	slices.Sort(codes)
	var kept []int
	for _, c := range codes {
		if c >= 65 {
			kept = append(kept, c)
		}
	}
	show(kept)
}
