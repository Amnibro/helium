// matmul: n x n f64 matrix product, i-k-j loop order. Prints the sum and one element.
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
	n := int(argN(100))
	a := make([]float64, n*n); b := make([]float64, n*n); c := make([]float64, n*n)
	for i := 0; i < n; i++ { for j := 0; j < n; j++ {
		a[i*n+j] = float64((i*31+j*17)%100) / 100.0
		b[i*n+j] = float64((i*13+j*29)%100)/50.0 - 1.0
	} }
	for i := 0; i < n; i++ { for k := 0; k < n; k++ {
		aik := a[i*n+k]
		for j := 0; j < n; j++ { c[i*n+j] += aik * b[k*n+j] }
	} }
	s := 0.0; for _, v := range c { s += v }
	fmt.Printf("%.6f %.9f\n", s, c[(n/2)*n+n/3])
}
