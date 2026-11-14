#!/bin/bash
H=${1:?hc}; d=$(cd "$(dirname "$0")/../.." && pwd); t=$(mktemp -d); p=0; f=0
for s in "$d"/hc/test/web/*.he; do n=$(basename "$s" .he); if HC_LIB="$d/hc/lib" "$H" "$s" "$t/$n.wasm" --web > "$t/e" 2>&1 && node "$d/tools/hc/webtest.mjs" "$t/$n.wasm" > "$t/o" 2>&1 && cmp -s "$t/o" "$d/hc/test/web/$n.out"; then p=$((p+1)); else f=$((f+1)); echo "FAIL $n"; head -5 "$t/e" "$t/o"; fi; done
HC_LIB="$d/hc/lib" "$H" "$d/test/thread_pingpong.amni" "$t/tp.wasm" --web > "$t/e" 2>&1 || f=$((f+1)); b=$(seq 1 140 | xargs -P 14 -I{} sh -c "node '$d/hc/web/host.mjs' '$t/tp.wasm' 2>&1 | head -1" | grep -vc '^377 -103493937 0 false$'); [ "$b" = 0 ] && p=$((p+1)) || { f=$((f+1)); echo "thread_pingpong: $b of 140 runs failed"; }
rm -rf "${t:?}"; echo "webtest: $p pass, $f fail"; [ $f -eq 0 ]
