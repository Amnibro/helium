#!/usr/bin/env bash
set -uo pipefail
D="$(cd "$(dirname "$0")" && pwd)" R="$(cd "$(dirname "$0")/../.." && pwd)" W=$(mktemp -d); trap 'rm -rf "$W"' EXIT; fail=0
for p in kern outline raster; do HC_LIB="$R/hc/lib" "$R/build/hc" build "$D/$p.amni" -o "$W/$p" || exit 1; done
INTER=/usr/share/fonts/inter/Inter.ttc; [ -f "$INTER" ] && python3 -c "from fontTools.ttLib import TTCollection; TTCollection('$INTER').fonts[0].save('$W/Inter.ttf')"
KERN="${KERN_FONTS:-$W/Inter.ttf /usr/share/fonts/noto/NotoSans-Regular.ttf /usr/share/fonts/TTF/trebuc.ttf}"
CFF="${CFF_FONTS:-/usr/share/fonts/OTF/Archivo-Regular.otf:0:1 /usr/share/fonts/adobe-source-serif/SourceSerif4Display-LightIt.otf:0:1 /usr/share/fonts/noto-cjk/NotoSansCJK-Regular.ttc:0:7}"
for f in $KERN; do [ -f "$f" ] || { echo "skip $f"; continue; }; python3 "$D/kern.py" "$f" | sort >"$W/a"; "$W/kern" "$f" | sort >"$W/b"; n=$(diff "$W/a" "$W/b" | grep -c '^[<>]'); echo "kern    $(basename "$f"): $(wc -l <"$W/b") pairs, $n differ from HarfBuzz"; [ "$n" = 0 ] || fail=1; done
for e in $CFF; do f=${e%%:*} r=${e#*:}; i=${r%%:*} s=${r#*:}; [ -f "$f" ] || { echo "skip $f"; continue; }; python3 "$D/outline.py" "$f" "$i" "$s" >"$W/a"; "$W/outline" "$f" "$i" "$s" >"$W/b"; n=$(diff "$W/a" "$W/b" | grep -c '^[<>]'); echo "outline $(basename "$f")#$i: $(grep -c ^G "$W/b") glyphs, $n lines differ from fontTools"; [ "$n" = 0 ] || fail=1; done
for f in ${RASTER_FONTS:-/usr/share/fonts/OTF/Archivo-Regular.otf $W/Inter.ttf}; do [ -f "$f" ] || continue; "$W/raster" "$f" >"$W/b"; python3 "$D/raster.py" "$f" >"$W/a"; python3 - "$W/a" "$W/b" "$(basename "$f")" <<'PY' || fail=1
import sys
p={int(l.split()[0]):int(l.split()[1]) for l in open(sys.argv[1])}; h={int(l.split()[0]):int(l.split()[3]) for l in open(sys.argv[2])}
r=[abs(h[c]-p[c])/max(p[c],1) for c in p]; m=sum(r)/len(r); print('raster  %s: ink vs FreeType mean %.2f%%, worst %.2f%%'%(sys.argv[3],100*m,100*max(r))); sys.exit(0 if m<0.02 and all((h[c]==0)==(p[c]==0) for c in p) else 1)
PY
done
[ $fail = 0 ] && echo "fonts: ok" || { echo "fonts: FAILED"; exit 1; }
