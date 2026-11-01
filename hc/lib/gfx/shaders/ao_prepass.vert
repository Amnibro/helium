#version 450
#include "mesh_vs.glsl"
layout(location = 0) out vec3 v_view_normal;
layout(location = 1) out vec3 v_view_position;
void main() {
	vec3 n;
	mat4 m;
	vec4 wp = mesh_vertex_world(n, m);
	gl_Position = clip_from_world * wp;
	vec4 vp = view_from_world * wp;
	v_view_position = vp.xyz;
	v_view_normal = mat3(view_from_world[0].xyz, view_from_world[1].xyz, view_from_world[2].xyz) * n;
}
