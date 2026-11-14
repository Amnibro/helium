#include "lighting.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_nd;
layout(set = 2, binding = 2) uniform sampler2DArrayShadow tex_shadow;
layout(set = 2, binding = 3) uniform samplerCubeArray tex_env;
layout(set = 2, binding = 4) uniform sampler2D tex_cloud;
layout(set = 2, binding = 5) uniform sampler3D tex_noise;
layout(set = 2, binding = 6) uniform sampler2DArrayShadow tex_local;
layout(set = 3, binding = 0) uniform Fog {
	mat4 inv_view_proj;
	mat4 cascade_mat[3];
	vec4 cascade_far;
	vec4 eye;
	vec4 view_dir;
	vec4 to_sun;
	vec4 sun_rgb;
	vec4 ambient;
	vec4 params;
	vec4 params2;
	vec4 light_pos[16];
	vec4 light_rgb[16];
	vec4 env;
	vec4 env_rot;
	vec4 cl_u;
	vec4 cl_v;
	vec4 cl;
	vec4 light_dir[16];
	vec4 light_shd[16];
	mat4 local_mat[12];
	vec4 vol_pos[8];
	vec4 vol_half[8];
	vec4 vol_rgb[8];
	vec4 vol;
	vec4 wind;
};
layout(location = 0) out vec4 out_rgba;
float cloud_t(vec3 p) {
	vec2 uv = vec2(dot(cl_u.xyz, p) + cl_u.w, dot(cl_v.xyz, p) + cl_v.w);
	vec2 e = smoothstep(vec2(0.5), vec2(0.45), abs(uv - 0.5));
	return mix(1.0, textureLod(tex_cloud, uv, 0.0).r, cl.x * e.x * e.y);
}
#include "sun_vis.glsl"
float local_vis(vec4 sh, vec3 lp, vec3 p) {
	if (sh.x < 0.0) return 1.0;
	vec3 d = p - lp;
	vec3 a = abs(d);
	int layer = int(sh.x) + (sh.y > 1.5 ? (a.x >= a.y && a.x >= a.z ? (d.x > 0.0 ? 0 : 1) : (a.y >= a.z ? (d.y > 0.0 ? 2 : 3) : (d.z > 0.0 ? 4 : 5))) : 0);
	vec4 s = local_mat[layer] * vec4(p, 1.0);
	if (s.w <= 0.0) return 1.0;
	vec3 ndc = s.xyz / s.w;
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	return texture(tex_local, vec4(uv, float(layer), ndc.z));
}
vec4 vol_at(vec3 p) {
	vec4 o = vec4(0.0);
	int n = int(vol.x);
	for (int k = 0; k < 8; k++) {
		if (k >= n) break;
		vec3 q = abs(p - vol_pos[k].xyz) / vol_half[k].xyz;
		float d = vol_rgb[k].w > 0.5 ? length(q) : max(q.x, max(q.y, q.z));
		if (d >= 1.0) continue;
		float w = vol_half[k].w > 0.0 ? clamp((1.0 - d) / max(vol_half[k].w, 1e-4), 0.0, 1.0) : 1.0;
		o += vec4(vol_rgb[k].rgb, 1.0) * (vol_pos[k].w * w * w * (3.0 - 2.0 * w));
	}
	return o;
}
void main() {
	vec3 src = texture(tex_hdr, in_uv).rgb;
	vec4 nd = texture(tex_nd, in_uv);
	vec4 w = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.5, 1.0);
	vec3 dir = normalize(w.xyz / w.w - eye.xyz);
	float far = params.w;
	float dist = nd.w > 0.0 ? min(nd.w / max(dot(dir, view_dir.xyz), 1e-3), far) : far;
	int steps = int(params2.x);
	int nv = int(vol.x);
	vec3 inv = 1.0 / vec3(abs(dir.x) < 1e-6 ? 1e-6 : dir.x, abs(dir.y) < 1e-6 ? 1e-6 : dir.y, abs(dir.z) < 1e-6 ? 1e-6 : dir.z);
	float t0 = dist;
	float t1 = 0.0;
	for (int k = 0; k < 8; k++) {
		if (k >= nv) break;
		vec3 a = (vol_pos[k].xyz - vol_half[k].xyz - eye.xyz) * inv;
		vec3 b = (vol_pos[k].xyz + vol_half[k].xyz - eye.xyz) * inv;
		vec3 lo = min(a, b);
		vec3 hi = max(a, b);
		float n0 = max(max(lo.x, lo.y), max(lo.z, 0.0));
		float n1 = min(min(hi.x, hi.y), min(hi.z, dist));
		if (n1 > n0 && vol_pos[k].w > 0.0) { t0 = min(t0, n0); t1 = max(t1, n1); }
	}
	bool hull = t1 > t0;
	bool glob = params.x > 0.0;
	if (!hull) { t0 = dist; t1 = dist; }
	if (!hull && !glob) steps = 0;
	float la = t0;
	float lb = dist - t1;
	int nh = hull ? (glob && la + lb > 1e-4 ? steps / 2 : steps) : 0;
	int na = glob ? int(float(steps - nh) * la / max(la + lb, 1e-6) + 0.5) : 0;
	int nb = steps - nh - na;
	float jit = fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)) + params2.y * 0.61803398875));
	float g = params2.z;
	float mu = dot(dir, to_sun.xyz);
	float phase = (1.0 - g * g) / (12.566370614 * pow(max(1.0 + g * g - 2.0 * g * mu, 1e-4), 1.5));
	float iso = 0.0795774715;
	vec3 acc = vec3(0.0);
	float tr = 1.0;
	int count = int(params2.w);
	vec3 amb = env.x > 0.5 ? textureLod(tex_env, vec4(env_rot.x * dir.x + env_rot.y * dir.z, dir.y, env_rot.x * dir.z - env_rot.y * dir.x, 0.0), env.w).rgb * env.y : ambient.rgb;
	for (int i = 0; i < 64; i++) {
		if (i >= steps) break;
		int j = i < na ? i : (i < na + nh ? i - na : i - na - nh);
		float dt = i < na ? la / float(max(na, 1)) : (i < na + nh ? (t1 - t0) / float(max(nh, 1)) : lb / float(max(nb, 1)));
		vec3 p = eye.xyz + dir * ((i < na ? 0.0 : (i < na + nh ? t0 : t1)) + (float(j) + jit) * dt);
		float gd = params.x * exp(-params.y * max(p.y - params.z, 0.0));
		vec4 vd = vol_at(p);
		float ext = gd + vd.a;
		if (ext <= 0.0) continue;
		vec3 sc = vec3(gd) + vd.rgb;
		float f = 1.0;
		if (vol.y > 0.0) {
			vec3 q = p * vol.z - wind.xyz;
			f += vol.y * (2.0 * smoothstep(0.35, 0.65, 0.5 * (textureLod(tex_noise, q, 0.0).r + textureLod(tex_noise, q * 0.25 + 0.37, 0.0).r)) - 1.0);
		}
		vec3 l = sun_rgb.rgb * (phase * sun_vis(p) * cloud_t(p)) + amb;
		for (int k = 0; k < 16; k++) {
			if (k >= count) break;
			vec3 d = light_pos[k].xyz - p;
			float ds = length(d);
			float c = range_falloff(ds, light_pos[k].w) * spot_cone(light_rgb[k].w, light_dir[k].w, light_dir[k].xyz, d / max(ds, 1e-4));
			if (c <= 0.0) continue;
			l += light_rgb[k].rgb * (c * iso * vol.w * local_vis(light_shd[k], light_pos[k].xyz, p));
		}
		float st = exp(-ext * f * dt);
		acc += tr * l * (sc / ext) * (1.0 - st);
		tr *= st;
	}
	out_rgba = vec4(src * tr + acc, 1.0);
}
