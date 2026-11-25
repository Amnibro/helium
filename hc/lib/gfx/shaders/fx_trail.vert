#include "fx_common.glsl"
layout(std430, set = 0, binding = 0) readonly buffer Parts { Part parts[]; };
layout(std430, set = 0, binding = 1) readonly buffer Alive { uint alive[]; };
layout(std430, set = 0, binding = 2) readonly buffer Emits { vec4 emits[]; };
layout(std430, set = 0, binding = 3) readonly buffer Trail { vec4 trail[]; };
layout(set = 1, binding = 0) uniform View { mat4 view_proj; mat4 view; vec4 eye; vec4 up; vec4 mode; };
layout(location = 0) out vec2 out_corner;
layout(location = 1) out vec4 out_rgba;
layout(location = 2) out vec2 out_depth_fade;
vec3 fx_tp(uint b, int j, float fr) { return j < 8 ? trail[b + uint(max(j, 0))].xyz : mix(trail[b + 8u].xyz, trail[b + 7u].xyz, fr); }
void main() {
	gl_Position = vec4(2.0, 2.0, 2.0, 1.0); out_corner = vec2(0.0); out_rgba = vec4(0.0); out_depth_fade = vec2(0.0);
	uint slot = alive[uint(gl_InstanceIndex) + 1u];
	Part p = parts[slot];
	int em = int(p.misc.x) * 15;
	float td = emits[em + 14].y;
	if (td <= 0.0 || abs(emits[em + 5].w - mode.x) > 0.5) return;
	vec2 corners[6] = vec2[6](vec2(0, -1), vec2(1, -1), vec2(1, 1), vec2(0, -1), vec2(1, 1), vec2(0, 1));
	vec2 c = corners[gl_VertexIndex % 6];
	int j = gl_VertexIndex / 6 + int(c.x);
	uint b = slot * 9u;
	float fr = clamp(trail[b].w / td, 0.0, 1.0);
	vec3 pj = fx_tp(b, j, fr);
	vec3 side = cross(fx_tp(b, j - 1, fr) - fx_tp(b, j + 1, fr), eye.xyz - pj);
	float l = length(side);
	side = l > 1e-9 ? side / l : vec3(0.0);
	float f = float(j) / 8.0;
	float t = p.pos.w / max(p.vel.w, 1e-4);
	out_corner = vec2(0.0, c.y);
	out_rgba = fx_curve4(emits[em + 6], emits[em + 7], emits[em + 8], emits[em + 9], t) * vec4(1.0, 1.0, 1.0, 1.0 - f);
	out_depth_fade = vec2(-(view * vec4(pj, 1.0)).z, emits[em + 5].z);
	gl_Position = view_proj * vec4(pj + side * (c.y * fx_curve1(emits[em + 10], t) * (1.0 - f)), 1.0);
}
