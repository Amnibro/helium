// spectral: power method on A(i,j) = 1/((i+j)(i+j+1)/2+i+1), 10 rounds of v = AtA u.
package main

import ("fmt"; "math"; "os"; "strconv")

func argN(d int64) int64 {
	if len(os.Args) > 1 {
		if v, err := strconv.ParseInt(os.Args[1], 10, 64); err == nil {
			return v
		}
	}
	return d
}

func a(i, j int) float64 { return 1.0 / float64((i+j)*(i+j+1)/2+i+1) }
func mulAv(v, out []float64) { n := len(v); for i := 0; i < n; i++ { s := 0.0; for j := 0; j < n; j++ { s += a(i, j) * v[j] }; out[i] = s } }
func mulAtv(v, out []float64) { n := len(v); for i := 0; i < n; i++ { s := 0.0; for j := 0; j < n; j++ { s += a(j, i) * v[j] }; out[i] = s } }
func mulAtAv(v, out, tmp []float64) { mulAv(v, tmp); mulAtv(tmp, out) }

func main() {
	n := int(argN(100))
	u := make([]float64, n); v := make([]float64, n); t := make([]float64, n)
	for i := range u { u[i] = 1 }
	for k := 0; k < 10; k++ { mulAtAv(u, v, t); mulAtAv(v, u, t) }
	vbv, vv := 0.0, 0.0
	for i := 0; i < n; i++ { vbv += u[i] * v[i]; vv += v[i] * v[i] }
	fmt.Printf("%.9f\n", math.Sqrt(vbv/vv))
}
