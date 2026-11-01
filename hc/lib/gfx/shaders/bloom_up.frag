#version 450
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform sampler2D up_src;
layout(set = 2, binding = 1) uniform sampler2D down_dst;
layout(set = 3, binding = 0) uniform BloomU { vec4 threshold; vec4 texel; };
#include "up9.glsl"
void main() { out_color = vec4(up9(up_src, in_uv, texel.xy) * texel.z + textureLod(down_dst, in_uv, 0.0).rgb * (1.0 - texel.z), 1.0); }
