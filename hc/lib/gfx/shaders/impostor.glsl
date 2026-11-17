#include "fade.glsl"
#ifndef IMP_PUSH
#define IMP_PUSH 0.0
#endif
layout(location = 0) in vec3 iv_world;
layout(location = 1) flat in vec4 iv_m0;
layout(location = 2) flat in vec4 iv_m1;
layout(location = 3) flat in vec4 iv_m2;
layout(location = 4) flat in vec4 iv_ray;
layout(location = 5) flat in vec4 iv_zr;
layout(location = 6) flat in vec4 iv_wr;
layout(location = 7) flat in vec4 iv_tint;
layout(location = 8) flat in vec4 iv_c;
layout(location = 9) flat in vec4 iv_e;
layout(location = 10) flat in vec4 iv_k;
layout(location = 11) in vec4 iv_cur;
layout(location = 12) in vec4 iv_prev;
#ifdef IMP_DECL
layout(set = 2, binding = 0) uniform sampler2DArray imp_a;
layout(set = 2, binding = 1) uniform sampler2DArray imp_b;
#define IMP_A imp_a
#define IMP_B imp_b
#endif
vec3 in_world = vec3(0.0);
vec3 in_nrm = vec3(0.0, 1.0, 0.0);
vec4 in_tan = vec4(1.0, 0.0, 0.0, 1.0);
vec4 in_uv = vec4(0.0);
vec4 in_col = vec4(1.0);
vec4 in_cur = vec4(0.0);
vec4 in_prev = vec4(0.0);
float imp_thr = 0.5;
float imp_shell = 0.05;
int imp_steps = 28;
float imp_cov = 1.0;
#ifndef IMP_SAMPLES
#define IMP_SAMPLES 1.0
#endif
#ifndef IMP_SHARP
#define IMP_SHARP 0.0
#endif
struct ImpView { vec3 r; vec3 u; vec3 d; float layer; };
struct ImpHit { float t; vec4 a; vec4 b; };
vec4 imp_tex_a(vec2 uv, float layer, float lod) {
#if IMP_SHARP > 0.0
	int l = int(lod + 0.5);
	ivec2 s = textureSize(IMP_A, l).xy;
	return texelFetch(IMP_A, ivec3(clamp(ivec2(uv * vec2(s)), ivec2(0), s - 1), int(layer)), l);
#else
	return textureLod(IMP_A, vec3(uv, layer), lod);
#endif
}
vec4 imp_tex_b(vec2 uv, float layer, float lod) {
#if IMP_SHARP > 0.0
	int l = int(lod + 0.5);
	ivec2 s = textureSize(IMP_B, l).xy;
	return texelFetch(IMP_B, ivec3(clamp(ivec2(uv * vec2(s)), ivec2(0), s - 1), int(layer)), l);
#else
	return textureLod(IMP_B, vec3(uv, layer), lod);
#endif
}
vec3 imp_obj(vec3 w) { vec4 p = vec4(w, 1.0); return vec3(dot(iv_m0, p), dot(iv_m1, p), dot(iv_m2, p)); }
vec3 imp_dir(vec3 w) { return vec3(dot(iv_m0.xyz, w), dot(iv_m1.xyz, w), dot(iv_m2.xyz, w)); }
ImpView imp_view(float gx, float gy) {
	float n = iv_e.w;
	vec2 uv = vec2(gx, gy) / (n - 1.0) * 2.0 - 1.0;
	vec2 p = vec2(uv.x + uv.y, uv.x - uv.y) * 0.5;
	vec3 d = normalize(vec3(p.x, max(1.0 - abs(p.x) - abs(p.y), 0.0), p.y));
	vec3 r = vec3(d.z, 0.0, -d.x);
	float rl = length(r);
	ImpView v;
	v.r = rl > 1e-4 ? r / rl : vec3(1.0, 0.0, 0.0);
	v.u = cross(d, v.r);
	v.d = d;
	v.layer = gy * n + gx;
	return v;
}
vec3 imp_proj(ImpView v, vec3 p) {
	vec3 q = (p - iv_c.xyz) / (2.0 * iv_c.w);
	return vec3(0.5 + dot(q, v.r), 0.5 - dot(q, v.u), 0.5 - dot(q, v.d));
}
bool imp_inside(ImpView v, vec3 p, float lod) {
	vec3 x = imp_proj(v, p);
	vec4 a = imp_tex_a(clamp(x.xy, vec2(0.0), vec2(1.0)), v.layer, lod);
	float h = imp_tex_b(clamp(x.xy, vec2(0.0), vec2(1.0)), v.layer, lod).a / max(a.a, 1e-4);
	return x.x >= 0.0 && x.y >= 0.0 && x.x <= 1.0 && x.y <= 1.0 && a.a >= imp_thr && x.z >= h && x.z <= h + imp_shell;
}
ImpHit imp_march(ImpView v, vec3 o, vec3 dir, float t1, float lod) {
	ImpHit r;
	r.t = -1.0;
	r.a = vec4(0.0);
	r.b = vec4(0.0);
	int steps = imp_steps;
	float dt = t1 / float(steps);
	float th = -1.0;
	for (int i = 0; i <= steps; i++) {
		if (imp_inside(v, o + dir * (float(i) * dt), lod)) {
			th = float(i) * dt;
			break;
		}
	}
	if (th < 0.0) return r;
	float lo = max(th - dt, 0.0);
	float hi = th;
	for (int k = 0; k < 5; k++) {
		float m = (lo + hi) * 0.5;
		bool ins = imp_inside(v, o + dir * m, lod);
		hi = ins ? m : hi;
		lo = ins ? lo : m;
	}
	vec3 x = imp_proj(v, o + dir * hi);
	r.t = hi;
	r.a = imp_tex_a(x.xy, v.layer, lod);
	r.b = imp_tex_b(x.xy, v.layer, lod);
	return r;
}
void imp_main() {
	vec3 wd = iv_ray.w > 0.5 ? normalize(iv_world - iv_ray.xyz) : normalize(iv_ray.xyz);
	vec3 o = imp_obj(iv_world);
	vec3 od = imp_dir(wd);
	vec3 dn = normalize(od);
	vec3 fx = dFdx(o);
	vec3 fy = dFdy(o);
	fx -= dn * dot(fx, dn);
	fy -= dn * dot(fy, dn);
	float lod = max(log2(max(max(length(fx), length(fy)) * float(textureSize(IMP_A, 0).x) / (2.0 * iv_c.w), 1e-6)) + iv_k.w - IMP_SHARP, 0.0);
	float ms = IMP_SAMPLES;
	imp_thr = ms > 1.5 ? 0.5 / ms : IMP_SHARP > 0.0 ? 0.5 : 0.5 + (imp_dither(gl_FragCoord.xy + vec2(11.0, 5.0)) - 0.5) * clamp(lod, 0.0, 1.0);
	float sc = exp2(min(lod, 3.0));
	imp_shell = iv_k.x * sc;
	imp_steps = max(int(iv_k.y / sc + 0.5), 7);
	float hide = iv_tint.w;
	if (hide > 0.0 && imp_dither(gl_FragCoord.xy) >= 1.0 - hide) discard;
	vec3 lo = iv_c.xyz - iv_e.xyz * 1.01;
	vec3 hi = iv_c.xyz + iv_e.xyz * 1.01;
	vec3 sd = vec3(od.x >= 0.0 ? 1.0 : -1.0, od.y >= 0.0 ? 1.0 : -1.0, od.z >= 0.0 ? 1.0 : -1.0);
	vec3 inv = sd / max(abs(od), vec3(1e-8));
	vec3 tm = max((lo - o) * inv, (hi - o) * inv);
	float t1 = max(min(min(tm.x, tm.y), tm.z), 0.0);
	vec3 ve = iv_ray.w > 0.5 ? normalize(imp_obj(iv_ray.xyz) - iv_c.xyz) : -dn;
	ve = vec3(ve.x, max(ve.y, 0.0), ve.z);
	vec2 p = ve.xz / max(abs(ve.x) + ve.y + abs(ve.z), 1e-6);
	float n1 = iv_e.w - 1.0;
	vec2 g = (vec2(p.x + p.y, p.x - p.y) * 0.5 + 0.5) * n1;
	vec2 g0 = clamp(floor(g), vec2(0.0), vec2(n1 - 1.0));
	vec2 f = clamp(g - g0, vec2(0.0), vec2(1.0));
	bool up = f.x + f.y > 1.0;
	vec3 a0 = up ? vec3(g0 + 1.0, f.x + f.y - 1.0) : vec3(g0, 1.0 - f.x - f.y);
	vec3 a1 = up ? vec3(g0.x, g0.y + 1.0, 1.0 - f.x) : vec3(g0.x + 1.0, g0.y, f.x);
	vec3 a2 = up ? vec3(g0.x + 1.0, g0.y, 1.0 - f.y) : vec3(g0.x, g0.y + 1.0, f.y);
	vec3 w = vec3(a0.z, a1.z, a2.z);
#ifdef IMP_NEAREST
	float tier = 2.0;
#else
	float tier = mod(iv_k.z, 4.0);
#endif
	float xs = imp_dither(gl_FragCoord.yx * 1.37 + vec2(3.1, 7.9));
	vec3 pick = xs < w.x ? vec3(1.0, 0.0, 0.0) : (xs < w.x + w.y ? vec3(0.0, 1.0, 0.0) : vec3(0.0, 0.0, 1.0));
	vec3 best = w.x >= w.y && w.x >= w.z ? vec3(1.0, 0.0, 0.0) : (w.y >= w.z ? vec3(0.0, 1.0, 0.0) : vec3(0.0, 0.0, 1.0));
	vec3 use = tier > 1.5 ? best : (tier > 0.5 ? w : pick);
	vec3 bg = best.x > 0.5 ? a0 : (best.y > 0.5 ? a1 : a2);
	ImpView vb = imp_view(bg.x, bg.y);
	vec3 e0 = imp_proj(vb, o);
	vec3 e1 = imp_proj(vb, o + od * t1);
	float em = clamp(ceil(log2(max(length(e1.xy - e0.xy) * float(textureSize(IMP_A, 0).x), 1.0))) + 1.0, 0.0, floor(log2(float(textureSize(IMP_A, 0).x))));
	if (textureLod(IMP_A, vec3(clamp(e0.xy, vec2(0.0), vec2(1.0)), vb.layer), em).a + textureLod(IMP_A, vec3(clamp(0.5 * (e0.xy + e1.xy), vec2(0.0), vec2(1.0)), vb.layer), em).a + textureLod(IMP_A, vec3(clamp(e1.xy, vec2(0.0), vec2(1.0)), vb.layer), em).a <= 0.0) discard;
	float ws = 0.0;
	float cs = 0.0;
	float ts = 0.0;
	vec3 as = vec3(0.0);
	vec3 ns = vec3(0.0);
	for (int i = 0; i < 3; i++) {
		vec3 ai = i == 0 ? a0 : (i == 1 ? a1 : a2);
		float wi = i == 0 ? use.x : (i == 1 ? use.y : use.z);
		if (wi < 1e-3) continue;
		ImpHit h = imp_march(imp_view(ai.x, ai.y), o, od, t1, lod);
		if (h.t < 0.0) continue;
		ws += wi;
		cs += wi * h.a.a;
		ts += wi * h.a.a * h.t;
		as += wi * h.a.rgb;
		ns += wi * (h.b.rgb * 2.0 - h.a.a);
	}
	float cq = floor(clamp(cs, 0.0, 1.0) * ms + 0.5);
	if (ms > 1.5 ? cq < 0.5 : ws < 0.5) discard;
	imp_cov = ms > 1.5 && cq < ms ? cq / ms + 0.015625 : 1.0;
	cs = max(cs, 1e-4);
	vec3 hw = iv_world + wd * (ts / cs + IMP_PUSH * iv_c.w);
	hw = iv_k.z > 3.5 ? iv_world : hw;
	vec3 nb = ns / cs;
	vec3 nw = normalize(nb.x * iv_m0.xyz + nb.y * iv_m1.xyz + nb.z * iv_m2.xyz + vec3(0.0, 1e-6, 0.0));
	in_world = hw;
	in_nrm = nw;
	in_tan = vec4(normalize(cross(abs(nw.y) < 0.99 ? vec3(0.0, 1.0, 0.0) : vec3(1.0, 0.0, 0.0), nw)), 1.0);
	in_uv = vec4(0.0);
	in_col = vec4(as / cs * (dot(iv_tint.rgb, vec3(1.0)) > 0.0 ? iv_tint.rgb : vec3(1.0)), 1.0);
	in_cur = iv_cur;
	in_prev = iv_prev;
	vec4 hp = vec4(hw, 1.0);
	gl_FragDepth = dot(iv_zr, hp) / dot(iv_wr, hp);
}
