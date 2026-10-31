package main

import (
	"fmt"
	"os"
	"strconv"
)

type Node struct{ l, r *Node }

func make_(d int) *Node {
	if d > 0 {
		return &Node{make_(d - 1), make_(d - 1)}
	}
	return &Node{}
}
func check(n *Node) int {
	if n.l == nil {
		return 1
	}
	return 1 + check(n.l) + check(n.r)
}
func main() {
	n := 10
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}
	mind := 4
	maxd := n
	if maxd < mind+2 {
		maxd = mind + 2
	}
	fmt.Printf("stretch tree of depth %d\t check: %d\n", maxd+1, check(make_(maxd+1)))
	long := make_(maxd)
	for d := mind; d <= maxd; d += 2 {
		it := 1 << (maxd - d + mind)
		chk := 0
		for i := 0; i < it; i++ {
			chk += check(make_(d))
		}
		fmt.Printf("%d\t trees of depth %d\t check: %d\n", it, d, chk)
	}
	fmt.Printf("long lived tree of depth %d\t check: %d\n", maxd, check(long))
}
