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

func digitSum(n int) int {
	if n < 0 {
		n = -n
	}
	s := 0
	for ; n > 0; n /= 10 {
		s += n % 10
	}
	return s
}

func main() {
	xs := []int{19, 28, 37, 8, 40}
	for i := 0; i < len(xs) && xs[i] >= 10; i++ {
		xs[i] = digitSum(xs[i])
	}
	show(xs)
}
