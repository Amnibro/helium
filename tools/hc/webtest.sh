#!/bin/bash
H=${1:?hc}; d=$(cd "$(dirname "$0")/../.." && pwd); t=$(mktemp -d); p=0; f=0
for s in "$d"/hc/test/web/*.he; do n=$(basename "$s" .he); if HC_LIB="$d/hc/lib" "$H" "$s" "$t/$n.wasm" --web > "$t/e" 2>&1 && node "$d/tools/hc/webtest.mjs" "$t/$n.wasm" > "$t/o" 2>&1 && cmp -s "$t/o" "$d/hc/test/web/$n.out"; then p=$((p+1)); else f=$((f+1)); echo "FAIL $n"; head -5 "$t/e" "$t/o"; fi; done
rm -rf "${t:?}"; echo "webtest: $p pass, $f fail"; [ $f -eq 0 ]
