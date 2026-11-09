// Colour pass for glTF metallic-roughness materials.
#include "lighting.glsl"
#include "ms_lut.glsl"
#include "skin_lut.glsl"

layout(location = 0) in vec3 in_world;
layout(location = 1) in vec3 in_nrm;
layout(location = 2) in vec4 in_tan;
layout(location = 3) in vec4 in_uv;
layout(location = 4) in vec4 in_col;
layout(location = 5) in vec4 in_cur;
layout(location = 6) in vec4 in_prev;

layout(set = 2, binding = 0) uniform sampler2D tex_base;
layout(set = 2, binding = 1) uniform sampler2D tex_mr;
layout(set = 2, binding = 2) uniform sampler2D tex_normal;
layout(set = 2, binding = 3) uniform sampler2D tex_occlusion;
layout(set = 2, binding = 4) uniform sampler2D tex_emissive;
layout(set = 2, binding = 5) uniform sampler2DArrayShadow tex_shadow;
layout(set = 2, binding = 6) uniform sampler2D tex_ao;
layout(set = 2, binding = 7) uniform sampler2DArray tex_ext_l;
layout(set = 2, binding = 8) uniform sampler2DArray tex_ext_s;
layout(set = 2, binding = 9) uniform sampler2D tex_trans;
layout(set = 2, binding = 10) uniform sampler2DArray tex_shadow_raw;
layout(set = 2, binding = 11) uniform sampler2DArrayShadow tex_local_shadow;
layout(set = 2, binding = 12) uniform sampler2D tex_bent;
layout(set = 2, binding = 13) uniform sampler2D tex_ssr;
layout(set = 2, binding = 14) uniform sampler2D tex_ssr_prev;
layout(set = 2, binding = 15) uniform samplerCubeArray tex_env;
layout(std430, set = 2, binding = 16) readonly buffer Nodes { vec4 bvh_nodes[]; };
layout(std430, set = 2, binding = 17) readonly buffer Tris { vec4 bvh_tris[]; };
layout(std430, set = 2, binding = 18) readonly buffer Irr { vec4 probe_irr[]; };
layout(std430, set = 2, binding = 19) readonly buffer Dist { vec2 probe_dist[]; };
layout(std430, set = 2, binding = 20) readonly buffer LightRecs { vec4 lrec[]; };
layout(std430, set = 2, binding = 21) readonly buffer LightCells { uint lcell[]; };

const int CASCADES = 3;
const int MAX_LIGHTS = 16;
const int LOCAL_LAYERS = 12;
const int MAX_PROBES = 8;

layout(set = 3, binding = 0) uniform Frame {
	mat4 cascade_mat[CASCADES];
	vec4 cascade_far;     // view-depth end of each cascade, w = shadow texel size
	vec4 eye;             // xyz camera position, w = 1 when screen-space AO is bound
	vec4 view_dir;        // xyz camera forward
	vec4 to_sun;          // xyz unit vector toward the sun, w = 1 casts shadows
	vec4 sun_rgb;         // rgb irradiance
	vec4 zenith;          // sky colours (also the ambient light)
	vec4 horizon;
	vec4 ground;
	vec4 screen;          // xy 1 / target size, z light count, w ambient scale
	vec4 light_pos[MAX_LIGHTS];   // xyz position, w range
	vec4 light_rgb[MAX_LIGHTS];   // rgb intensity, w kind (0 point; spot reserved)
	vec4 gi;
	vec4 gi_origin;
	vec4 gi_step;
	vec4 gi_dims;
	vec4 light_dir[MAX_LIGHTS];
	vec4 light_shd[MAX_LIGHTS];
	mat4 local_mat[LOCAL_LAYERS];
	vec4 refl;
	mat4 view_m;
	vec4 env;
	vec4 env_rot;
	mat4 vp;
	vec4 cluster;
	vec4 cluster2;
	vec4 probe_n;
	vec4 probe_pos[MAX_PROBES];
	vec4 probe_lo[MAX_PROBES];
	vec4 probe_hi[MAX_PROBES];
};
#include "gi.glsl"

layout(set = 3, binding = 1) uniform Surface {
	vec4 base;            // base colour factor
	vec4 emissive;        // rgb emissive (strength applied), w unlit
	vec4 params;          // x metallic, y roughness, z normal scale, w occlusion strength
	vec4 alpha;           // x mode (0 opaque, 1 mask, 2 blend), y cutoff, z double sided
	vec4 uv_sets;         // which UV set each texture reads: base, mr, normal, occlusion
	vec4 uv_sets2;        // x emissive, y debug view (see scene3d.debug_view), z multiscatter on + 2 * furnace control mode, w furnace control scale
	vec4 tri;             // x world triplanar tiles per unit (0 = mesh UVs), y top layer coverage, z top layer tiles per unit, w top edge sharpness
	vec4 top_tint;        // top layer colour factor
	vec4 xm_base;
	vec4 xm_mr;
	vec4 xm_nrm;
	vec4 xm_occ;
	vec4 xm_emi;
	vec4 xo0;
	vec4 xo1;
	vec4 xo2;
	vec4 sheen;
	vec4 misc;
	vec4 shade_a;
	vec4 shade_b;
	vec4 shade_c;
	vec4 xm_det;
	vec4 xo_det;
	vec4 top_lay;
};

layout(location = 0) out vec4 out_rgba;

vec2 pom_off = vec2(0.0);
vec2 pick_uv(float set) { return (set > 0.5 ? in_uv.zw : in_uv.xy) + pom_off; }
vec2 water_grad(vec2 p, float tm) {
	vec2 g = vec2(0.0);
	vec2 q = p;
	float f = shade_b.x;
	float a = shade_b.y;
	float ang = 0.7;
	for (int i = 0; i < 11; i++) {
		vec2 d = vec2(cos(ang), sin(ang));
		float ph = dot(q, d) * f + tm * sqrt(9.81 * f) * shade_b.z;
		g += d * a * cos(ph);
		q += d * sin(ph) * a / f * 0.5;
		f *= 1.31;
		a *= 0.87;
		ang += 2.4;
	}
	return g;
}
#include "ext.glsl"
vec3 sheen_term(vec3 n, vec3 v, vec3 l, vec3 e) { return sheen_lobe(n, v, l, e, sheen.rgb, sheen.a); }
float sheen_keep() { return 1.0 - max(max(sheen.r, sheen.g), sheen.b) * 0.17; }
vec2 xuv(float set, vec4 m, vec2 o) { vec2 u = pick_uv(set); return vec2(dot(m.xy, u), dot(m.zw, u)) + o; }
struct Mat { vec3 nm; vec3 gn; float curv; float thick; float cav; };
float skin_lut(float c, float s) {
	float x = clamp(c * 0.5 + 0.5, 0.0, 1.0) * float(SKIN_T - 1);
	float y = sqrt(clamp(s, 0.0, 1.0)) * float(SKIN_S - 1);
	int x0 = min(int(x), SKIN_T - 2);
	int y0 = min(int(y), SKIN_S - 2);
	int i = y0 * SKIN_T + x0;
	return mix(mix(SKIN_D[i], SKIN_D[i + 1], x - float(x0)), mix(SKIN_D[i + SKIN_T], SKIN_D[i + SKIN_T + 1], x - float(x0)), y - float(y0));
}
vec3 skin_trans(float t, vec3 d) { return 0.25 * (exp(-t / d) + 3.0 * exp(-t / (3.0 * d))); }
vec3 mat_term(vec3 n, vec3 v, vec3 l, vec3 e, vec3 albedo, vec3 f0, float rough, vec3 ms, vec3 kd, float vis, Mat q, ExtS x) {
	if (misc.z > 0.5) return ext_term(n, v, l, e, albedo, f0, rough, ms, kd, vis, x);
	int model = int(misc.y + 0.5);
	if (model == 1) {
		vec3 d = max(shade_a.rgb, vec3(1e-5));
		vec3 s = d * q.curv;
		vec3 nr = normalize(mix(q.nm, q.gn, shade_c.w));
		vec3 sv = pow(vec3(clamp(vis, 0.0, 1.0)), mix(vec3(1.0), d.r / d, 0.15));
		vec3 dif = vec3(skin_lut(dot(nr, l), s.r), skin_lut(dot(q.nm, l), s.g), skin_lut(dot(q.nm, l), s.b));
		vec3 spec = mix(light_term(n, v, l, e, vec3(0.0), f0, rough, ms, kd), light_term(n, v, l, e, vec3(0.0), f0, clamp(rough * shade_b.w, 0.03, 1.0), ms, kd), shade_b.z) * q.cav;
		vec3 tr = skin_trans(q.thick, d) * clamp((0.1 - dot(q.gn, l)) / 1.1, 0.0, 1.0) * shade_a.w;
		return (kd * albedo / PI_F * (dif * sv * mix(1.0, q.cav, 0.5) + tr)) * e + spec * vis;
	}
	if (model == 2) {
		float w = shade_c.w;
		vec3 dif = kd * albedo / PI_F * clamp((dot(n, l) + w) / (1.0 + w), 0.0, 1.0) * e;
		vec3 spec = light_term(n, v, l, e, vec3(0.0), f0, rough, ms, kd) + shade_b.z * light_term(q.gn, v, l, e, vec3(0.0), vec3(0.02), shade_b.w, vec3(1.0), kd);
		return (dif + spec) * vis;
	}
	if (model == 3) {
		float w = shade_a.x;
		float nl = dot(n, l);
		vec3 dif = kd * albedo / PI_F * clamp((nl + w) / (1.0 + w), 0.0, 1.0) * e;
		vec3 fz = sheen.rgb * e * shade_a.y * pow(1.0 - max(dot(n, v), 0.0), 3.0) * clamp((nl + 0.5) / 1.5, 0.0, 1.0);
		return ((dif + shade_a.z * light_term(n, v, l, e, vec3(0.0), f0, rough, ms, kd)) * sheen_keep() + sheen_term(n, v, l, e) + fz) * vis * q.cav;
	}
	return (light_term(n, v, l, e, albedo, f0, rough, ms, kd) * sheen_keep() + sheen_term(n, v, l, e)) * vis;
}
vec2 eye_uv(vec2 uv, vec3 v, vec3 n) {
	vec3 dpx = dFdx(in_world);
	vec3 dpy = dFdy(in_world);
	vec2 dux = dFdx(uv);
	vec2 duy = dFdy(uv);
	float det = dux.x * duy.y - duy.x * dux.y;
	float inv = abs(det) > 1e-20 ? 1.0 / det : 0.0;
	vec3 tu = (dpx * duy.y - dpy * dux.y) * inv;
	vec3 bv = (dpy * dux.x - dpx * duy.x) * inv;
	vec2 c = distance(uv, shade_a.xy) < distance(uv, shade_a.zw) ? shade_a.xy : shade_a.zw;
	float r = distance(uv, c) / max(shade_c.x, 1e-4);
	vec3 rr = refract(-v, n, 1.0 / 1.376);
	vec3 off = rr * (shade_c.y * max(1.0 - r * r, 0.0) / max(dot(-rr, n), 0.2));
	vec2 o = vec2(dot(off, tu) / max(dot(tu, tu), 1e-12), dot(off, bv) / max(dot(bv, bv), 1e-12));
	return r < 1.0 ? uv + o : uv;
}
float eye_ring(vec2 uv) {
	vec2 c = distance(uv, shade_a.xy) < distance(uv, shade_a.zw) ? shade_a.xy : shade_a.zw;
	float r = distance(uv, c) / max(shade_c.x, 1e-4);
	return 1.0 - shade_c.z * smoothstep(0.72, 0.98, r) * (1.0 - smoothstep(0.98, 1.18, r));
}

// Single-scatter directional albedo of the specular lobe from ms_lut.glsl (16-bit
// unorm pairs), bilinear (columns are sqrt(n.v), rows roughness): x = E(n.v, rough)
// with Fresnel = 1, y = B, the part of E carried by Schlick's (1 - v.h)^5 term.
vec2 ms_lut(float n_v, float rough) {
	float x = sqrt(clamp(n_v, 0.0, 1.0)) * float(MS_N - 1);
	float y = clamp(rough, 0.0, 1.0) * float(MS_N - 1);
	int x0 = min(int(x), MS_N - 2);
	int y0 = min(int(y), MS_N - 2);
	float fx = x - float(x0);
	float fy = y - float(y0);
	int i = y0 * MS_N + x0;
	vec2 a = mix(unpackUnorm2x16(MS_EB[i]), unpackUnorm2x16(MS_EB[i + 1]), fx);
	vec2 b = mix(unpackUnorm2x16(MS_EB[i + MS_N]), unpackUnorm2x16(MS_EB[i + MS_N + 1]), fx);
	return mix(a, b, fy);
}

// E for the compensation only, with a silhouette cap: where sqrt(n.v) (MS_N - 1) < 3 (n.v
// below about 0.0094) E falls steeply toward grazing and bilinear interpolation between
// nodes undershoots it, so 1 / E would overshoot (white metals gained up to 5.4 %); there
// the largest E of the four corners is used, which can only lower the gain. The diffuse
// weight keeps the bilinear (E, B). make_ms_lut's check 2 replays this exactly.
float ms_e(float n_v, float rough, float e) {
	float x = sqrt(clamp(n_v, 0.0, 1.0)) * float(MS_N - 1);
	if (x >= 3.0) return e;
	float y = clamp(rough, 0.0, 1.0) * float(MS_N - 1);
	int x0 = min(int(x), MS_N - 2);
	int y0 = min(int(y), MS_N - 2);
	int i = y0 * MS_N + x0;
	float a = max(unpackUnorm2x16(MS_EB[i]).x, unpackUnorm2x16(MS_EB[i + 1]).x);
	float b = max(unpackUnorm2x16(MS_EB[i + MS_N]).x, unpackUnorm2x16(MS_EB[i + MS_N + 1]).x);
	return max(a, b);
}

// Multiple-scattering compensation for the specular lobe. A white (F = 1) lobe reflects
// E of the incoming energy after one bounce; the rest would leave after further bounces
// between microfacets, so the lobe is scaled by 1 + F0 (1 / E - 1), which brings a white
// conductor back to 1 and leaves a low-F0 dielectric almost unchanged. E is floored at
// 0.25, which caps the factor at 1 + 3 F0 where the table's E is tiny: the floor limits
// how much lost energy is put back (a loss), it does not bound a gain. The gain is
// bounded by make_ms_lut's check 2 with the cap in ms_e(): below 3 % at every n.v.
vec3 ms_factor(vec3 f0, float e, bool on) {
	if (!on) return vec3(1.0);
	return 1.0 + f0 * (1.0 / max(e, 0.25) - 1.0);
}

// Diffuse weight per view direction: the energy the (compensated) specular lobe does not
// reflect. Its Fresnel-weighted albedo is E_F = F0 (E - B) + B (a scale / bias split of
// the directional albedo), and with compensation the lobe returns ms E_F = E_F + E_ms,
// so the diffuse lobe gets 1 - ms E_F. This is the directional-albedo energy coupling of
// Fdez-Aguera 2019 ("A Multiple-Scattering Microfacet Model for Real-Time Image-based
// Lighting"), applied here to direct lights. Weighting by 1 - F(v.h) per light instead
// lets rough dielectrics exceed 1 near grazing (kept only as a furnace control).
vec3 diffuse_weight(vec3 f0, vec2 eb, vec3 ms) {
	return max(1.0 - ms * (f0 * (eb.x - eb.y) + eb.y), vec3(0.0));
}

vec2 vogel(int i, int k, float rot) { float a = float(i) * 2.39996323 + rot; return vec2(cos(a), sin(a)) * sqrt((float(i) + 0.5) / float(k)); }
float sun_pcss(vec2 uv, float zd, int c, float row0, vec3 n) {
	float texel = cascade_far.w;
	float zr = min(zd, 0.99999);
	vec3 rx = vec3(cascade_mat[c][0][0], cascade_mat[c][1][0], cascade_mat[c][2][0]);
	vec3 ry = vec3(cascade_mat[c][0][1], cascade_mat[c][1][1], cascade_mat[c][2][1]);
	vec3 rz = vec3(cascade_mat[c][0][2], cascade_mat[c][1][2], cascade_mat[c][2][2]);
	float zs = length(rz);
	vec3 nn = vec3(dot(rx, n) / dot(rx, rx), dot(ry, n) / dot(ry, ry), dot(rz, n) / dot(rz, rz));
	vec2 g = vec2(-2.0 * nn.x, 2.0 * nn.y) / (abs(nn.z) > 1e-7 ? nn.z : 1e-7);
	float gm = 10.0 * zs / row0;
	g *= min(1.0, gm / max(length(g), 1e-9));
	float tn = view_dir.w;
	float rs = max(tn * min(sun_rgb.w, zr / zs) * row0 * 0.5, 2.0 * texel);
	float rot = gi.w > 0.5 ? 6.2831853 * fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)))) : 0.0;
	float bias = zs * texel / row0 + 2e-6;
	ivec2 dim = ivec2(textureSize(tex_shadow_raw, 0).xy) - 1;
	float zb = 0.0, nb = 0.0;
	float kw = tn * row0 * 0.5 / zs;
	float r0 = 0.5 * texel;
	for (int i = 0; i < 32; i++) {
		vec2 o = vogel(i, 32, rot) * (i == 0 ? 0.0 : r0 * pow(max(rs / r0, 1.0), float(i) / 31.0) / sqrt((float(i) + 0.5) / 32.0));
		float d = texelFetch(tex_shadow_raw, ivec3(clamp(ivec2((uv + o) / texel), ivec2(0), dim), c), 0).r;
		float zt = min(zr + dot(g, o), 0.99999) - bias;
		float w = d < zt ? clamp(2.0 - 2.0 * length(o) / max((zt - d) * kw, 1.5 * texel), 0.0, 1.0) : 0.0;
		zb += w * d;
		nb += w;
	}
	if (nb < 1e-3) return 1.0;
	float rf = clamp((zr - zb / nb) * kw, texel, rs);
	float lit = 0.0;
	for (int i = 0; i < 28; i++) {
		vec2 o = vogel(i, 28, rot + 1.3) * rf;
		lit += texture(tex_shadow, vec4(uv + o, float(c), min(zr + dot(g, o), 0.99999) - bias));
	}
	return mix(1.0, lit / 28.0, clamp(nb, 0.0, 1.0));
}
float local_visibility(vec4 sh, vec3 lp, vec3 ldir, vec3 p, vec3 n) {
	if (sh.x < 0.0) return 1.0;
	vec3 d = p - lp;
	vec3 a = abs(d);
	int f = sh.y > 1.5 ? (a.x >= a.y && a.x >= a.z ? (d.x > 0.0 ? 0 : 1) : (a.y >= a.z ? (d.y > 0.0 ? 2 : 3) : (d.z > 0.0 ? 4 : 5))) : 0;
	int layer = int(sh.x) + f;
	float dist = sh.y > 1.5 ? max(a.x, max(a.y, a.z)) : max(dot(d, ldir), 1e-3);
	float off = 1.5 * sh.z * dist;
	vec4 s = local_mat[layer] * vec4(p + n * off - d / max(length(d), 1e-4) * off, 1.0);
	if (s.w <= 0.0) return 1.0;
	vec3 ndc = s.xyz / s.w;
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	float texel = 1.0 / float(textureSize(tex_local_shadow, 0).x);
	float rot = gi.w > 0.5 ? 6.2831853 * fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)))) : 0.0;
	float lit = 0.0;
	for (int k = 0; k < 12; k++) lit += texture(tex_local_shadow, vec4(uv + vogel(k, 12, rot) * (sh.w * texel), float(layer), ndc.z));
	return lit / 12.0;
}
float mr_grain(vec3 p) { vec3 r = fract(floor(p * 7.0) * 0.1031); r += dot(r, r.zyx + 31.32); return fract((r.x + r.y) * r.z); }
float spot_cone(float inner, float co, vec3 ldir, vec3 ld) {
	return co < -1.5 ? 1.0 : smoothstep(co, inner - 1.0, dot(-ld, ldir));
}
float sun_visibility(vec3 p, vec3 n) {
	if (to_sun.w < 0.5) return 1.0;
	float depth = dot(p - eye.xyz, view_dir.xyz);
	int c = 0;
	if (depth > cascade_far.x) c = 1;
	if (depth > cascade_far.y) c = 2;
	if (depth > cascade_far.z) return 1.0;
	// offset along the normal by 1.5 shadow-map texels of the chosen cascade: the
	// cascade's projection maps world x to ndc x with scale |row 0| = 1 / half width,
	// so one texel (uv size 1 / map size) spans 2 / (|row 0| * map size) world units
	float texel = cascade_far.w;
	float row0 = length(vec3(cascade_mat[c][0][0], cascade_mat[c][1][0], cascade_mat[c][2][0]));
	vec3 q = p + n * (1.5 * 2.0 * texel / row0);
	vec4 s = cascade_mat[c] * vec4(q, 1.0);
	vec3 ndc = vec3(s.xy / s.w, min(s.z / s.w, 0.99999));
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	if (view_dir.w > 0.0) return sun_pcss(uv, ndc.z, c, row0, n);
	float lit = 0.0;
	// to_sun.w - 1 = penumbra radius in world units: rotated Poisson taps, the noise left to TAA
	float soft = to_sun.w - 1.0;
	if (soft > 0.0) {
		const vec2 pd[12] = vec2[](vec2(-0.326, -0.406), vec2(-0.840, -0.074), vec2(-0.696, 0.457), vec2(-0.203, 0.621), vec2(0.962, -0.195), vec2(0.473, -0.480),
			vec2(0.519, 0.767), vec2(0.185, -0.893), vec2(0.507, 0.064), vec2(0.896, 0.412), vec2(-0.322, -0.933), vec2(-0.792, -0.598));
		float ruv = max(soft * row0 * 0.5, 1.5 * texel);
		float ang = 6.2831853 * fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715))));
		mat2 rot = mat2(cos(ang), sin(ang), -sin(ang), cos(ang));
		float bias = 0.0008 * (1.0 + 0.25 * ruv / texel);
		for (int i = 0; i < 12; i++) lit += texture(tex_shadow, vec4(uv + rot * pd[i] * ruv, float(c), ndc.z - bias));
		return lit / 12.0;
	}
	for (int y = -1; y <= 1; y++)
		for (int x = -1; x <= 1; x++)
			lit += texture(tex_shadow, vec4(uv + vec2(x, y) * texel, float(c), ndc.z - 0.0008));
	return lit / 9.0;
}

float so_lag(float n_v, float ao, float a) { return clamp(pow(n_v + ao, exp2(-16.0 * a - 1.0)) - 1.0 + ao, 0.0, 1.0); }
float spec_occ(vec3 r, float n_v, float rough, vec3 gn, float occ, float aos, float occm) {
	if (refl.y < 0.5) return occ;
	float a = rough * rough;
	float hz = clamp(1.0 + dot(r, gn), 0.0, 1.0);
	float s = so_lag(n_v, aos, a);
	if (refl.y > 1.5) {
		vec4 bw = texelFetch(tex_bent, ivec2(gl_FragCoord.xy), 0);
		vec3 bn = normalize((vec4(bw.xyz, 0.0) * view_m).xyz);
		float av = acos(sqrt(clamp(1.0 - bw.w, 0.0, 1.0)));
		float as_ = 2.0 * atan(a);
		float d = acos(clamp(dot(bn, r), -1.0, 1.0));
		float lo = abs(av - as_);
		float sm = sin(min(av, as_));
		float ss = sin(as_);
		s = clamp(sm * sm / max(ss * ss, 1e-4) * (1.0 - smoothstep(0.0, 1.0, clamp((d - lo) / max(av + as_ - lo, 1e-4), 0.0, 1.0))), 0.0, 1.0);
	}
	return s * so_lag(n_v, occm, a) * hz * hz;
}
vec4 amb_lobe(vec3 nn, vec3 v, vec3 l, float rough, vec3 irr, vec3 gi_irr, bool use_gi, vec3 gn, vec3 oc, vec4 sr) {
	float n_v = max(dot(nn, v), 1e-4);
	vec3 r = reflect(-v, nn);
	vec3 env = mix(use_gi ? gi_irr : sky_color(r, l, zenith.rgb, horizon.rgb, ground.rgb, vec3(0.0)), irr, rough * rough) * spec_occ(r, n_v, rough, gn, oc.x, oc.y, oc.z);
	float w = sr.w * (1.0 - smoothstep(0.7 * refl.z, refl.z, rough));
	vec3 hit = w > 0.0 ? textureLod(tex_ssr_prev, sr.xy, log2(max(2.0 * rough * rough * sr.z * refl.w, 1.0))).rgb : vec3(0.0);
	float sw = (1.0 - rough) * (1.0 - rough);
	return vec4(mix(env, hit, w), pow(1.0 - n_v, 5.0) * sw);
}
vec3 ambient_light(vec3 n, vec3 v, vec3 l, vec3 base_rgb, float metal, float rough, vec3 gi_irr, bool use_gi, vec3 gn, vec3 oc, float dao, vec4 sr, Mat q) {
	int model = int(misc.y + 0.5);
	vec3 irr = mix(ground.rgb, zenith.rgb, n.y * 0.5 + 0.5);
	irr = mix(irr, horizon.rgb, 0.5 * (1.0 - abs(n.y)));
	if (use_gi) irr = gi_irr;
	vec4 e = amb_lobe(n, v, l, rough, irr, gi_irr, use_gi, gn, oc, sr);
	float f0d = model == 1 ? shade_c.x : 0.04;
	float fd = f0d + (1.0 - f0d) * e.w;
	vec3 spec = fd * e.rgb;
	if (model == 1) {
		vec4 e2 = amb_lobe(n, v, l, clamp(rough * shade_b.w, 0.03, 1.0), irr, gi_irr, use_gi, gn, oc, sr);
		spec = mix(spec, (f0d + (1.0 - f0d) * e2.w) * e2.rgb, shade_b.z);
	}
	if (model == 2) {
		vec4 ec = amb_lobe(q.gn, v, l, shade_b.w, irr, gi_irr, use_gi, gn, oc, sr);
		spec += shade_b.z * (0.02 + 0.98 * ec.w) * ec.rgb;
	}
	vec3 fm = base_rgb + (1.0 - base_rgb) * e.w;
	vec3 dielectric = base_rgb * (1.0 - fd) * irr * dao + spec;
	return mix(dielectric, fm * e.rgb, metal);
}
vec3 env_dir(vec3 d) { return vec3(env_rot.x * d.x + env_rot.y * d.z, d.y, env_rot.x * d.z - env_rot.y * d.x); }
vec4 probe_mix(vec3 d, float lod, bool par) {
	vec3 acc = vec3(0.0);
	float rest = 1.0;
	int np = int(probe_n.x + 0.5);
	for (int i = 0; i < MAX_PROBES; i++) {
		if (i >= np || rest < 0.004) break;
		vec3 lo = probe_lo[i].xyz;
		vec3 hi = probe_hi[i].xyz;
		vec3 a = in_world - lo;
		vec3 b = hi - in_world;
		float w = clamp(1.0 + min(min(min(a.x, a.y), a.z), min(min(b.x, b.y), b.z)) / probe_lo[i].w, 0.0, 1.0) * rest;
		if (w <= 0.0) continue;
		vec3 dd = d;
		if (par && probe_n.z > 0.5) {
			vec3 ds = vec3(abs(d.x) < 1e-5 ? 1e-5 : d.x, abs(d.y) < 1e-5 ? 1e-5 : d.y, abs(d.z) < 1e-5 ? 1e-5 : d.z);
			vec3 tf = max((hi - in_world) / ds, (lo - in_world) / ds);
			dd = in_world + d * max(min(min(tf.x, tf.y), tf.z), 0.0) - probe_pos[i].xyz;
		}
		acc += w * textureLod(tex_env, vec4(dd, float(i + 1)), lod).rgb;
		rest -= w;
	}
	return vec4(acc * probe_n.y, rest);
}
vec3 env_irr(vec3 n) {
	vec3 s = env.x > 0.5 ? textureLod(tex_env, vec4(env_dir(n), 0.0), env.w).rgb * env.y : mix(mix(ground.rgb, zenith.rgb, n.y * 0.5 + 0.5), horizon.rgb, 0.5 * (1.0 - abs(n.y))) * screen.w;
	if (probe_n.x < 0.5) return s;
	vec4 p = probe_mix(n, env.w, false);
	return p.rgb + s * p.w;
}
vec3 env_lobe(vec3 nn, vec3 v, float rough, vec3 gn, vec3 oc, vec4 sr) {
	vec3 r = reflect(-v, nn);
	vec3 d = normalize(mix(r, nn, rough * rough));
	vec3 e = env.x > 0.5 ? textureLod(tex_env, vec4(env_dir(d), 0.0), rough * env.z).rgb * env.y : mix(sky_color(d, normalize(to_sun.xyz), zenith.rgb, horizon.rgb, ground.rgb, vec3(0.0)), env_irr(nn), rough * rough) * screen.w;
	if (probe_n.x > 0.5) {
		vec4 p = probe_mix(d, rough * env.z, true);
		e = p.rgb + e * p.w;
	}
	e *= spec_occ(r, max(dot(nn, v), 1e-4), rough, gn, oc.x, oc.y, oc.z);
	float w = sr.w * (1.0 - smoothstep(0.7 * refl.z, refl.z, rough));
	return w > 0.0 ? mix(e, textureLod(tex_ssr_prev, sr.xy, log2(max(2.0 * rough * rough * sr.z * refl.w, 1.0))).rgb, w) : e;
}
vec3 env_ef(vec3 f0, float f90, vec2 eb, vec3 ms) { return ms * (f0 * (eb.x - eb.y) + f90 * eb.y); }
vec3 transmitted(vec3 n, vec3 v, float rough, vec3 tint, vec3 ef, ExtS x) {
	vec3 ray = refract(-v, n, 1.0 / x_ior.x) * x.thick * misc.w;
	vec4 c = vp * vec4(in_world + ray, 1.0);
	vec2 uv = clamp(vec2(c.x / c.w * 0.5 + 0.5, 0.5 - c.y / c.w * 0.5), vec2(0.0), vec2(1.0));
	float lw = log2(float(textureSize(tex_trans, 0).x));
	float lod = min(lw * rough * clamp(x_ior.x * 2.0 - 2.0, 0.0, 1.0), lw - 4.0);
	vec3 att = x_trans.z > 0.0 ? exp(log(max(x_atten.rgb, vec3(1e-4))) / x_trans.z * length(ray)) : vec3(1.0);
	return (1.0 - ef) * textureLod(tex_trans, uv, lod).rgb * att * tint;
}
vec3 ambient_env(vec3 n, vec3 v, vec3 base_rgb, vec3 albedo, vec3 f0, float rough, vec2 eb, vec3 ms, vec3 kd, vec3 gi_irr, bool use_gi, vec3 gn, vec3 oc, vec4 sr, Mat q, ExtS x) {
	int model = int(misc.y + 0.5);
	float dao = oc.x;
	float n_v = max(dot(n, v), 1e-4);
	vec3 irr = use_gi ? gi_irr : env_irr(n);
	vec3 nb = n;
	if (x.aniso > 0.0) nb = normalize(mix(normalize(cross(cross(x.tb, v), x.tb)), n, pow(1.0 - x.aniso * (1.0 - rough), 4.0)));
	vec3 ef = env_ef(f0, x.f90, eb, ms);
	vec3 spec = env_lobe(nb, v, rough, gn, oc, sr) * ef;
	if (model == 1) {
		float r2 = clamp(rough * shade_b.w, 0.03, 1.0);
		spec = mix(spec, env_lobe(n, v, r2, gn, oc, sr) * env_ef(f0, 1.0, ms_lut(n_v, r2), ms), shade_b.z);
	}
	if (model == 2) spec += shade_b.z * env_lobe(q.gn, v, shade_b.w, gn, oc, sr) * env_ef(vec3(0.02), 1.0, ms_lut(max(dot(q.gn, v), 1e-4), shade_b.w), vec3(1.0));
	vec3 rgb = albedo * max(kd, vec3(0.0)) * irr * dao * (1.0 - x.trans) + spec;
	if (x.trans > 0.0) rgb += x.trans * transmitted(n, v, rough, base_rgb, ef, x);
	float sm = vmax3(x.sheen_c);
	if (sm > 0.0) rgb = rgb * (1.0 - sm * sheen_e(n_v, x.sheen_r)) + x.sheen_c * sheen_e(n_v, x.sheen_r) * irr * dao;
	if (x.coat > 0.0) {
		float cv = max(dot(x.coat_n, v), 1e-4);
		rgb = rgb * (1.0 - x.coat * (0.04 + 0.96 * pow(1.0 - cv, 5.0))) + x.coat * env_lobe(x.coat_n, v, x.coat_r, gn, oc, sr) * env_ef(vec3(0.04), 1.0, ms_lut(cv, x.coat_r), vec3(1.0));
	}
	return rgb;
}

void main() {
	float cst = eye.w > 1.5 ? texture(tex_ao, gl_FragCoord.xy * screen.xy).g : 1.0;
	if (misc.x > 0.0) { out_rgba = vec4(0.0, 0.0, 0.0, misc.x * (1.0 - sun_visibility(in_world, normalize(in_nrm)) * cst)); return; }
	int model = int(misc.y + 0.5);
	bool is_water = model == 4;
	if (is_water) model = 0;
	if (misc.z > 0.5 && x_to[12].z >= 0.0 && x_ior.z > 0.0 && abs(in_tan.w) > 0.5) {
		vec3 nw = normalize(in_nrm);
		vec3 vw = normalize(eye.xyz - in_world);
		vec3 tw0 = normalize(in_tan.xyz - nw * dot(nw, in_tan.xyz));
		vec3 bw0 = cross(nw, tw0) * in_tan.w;
		vec3 vt = vec3(dot(vw, tw0), dot(vw, bw0), max(dot(vw, nw), 0.08));
		vec2 u0 = pick_uv(x_to[12].w);
		vec2 uh = vec2(dot(x_tm[12].xy, u0) + x_to[12].x, dot(x_tm[12].zw, u0) + x_to[12].y);
		float hlod = max(log2(max(length(fwidth(uh)) * float(textureSize(tex_ext_l, 0).x), 1.0)), 0.0);
		int st = int(mix(40.0, 10.0, vt.z));
		float ds = 1.0 / float(st);
		vec2 du = vec2(-vt.x, vt.y) / vt.z * x_ior.z * ds;
		vec2 off = vec2(0.0);
		float dep = 0.0;
		float hd = 1.0 - textureLod(tex_ext_l, vec3(uh, x_to[12].z), hlod).r;
		float pd = hd;
		for (int i = 0; i < st; i++) {
			if (dep >= hd) break;
			off += du;
			dep += ds;
			pd = hd;
			hd = 1.0 - textureLod(tex_ext_l, vec3(uh + off, x_to[12].z), hlod).r;
		}
		float ga = hd - dep;
		float gb = pd - (dep - ds);
		pom_off = off - du * clamp(ga / min(ga - gb, -1e-5), 0.0, 1.0);
	}
	vec2 buv = xuv(uv_sets.x, xm_base, xo0.xy);
	if (model == 2) buv = eye_uv(buv, normalize(eye.xyz - in_world), normalize(in_nrm));
	vec4 tint = base * in_col * texture(tex_base, buv);
	if (model == 2) tint.rgb *= eye_ring(buv);
	// world-aligned layers: triplanar base and a top layer on up-facing surfaces
	vec3 gw = normalize(in_nrm);
	bool tp = tri.x > 0.0;
	vec3 tw = pow(abs(gw), vec3(4.0));
	tw /= tw.x + tw.y + tw.z;
	vec2 ux = in_world.zy * tri.x;
	vec2 uy = in_world.xz * tri.x;
	vec2 uz = in_world.xy * tri.x;
	vec2 ut = in_world.xz * tri.z;
	if (tp) tint = base * in_col * (texture(tex_base, ux) * tw.x + texture(tex_base, uy) * tw.y + texture(tex_base, uz) * tw.z);
	float topf = 0.0;
	if (tri.y > 0.0) {
		vec4 tc = top_tint * texture(tex_ext_s, vec3(ut, top_lay.x));
		float hb = dot(tc.rgb - tint.rgb, vec3(0.333)) * 1.5;
		topf = clamp((gw.y - 1.0 + tri.y + hb * 0.25) * tri.w, 0.0, 1.0) * in_col.a;
		tint = mix(tint, vec4(tc.rgb, tint.a), topf);
	}
	if (alpha.x > 0.5 && alpha.x < 1.5 && tint.a < alpha.y) discard;
	if (emissive.w > 0.5) { out_rgba = vec4(tint.rgb, alpha.x > 1.5 ? tint.a : 1.0); return; }

	vec3 n = normalize(in_nrm);
	if (!gl_FrontFacing && alpha.z > 0.5) n = -n;

	// tangent frame: from the vertex tangent, or from screen derivatives when absent
	vec3 t;
	vec3 b;
	vec2 uvn = xuv(uv_sets.z, xm_nrm, xo1.xy);
	if (abs(in_tan.w) > 0.5) {
		t = normalize(in_tan.xyz - n * dot(n, in_tan.xyz));
		b = cross(n, t) * in_tan.w;
	} else {
		// solve dP = T du + Bv dv on the pixel footprint; glTF's bitangent points
		// toward decreasing v (up in the image), so B = -Bv
		vec3 dpx = dFdx(in_world);
		vec3 dpy = dFdy(in_world);
		vec2 dux = dFdx(uvn);
		vec2 duy = dFdy(uvn);
		float det = dux.x * duy.y - duy.x * dux.y;
		float inv = abs(det) > 1e-20 ? 1.0 / det : 0.0;
		vec3 tu = (dpx * duy.y - dpy * dux.y) * inv;
		vec3 bv = (dpy * dux.x - dpx * duy.x) * inv;
		t = tu - n * dot(n, tu);
		t = dot(t, t) > 1e-16 ? normalize(t) : normalize(cross(abs(n.y) < 0.99 ? vec3(0.0, 1.0, 0.0) : vec3(1.0, 0.0, 0.0), n));
		b = cross(n, t) * (dot(cross(n, t), -bv) < 0.0 ? -1.0 : 1.0);
	}
	if (is_water) {
		vec2 wg = water_grad(in_world.xz, cluster.w);
		n = normalize(n + vec3(-wg.x, 0.0, -wg.y));
		t = normalize(t - n * dot(n, t));
		b = cross(n, t) * (dot(cross(n, t), b) < 0.0 ? -1.0 : 1.0);
	}
	vec3 n0 = n;
	vec3 tn = texture(tex_normal, uvn).xyz * 2.0 - 1.0;
	float tl = length(tn);
	tn.xy *= params.z;
	n = normalize(mat3(t, b, n) * tn);
	vec4 mr = texture(tex_mr, xuv(uv_sets.y, xm_mr, xo0.zw));
	if (tp) {
		vec3 nx = texture(tex_normal, ux).xyz * 2.0 - 1.0;
		vec3 ny = texture(tex_normal, uy).xyz * 2.0 - 1.0;
		vec3 nz = texture(tex_normal, uz).xyz * 2.0 - 1.0;
		nx.xy *= params.z; ny.xy *= params.z; nz.xy *= params.z;
		nx = vec3(nx.xy + gw.zy, abs(nx.z) * gw.x);
		ny = vec3(ny.xy + gw.xz, abs(ny.z) * gw.y);
		nz = vec3(nz.xy + gw.xy, abs(nz.z) * gw.z);
		n = normalize(nx.zyx * tw.x + ny.xzy * tw.y + nz.xyz * tw.z);
		if (!gl_FrontFacing && alpha.z > 0.5) n = -n;
		mr = texture(tex_mr, ux) * tw.x + texture(tex_mr, uy) * tw.y + texture(tex_mr, uz) * tw.z;
	}
	if (topf > 0.0) {
		vec3 nt = texture(tex_ext_l, vec3(ut, top_lay.z)).xyz * 2.0 - 1.0;
		nt = normalize(vec3(nt.x + gw.x, abs(nt.z) * gw.y, nt.y + gw.z));
		n = normalize(mix(n, nt, topf));
		mr = mix(mr, texture(tex_ext_l, vec3(ut, top_lay.y)), topf);
	}
	vec3 nm = n;
	vec4 dt = texture(tex_ext_l, vec3(xuv(uv_sets.x, xm_det, xo_det.xy), top_lay.w));
	float dmask = model == 1 ? mr.b : 1.0;
	float dcurv = length(fwidth(normalize(in_nrm))) / max(length(fwidth(in_world)), 1e-6);
	Mat q = Mat(nm, normalize(in_nrm), in_uv.z > 0.0 ? max(in_uv.z, 0.0) : dcurv, in_uv.z > 0.0 ? max(in_uv.w, 0.0005) : 1.0, 1.0);
	if (!gl_FrontFacing && alpha.z > 0.5) q.gn = -q.gn;
	if (model > 0) {
		n = normalize(n + (t * (dt.x * 2.0 - 1.0) + b * (dt.y * 2.0 - 1.0)) * shade_b.x * dmask);
		q.cav = mix(1.0, dt.a, shade_b.y * dmask);
	}
	float metal = model == 0 ? clamp(params.x * mr.b, 0.0, 1.0) : 0.0;
	float rough = clamp(params.y * mr.g * (model > 0 ? mix(1.0, 0.5 + dt.b, dmask) : 1.0), 0.03, 1.0);
	if (env_rot.w > 0.5) {
		vec3 dn = max(abs(dFdx(n0)), abs(dFdy(n0)));
		rough = min(max(rough, 0.0525) + max(dn.x, max(dn.y, dn.z)) + clamp(0.25 * (1.0 / max(tl, 0.25) - 1.03), 0.0, 0.1) * params.z, 1.0);
	}
	float occm = 1.0 + params.w * ((tp ? mr.r : texture(tex_occlusion, xuv(uv_sets.w, xm_occ, xo1.zw)).r) - 1.0);
	float aos = eye.w > 0.5 ? texture(tex_ao, gl_FragCoord.xy * screen.xy).r : 1.0;
	if (model > 0) occm *= model == 3 ? q.cav : mix(1.0, q.cav, 0.5);
	float occ = occm * aos;

	if (cluster2.z > 0.0 || cluster2.w > 0.0) {
		float up = smoothstep(0.15, 0.75, n0.y);
		float wet = cluster2.z * mix(0.45, 1.0, up);
		tint.rgb *= mix(1.0, mix(0.55, 1.0, metal), wet);
		rough = mix(rough, min(rough, 0.07 + 0.25 * rough * (1.0 - up)), wet);
		float sn = cluster2.w * smoothstep(0.25, 0.7, n0.y + 0.15 * (mr_grain(in_world) - 0.5));
		tint.rgb = mix(tint.rgb, vec3(0.87, 0.9, 0.93), sn);
		rough = mix(rough, 0.55, sn);
		metal *= 1.0 - sn;
	}
	vec3 albedo = tint.rgb * (1.0 - metal);
	vec3 f0 = mix(vec3(model == 1 ? shade_c.x : 0.04), tint.rgb, metal);
	vec3 v = normalize(eye.xyz - in_world);
	ExtS x = ExtS(n0, 0.0, 0.03, 0.0, 0.0, t, 0.0, b, 1.0, sheen.rgb, sheen.a);
	if (misc.z > 0.5) {
		float sf = x_ior.y * ext_map(0).a;
		float fd = ((x_ior.x - 1.0) / (x_ior.x + 1.0));
		f0 = mix(min(vec3(fd * fd) * x_spec.rgb * ext_map(1).rgb, vec3(1.0)) * sf, tint.rgb, metal);
		x.f90 = mix(sf, 1.0, metal);
		x.coat = x_coat.x * ext_map(2).r;
		x.coat_r = clamp(x_coat.y * ext_map(3).g, 0.03, 1.0);
		if (x_to[4].z >= 0.0) {
			vec3 cn = ext_map(4).xyz * 2.0 - 1.0;
			cn.xy *= x_coat.z;
			x.coat_n = normalize(mat3(t, b, n0) * cn);
		}
		x.trans = x_trans.x * ext_map(5).r;
		x.thick = x_trans.y * ext_map(6).g;
		x.sheen_c = sheen.rgb * ext_map(10).rgb;
		x.sheen_r = clamp(sheen.a * ext_map(11).a, 0.0, 1.0);
		if (x_aniso.x > 0.0) {
			vec4 am = ext_map(7);
			vec2 ad = x_to[7].z >= 0.0 ? am.rg * 2.0 - 1.0 : vec2(1.0, 0.0);
			float as_ = x_to[7].z >= 0.0 ? am.b : 1.0;
			x.aniso = clamp(x_aniso.x * as_, 0.0, 1.0);
			vec2 ar = vec2(x_aniso.y * ad.x - x_aniso.z * ad.y, x_aniso.z * ad.x + x_aniso.y * ad.y);
			x.ta = normalize(t * ar.x + b * ar.y);
			x.tb = normalize(cross(n, x.ta));
		}
		float ix = x_irid.x * ext_map(8).r;
		if (ix > 0.0) {
			float nvi = max(dot(n, v), 1e-4);
			vec3 fi = irid_f0(x_irid.y, nvi, mix(x_irid.z, x_irid.w, ext_map(9).g), f0);
			float xi = 1.0 - nvi;
			float xi5 = xi * xi * xi * xi * xi;
			f0 = mix(f0, clamp((fi - vec3(xi5)) / max(1.0 - xi5, 1e-4), vec3(0.0), vec3(1.0)), ix);
		}
	}
	vec3 rgb = vec3(0.0);
	float n_v = max(dot(n, v), 1e-4);
	vec2 eb = ms_lut(n_v, rough);
	// uv_sets2.z = multiscatter on (0 / 1) + 2 * furnace control mode (scene3d.furnace_mode,
	// 0 in normal use): 1 gives dielectrics F0 = 1 in the specular lobe only, 2 restores the
	// older 1 - F(v.h) diffuse weight. Both must make the furnace test fail.
	int mode = int(uv_sets2.z + 0.5);
	int control = mode / 2;
	bool ms_on = mode - 2 * control == 1;
	float e_ms = ms_e(n_v, rough, eb.x);
	vec3 ms = ms_factor(f0, e_ms, ms_on);
	vec3 kd = max(1.0 - ms * (f0 * (eb.x - eb.y) + x.f90 * eb.y), vec3(0.0));
	vec3 f0_spec = f0;
	if (control == 1) { f0_spec = mix(vec3(1.0), tint.rgb, metal); ms = ms_factor(f0_spec, e_ms, ms_on); }
	if (control == 2) kd = vec3(-1.0);
	vec3 l = normalize(to_sun.xyz);
	vec3 gn = normalize(in_nrm);
	if (!gl_FrontFacing && alpha.z > 0.5) gn = -gn;
	vec3 rp = in_world + gn * 2e-3;
	rgb += mat_term(n, v, l, sun_rgb.rgb, albedo, f0_spec, rough, ms, kd, (gi.y > 0.5 && to_sun.w > 0.5 ? (dot(gn, l) > 0.0 && gi_visible(rp, l, 1e4) ? 1.0 : 0.0) : sun_visibility(in_world, gn)) * cst, q, x);
	if (screen.z > 0.5) {
		int cx = clamp(int(gl_FragCoord.x * screen.x * cluster.x), 0, int(cluster.x) - 1);
		int cy = clamp(int(gl_FragCoord.y * screen.y * cluster.y), 0, int(cluster.y) - 1);
		int cz = clamp(int(log(max(dot(in_world - eye.xyz, view_dir.xyz), 1e-4) / cluster2.x) * cluster2.y), 0, int(cluster.z) - 1);
		uint head = lcell[(cz * int(cluster.y) + cy) * int(cluster.x) + cx];
		int lfirst = int(head >> 8u);
		int lcount = int(head & 255u);
		for (int li = 0; li < lcount; li++) {
			int i = int(lcell[lfirst + li]) * 5;
			vec4 lp = lrec[i];
			vec4 lc = lrec[i + 1];
			vec4 lx = lrec[i + 2];
			vec4 la = lrec[i + 4];
			vec3 d = lp.xyz - in_world;
			float dist = length(d);
			vec3 ld = d / max(dist, 1e-4);
			if (gi.y > 0.5 && (dot(gn, ld) <= 0.0 || !gi_visible(rp, ld, dist - 2e-3))) continue;
			float fq = clamp(1.0 - (dist * dist) / (lp.w * lp.w), 0.0, 1.0);
			float fall = la.x > 0.0 ? fq * fq / (dist * dist + la.x * la.x) : range_falloff(dist, lp.w);
			vec3 le = lc.rgb * fall * spot_cone(lc.w, lx.w, lx.xyz, ld) * local_visibility(lrec[i + 3], lp.xyz, lx.xyz, in_world, gn);
			if (la.x <= 0.0 && la.y <= 0.0) { rgb += mat_term(n, v, ld, le, albedo, f0_spec, rough, ms, kd, 1.0, q, x); continue; }
			vec3 rv = reflect(-v, n);
			vec3 dl = d;
			float aa = max(rough * rough, 0.002);
			float nrm = 1.0;
			if (la.y > 0.0) {
				vec3 ax = lx.xyz * la.y;
				vec3 l0 = d - ax * 0.5;
				float rl = dot(rv, ax);
				dl = l0 + ax * clamp((dot(rv, l0) * rl - dot(l0, ax)) / max(dot(ax, ax) - rl * rl, 1e-5), 0.0, 1.0);
				float ta = clamp(aa + la.y * 0.5 / max(length(dl), 1e-3), 0.0, 1.0);
				nrm *= aa / ta;
			}
			if (la.x > 0.0) {
				vec3 cr = dot(dl, rv) * rv - dl;
				dl += cr * clamp(la.x / max(length(cr), 1e-5), 0.0, 1.0);
				float sa = clamp(aa + la.x * 0.5 / max(length(dl), 1e-3), 0.0, 1.0);
				nrm *= (aa / sa) * (aa / sa);
			}
			rgb += mat_term(n, v, ld, le, albedo, f0_spec, rough, vec3(0.0), kd, 1.0, q, x);
			rgb += mat_term(n, v, normalize(dl), le * nrm, vec3(0.0), f0_spec, rough, ms, kd, 1.0, q, x);
		}
	}
	// furnace control hook (scene3d.furnace_scale, 1 in normal use): scales the direct
	// light so the furnace test can check that it notices a non-conserving BRDF
	rgb *= uv_sets2.w;
	vec3 direct = rgb;
	bool use_gi = gi.x > 0.5;
	vec3 gi_irr = use_gi ? gi_irradiance(in_world, n, v, gi_origin, gi_step, gi_dims) : vec3(0.0);
	float dao = use_gi ? (gi.z > 0.5 ? occ : 1.0) : occ;
	float wdz = 0.0;
	if (is_water) {
		vec4 wc = vp * vec4(in_world, 1.0);
		vec2 wuv = vec2(wc.x / wc.w * 0.5 + 0.5, 0.5 - wc.y / wc.w * 0.5);
		float zw = dot(in_world - eye.xyz, view_dir.xyz);
		float zs = textureLod(tex_trans, clamp(wuv + n.xz * 0.02, vec2(0.0), vec2(1.0)), 0.0).a;
		wdz = zs > 0.0 ? max(zs - zw, 0.0) : 7.0;
		x.thick = min(wdz, 2.0);
		tint.rgb = exp(-shade_a.rgb * max(wdz, 0.02));
	}
	vec4 sr = refl.x > 0.5 && alpha.x < 1.5 && x.trans <= 0.0 ? texelFetch(tex_ssr, ivec2(gl_FragCoord.xy), 0) : vec4(0.0);
	vec3 ambient = env.x > 0.5 || misc.z > 0.5 || probe_n.x > 0.5 ? ambient_env(n, v, tint.rgb, albedo, f0, rough, eb, ms, kd, gi_irr, use_gi, gn, vec3(dao, aos, occm), sr, q, x) : ambient_light(n, v, l, tint.rgb, metal, rough, gi_irr, use_gi, gn, vec3(dao, aos, occm), dao, sr, q) * (use_gi ? 1.0 : screen.w);
	rgb += ambient;

	rgb += emissive.rgb * texture(tex_emissive, xuv(uv_sets2.x, xm_emi, xo2.xy)).rgb;
	if (is_water) {
		vec3 sky_i = env.x > 0.5 ? textureLod(tex_env, vec4(env_dir(vec3(0.0, 1.0, 0.0)), 0.0), env.w).rgb * env.y : sky_color(vec3(0.0, 1.0, 0.0), normalize(to_sun.xyz), zenith.rgb, horizon.rgb, ground.rgb, vec3(0.0));
		vec3 lit = sky_i + sun_rgb.rgb * max(to_sun.y, 0.0) * 0.318309886;
		rgb += shade_c.rgb * (vec3(1.0) - tint.rgb) * lit;
		float nz = water_grad(in_world.xz * 3.1, cluster.w * 0.7).x * 7.0 + 0.5;
		float foam = shade_b.w * smoothstep(0.32, 0.0, wdz + 0.14 * nz);
		rgb = mix(rgb, vec3(0.87) * lit, clamp(foam, 0.0, 1.0));
	}
	out_rgba = vec4(rgb, alpha.x > 1.5 ? tint.a : 1.0);

	int dbg = int(uv_sets2.y + 0.5);
	if (dbg == 1) out_rgba = vec4(n * 0.5 + 0.5, 1.0);
	else if (dbg == 2) out_rgba = vec4(normalize(in_nrm) * 0.5 + 0.5, 1.0);
	else if (dbg == 3) out_rgba = vec4(t * 0.5 + 0.5, 1.0);
	else if (dbg == 4) out_rgba = vec4(ambient, 1.0);
	else if (dbg == 5) out_rgba = vec4(direct, 1.0);
	else if (dbg == 6) out_rgba = vec4(vec3(occ), 1.0);
	else if (dbg == 7) out_rgba = vec4(tint.rgb, 1.0);
	else if (dbg == 8) out_rgba = vec4(vec3(max(dot(n, v), 0.0)), 1.0);
	else if (dbg == 9) out_rgba = vec4(vec3(spec_occ(reflect(-v, n), n_v, rough, gn, dao, aos, occm)), 1.0);
	else if (dbg == 10) out_rgba = vec4(sr.w, sr.z, 0.0, 1.0);
}
