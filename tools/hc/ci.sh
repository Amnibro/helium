#!/bin/bash
set -u
R=$(cd "$(dirname "$0")/../.." && pwd); cd "$R"
B=${BUILD:-$R/build}; W=${CI_DIR:-$B/ci}; rm -rf "${W:?}"; mkdir -p "$W"
[ -x "$B/hcn" ] && [ -x "$B/hc" ] && [ -z "${REBUILD:-}" ] || BUILD="$B" hc/bootstrap.sh || exit 1
HN=${HC:-$B/hcn}; HC_=${HCC:-$B/hc}; fail=0
step() { local n=$1; shift; local o; o=$("$@" 2>&1); local r=$?; printf '%-9s %s\n' "$n" "$(printf '%s\n' "$o" | grep -v '^$' | if [[ $n =~ ^(native|c|web)$ ]]; then head -1; else tail -1; fi)"; [ $r -eq 0 ] || { fail=1; printf '%s\n' "$o" | grep -v '^$' | tail -n 15 | sed 's/^/    /'; }; }
base() { local l=$1 r=$2 f=$3; grep -P "^(pass|gpu)\t" "$r" | cut -f2 | sort > "$W/$l.pass"; [ -f "$f" ] && { local lost; lost=$(comm -23 "$f" "$W/$l.pass"); [ -z "$lost" ] || { echo "$l lost: $lost"; fail=1; }; }; }
step native env HC_NATIVE=1 nice -n 19 timeout 2400 python3 tools/hc/difftest.py . "$HN" "$W/native"; base native "$W/native/report.txt" tools/hc/baseline/native.txt
step c nice -n 19 timeout 2400 python3 tools/hc/difftest.py . "$HC_" "$W/c"; base c "$W/c/report.txt" tools/hc/baseline/c.txt
step web env HCW="$HN" HC_NATIVE=1 nice -n 19 timeout 2400 python3 tools/hc/difftest.py . tools/hc/hcweb.sh "$W/web"; base web "$W/web/report.txt" tools/hc/baseline/web.txt
step vecfuzz python3 tools/hc/vecfuzz.py "$HN" 600 1
step vecweb env VFWEB=1 python3 tools/hc/vecfuzz.py "$HN" 140 7001
step he tools/hc/hetest.sh "$HN"
step lsp timeout 300 python3 tools/hc/lsptest.py "$HN"
step webhost tools/hc/webtest.sh "$HN"
step pkg python3 tools/hc/pkgtest.py "$HN"
step lut tools/hc/luttest.sh "$HN"
step err python3 tools/hc/errtest.py "$HN"
step warn tools/hc/warntest.sh "$HN"
step nav sh -c 'HC_LIB=hc/lib "$0" build hc/test/nav/nav_test.amni -o "$1/nt" 2>/dev/null && "$1/nt"' "$HN" "$W"
step net sh -c 'HC_LIB=hc/lib "$0" build hc/test/net/net_test.amni -o "$1/net" 2>/dev/null && "$1/net"' "$HN" "$W"
step stream sh -c 'HC_LIB=hc/lib "$0" build hc/test/stream/stream_test.amni -o "$1/st" 2>/dev/null && STREAM_DIR="$1/stream" "$1/st"' "$HN" "$W"
step audio3d sh -c 'HC_LIB=hc/lib "$0" build hc/test/audio3d/audio3d_test.amni -o "$1/a3" 2>/dev/null && "$1/a3"' "$HN" "$W"
step hud sh -c 'gunzip -c hc/test/hud/trees.txt.gz > "$1/trees.txt" && HC_LIB=hc/lib "$0" build hc/test/hud/hud_test.amni -o "$1/hud" 2>/dev/null && HUD_TREES="$1/trees.txt" "$1/hud"' "$HN" "$W"
step edit sh -c 'HC_LIB=hc/lib "$0" build hc/test/edit/edit_test.amni -o "$1/edit" 2>/dev/null && "$1/edit" && HC_LIB=hc/lib "$0" build hc/apps/editor/editor.amni -o "$1/editor" 2>/dev/null' "$HN" "$W"
step touch sh -c 'HC_LIB=hc/lib "$0" build hc/test/mobile/touch_test.amni -o "$1/touch" 2>/dev/null && "$1/touch"' "$HN" "$W"
step scal sh -c 'HC_LIB=hc/lib "$0" build hc/test/mobile/scal_test.amni -o "$1/scal" 2>/dev/null && "$1/scal" && HC_LIB=hc/lib "$0" build hc/apps/mobile/mobile.amni -o "$1/mobile" 2>/dev/null' "$HN" "$W"
step import_up sh -c 'HC_LIB=hc/lib "$0" build hc/test/import_up/app/main.amni -o "$1/iu" 2>/dev/null && "$1/iu" | grep -q "parent directory" && ! HC_LIB=hc/lib "$0" build hc/test/import_up/bad.amni -o "$1/iub" 2>&1 | grep -q "runtime error" && ! HC_LIB=hc/lib "$0" build hc/test/import_up/kw.amni -o "$1/iub" 2>&1 | grep -q "runtime error"' "$HN" "$W"
step adl sh -c 'cd hc/test/adl && HC_LIB=../../lib "$0" build main.amni -o "$1/adl" 2>/dev/null && "$1/adl" | cmp -s - main.out && HC_LIB=../../lib "$2" build main.amni -o "$1/adl.c" 2>/dev/null && cc -w -I../.. -o "$1/adlc" "$1/adl.c" -lm && "$1/adlc" | cmp -s - main.out && echo ok' "$HN" "$W" "$HC_"
step libm sh -c 'HC_LIB=hc/lib "$0" build test/libm/drive_libm.amni -o "$1/libm" 2>/dev/null && "$1/libm" < test/libm/cases.txt | grep -q "| libm 12000/12000" && echo ok' "$HN" "$W"
step net_sock sh -c 'for t in net_tcp net_udp net_poll; do HC_LIB=hc/lib "$0" build hc/test/net_sock/$t.he -o "$1/$t" 2>/dev/null && "$1/$t" | cmp -s - hc/test/net_sock/$t.out || exit 1; done' "$HN" "$W"
step net_quic sh -c 'for t in cert tls wire conn link udp speed; do HC_LIB=hc/lib "$0" build hc/test/net_quic/$t.he -o "$1/$t" 2>/dev/null && "$1/$t" "$1/$t.d" | cmp -s - hc/test/net_quic/$t.out || exit 1; done' "$HN" "$W"
step gf sh -c 'for v in HC_VK HC_NOVK HC_NOA64; do for t in gf/gf_dot hex_vk words_vk ord_vk; do env "$v=1" HC_LIB=hc/lib "$0" build hc/test/$t.he -o "$1/gf" 2>/dev/null && "$1/gf" $v | cmp -s - hc/test/$t.out || exit 1; done; done' "$HN" "$W"
[ -n "${HELIUM_QUIC_INTEROP:-}" ] && step quic_interop sh -c 'HC_LIB=hc/lib "$0" build hc/test/net_quic/interop.he -o "$1/interop" 2>/dev/null && "$1/interop" "$1/interop.d" | cmp -s - hc/test/net_quic/interop.out' "$HN" "$W"
[ -n "${HELIUM_GFX_TEST:-}" ] && step gfx env GFX_OUT="${GFX_OUT:-$W/gfx}" tools/hc/gfxtest.sh "$HN"
[ -n "${HELIUM_WGSL_TEST:-}" ] && step wgsl node tools/hc/wgsltest.mjs "$HN"
[ -n "${HELIUM_WEBGPU_TEST:-}" ] && step webgpu sh -c '${GPU_LOCK:+flock "$GPU_LOCK"} node tools/hc/webgputest.mjs "$0"' "$HN"
[ $fail -eq 0 ] && echo "ci: ok" || echo "ci: FAILED"; exit $fail
