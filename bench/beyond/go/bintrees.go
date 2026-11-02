// bintrees: arena binary trees. Nodes are index pairs in one array; each tree is built
// bottom-up into the arena after the long-lived tree and released by resetting the top.
package main

import ("fmt"; "os"; "strconv")

func argN(d int64) int64 {
	if len(os.Args) > 1 {
		if v, err := strconv.ParseInt(os.Args[1], 10, 64); err == nil {
			return v
		}
	}
	return d
}

var L, R []int32
var top int32

func build(d int) int32 {
	i := top; top++
	if d > 0 { l := build(d - 1); r := build(d - 1); L[i] = l; R[i] = r } else { L[i] = -1; R[i] = -1 }
	return i
}

func check(i int32) int64 { if L[i] < 0 { return 1 }; return 1 + check(L[i]) + check(R[i]) }

func main() {
	maxd := int(argN(10))
	if maxd < 6 { maxd = 6 }
	cap := (2 << (maxd + 1)) + (2 << maxd)
	L = make([]int32, cap); R = make([]int32, cap)
	s := build(maxd + 1)
	fmt.Printf("stretch tree of depth %d\t check: %d\n", maxd+1, check(s))
	top = 0
	lived := build(maxd)
	mark := top
	for d := 4; d <= maxd; d += 2 {
		iters := int64(1) << (maxd - d + 4); c := int64(0)
		for k := int64(0); k < iters; k++ { top = mark; c += check(build(d)) }
		fmt.Printf("%d\t trees of depth %d\t check: %d\n", iters, d, c)
	}
	fmt.Printf("long lived tree of depth %d\t check: %d\n", maxd, check(lived))
}
