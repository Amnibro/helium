package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n := 1000
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}
	m := make(map[string]int)
	x := uint64(1)
	buf := make([]byte, 0, 32)
	for i := 0; i < n; i++ {
		x = (x*1103515245 + 12345) & 0x7fffffff
		buf = strconv.AppendUint(append(buf[:0], "key"...), x%200000, 10)
		m[string(buf)]++
	}
	maxc := 0
	for _, v := range m {
		if v > maxc {
			maxc = v
		}
	}
	sum := 0
	for j := 0; j < 1000; j++ {
		buf = strconv.AppendInt(append(buf[:0], "key"...), int64(j), 10)
		sum += m[string(buf)]
	}
	fmt.Println(len(m), maxc, sum)
}
