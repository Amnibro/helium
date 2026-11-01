#!/usr/bin/env bash
# Headless GPU-skinning build-and-bench: 32 full-res skinned characters per
# hero GLB, Vulkan compute, no window. Builds the shader with Helium's own
# GLSL->SPIR-V compiler, checks GPU vs CPU skinning, prints frame time/fps,
# and writes everything to a results text file. Exits when done; nothing is
# left running.
#
#   HCN=path/to/hcn HC_LIB=path/to/hc/lib \
#   hc/test/anim/gpuskin_bench.sh <results.txt> <frames> <hero.glb>...
#
# Optional: GSK_DEVICE=<index> (default: prefer discrete GPU), and
# GSK_SHA=<sha256 list> to verify the hero GLBs before and after (read-only).
set -u
HERE="$(cd "$(dirname "$0")" && pwd)"
OUT="${1:?results file}"; FRAMES="${2:?frames}"; shift 2
HCN="${HCN:-$HERE/../../../build/hcn}"
export HC_LIB="${HC_LIB:-$HERE/../../lib}"
WORK="$(mktemp -d)"; trap 'rm -rf "$WORK"' EXIT
log() { echo "$@" | tee -a "$OUT"; }
: > "$OUT"
log "gpuskin bench  $(date '+%Y-%m-%d %H:%M:%S %Z')  host $(hostname)  frames $FRAMES"
log "hcn $HCN"
if [ -n "${GSK_SHA:-}" ]; then
	if sha256sum --quiet -c "$GSK_SHA" >>"$OUT" 2>&1; then log "glb sha256 before: OK ($(wc -l < "$GSK_SHA") files)"; else log "glb sha256 before: MISMATCH"; exit 1; fi
fi
"$HCN" --spv "$HC_LIB/anim/skin.comp" "$WORK/skin.spv" >>"$OUT" 2>&1 || { log "shader build failed"; exit 1; }
log "skin.spv $(stat -c %s "$WORK/skin.spv") bytes (hcn --spv)"
if command -v spirv-val >/dev/null 2>&1; then
	if spirv-val --target-env vulkan1.0 "$WORK/skin.spv" >>"$OUT" 2>&1; then log "spirv-val: OK"; else log "spirv-val: FAILED"; fi
fi
"$HCN" build "$HERE/anim_gpuskin.amni" -o "$WORK/gpuskin" >>"$OUT" 2>&1 || { log "build failed"; exit 1; }
rc=0
for g in "$@"; do
	log ""
	"$WORK/gpuskin" "$g" "$WORK/skin.spv" "$FRAMES" ${GSK_DEVICE:-} 2>&1 | tee -a "$OUT"
	r=${PIPESTATUS[0]}; [ "$r" -ne 0 ] && { log "exit $r"; rc=1; }
done
if [ -n "${GSK_SHA:-}" ]; then
	if sha256sum --quiet -c "$GSK_SHA" >>"$OUT" 2>&1; then log "glb sha256 after: OK"; else log "glb sha256 after: MISMATCH"; rc=1; fi
fi
log "done $(date '+%H:%M:%S %Z')  rc $rc"
exit $rc
