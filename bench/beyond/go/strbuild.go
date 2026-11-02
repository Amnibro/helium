// strbuild: write n numbers (xorshift32 % 1000000) comma separated into one string,
// then split it on commas and parse every field back. Prints length, count and sum.
package main

import ("fmt"; "os"; "strconv"; "strings")

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
	var b []byte
	for i := int64(0); i < n; i++ { if i > 0 { b = append(b, ',') }; b = strconv.AppendUint(b, uint64(rnd()%1000000), 10) }
	s := string(b)
	count, sum := int64(0), int64(0)
	for _, f := range strings.Split(s, ",") { v, _ := strconv.ParseInt(f, 10, 64); sum += v; count++ }
	fmt.Println(len(s), count, sum)
}
