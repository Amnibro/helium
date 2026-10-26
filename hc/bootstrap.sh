#!/bin/bash
set -e
d=$(cd "$(dirname "$0")" && pwd); b=${BUILD:-$d/../build}; mkdir -p "$b"
cc=${CC:-clang}; fl="-O2 -fwrapv -w -I$d"
if [ ! -x "$b/hc" ]; then
	if [ -f "$d/seed/hc.c" ]; then $cc $fl "$d/seed/hc.c" -o "$b/hc0" -lm
	else ${STAGE0:-helium} build "$d/hc.amni" -o "$b/hc0"; fi
else cp "$b/hc" "$b/hc0"; fi
cd "$d/.."
HC_LIB=$d/lib "$b/hc0" hc/hc.amni "$b/hc1.c" && $cc $fl "$b/hc1.c" -o "$b/hc1" -lm
HC_LIB=$d/lib "$b/hc1" hc/hc.amni "$b/hc2.c" && $cc $fl "$b/hc2.c" -o "$b/hc2" -lm
HC_LIB=$d/lib "$b/hc2" hc/hc.amni "$b/hc3.c"
cmp "$b/hc2.c" "$b/hc3.c" && mv "$b/hc2" "$b/hc" && mkdir -p "$d/seed" && cp "$b/hc3.c" "$d/seed/hc.c" && rm -f "$b"/hc0 "$b"/hc1 "$b"/hc1.c "$b"/hc2.c "$b"/hc3.c && echo "bootstrap ok: $b/hc"
