#!/bin/bash
# gfxtest.sh hc: builds hc/test/gfx/gfx_smoke.amni against hc/lib/gfx and checks
# its CPU output against gfx_smoke.out, then runs the headless GPU checks
# (sun-sweep furnace, sphere grid vs hc/test/gfx/golden/spheres.png, full frame, timing).
# Needs libSDL3 and a Vulkan device; ci.sh only runs it when HELIUM_GFX_TEST=1.
# The golden is required: a missing golden or PSNR <= 40 dB fails.
# GPU_LOCK=<file> serializes the GPU run on a shared machine (blocking flock).
# GFX_OUT=<dir> keeps the rendered PNGs and the raw output (default: a temp dir).
# GFX_MAKE_GOLDEN=1 renders and writes golden/spheres.png instead (then exits 1 so a
#   new golden is never taken silently; review and commit it, then rerun).
# GPUTIME=0 skips the gputime Vulkan layer (GPU-timestamp frame times) built from
#   tools/hc/gputime with $CC (default cc).
H=${1:?usage: gfxtest.sh hc}; R=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
O=${GFX_OUT:-$T}; mkdir -p "$O"; G="$R/hc/test/gfx/golden/spheres.png"
if [ "${GFX_MAKE_GOLDEN:-0}" != 1 ] && [ ! -f "$G" ]; then echo "gfxtest: FAILED: golden $G is missing (GFX_MAKE_GOLDEN=1 writes one)"; exit 1; fi
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" build "$R/hc/test/gfx/gfx_smoke.amni" -o "$T/gs" > "$T/build.txt" 2>&1 || { echo "gfxtest: build failed"; grep -av "W[0-9]" "$T/build.txt" | tail -n 5; exit 1; }
E=()
if [ "${GPUTIME:-1}" != 0 ]; then
	"$R/tools/hc/gputime/build.sh" "$T/layer" > "$T/layer.txt" 2>&1 || { echo "gfxtest: gputime layer build failed"; tail -n 5 "$T/layer.txt"; exit 1; }
	: > "$O/gputime.log"; E=(env VK_LAYER_PATH="$T/layer" VK_INSTANCE_LAYERS=VK_LAYER_HELIUM_gputime HELIUM_GPUTIME="$O/gputime.log")
fi
L=(); [ -n "${GPU_LOCK:-}" ] && L=(flock "$GPU_LOCK")
A=("$G"); [ "${GFX_MAKE_GOLDEN:-0}" = 1 ] && A=()
"${L[@]}" "${E[@]}" "$T/gs" "$O" "${A[@]}" > "$T/all.txt" 2> "$T/err.txt"; rc=$?
cp "$T/all.txt" "$O/gfx_smoke.txt" 2>/dev/null
if [ "${GFX_MAKE_GOLDEN:-0}" = 1 ]; then
	[ -f "$O/spheres.png" ] || { echo "gfxtest: no spheres.png rendered"; tail -n 5 "$T/err.txt"; exit 1; }
	mkdir -p "$(dirname "$G")"; cp "$O/spheres.png" "$G"; echo "gfxtest: wrote $G; review it, commit it and rerun"; exit 1
fi
[ $rc = 0 ] || { echo "gfxtest: run failed"; tail -n 5 "$T/all.txt" "$T/err.txt"; exit 1; }
grep -av "^gpu:" "$T/all.txt" > "$T/cpu.txt"
cmp -s "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out" || { echo "gfxtest: CPU output differs"; diff "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out"; exit 1; }
grep -a "^gpu:" "$T/all.txt"; g=$(grep -a "^gpu: \(ok\|skipped\|FAILED\)" "$T/all.txt")
case "$g" in
	"gpu: ok"*) echo "gfxtest: ok";;
	"gpu: skipped"*) echo "gfxtest: ok (CPU only)";;
	*) echo "gfxtest: GPU checks failed"; exit 1;;
esac
