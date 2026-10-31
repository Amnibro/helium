package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	n := 200
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}
	count := 0
	for y := 0; y < n; y++ {
		ci := 2.0*float64(y)/float64(n) - 1.0
		for x := 0; x < n; x++ {
			cr := 2.0*float64(x)/float64(n) - 1.5
			var zr, zi, tr, ti float64
			i := 0
			for i < 50 && tr+ti <= 4.0 {
				zi = 2.0*zr*zi + ci
				zr = tr - ti + cr
				tr = zr * zr
				ti = zi * zi
				i++
			}
			if tr+ti <= 4.0 {
				count++
			}
		}
	}
	fmt.Println(count)
}
