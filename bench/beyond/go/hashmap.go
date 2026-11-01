// hashmap: n inserts of xorshift32 keys mod n/2 (value += i), then n lookups of keys mod n.
// Prints entry count, sum of found values and miss count. Uses the built-in map.
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
	n := argN(1000)
	m := map[uint32]int64{}
	half := uint32(n / 2)
	for i := int64(0); i < n; i++ { m[rnd()%half] += i }
	sum, miss := int64(0), int64(0)
	for i := int64(0); i < n; i++ { if v, ok := m[rnd()%uint32(n)]; ok { sum += v } else { miss++ } }
	fmt.Println(len(m), sum, miss)
}
