#include "fx_common.glsl"
layout(std430, set = 0, binding = 0) readonly buffer Parts { Part parts[]; };
layout(std430, set = 0, binding = 1) readonly buffer Alive { uint alive[]; };
layout(std430, set = 0, binding = 2) readonly buffer Emits { vec4 emits[]; };
layout(set = 1, binding = 0) uniform View { mat4 view_proj; mat4 view; vec4 right; vec4 up; vec4 mode; };
layout(location = 0) out vec2 out_corner;
layout(location = 1) out vec4 out_rgba;
layout(location = 2) out vec2 out_depth_fade;
void main() {
	uint q = uint(gl_VertexIndex / 6);
	int k = gl_VertexIndex % 6;
	gl_Position = vec4(2.0, 2.0, 2.0, 1.0); out_corner = vec2(0.0); out_rgba = vec4(0.0); out_depth_fade = vec2(0.0);
	if (q >= alive[0]) return;
	Part p = parts[alive[q + 1u]];
	int em = (int(p.misc.x)) * 11;
	if (abs(emits[em + 5].w - mode.x) > 0.5) return;
	vec2 corners[6] = vec2[6](vec2(-1, -1), vec2(1, -1), vec2(1, 1), vec2(-1, -1), vec2(1, 1), vec2(-1, 1));
	vec2 c = corners[k];
	float t = p.pos.w / max(p.vel.w, 1e-4);
	float r = fx_curve1(emits[em + 10], t);
	vec3 w = p.pos.xyz + (right.xyz * c.x + up.xyz * c.y) * r;
	out_corner = c;
	out_rgba = fx_curve4(emits[em + 6], emits[em + 7], emits[em + 8], emits[em + 9], t);
	out_depth_fade = vec2(-(view * vec4(p.pos.xyz, 1.0)).z, emits[em + 5].z);
	gl_Position = view_proj * vec4(w, 1.0);
}
