// Colour pass for glTF metallic-roughness materials.
#include "lighting.glsl"

layout(location = 0) in vec3 in_world;
layout(location = 1) in vec3 in_nrm;
layout(location = 2) in vec4 in_tan;
layout(location = 3) in vec4 in_uv;
layout(location = 4) in vec4 in_col;

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
	vec4 uv_sets2;        // x emissive
};

layout(location = 0) out vec4 out_rgba;

vec2 pick_uv(float set) { return set > 0.5 ? in_uv.zw : in_uv.xy; }

float sun_visibility(vec3 p, vec3 n) {
	if (to_sun.w < 0.5) return 1.0;
	float depth = dot(p - eye.xyz, view_dir.xyz);
	int c = 0;
	if (depth > cascade_far.x) c = 1;
	if (depth > cascade_far.y) c = 2;
	if (depth > cascade_far.z) return 1.0;
	// offset along the normal by about a texel of the chosen cascade
	float scale = float(c + 1) * float(c + 1);
	vec3 q = p + n * (0.02 * scale);
	vec4 s = cascade_mat[c] * vec4(q, 1.0);
	vec3 ndc = s.xyz / s.w;
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	float texel = cascade_far.w;
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
	vec4 base = base * in_col * texture(tex_base, pick_uv(uv_sets.x));
	if (alpha.x > 0.5 && alpha.x < 1.5 && base.a < alpha.y) discard;
	if (emissive.w > 0.5) { out_rgba = vec4(base.rgb, alpha.x > 1.5 ? base.a : 1.0); return; }

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

	vec3 albedo = base.rgb * (1.0 - metal);
	vec3 f0 = mix(vec3(0.04), base.rgb, metal);
	vec3 v = normalize(eye.xyz - in_world);
	vec3 rgb = vec3(0.0);
	vec3 l = normalize(to_sun.xyz);
	rgb += light_term(n, v, l, sun_rgb.rgb, albedo, f0, rough) * sun_visibility(in_world, normalize(in_nrm));
	int count = int(screen.z);
	for (int i = 0; i < MAX_LIGHTS; i++) {
		if (i >= count) break;
		vec3 d = light_pos[i].xyz - in_world;
		float dist = length(d);
		rgb += light_term(n, v, d / max(dist, 1e-4), light_rgb[i].rgb * range_falloff(dist, light_pos[i].w), albedo, f0, rough);
	}

	rgb += ambient_light(n, v, l, base.rgb, metal, rough) * occ * screen.w;

	rgb += emissive.rgb * texture(tex_emissive, pick_uv(uv_sets2.x)).rgb;
	out_rgba = vec4(rgb, alpha.x > 1.5 ? base.a : 1.0);
}
