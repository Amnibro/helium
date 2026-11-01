#!/bin/bash
# gfxtest.sh hc: builds hc/test/gfx/gfx_smoke.amni against hc/lib/gfx, checks
# the CPU output, then renders one headless frame (PBR, shadows, SSAO, bloom,
# filmic tonemap, GPU particles) and checks it is lit. No GPU: CPU part only.
# GPU_LOCK=<file> serializes the GPU run on a shared machine (flock).
H=${1:?usage: gfxtest.sh hc}; R=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" "$R/hc/test/gfx/gfx_smoke.amni" "$T/gs" --native || { echo "gfxtest: build failed"; exit 1; }
"$T/gs" > "$T/cpu.txt" && cmp -s "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out" || { echo "gfxtest: CPU output differs"; diff "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out"; exit 1; }
L=(); [ -n "${GPU_LOCK:-}" ] && L=(flock "$GPU_LOCK"); "${L[@]}" "$T/gs" "$T/frame.png" > "$T/gpu.txt" 2>&1; g=$(grep "^gpu:" "$T/gpu.txt")
case "$g" in
	"gpu: ok"*) echo "gfxtest: ok (${g#gpu: ok })";;
	"gpu: skipped"*) echo "gfxtest: ok (CPU only; ${g#gpu: })";;
	*) echo "gfxtest: GPU frame failed: $g"; exit 1;;
esac
