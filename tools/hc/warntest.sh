#!/bin/sh
# waste-checker tests: each hc/test/warn/x.he must check clean and print exactly the
# "line Wn" warnings listed in x.warn (an empty .warn means no warning may fire).
# Also runs the std construct tests (seq/tab/each_sum, radix sort, counter lowering)
# on the web backend; hetest covers them on c, native and debug.
HC=${1:?usage: warntest.sh <hc>}; R=$(cd "$(dirname "$0")/../.." && pwd); D=$R/hc/test/warn; L=${HC_LIB:-$R/hc/lib}; W=$(mktemp -d); p=0; f=0
for t in "$D"/*.he; do n=$(basename "$t" .he)
	o=$(HC_LIB=$L "$HC" check "$t" 2>&1); r=$?
	got=$(printf '%s\n' "$o" | sed -n 's/^[^:]*:\([0-9]*\): warning: \(W[0-9]\) .*/\1 \2/p')
	if [ $r -eq 0 ] && [ "$got" = "$(cat "$D/$n.warn")" ]; then p=$((p+1)); else f=$((f+1)); echo "FAIL $n: $(printf '%s' "$o" | head -c 300)"; fi
done
for n in minimal_constructs radix_sort counter_lower; do
	if HC_LIB=$L "$HC" "$R/hc/test/$n.he" "$W/x.wasm" --web >/dev/null 2>&1 && node "$R/hc/web/host.mjs" "$W/x.wasm" 2>&1 | cmp -s - "$R/hc/test/$n.out"; then p=$((p+1)); else f=$((f+1)); echo "FAIL $n (web)"; fi
done
rm -rf "$W"; echo "warntest: $p pass, $f fail"; [ $f = 0 ]
