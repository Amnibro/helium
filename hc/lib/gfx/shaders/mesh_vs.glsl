layout(location = 0) in vec3 a_pos;
layout(location = 1) in vec3 a_nrm;
layout(location = 2) in vec2 a_uv;
layout(location = 3) in vec2 a_uv1;
layout(location = 4) in vec4 a_col;
layout(location = 5) in vec4 a_jnt;
layout(location = 6) in vec4 a_wgt;
layout(location = 7) in vec4 i_m0;
layout(location = 8) in vec4 i_m1;
layout(location = 9) in vec4 i_m2;
layout(location = 10) in vec4 i_m3;
layout(location = 11) in vec4 i_n0;
layout(location = 12) in vec4 i_n1;
layout(location = 13) in vec4 i_n2;
layout(location = 14) in vec4 i_extra;
layout(set = 0, binding = 0) readonly buffer Joints { vec4 joints[]; };
layout(set = 0, binding = 1) readonly buffer Morphs { vec4 morphs[]; };
#include "view_vs.glsl"
layout(location = 0) out vec4 o_world_position;
layout(location = 1) out vec3 o_world_normal;
layout(location = 2) out vec2 o_uv;
layout(location = 3) out vec2 o_uv_b;
layout(location = 4) out vec4 o_world_tangent;
layout(location = 5) out vec4 o_color;
layout(location = 6) flat out uint o_flags;
mat3 inverse_transpose_3x3(mat3 m) { vec3 x = cross(m[1], m[2]); vec3 y = cross(m[2], m[0]); vec3 z = cross(m[0], m[1]); float det = dot(m[2], z); return mat3(x / det, y / det, z / det); }
mat4 jm(int b) { return mat4(joints[b], joints[b + 1], joints[b + 2], joints[b + 3]); }
mat4 mesh_model() {
	if (info.x >= 0) { ivec4 j = (ivec4(a_jnt) + ivec4(info.x)) * 4; return a_wgt.x * jm(j.x) + a_wgt.y * jm(j.y) + a_wgt.z * jm(j.z) + a_wgt.w * jm(j.w); }
	return mat4(i_m0, i_m1, i_m2, i_m3);
}
vec4 mesh_vertex_world(out vec3 nrm_out, out mat4 model) {
	vec3 pos = a_pos;
	vec3 nrm = a_nrm;
	int count = info.y;
	for (int t = 0; t < count; t++) {
		float w = mw[t / 4][t % 4];
		if (w != 0.0) {
			int base = info.z + (t * 2) * info.w + gl_VertexIndex;
			pos += w * morphs[base].xyz;
			nrm += w * morphs[base + info.w].xyz;
		}
	}
	model = mesh_model();
	vec4 wp = model * vec4(pos, 1.0);
	mat3 nm = info.x >= 0 ? inverse_transpose_3x3(mat3(model[0].xyz, model[1].xyz, model[2].xyz)) : mat3(i_n0.xyz, i_n1.xyz, i_n2.xyz);
	nrm_out = normalize(nm * nrm);
	return wp;
}
void mesh_vertex() {
	vec3 n; mat4 model;
	vec4 wp = mesh_vertex_world(n, model);
	o_world_position = wp;
	gl_Position = clip_from_world * wp;
	o_world_normal = n;
	o_uv = a_uv;
	o_uv_b = a_uv1;
	o_world_tangent = vec4(1.0, 0.0, 0.0, 1.0);
	o_color = a_col;
	o_flags = uint(i_extra.z) | (uint(i_extra.w) << 8);
}
