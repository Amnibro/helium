// json: generate a JSON array of n records, then parse it with a generic recursive-descent
// parser. Prints the sum of all numbers, total string bytes, trues, objects and arrays.
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

var D []byte
var P int
var nums, strs, trues, objs, arrs int64

func ws() { for P < len(D) && (D[P] == ' ' || D[P] == '\n' || D[P] == '\t' || D[P] == '\r') { P++ } }
func str() { P++; s := P; for D[P] != '"' { if D[P] == '\\' { P++ }; P++ }; strs += int64(P - s); P++ }
func value() {
	ws()
	c := D[P]
	if c == '{' {
		objs++; P++; ws()
		if D[P] == '}' { P++; return }
		for { ws(); str(); ws(); P++; value(); ws(); if D[P] == ',' { P++; continue }; P++; return }
	} else if c == '[' {
		arrs++; P++; ws()
		if D[P] == ']' { P++; return }
		for { value(); ws(); if D[P] == ',' { P++; continue }; P++; return }
	} else if c == '"' { str()
	} else if c == 't' { trues++; P += 4
	} else if c == 'f' { P += 5
	} else if c == 'n' { P += 4
	} else {
		neg := false; if D[P] == '-' { neg = true; P++ }
		v := int64(0); for P < len(D) && D[P] >= '0' && D[P] <= '9' { v = v*10 + int64(D[P]-'0'); P++ }
		if neg { nums -= v } else { nums += v }
	}
}

func main() {
	n := argN(1000)
	D = append(D, '[')
	for i := int64(0); i < n; i++ {
		if i > 0 { D = append(D, ",\n"...) }
		D = append(D, "{\"id\":"...); D = strconv.AppendInt(D, i, 10)
		D = append(D, ",\"name\":\"item"...); D = strconv.AppendInt(D, i, 10)
		D = append(D, "\",\"tags\":[\"t"...); D = strconv.AppendUint(D, uint64(rnd()%100), 10); D = append(D, "\",\"t"...); D = strconv.AppendUint(D, uint64(rnd()%100), 10)
		D = append(D, "\"],\"pos\":{\"x\":"...); D = strconv.AppendUint(D, uint64(rnd()%10000), 10); D = append(D, ",\"y\":"...); D = strconv.AppendInt(D, int64(rnd()%10000)-5000, 10)
		D = append(D, "},\"ok\":"...); if rnd()&1 != 0 { D = append(D, "true"...) } else { D = append(D, "false"...) }; D = append(D, '}')
	}
	D = append(D, ']')
	P = 0
	value()
	fmt.Println(len(D), nums, strs, trues, objs, arrs)
}
