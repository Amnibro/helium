#!/bin/bash
# gfxtest.sh hc: builds hc/test/gfx/gfx_smoke.amni against hc/lib/gfx and checks
# its CPU output against gfx_smoke.out, then runs the headless GPU checks
# (white furnace, sphere grid vs hc/test/gfx/golden/spheres.png, full frame, timing).
# Needs libSDL3 and a Vulkan device; ci.sh only runs it when HELIUM_GFX_TEST=1.
# GPU_LOCK=<file> serializes the GPU run on a shared machine (flock -w 300).
# GFX_OUT=<dir> keeps the rendered PNGs (default: a temp dir that is removed).
H=${1:?usage: gfxtest.sh hc}; R=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
O=${GFX_OUT:-$T}; mkdir -p "$O"; G="$R/hc/test/gfx/golden/spheres.png"; [ -f "$G" ] || G=""
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" build "$R/hc/test/gfx/gfx_smoke.amni" -o "$T/gs" > "$T/build.txt" 2>&1 || { echo "gfxtest: build failed"; grep -av "W[0-9]" "$T/build.txt" | tail -n 5; exit 1; }
L=(); [ -n "${GPU_LOCK:-}" ] && L=(flock -w 300 "$GPU_LOCK")
"${L[@]}" "$T/gs" "$O" $G > "$T/all.txt" 2> "$T/err.txt" || { echo "gfxtest: run failed"; tail -n 5 "$T/all.txt" "$T/err.txt"; exit 1; }
grep -av "^gpu:" "$T/all.txt" > "$T/cpu.txt"
cmp -s "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out" || { echo "gfxtest: CPU output differs"; diff "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out"; exit 1; }
grep -a "^gpu:" "$T/all.txt"; g=$(grep -a "^gpu: \(ok\|skipped\|FAILED\)" "$T/all.txt")
case "$g" in
	"gpu: ok"*) echo "gfxtest: ok";;
	"gpu: skipped"*) echo "gfxtest: ok (CPU only)";;
	*) echo "gfxtest: GPU checks failed"; exit 1;;
esac
