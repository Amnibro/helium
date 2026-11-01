#version 450
#include "pbr_fs.glsl"
layout(set = 3, binding = 3) uniform Outline { vec4 o; };
void main() { out_color = vec4(o.yzw, 1.0); }
