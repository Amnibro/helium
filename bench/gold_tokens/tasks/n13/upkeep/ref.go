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
	for _, w := range strings.Fields("parse the config file then retry") {
		lengths = append(lengths, len(w))
	}
	for i := 1; i < len(lengths); i++ {
		lengths[i] += lengths[i-1]
	}
	show(lengths)
}
