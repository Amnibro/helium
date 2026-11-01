#!/bin/bash
set -u
R=$(cd "$(dirname "$0")/../.." && pwd); cd "$R"
B=${BUILD:-$R/build}; W=${CI_DIR:-$B/ci}; rm -rf "${W:?}"; mkdir -p "$W"
[ -x "$B/hcn" ] && [ -x "$B/hc" ] && [ -z "${REBUILD:-}" ] || BUILD="$B" hc/bootstrap.sh || exit 1
HN=${HC:-$B/hcn}; HC_=${HCC:-$B/hc}; fail=0
step() { local n=$1; shift; local o; o=$("$@" 2>&1); local r=$?; printf '%-9s %s\n' "$n" "$(printf '%s\n' "$o" | grep -v '^$' | if [[ $n =~ ^(native|c|web)$ ]]; then head -1; else tail -1; fi)"; [ $r -eq 0 ] || fail=1; }
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
[ $fail -eq 0 ] && echo "ci: ok" || echo "ci: FAILED"; exit $fail
