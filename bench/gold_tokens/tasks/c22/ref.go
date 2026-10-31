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
	text := "Helium"
	var codes []int
	for i := 0; i < len(text); i += 2 {
		codes = append(codes, int(text[i]))
	}
	show(codes)
}
