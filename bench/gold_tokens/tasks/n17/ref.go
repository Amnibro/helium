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
	text := strings.ToLower("retry loop")
	var counts []int
	for _, v := range "aeiou" {
		counts = append(counts, strings.Count(text, string(v)))
	}
	show(counts)
}
