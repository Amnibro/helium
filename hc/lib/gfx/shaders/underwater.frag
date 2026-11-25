#include "water.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_nd;
layout(set = 2, binding = 2) uniform sampler2DArrayShadow tex_shadow;
layout(set = 3, binding = 0) uniform Sea {
	mat4 inv_view_proj;
	mat4 cascade_mat[3];
	vec4 cascade_far;
	vec4 eye;
	vec4 view_dir;
	vec4 to_sun;
	vec4 sun_rgb;
	vec4 ambient;
	vec4 absorb;
	vec4 scatter;
	vec4 box;
	vec4 waves;
	vec4 params;
};
layout(location = 0) out vec4 out_rgba;
#include "sun_vis.glsl"
vec2 bend(vec2 s) {
	vec2 g = water_wave(s, waves.w, waves.xyz, 5).xy;
	vec3 r = refract(-to_sun.xyz, normalize(vec3(-g.x, 1.0, -g.y)), 0.75);
	return r.xz / max(-r.y, 0.05);
}
void main() {
	vec3 src = texture(tex_hdr, in_uv).rgb;
	vec4 nd = texture(tex_nd, in_uv);
	vec4 w = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.5, 1.0);
	vec3 dir = normalize(w.xyz / w.w - eye.xyz);
	float level = ambient.w;
	vec2 inv = 1.0 / vec2(abs(dir.x) < 1e-6 ? 1e-6 : dir.x, abs(dir.z) < 1e-6 ? 1e-6 : dir.z);
	vec2 ex = max((box.xy - eye.xz) * inv, (box.zw - eye.xz) * inv);
	float te = min(nd.w > 0.0 ? nd.w / max(dot(dir, view_dir.xyz), 1e-3) : 1e9, min(ex.x, ex.y));
	if (dir.y > 1e-6) te = min(te, (level - eye.y) / dir.y);
	vec3 a = absorb.rgb;
	float tm = min(te, 9.0 / max(min(a.r, min(a.g, a.b)), 1e-3));
	int n = int(absorb.w);
	float j = fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)) + params.x * 0.61803398875));
	vec3 r0 = refract(-to_sun.xyz, vec3(0.0, 1.0, 0.0), 0.75);
	float cr = max(-r0.y, 0.05);
	vec2 c0 = r0.xz / cr;
	vec3 sum = vec3(0.0);
	float tp = 0.0;
	vec3 ep = vec3(1.0);
	for (int i = 0; i < n; i++) {
		float s = float(i + 1) / float(n);
		float t1 = tm * s * s;
		vec3 e1 = exp(-a * t1);
		vec3 p = eye.xyz + dir * mix(tp, t1, j);
		float d = max(level - p.y, 0.0);
		vec3 lit = ambient.rgb * exp(-a * d);
		if (to_sun.y > 0.0) {
			vec2 s0 = p.xz - c0 * d;
			float k = 1.0;
			if (scatter.w > 0.0 && s0.x > box.x && s0.y > box.y && s0.x < box.z && s0.y < box.w) {
				float kk = d * params.y;
				vec2 b = bend(s0);
				vec2 jx = vec2(1.0, 0.0) + (bend(s0 + vec2(0.01, 0.0)) - b) * (kk * 100.0);
				vec2 jz = vec2(0.0, 1.0) + (bend(s0 + vec2(0.0, 0.01)) - b) * (kk * 100.0);
				k = 1.0 + scatter.w * (1.0 / max(abs(jx.x * jz.y - jx.y * jz.x), 1.0 / params.z) - 1.0);
			}
			lit += sun_rgb.rgb * (to_sun.y * 0.318309886 * k * sun_vis(vec3(s0.x, level, s0.y))) * exp(-a * (d / cr));
		}
		sum += (ep - e1) * lit;
		tp = t1;
		ep = e1;
	}
	out_rgba = vec4(src * exp(-a * te) + scatter.rgb * sum, 1.0);
}
