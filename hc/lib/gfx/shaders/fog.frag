#include "lighting.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_nd;
layout(set = 2, binding = 2) uniform sampler2DArrayShadow tex_shadow;
layout(set = 2, binding = 3) uniform samplerCube tex_env;
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
};
layout(location = 0) out vec4 out_rgba;
float sun_vis(vec3 p) {
	if (to_sun.w < 0.5) return 1.0;
	float depth = dot(p - eye.xyz, view_dir.xyz);
	int c = depth > cascade_far.y ? 2 : (depth > cascade_far.x ? 1 : 0);
	if (depth > cascade_far.z) return 1.0;
	vec4 s = cascade_mat[c] * vec4(p, 1.0);
	vec3 ndc = s.xyz / s.w;
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	return texture(tex_shadow, vec4(uv, float(c), ndc.z - 0.001));
}
void main() {
	vec3 src = texture(tex_hdr, in_uv).rgb;
	vec4 nd = texture(tex_nd, in_uv);
	vec4 w = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.5, 1.0);
	vec3 dir = normalize(w.xyz / w.w - eye.xyz);
	float far = params.w;
	float dist = nd.w > 0.0 ? min(nd.w / max(dot(dir, view_dir.xyz), 1e-3), far) : far;
	int steps = int(params2.x);
	float dt = dist / float(steps);
	float jit = fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)) + params2.y * 0.61803398875));
	float g = params2.z;
	float mu = dot(dir, to_sun.xyz);
	float phase = (1.0 - g * g) / (12.566370614 * pow(max(1.0 + g * g - 2.0 * g * mu, 1e-4), 1.5));
	float iso = 0.0795774715;
	vec3 acc = vec3(0.0);
	float tr = 1.0;
	int count = int(params2.w);
	vec3 amb = env.x > 0.5 ? textureLod(tex_env, vec3(env_rot.x * dir.x + env_rot.y * dir.z, dir.y, env_rot.x * dir.z - env_rot.y * dir.x), env.w).rgb * env.y : ambient.rgb;
	for (int i = 0; i < 64; i++) {
		if (i >= steps) break;
		vec3 p = eye.xyz + dir * ((float(i) + jit) * dt);
		float dens = params.x * exp(-params.y * max(p.y - params.z, 0.0));
		if (dens <= 0.0) continue;
		vec3 l = sun_rgb.rgb * phase * sun_vis(p) + amb;
		for (int k = 0; k < 16; k++) {
			if (k >= count) break;
			float d = length(light_pos[k].xyz - p);
			l += light_rgb[k].rgb * range_falloff(d, light_pos[k].w) * iso;
		}
		float ext = dens * dt;
		float st = exp(-ext);
		acc += tr * l * (1.0 - st);
		tr *= st;
	}
	out_rgba = vec4(src * tr + acc, 1.0);
}
