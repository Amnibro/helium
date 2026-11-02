// Colour pass for glTF metallic-roughness materials.
#include "lighting.glsl"
#include "ms_lut.glsl"

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

const int CASCADES = 3;
const int MAX_LIGHTS = 8;

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
};

layout(set = 3, binding = 1) uniform Surface {
	vec4 base;            // base colour factor
	vec4 emissive;        // rgb emissive (strength applied), w unlit
	vec4 params;          // x metallic, y roughness, z normal scale, w occlusion strength
	vec4 alpha;           // x mode (0 opaque, 1 mask, 2 blend), y cutoff, z double sided
	vec4 uv_sets;         // which UV set each texture reads: base, mr, normal, occlusion
	vec4 uv_sets2;        // x emissive, y debug view (see scene3d.debug_view), z multiscatter on + 2 * furnace control mode, w furnace control scale
};

layout(location = 0) out vec4 out_rgba;

vec2 pick_uv(float set) { return set > 0.5 ? in_uv.zw : in_uv.xy; }

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
	vec3 ndc = s.xyz / s.w;
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	float lit = 0.0;
	for (int y = -1; y <= 1; y++)
		for (int x = -1; x <= 1; x++)
			lit += texture(tex_shadow, vec4(uv + vec2(x, y) * texel, float(c), ndc.z - 0.0008));
	return lit / 9.0;
}

// Ambient from the analytic sky: its irradiance for the diffuse lobe and the sky
// along the mirror direction for the specular lobe, blended by a roughness-damped
// Fresnel weight. The dielectric and metal responses are mixed by metalness, so a
// white surface returns exactly the environment in a uniform sky (white furnace).
// Probe irradiance or a prefiltered environment can replace this function.
vec3 ambient_light(vec3 n, vec3 v, vec3 l, vec3 base_rgb, float metal, float rough) {
	vec3 irr = mix(ground.rgb, zenith.rgb, n.y * 0.5 + 0.5);
	irr = mix(irr, horizon.rgb, 0.5 * (1.0 - abs(n.y)));
	vec3 r = reflect(-v, n);
	vec3 env = sky_color(r, l, zenith.rgb, horizon.rgb, ground.rgb, vec3(0.0));
	env = mix(env, irr, rough * rough);
	float n_v = max(dot(n, v), 1e-4);
	float smooth_w = (1.0 - rough) * (1.0 - rough);
	float fw = pow(1.0 - n_v, 5.0) * smooth_w;
	float fd = 0.04 + 0.96 * fw;
	vec3 fm = base_rgb + (1.0 - base_rgb) * fw;
	vec3 dielectric = base_rgb * (1.0 - fd) * irr + fd * env;
	return mix(dielectric, fm * env, metal);
}

void main() {
	vec4 tint = base * in_col * texture(tex_base, pick_uv(uv_sets.x));
	if (alpha.x > 0.5 && alpha.x < 1.5 && tint.a < alpha.y) discard;
	if (emissive.w > 0.5) { out_rgba = vec4(tint.rgb, alpha.x > 1.5 ? tint.a : 1.0); return; }

	vec3 n = normalize(in_nrm);
	if (!gl_FrontFacing && alpha.z > 0.5) n = -n;

	// tangent frame: from the vertex tangent, or from screen derivatives when absent
	vec3 t;
	vec3 b;
	vec2 uvn = pick_uv(uv_sets.z);
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
	vec3 tn = texture(tex_normal, uvn).xyz * 2.0 - 1.0;
	tn.xy *= params.z;
	n = normalize(mat3(t, b, n) * tn);

	vec4 mr = texture(tex_mr, pick_uv(uv_sets.y));
	float metal = clamp(params.x * mr.b, 0.0, 1.0);
	float rough = clamp(params.y * mr.g, 0.03, 1.0);
	float occ = 1.0 + params.w * (texture(tex_occlusion, pick_uv(uv_sets.w)).r - 1.0);
	if (eye.w > 0.5) occ *= texture(tex_ao, gl_FragCoord.xy * screen.xy).r;

	vec3 albedo = tint.rgb * (1.0 - metal);
	vec3 f0 = mix(vec3(0.04), tint.rgb, metal);
	vec3 v = normalize(eye.xyz - in_world);
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
	vec3 kd = diffuse_weight(f0, eb, ms);
	vec3 f0_spec = f0;
	if (control == 1) { f0_spec = mix(vec3(1.0), tint.rgb, metal); ms = ms_factor(f0_spec, e_ms, ms_on); }
	if (control == 2) kd = vec3(-1.0);
	vec3 l = normalize(to_sun.xyz);
	rgb += light_term(n, v, l, sun_rgb.rgb, albedo, f0_spec, rough, ms, kd) * sun_visibility(in_world, normalize(in_nrm));
	int count = int(screen.z);
	for (int i = 0; i < MAX_LIGHTS; i++) {
		if (i >= count) break;
		vec3 d = light_pos[i].xyz - in_world;
		float dist = length(d);
		rgb += light_term(n, v, d / max(dist, 1e-4), light_rgb[i].rgb * range_falloff(dist, light_pos[i].w), albedo, f0_spec, rough, ms, kd);
	}

	// furnace control hook (scene3d.furnace_scale, 1 in normal use): scales the direct
	// light so the furnace test can check that it notices a non-conserving BRDF
	rgb *= uv_sets2.w;
	vec3 direct = rgb;
	vec3 ambient = ambient_light(n, v, l, tint.rgb, metal, rough) * occ * screen.w;
	rgb += ambient;

	rgb += emissive.rgb * texture(tex_emissive, pick_uv(uv_sets2.x)).rgb;
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
}
