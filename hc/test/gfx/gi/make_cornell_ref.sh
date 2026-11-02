#!/bin/bash
# make_cornell_ref.sh <hc> <out.txt> [spp] [jobs]: builds cornell_pt.amni, runs `jobs`
# worker processes (rows j % jobs == worker), merges them by pixel index and writes
# "<index> r g b relSE" per pixel (%.6g, linear radiance; relSE = standard error of the
# pixel's luminance over its mean, 0 where the mean is 0). The image does not depend on
# `jobs` (the generator is keyed per pixel and sample). Prints the noise summary and the
# sha256 of the output; hc/test/gfx/gi/cornell_ref.sha256 holds the committed hash.
set -e
H=${1:?usage: make_cornell_ref.sh hc out.txt [spp] [jobs]}; OUT=${2:?out}; SPP=${3:-65536}; J=${4:-30}
R=$(cd "$(dirname "$0")/../../../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" build "$R/hc/test/gfx/gi/cornell_pt.amni" -o "$T/pt" > "$T/build.txt" 2>&1 || { grep -av "W[0-9]" "$T/build.txt" | tail -n 5; exit 1; }
for ((k = 0; k < J; k++)); do "$T/pt" $k $J $SPP > "$T/part$k.txt" & done; wait
cat "$T"/part*.txt | sort -n -k1,1 | awk '{n=$5; m=$6/n; v=$7/n-m*m; if (v<0) v=0; se=(m>0)?sqrt(v/n)/m:0; printf "%d %.6g %.6g %.6g %.6g\n", $1, $2, $3, $4, se}' > "$OUT"
[ "$(wc -l < "$OUT")" = 16384 ] || { echo "make_cornell_ref: expected 16384 pixels"; exit 1; }
awk -v spp=$SPP '$5>0{c++; s+=$5; a[c]=$5} END{n=asort(a); printf "cornell_ref: spp %d, %d lit pixels, luminance rel. standard error mean %.4f%%, median %.4f%%, p99 %.4f%%, max %.4f%%\n", spp, c, 100*s/c, 100*a[int(n*0.5)], 100*a[int(n*0.99)], 100*a[n]}' "$OUT"
echo "cornell_ref: sha256 $(sha256sum "$OUT" | cut -d' ' -f1)"
