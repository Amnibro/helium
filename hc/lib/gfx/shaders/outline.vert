#version 450
#include "mesh_vs.glsl"
layout(set = 1, binding = 2) uniform Outline { vec4 o; };
void main() { mesh_vertex(); o_world_position = o_world_position + vec4(normalize(o_world_normal) * o.x, 0.0); gl_Position = clip_from_world * o_world_position; }
