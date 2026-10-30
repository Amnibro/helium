#!/bin/sh
HC=${1:?usage: hetest.sh <hc> [test-dir]}; D=${2:-$(dirname "$0")/../../hc/test}; L=${HC_LIB:-$(dirname "$0")/../../hc/lib}; W=$(mktemp -d); p=0; f=0
for t in "$D"/*.he; do n=$(basename "$t" .he); for m in c native debug; do rm -f "$W/x" "$W/x.c"; case $m in c) HC_LIB=$L "$HC" "$t" "$W/x.c" 2>"$W/e" && ${CC:-clang} -O1 -fwrapv -w -I"$L/.." "$W/x.c" -o "$W/x" -lm 2>>"$W/e";; native) HC_LIB=$L "$HC" "$t" "$W/x" --native 2>"$W/e";; debug) HC_LIB=$L "$HC" "$t" "$W/x" --native --debug 2>"$W/e";; esac; if [ -x "$W/x" ] && "$W/x" 2>&1 | cmp -s - "$D/$n.out"; then p=$((p+1)); else f=$((f+1)); echo "FAIL $n ($m): $(head -c 300 "$W/e")"; fi; done; done
rm -rf "$W"; echo "hetest: $p pass, $f fail"; [ $f = 0 ]
