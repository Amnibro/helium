#!/bin/bash
set -euo pipefail
d=$(cd "$(dirname "$0")" && pwd); b=${BUILD:-$d/../build}; mkdir -p "$b"
cc=${CC:-clang}; fl="-O2 -fwrapv -w -I$d"
stage() { HC_LIB=$d/lib "$1" "$d/hc.amni" "$2" || { echo "bootstrap: $1 failed on hc.amni" >&2; exit 1; }; }
if [ -f "$d/seed/hc.c" ]; then $cc $fl "$d/seed/hc.c" -o "$b/hc0" -lm; else ${STAGE0:-helium} build "$d/hc.amni" -o "$b/hc0"; fi
stage "$b/hc0" "$b/hc1.c"; $cc $fl "$b/hc1.c" -o "$b/hc1" -lm
stage "$b/hc1" "$b/hc2.c"; $cc $fl "$b/hc2.c" -o "$b/hc2" -lm
stage "$b/hc2" "$b/hc3.c"
cmp -s "$b/hc2.c" "$b/hc3.c" || { echo "bootstrap: stage2 and stage3 differ" >&2; exit 1; }
mv "$b/hc2" "$b/hc"; cp "$b/hc3.c" "$d/seed/hc.c"; rm -f "$b"/hc0 "$b"/hc1 "$b"/hc1.c "$b"/hc2.c "$b"/hc3.c
echo "bootstrap ok: $b/hc"
