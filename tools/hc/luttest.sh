#!/bin/bash
H=${1:?usage: luttest.sh hc}; R=$(cd "$(dirname "$0")/../.." && pwd); T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
HC_LIB=${HC_LIB:-$R/hc/lib} "$H" "$R/hc/test/lut/lut_gpu.amni" "$T/lg" --native || { echo "luttest: build failed"; exit 1; }
HOME=$T/c HELIUM_GPU=off "$T/lg" > "$T/cpu.txt" && cmp -s "$T/cpu.txt" "$R/hc/test/lut/lut_gpu.out" || { echo "luttest: CPU tables differ"; exit 1; }
HOME=$T/g HELIUM_GPU_MIN_MS=0 HELIUM_GPU_LOG=1 "$T/lg" > "$T/gpu.txt" 2> "$T/log.txt"; n=$(grep -c "^gpu fill" "$T/log.txt")
cmp -s "$T/gpu.txt" "$R/hc/test/lut/lut_gpu.out" || { echo "luttest: GPU tables differ"; exit 1; }
HOME=$T/g HELIUM_GPU=off "$T/lg" > "$T/again.txt" && cmp -s "$T/again.txt" "$R/hc/test/lut/lut_gpu.out" || { echo "luttest: saved tables differ"; exit 1; }
echo "luttest: ok ($n tables filled on the GPU)"
