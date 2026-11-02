#!/bin/bash
# build.sh <dir>: builds the gputime Vulkan layer into <dir> with its manifest.
# Use it with:  VK_LAYER_PATH=<dir> VK_INSTANCE_LAYERS=VK_LAYER_HELIUM_gputime \
#               HELIUM_GPUTIME=<log file> <program>
D=${1:?usage: build.sh <dir>}; S=$(cd "$(dirname "$0")" && pwd); mkdir -p "$D"
${CC:-cc} -O2 -shared -fPIC -fvisibility=hidden -o "$D/libVkLayer_helium_gputime.so" "$S/gputime_layer.c" -lpthread || exit 1
cat > "$D/VkLayer_helium_gputime.json" <<J
{
	"file_format_version": "1.0.0",
	"layer": {
		"name": "VK_LAYER_HELIUM_gputime",
		"type": "GLOBAL",
		"library_path": "./libVkLayer_helium_gputime.so",
		"api_version": "1.3.0",
		"implementation_version": "1",
		"description": "Helium: GPU time per queue submit from timestamp queries",
		"functions": {
			"vkGetInstanceProcAddr": "helium_gputime_GetInstanceProcAddr",
			"vkGetDeviceProcAddr": "helium_gputime_GetDeviceProcAddr"
		}
	}
}
J
