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
	int em = (int(p.misc.x)) * 13;
	if (abs(emits[em + 5].w - mode.x) > 0.5) return;
	vec4 wx = emits[em + 11];
	bool wb = wx.y > 0.5;
	if (wb && p.misc.z > 1.5) return;
	bool sp = wb && p.misc.z > 0.5;
	vec2 corners[6] = vec2[6](vec2(-1, -1), vec2(1, -1), vec2(1, 1), vec2(-1, -1), vec2(1, 1), vec2(-1, 1));
	vec2 c = corners[k];
	float t = p.pos.w / max(p.vel.w, 1e-4);
	float a = sp ? clamp((p.misc.w - p.pos.y) / max(-p.vel.y, 1e-3) / max(wx.z, 1e-4), 0.0, 1.0) : 0.0;
	float r = sp ? wx.w * (0.4 + 0.6 * a) : fx_curve1(emits[em + 10], t);
	vec3 pc = sp ? vec3(p.pos.x, p.misc.w + r * 0.5, p.pos.z) : p.pos.xyz;
	out_corner = c;
	out_rgba = sp ? emits[em + 12] * vec4(1.0, 1.0, 1.0, 1.0 - a) : fx_curve4(emits[em + 6], emits[em + 7], emits[em + 8], emits[em + 9], t);
	out_depth_fade = vec2(-(view * vec4(pc, 1.0)).z, emits[em + 5].z);
	vec3 hv = p.vel.xyz * (0.5 * wx.x);
	vec4 cp = view_proj * vec4(pc, 1.0);
	vec4 ca = view_proj * vec4(pc - hv, 1.0);
	vec4 cb = view_proj * vec4(pc + hv, 1.0);
	vec4 cu = view_proj * vec4(pc + up.xyz * r, 1.0);
	if (!sp && wx.x > 0.0 && min(min(ca.w, cb.w), min(cp.w, cu.w)) > 1e-3) {
		vec2 hp = mode.zw * 0.5;
		vec2 sa = ca.xy / ca.w * hp; vec2 sb = cb.xy / cb.w * hp;
		vec2 d = (sb - sa) * 0.5; float l = length(d);
		float rp = length(cu.xy / cu.w * hp - cp.xy / cp.w * hp);
		vec2 u = l > 1e-6 ? d / l : vec2(0.0, 1.0);
		vec2 o = (sa + sb) * 0.5 + u * (c.x * max(l, rp)) + vec2(-u.y, u.x) * (c.y * rp);
		gl_Position = vec4(o / hp, cp.z / cp.w, 1.0);
		return;
	}
	gl_Position = view_proj * vec4(pc + (right.xyz * c.x + up.xyz * c.y) * r, 1.0);
}
