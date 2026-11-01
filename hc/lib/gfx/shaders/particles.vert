#version 450
// Vertex-pulled particle quads (6 vertices per particle).
// Sparks stretch along their velocity, dust is a camera-facing puff.
struct P { vec4 pl; vec4 vk; vec4 cs; vec4 ex; };
layout(std430, set = 0, binding = 0) readonly buffer Ps { P ps[]; };
layout(set = 1, binding = 0) uniform PV { mat4 cfw; vec4 cr; vec4 cu; vec4 ce; };
layout(location = 0) out vec4 v_col;
layout(location = 1) out vec2 v_q;
layout(location = 2) flat out float v_kind;

const vec2 Q[6] = vec2[6](vec2(-1.0, -1.0), vec2(1.0, -1.0), vec2(1.0, 1.0), vec2(-1.0, -1.0), vec2(1.0, 1.0), vec2(-1.0, 1.0));

void main() {
	uint id = uint(gl_VertexIndex) / 6u;
	vec2 q = Q[uint(gl_VertexIndex) % 6u];
	P p = ps[id];
	v_q = q;
	v_kind = p.vk.w;
	if (p.pl.w <= 0.0) { gl_Position = vec4(0.0, 0.0, -2.0, 1.0); v_col = vec4(0.0); return; }
	float t = clamp(p.pl.w / max(p.ex.x, 1e-3), 0.0, 1.0);
	vec3 pos = p.pl.xyz;
	float sz = p.cs.w;
	vec3 wp;
	if (p.vk.w < 0.5) {
		vec3 v = p.vk.xyz;
		float sp = length(v);
		vec3 ax = sp > 1e-3 ? v / sp : cu.xyz;
		vec3 side = cross(ax, ce.xyz - pos);
		side = length(side) > 1e-5 ? normalize(side) : cr.xyz;
		wp = pos + ax * (q.y * (sz + sp * 0.03)) + side * (q.x * sz);
		v_col = vec4(p.cs.rgb * (t * t * 1.5 + 0.1), 1.0);
	} else {
		wp = pos + cr.xyz * (q.x * sz) + cu.xyz * (q.y * sz);
		v_col = vec4(p.cs.rgb, 4.0 * t * (1.0 - t) * 0.35);
	}
	gl_Position = cfw * vec4(wp, 1.0);
}
