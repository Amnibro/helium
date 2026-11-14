layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform samplerCube tex_clear;
layout(set = 2, binding = 1) uniform samplerCubeArray tex_env;
layout(set = 2, binding = 2) uniform sampler3D tex_noise;
#include "cloud.glsl"
layout(set = 3, binding = 0) uniform Clouds { mat4 inv_view_proj; vec4 eye; vec4 to_sun; vec4 sun_rgb; vec4 slab; vec4 wind; vec4 env; vec4 env_rot; vec4 amb_hi; vec4 amb_lo; };
layout(location = 0) out vec4 out_rgba;
void main() {
	vec4 a = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.0, 1.0);
	vec4 b = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 1.0, 1.0);
	vec3 d = normalize(b.xyz / b.w - a.xyz / a.w);
	float iy = 1.0 / (abs(d.y) > 1e-4 ? d.y : 1e-4);
	float ta = (slab.x - eye.y) * iy;
	float tb = (slab.x + slab.y - eye.y) * iy;
	float s0 = max(min(ta, tb), 0.0);
	float s1 = min(max(ta, tb), s0 + 14.0);
	if (s1 <= s0) { out_rgba = vec4(0.0, 0.0, 0.0, 1.0); return; }
	int steps = int(wind.z);
	float dt = (s1 - s0) / float(steps);
	float jit = wind.w < 0.0 ? 0.5 : fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)) + wind.w * 0.61803398875));
	vec3 rd = vec3(env_rot.x * d.x + env_rot.y * d.z, d.y, env_rot.x * d.z - env_rot.y * d.x);
	vec3 hi = env.x > 0.5 ? textureLod(tex_env, vec4(0.0, 1.0, 0.0, 0.0), env.z).rgb * env.y : amb_hi.rgb;
	vec3 lo = env.x > 0.5 ? textureLod(tex_env, vec4(0.0, -1.0, 0.0, 0.0), env.z).rgb * env.y : amb_lo.rgb;
	vec3 far_c = env.x > 0.5 ? (env_rot.z > 0.5 ? textureLod(tex_clear, rd, 0.0).rgb : textureLod(tex_env, vec4(rd, 0.0), env_rot.w).rgb) * env.y : amb_hi.rgb;
	float cs = dot(d, to_sun.xyz);
	vec3 sun = sun_rgb.rgb * to_sun.w;
	vec3 cl = vec3(0.0);
	float ct = 1.0;
	for (int i = 0; i < 128; i++) {
		if (i >= steps || ct < 0.01) break;
		float sm = s0 + (float(i) + 0.5) * dt;
		if (c_dens(eye.xyz + d * sm, slab, wind.xy, -1.0) <= 0.0) continue;
		float lv = 1.0 + clamp(1.5 - sm / 20.0, 0.0, 1.0);
		for (int j = 0; j < 2; j++) {
			float s = s0 + (float(i) + (float(j) + jit) * 0.5) * dt;
			vec3 q = eye.xyz + d * s;
			float de = c_dens(q, slab, wind.xy, lv);
			if (de <= 0.0) continue;
			float stp = exp(-de * dt * 0.5);
			cl += ct * (1.0 - stp) * mix(far_c, c_light(q, de, to_sun.xyz, slab, wind.xy, cs, sun, lo, hi, lv), exp(-s * env.w));
			ct *= stp;
		}
	}
	out_rgba = vec4(cl, ct);
}
