// fannkuch: pancake flips over all permutations (permutation index order), checksum and max flips.
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
	n := int(argN(7))
	var perm, perm1, count [16]int
	for i := 0; i < n; i++ { perm1[i] = i }
	r, maxf, pc, checksum := n, 0, 0, 0
	for {
		for r != 1 { count[r-1] = r; r-- }
		for i := 0; i < n; i++ { perm[i] = perm1[i] }
		flips, k := 0, perm[0]
		for k != 0 {
			i, j := 0, k
			for i < j { perm[i], perm[j] = perm[j], perm[i]; i++; j-- }
			flips++
			k = perm[0]
		}
		if flips > maxf { maxf = flips }
		if pc%2 == 0 { checksum += flips } else { checksum -= flips }
		for {
			if r == n { fmt.Printf("%d\nPfannkuchen(%d) = %d\n", checksum, n, maxf); return }
			p0 := perm1[0]
			for i := 0; i < r; i++ { perm1[i] = perm1[i+1] }
			perm1[r] = p0
			count[r]--
			if count[r] > 0 { break }
			r++
		}
		pc++
	}
}
