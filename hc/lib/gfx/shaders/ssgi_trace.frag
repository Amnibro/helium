layout(set = 2, binding = 0) uniform sampler2D tex_depth;
layout(set = 2, binding = 1) uniform sampler2D tex_h1;
layout(set = 2, binding = 2) uniform sampler2D tex_h2;
layout(set = 2, binding = 3) uniform sampler2D tex_h3;
layout(set = 2, binding = 4) uniform sampler2D tex_h4;
layout(set = 2, binding = 5) uniform sampler2D tex_h5;
layout(set = 2, binding = 6) uniform sampler2D tex_h6;
layout(set = 2, binding = 7) uniform sampler2D tex_h7;
layout(set = 2, binding = 8) uniform sampler2D tex_nd;
layout(set = 2, binding = 9) uniform sampler2D tex_motion;
layout(set = 2, binding = 10) uniform sampler2D tex_prev;
layout(set = 3, binding = 0) uniform Ssgi { vec4 lens; vec4 jit; vec4 tune; vec4 edge; mat4 inv_view; mat4 prev_vp; vec4 misc; };
layout(location = 0) out vec4 out_gi;
#include "hiz_march.glsl"
void main() {
	out_gi = vec4(0.0, 0.0, 0.0, 1.0);
	ivec2 x = min(ivec2(gl_FragCoord.xy) * 2, ivec2(jit.zw) - 1);
	float z = texelFetch(tex_depth, x, 0).r;
	if (z <= 0.0) return;
	vec3 n = normalize(texelFetch(tex_nd, x, 0).xyz);
	vec3 p = view_pos(vec2(x) + 0.5 + jit.xy, z);
	p += n * (3.0 * z * lens.y / jit.w);
	vec3 t1 = normalize(abs(n.y) < 0.9 ? cross(n, vec3(0.0, 1.0, 0.0)) : cross(n, vec3(1.0, 0.0, 0.0)));
	vec3 t2 = cross(n, t1);
	float nz = fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715))) + edge.z * 0.61803399);
	int nr = int(misc.x + 0.5);
	vec3 acc = vec3(0.0);
	float vis = 0.0;
	float nu = 0.0;
	for (int i = 0; i < 16; i++) {
		if (i >= nr) break;
		float u = fract((float(i) + 0.5) / float(nr) + nz);
		float a = float(i) * 2.39996323 + nz * 6.28318531;
		float sr = sqrt(u);
		vec3 r = normalize(t1 * (cos(a) * sr) + t2 * (sin(a) * sr) + n * sqrt(max(1.0 - u, 0.0)));
		vec2 sh;
		int hm = hiz_march(p, r, tune.z, int(tune.x), tune.y * z, 1, sh);
		nu += hm == 1 ? 1.0 : 0.0;
		if (hm != 0) { vis += hm == 2 ? 1.0 : 0.0; continue; }
		ivec2 hx = clamp(ivec2(floor(sh)), ivec2(0), ivec2(jit.zw) - 1);
		float zh = texelFetch(tex_depth, hx, 0).r;
		if (zh <= 0.0) { vis += 1.0; continue; }
		vec3 nh = texelFetch(tex_nd, hx, 0).xyz;
		if (dot(nh, r) > 0.0) continue;
		vec3 ph = view_pos(sh + jit.xy, zh);
		vec2 uv = sh / jit.zw;
		vec2 e = clamp(min(uv, 1.0 - uv) / max(edge.x, 1e-4), 0.0, 1.0);
		float w = e.x * e.y * (1.0 - smoothstep(0.9, 1.0, length(ph - p) / tune.z));
		vec4 c = prev_vp * (inv_view * vec4(ph, 1.0));
		vec2 pu = tune.w > 0.5 ? (sh + jit.xy) / jit.zw - texelFetch(tex_motion, hx, 0).xy : vec2(c.x / c.w * 0.5 + 0.5, 0.5 - c.y / c.w * 0.5);
		bool on = misc.y > 0.5 && all(greaterThanEqual(pu, vec2(0.0))) && all(lessThanEqual(pu, vec2(1.0)));
		acc += on ? textureLod(tex_prev, pu, 0.0).rgb * w : vec3(0.0);
		vis += 1.0 - w;
	}
	float nk = float(nr) - nu;
	out_gi = nk > 0.5 ? vec4(acc / nk, vis / nk) : vec4(0.0, 0.0, 0.0, 1.0);
}
