#!/bin/bash
# gfxtest.sh hc: builds hc/test/gfx/gfx_smoke.amni against hc/lib/gfx and checks
# its CPU output against gfx_smoke.out, then runs the headless GPU checks
# (sun-sweep furnace, sphere grid vs hc/test/gfx/golden/spheres.png with the effects off
# and vs golden/spheres_default.png with the shipped look, full frame, timing, motion,
# TAA, upscaling, shadows).
# Needs libSDL3 and a Vulkan device; ci.sh only runs it when HELIUM_GFX_TEST=1.
# Both goldens are required: a missing golden or PSNR <= 40 dB fails.
# GPU_LOCK=<file> serializes the GPU run on a shared machine (blocking flock).
# GFX_OUT=<dir> keeps the rendered PNGs and the raw output (default: a temp dir).
# GFX_MAKE_GOLDEN=1 renders and writes both goldens instead, GFX_MAKE_GOLDEN=default
#   only golden/spheres_default.png (then exits 1 so a new golden is never taken
#   silently; review and commit it, then rerun).
# GPUTIME=0 skips the gputime Vulkan layer (GPU-timestamp frame times) built from
#   tools/hc/gputime with $CC (default cc).
# GFX_REQUIRE_GPU=1 makes "no GPU" a failure instead of "gfxtest: SKIPPED (no GPU)".
# $GFX_OUT/results.txt gets the raw results with a header (date, commit, command, host,
#   Vulkan device and driver, package versions) for hc/test/gfx/results/.
# First, on the CPU: hc/test/gfx/tools/make_ms_lut.amni must reproduce
#   hc/lib/gfx/shaders/ms_lut.glsl byte for byte and pass its grazing-corner check.
H=${1:?usage: gfxtest.sh hc}; R=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
O=${GFX_OUT:-$T}; mkdir -p "$O"; G="$R/hc/test/gfx/golden/spheres.png"; G2="$R/hc/test/gfx/golden/spheres_default.png"; MG=${GFX_MAKE_GOLDEN:-0}; RES="$O/results.txt"
{
	echo "# tools/hc/gfxtest.sh run, raw output"
	[ -n "${GPU_LOCK:-}" ] && echo "# GPU part run under: flock $GPU_LOCK (headless, no window)"
	echo "# date: $(date -Iseconds)"
	echo "# commit: $(git -C "$R" rev-parse HEAD 2>/dev/null)  (worktree changes: $(git -C "$R" status --porcelain 2>/dev/null | wc -l))"
	c=""; for v in MESA_VK_DEVICE_SELECT CC GPU_LOCK GPUTIME FURNACE_K GFX_MAKE_GOLDEN GFX_REQUIRE_GPU; do [ -n "${!v+x}" ] && c="$c$v='${!v}' "; done
	[ -n "${GFX_OUT:-}" ] && c="${c}GFX_OUT=<dir> "
	echo "# command: ${c}tools/hc/gfxtest.sh $*"
	echo "# host: $(uname -srm)"
	command -v vulkaninfo > /dev/null && vulkaninfo --summary 2>/dev/null | grep -E "^\s*(apiVersion|conformanceVersion|deviceName|driverInfo|driverName)\s*=" | sed "s/^\s*/# vulkan: /"
	command -v pacman > /dev/null && echo "# packages: $(pacman -Q sdl3 vulkan-radeon mesa 2>/dev/null | tr '\n' ' ')"
	echo "# gpu-timestamp: tools/hc/gputime Vulkan layer, one timestamp pair per primary command"
	echo "#   buffer (TOP_OF_PIPE at begin, BOTTOM_OF_PIPE at end), summed per submit; raw log: gputime.log"
	echo "# wall-clock: gfx::time() around render + submit + fence wait; no readback in either"
	echo "#"
} > "$RES"
say() { echo "$@"; echo "$@" >> "$RES"; }
if [ "$MG" = 0 ]; then for g in "$G" "$G2"; do [ -f "$g" ] || { echo "gfxtest: FAILED: golden $g is missing (GFX_MAKE_GOLDEN=1 writes both)"; exit 1; }; done; fi
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" run "$R/hc/test/gfx/tools/make_ms_lut.amni" > "$T/ms_lut.glsl" 2> "$O/ms_lut.txt" || { echo "gfxtest: make_ms_lut failed"; tail -n 5 "$T/ms_lut.glsl" "$O/ms_lut.txt"; exit 1; }
cat "$O/ms_lut.txt"; cat "$O/ms_lut.txt" >> "$RES"
cmp -s "$T/ms_lut.glsl" "$R/hc/lib/gfx/shaders/ms_lut.glsl" || { say "gfxtest: FAILED: make_ms_lut output differs from hc/lib/gfx/shaders/ms_lut.glsl"; exit 1; }
grep -q "^make_ms_lut: grazing compensation: .* PASS$" "$O/ms_lut.txt" || { say "gfxtest: FAILED: make_ms_lut grazing check"; exit 1; }
say "gfxtest: ms_lut.glsl reproduced byte for byte"
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" build "$R/hc/test/gfx/gfx_smoke.amni" -o "$T/gs" > "$T/build.txt" 2>&1 || { echo "gfxtest: build failed"; grep -av "W[0-9]" "$T/build.txt" | tail -n 5; exit 1; }
E=()
if [ "${GPUTIME:-1}" != 0 ]; then
	"$R/tools/hc/gputime/build.sh" "$T/layer" > "$T/layer.txt" 2>&1 || { echo "gfxtest: gputime layer build failed"; tail -n 5 "$T/layer.txt"; exit 1; }
	: > "$O/gputime.log"; E=(env VK_LAYER_PATH="$T/layer" VK_INSTANCE_LAYERS=VK_LAYER_HELIUM_gputime HELIUM_GPUTIME="$O/gputime.log")
fi
L=(); [ -n "${GPU_LOCK:-}" ] && L=(flock "$GPU_LOCK")
A=("$G" "$G2"); [ "$MG" != 0 ] && A=()
[ "$MG" = default ] && E=(env GFX_ONLY=default "${E[@]}")
"${L[@]}" "${E[@]}" "$T/gs" "$O" "${A[@]}" > "$T/all.txt" 2> "$T/err.txt"; rc=$?
cp "$T/all.txt" "$O/gfx_smoke.txt" 2>/dev/null; cat "$T/all.txt" >> "$RES" 2>/dev/null
if [ "$MG" != 0 ]; then
	mkdir -p "$(dirname "$G")"
	if [ "$MG" = 1 ]; then
		[ -f "$O/spheres.png" ] || { echo "gfxtest: no spheres.png rendered"; tail -n 5 "$T/err.txt"; exit 1; }
		cp "$O/spheres.png" "$G"; echo "gfxtest: wrote $G; review it, commit it and rerun"
	fi
	[ -f "$O/spheres_default.png" ] || { echo "gfxtest: no spheres_default.png rendered"; tail -n 5 "$T/err.txt"; exit 1; }
	cp "$O/spheres_default.png" "$G2"; echo "gfxtest: wrote $G2; review it, commit it and rerun"; exit 1
fi
[ $rc = 0 ] || { echo "gfxtest: run failed"; tail -n 5 "$T/all.txt" "$T/err.txt"; exit 1; }
grep -av "^gpu:" "$T/all.txt" > "$T/cpu.txt"
cmp -s "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out" || { echo "gfxtest: CPU output differs"; diff "$T/cpu.txt" "$R/hc/test/gfx/gfx_smoke.out"; exit 1; }
grep -a "^gpu:" "$T/all.txt"; g=$(grep -a "^gpu: \(ok\|skipped\|FAILED\)" "$T/all.txt")
case "$g" in
	"gpu: ok"*) say "gfxtest: ok";;
	"gpu: skipped"*) if [ "${GFX_REQUIRE_GPU:-0}" = 1 ]; then say "gfxtest: FAILED: no GPU (GFX_REQUIRE_GPU=1)"; exit 1; fi; say "gfxtest: SKIPPED (no GPU); CPU checks ok";;
	*) say "gfxtest: GPU checks failed"; exit 1;;
esac
