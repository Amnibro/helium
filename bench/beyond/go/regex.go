// regex: backtracking matcher for literals . * + ? ^ $ (Pike style, leftmost, any match),
// run over n generated lines for six patterns. Prints the match count of each pattern.
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

var re, tx []byte

func one(c byte, t int) bool { return t < len(tx) && (c == '.' || c == tx[t]) }
func star(c byte, r, t int) bool { for { if here(r, t) { return true }; if !one(c, t) { return false }; t++ } }
func here(r, t int) bool {
	rl := len(re)
	if r == rl { return true }
	if r+1 < rl && re[r+1] == '*' { return star(re[r], r+2, t) }
	if r+1 < rl && re[r+1] == '+' { return one(re[r], t) && star(re[r], r+2, t+1) }
	if r+1 < rl && re[r+1] == '?' { if one(re[r], t) && here(r+2, t+1) { return true }; return here(r+2, t) }
	if re[r] == '$' && r+1 == rl { return t == len(tx) }
	if one(re[r], t) { return here(r+1, t+1) }
	return false
}
func match() bool {
	if len(re) > 0 && re[0] == '^' { return here(1, 0) }
	for t := 0; t <= len(tx); t++ { if here(0, t) { return true } }
	return false
}

func main() {
	n := int(argN(1000))
	pats := []string{"ab*c", "^a.*f$", "c.d.e", "fa+b?c", "e.*e.*e.*a", "dd*ee*ff*a$"}
	var buf []byte; var off []int
	for i := 0; i < n; i++ { off = append(off, len(buf)); k := 20 + int(rnd()%40); for j := 0; j < k; j++ { buf = append(buf, byte('a'+rnd()%6)) } }
	off = append(off, len(buf))
	var out []string
	for _, p := range pats {
		re = []byte(p); c := 0
		for i := 0; i < n; i++ { tx = buf[off[i]:off[i+1]]; if match() { c++ } }
		out = append(out, strconv.Itoa(c))
	}
	fmt.Println(strings.Join(out, " "))
}
