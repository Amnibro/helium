#include "fx_common.glsl"
layout(std430, set = 0, binding = 0) readonly buffer Parts { Part parts[]; };
layout(std430, set = 0, binding = 1) readonly buffer Ev { uint evd[]; };
layout(std430, set = 0, binding = 2) readonly buffer Emits { vec4 emits[]; };
layout(std430, set = 0, binding = 3) readonly buffer Mesh { vec4 mesh[]; };
layout(set = 1, binding = 0) uniform View { mat4 view_proj; mat4 view; vec4 eye; vec4 up; vec4 mode; };
layout(location = 0) out vec3 out_nrm;
layout(location = 1) out vec4 out_rgba;
void main() {
	gl_Position = vec4(2.0, 2.0, 2.0, 1.0); out_nrm = vec3(0.0, 1.0, 0.0); out_rgba = vec4(0.0);
	Part p = parts[evd[uint(mode.y) + 1u + uint(gl_InstanceIndex)]];
	int em = int(p.misc.x) * 15;
	if (abs(emits[em + 14].z - mode.x) > 0.5) return;
	float t = p.pos.w / max(p.vel.w, 1e-4);
	float spin = emits[em + 14].w;
	uint s = uint(p.misc.y);
	vec3 ax = normalize(vec3(fx_rnd(s), fx_rnd(s), fx_rnd(s)) * 2.0 - 1.0 + vec3(1e-4, 0.0, 0.0));
	float ang = spin == 0.0 ? 0.0 : fx_rnd(s) * 6.2831853 + spin * p.pos.w;
	float ca = cos(ang); float sa = sin(ang);
	vec3 v = mesh[gl_VertexIndex * 2].xyz * fx_curve1(emits[em + 10], t);
	vec3 n = mesh[gl_VertexIndex * 2 + 1].xyz;
	v = v * ca + cross(ax, v) * sa + ax * (dot(ax, v) * (1.0 - ca));
	out_nrm = n * ca + cross(ax, n) * sa + ax * (dot(ax, n) * (1.0 - ca));
	out_rgba = fx_curve4(emits[em + 6], emits[em + 7], emits[em + 8], emits[em + 9], t);
	gl_Position = view_proj * vec4(p.pos.xyz + v, 1.0);
}
