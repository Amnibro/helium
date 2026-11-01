// mandelbrot: n x n grid over [-1.5,0.5]x[-1,1], 50 iterations, escape |z|^2 > 4.
// Prints the number of points inside and a hash of the row-packed bitmap.
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

func main() {
	n := argN(200)
	inside := int64(0); h := uint32(2166136261)
	for y := int64(0); y < n; y++ {
		ci := 2.0*float64(y)/float64(n) - 1.0
		bits := uint32(0); nb := 0
		for x := int64(0); x < n; x++ {
			cr := 2.0*float64(x)/float64(n) - 1.5
			zr, zi := 0.0, 0.0
			in := uint32(1)
			for i := 0; i < 50; i++ {
				tr := zr*zr - zi*zi + cr
				ti := 2.0*zr*zi + ci
				zr, zi = tr, ti
				if zr*zr+zi*zi > 4.0 { in = 0; break }
			}
			bits = (bits << 1) | in; nb++
			inside += int64(in)
			if nb == 8 { h = (h ^ bits) * 16777619; bits = 0; nb = 0 }
		}
		if nb > 0 { h = (h ^ (bits << (8 - nb))) * 16777619 }
	}
	fmt.Println(inside, h)
}
