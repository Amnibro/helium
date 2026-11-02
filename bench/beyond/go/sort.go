// sort: bottom-up merge sort of n xorshift32 values. Prints a position-weighted checksum
// modulo 1e9+7 and whether the result is ordered.
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

var rs uint32 = 2463534242

func rnd() uint32 { rs ^= rs << 13; rs ^= rs >> 17; rs ^= rs << 5; return rs }

func main() {
	n := int(argN(1000))
	src := make([]uint32, n); dst := make([]uint32, n)
	for i := range src { src[i] = rnd() }
	for w := 1; w < n; w *= 2 {
		for lo := 0; lo < n; lo += 2 * w {
			mid := min(lo+w, n); hi := min(lo+2*w, n)
			i, j, k := lo, mid, lo
			for i < mid && j < hi { if src[i] <= src[j] { dst[k] = src[i]; i++ } else { dst[k] = src[j]; j++ }; k++ }
			for i < mid { dst[k] = src[i]; i++; k++ }
			for j < hi { dst[k] = src[j]; j++; k++ }
		}
		src, dst = dst, src
	}
	h, ok := int64(0), 1
	for i := 0; i < n; i++ { h = (h + int64(src[i])*int64(i%1000+1)) % 1000000007; if i > 0 && src[i-1] > src[i] { ok = 0 } }
	fmt.Println(h, ok)
}
