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

func applyMemo(xs []int, f func(int) int) []int {
	memo := map[int]int{}
	hits := 0
	out := make([]int, len(xs))
	for i, x := range xs {
		if v, ok := memo[x]; ok {
			hits++
			out[i] = v
		} else {
			memo[x] = f(x)
			out[i] = memo[x]
		}
	}
	fmt.Printf("subfunction ran on %d results, %d memo hits\n", len(out), hits)
	return out
}

func digitRecords(n int) int {
	if n < 0 {
		n = -n
	}
	count, best := 0, -1
	for _, c := range strconv.Itoa(n) {
		if d := int(c - '0'); d > best {
			best = d
			count++
		}
	}
	return count
}

func main() {
	out := applyMemo([]int{142, 365, 876}, digitRecords)
	value, i := len(out), len(out)
	for i > 0 && out[i-1] > value {
		i--
	}
	show(slices.Insert(out, i, value))
}
