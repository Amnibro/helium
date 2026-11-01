#version 450
#include "mesh_vs.glsl"
void main() { vec3 n; mat4 m; gl_Position = clip_from_world * mesh_vertex_world(n, m); }
