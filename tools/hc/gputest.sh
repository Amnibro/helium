#!/bin/bash
H=${1:?usage: gputest.sh hc}; R=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT; L=${HC_LIB:-$R/hc/lib}; ok=0
for k in "$R"/hc/test/gpu/*.amni; do
	n=$(basename "$k" .amni)
	HC_LIB=$L "$H" "$k" "$T/$n" --native && "$T/$n" > "$T/$n.cpu" || { echo "gputest: $n CPU build or run failed"; exit 1; }
	cmp -s "$T/$n.cpu" "${k%.amni}.out" || { echo "gputest: $n CPU output differs"; exit 1; }
	HC_LIB=$L "$H" --wgsl "$k" "$T/$n.js" || { echo "gputest: $n --wgsl failed"; exit 1; }
	[ -f "${k%.amni}.page.js" ] || continue
	cp "${k%.amni}.page.js" "$R/hc/web/hgpu.js" "$T/"; echo '<!doctype html><meta charset=utf-8><title>hgpu</title>' > "$T/index.html"
	node "$R/tools/hc/gpurun.mjs" "$T" "$n.page.js" > "$T/$n.gpu" || { echo "gputest: $n browser run failed"; exit 1; }
	node -e '
const fs=require("fs"),[g,c]=process.argv.slice(1,3).map(f=>fs.readFileSync(f,"utf8")),G=JSON.parse(g),C=c.trim().split("\n").map(l=>JSON.parse(l)),ks=Object.keys(G).filter(k=>Array.isArray(G[k]));
if(G.err||G.errs){console.log("gputest:",JSON.stringify(G.err||G.errs));process.exit(1);}
let bad=0;ks.forEach((k,i)=>{const a=C[i],b=G[k];if(!a||a.length!==b.length){bad++;console.log("gputest:",k,"length");return;}a.forEach((x,j)=>{if(Math.abs(x-b[j])>1e-5*Math.max(1,Math.abs(x)))bad++;});});
console.log("gputest:",process.argv[3],G.adapter.trim(),ks.length,"arrays",bad?bad+" mismatches":"match");process.exit(bad?1:0);' "$T/$n.gpu" "$T/$n.cpu" "$n" || exit 1
	ok=$((ok + 1))
done
echo "gputest ok ($ok kernel files on WebGPU)"
