#include "sheen_lut.glsl"
layout(set = 3, binding = 2) uniform ExtBlock {
	vec4 x_ior;
	vec4 x_spec;
	vec4 x_coat;
	vec4 x_trans;
	vec4 x_atten;
	vec4 x_aniso;
	vec4 x_irid;
	vec4 x_tm[13];
	vec4 x_to[13];
};
struct ExtS { vec3 coat_n; float coat; float coat_r; float trans; float thick; vec3 ta; float aniso; vec3 tb; float f90; vec3 sheen_c; float sheen_r; vec4 rr; };
vec4 ext_map(int i) {
	vec4 o = x_to[i];
	if (o.z < 0.0) return vec4(1.0);
	vec2 u = pick_uv(o.w);
	vec3 c = vec3(dot(x_tm[i].xy, u) + o.x, dot(x_tm[i].zw, u) + o.y, o.z);
	if (i == 1 || i == 10) return smpa(tex_ext_s, c);
	return smpa(tex_ext_l, c);
}
float sheen_e(float n_v, float r) {
	float x = clamp(n_v, 0.0, 1.0) * float(SHEEN_N - 1);
	float y = clamp(r, 0.0, 1.0) * float(SHEEN_N - 1);
	int x0 = min(int(x), SHEEN_N - 2);
	int y0 = min(int(y), SHEEN_N - 2);
	int i = y0 * SHEEN_N + x0;
	return mix(mix(SHEEN_E[i], SHEEN_E[i + 1], x - float(x0)), mix(SHEEN_E[i + SHEEN_N], SHEEN_E[i + SHEEN_N + 1], x - float(x0)), y - float(y0));
}
float vmax3(vec3 c) { return max(c.r, max(c.g, c.b)); }
vec3 sheen_lobe(vec3 n, vec3 v, vec3 l, vec3 e, vec3 c, float r) {
	float n_l = max(dot(n, l), 0.0);
	if (n_l <= 0.0 || vmax3(c) <= 0.0) return vec3(0.0);
	float n_v = max(dot(n, v), 1e-4);
	float n_h = max(dot(n, normalize(v + l)), 0.0);
	float rr = max(r, 0.07);
	float ia = 1.0 / (rr * rr);
	return c * ((2.0 + ia) * pow(max(1.0 - n_h * n_h, 0.0078125), 0.5 * ia) / (2.0 * PI_F)) * min(1.0 / (4.0 * (n_l + n_v - n_l * n_v)), 1.0) * e * n_l;
}
vec3 ext_term(vec3 n, vec3 v, vec3 l, vec3 e, vec3 albedo, vec3 f0, float rough, vec3 ms, vec3 kd, float vis, ExtS x) {
	float n_l = max(dot(n, l), 0.0);
	float n_v = max(dot(n, v), 1e-4);
	vec3 h = normalize(v + l);
	float p5 = pow(1.0 - max(dot(v, h), 0.0), 5.0);
	vec3 rgb = vec3(0.0);
	if (n_l > 0.0) {
		float a = max(rough * rough, 0.002);
		float n_h = max(dot(n, h), 0.0);
		float dg;
		if (x.aniso > 0.0) {
			float at = mix(a, 1.0, x.aniso * x.aniso);
			float th = dot(x.ta, h);
			float bh = dot(x.tb, h);
			float w = (th * th) / (at * at) + (bh * bh) / (a * a) + n_h * n_h;
			float tv = dot(x.ta, v);
			float bv = dot(x.tb, v);
			float tl = dot(x.ta, l);
			float bl = dot(x.tb, l);
			dg = (1.0 / (PI_F * at * a * w * w)) * 0.5 / max(n_l * sqrt(at * at * tv * tv + a * a * bv * bv + n_v * n_v) + n_v * sqrt(at * at * tl * tl + a * a * bl * bl + n_l * n_l), 1e-4);
		} else dg = ggx_d(n_h, a) * smith_g(n_l, n_v, rough) / (4.0 * n_l * n_v + 1e-4);
		rgb = (kd * albedo / PI_F * (1.0 - x.trans) + ms * (f0 + (vec3(x.f90) - f0) * p5) * dg) * e * n_l;
	}
	rgb = rgb * (1.0 - vmax3(x.sheen_c) * sheen_e(n_v, x.sheen_r)) + sheen_lobe(n, v, l, e, x.sheen_c, x.sheen_r);
	if (x.coat > 0.0) {
		float cl = max(dot(x.coat_n, l), 0.0);
		float cv = max(dot(x.coat_n, v), 1e-4);
		float cf = 0.04 + 0.96 * pow(1.0 - cv, 5.0);
		vec3 c = cl > 0.0 ? e * cl * (0.04 + 0.96 * p5) * ggx_d(max(dot(x.coat_n, h), 0.0), max(x.coat_r * x.coat_r, 0.002)) * smith_g(cl, cv, x.coat_r) / (4.0 * cl * cv + 1e-4) : vec3(0.0);
		rgb = rgb * (1.0 - x.coat * cf) + x.coat * c;
	}
	return rgb * vis;
}
vec3 irid_sens(float opd, vec3 shift) {
	float ph = 2.0 * PI_F * opd * 1.0e-9;
	vec3 val = vec3(5.4856e-13, 4.4201e-13, 5.2481e-13);
	vec3 pos = vec3(1.6810e6, 1.7953e6, 2.2084e6);
	vec3 va = vec3(4.3278e9, 9.3046e9, 6.6121e9);
	vec3 xyz = val * sqrt(2.0 * PI_F * va) * cos(pos * ph + shift) * exp(-ph * ph * va);
	xyz.x += 9.7470e-14 * sqrt(2.0 * PI_F * 4.5282e9) * cos(2.2399e6 * ph + shift.x) * exp(-4.5282e9 * ph * ph);
	xyz /= 1.0685e-7;
	return mat3(vec3(3.2404542, -0.9692660, 0.0556434), vec3(-1.5371385, 1.8760108, -0.2040259), vec3(-0.4985314, 0.0415560, 1.0572252)) * xyz;
}
float ior_f0(float a, float b) { float q = (a - b) / (a + b); return q * q; }
vec3 ior_from_f0(vec3 f) { vec3 s = sqrt(clamp(f, vec3(0.0), vec3(0.9999))); return (1.0 + s) / (1.0 - s); }
vec3 irid_f0(float eta2, float cos1, float thick, vec3 base) {
	float top = mix(1.0, eta2, smoothstep(0.0, 0.03, thick));
	float s2 = (1.0 / (top * top)) * (1.0 - cos1 * cos1);
	float c2sq = 1.0 - s2;
	if (c2sq < 0.0) return vec3(1.0);
	float cos2 = sqrt(c2sq);
	float r0 = ior_f0(top, 1.0);
	float x1 = 1.0 - cos1;
	float x15 = x1 * x1 * x1 * x1 * x1;
	float r12 = r0 + (1.0 - r0) * x15;
	float t121 = 1.0 - r12;
	float phi12 = top < 1.0 ? PI_F : 0.0;
	float phi21 = PI_F - phi12;
	vec3 base_ior = ior_from_f0(base);
	vec3 r1 = (base_ior - top) * (base_ior - top) / ((base_ior + top) * (base_ior + top));
	float x2 = 1.0 - cos2;
	float x25 = x2 * x2 * x2 * x2 * x2;
	vec3 r23 = r1 + (1.0 - r1) * x25;
	vec3 phi23 = vec3(base_ior.x < top ? PI_F : 0.0, base_ior.y < top ? PI_F : 0.0, base_ior.z < top ? PI_F : 0.0);
	float opd = 2.0 * top * thick * cos2;
	vec3 phi = vec3(phi21) + phi23;
	vec3 r123 = clamp(r12 * r23, vec3(1e-5), vec3(0.9999));
	vec3 rq = sqrt(r123);
	vec3 rs = t121 * t121 * r23 / (1.0 - r123);
	vec3 i0 = r12 + rs;
	vec3 cm = rs - t121;
	vec3 sum = i0;
	cm *= rq;
	sum += cm * 2.0 * irid_sens(opd, phi);
	cm *= rq;
	sum += cm * 2.0 * irid_sens(2.0 * opd, 2.0 * phi);
	return max(sum, vec3(0.0));
}
