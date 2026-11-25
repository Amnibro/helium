#include "lighting.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform samplerCubeArray tex_env;
layout(set = 2, binding = 1) uniform sampler2D tex_cloud;
layout(set = 2, binding = 2) uniform samplerCube tex_clear;
layout(set = 3, binding = 0) uniform Sky { mat4 inv_view_proj; mat4 prev_view_proj; vec4 to_sun; vec4 sun_rgb; vec4 zenith; vec4 horizon; vec4 ground; vec4 env; vec4 env_rot; vec4 cloud; };
layout(location = 0) out vec4 out_rgba;
vec4 cloud_up(vec2 uv) {
	vec2 sz = vec2(textureSize(tex_cloud, 0));
	vec2 c = floor(uv * sz - 0.5) + 0.5;
	vec2 f = uv * sz - c;
	vec2 w0 = f * (-0.5 + f * (1.0 - 0.5 * f));
	vec2 w3 = f * f * (-0.5 + 0.5 * f);
	vec2 wm = 1.0 - w0 - w3;
	vec2 t0 = (c - 1.0) / sz;
	vec2 t3 = (c + 2.0) / sz;
	vec2 tm = (c + f * (0.5 + f * (2.0 - 1.5 * f)) / wm) / sz;
	vec4 r = (textureLod(tex_cloud, vec2(t0.x, t0.y), 0.0) * w0.x + textureLod(tex_cloud, vec2(tm.x, t0.y), 0.0) * wm.x + textureLod(tex_cloud, vec2(t3.x, t0.y), 0.0) * w3.x) * w0.y + (textureLod(tex_cloud, vec2(t0.x, tm.y), 0.0) * w0.x + textureLod(tex_cloud, vec2(tm.x, tm.y), 0.0) * wm.x + textureLod(tex_cloud, vec2(t3.x, tm.y), 0.0) * w3.x) * wm.y + (textureLod(tex_cloud, vec2(t0.x, t3.y), 0.0) * w0.x + textureLod(tex_cloud, vec2(tm.x, t3.y), 0.0) * wm.x + textureLod(tex_cloud, vec2(t3.x, t3.y), 0.0) * w3.x) * w3.y;
	return vec4(max(r.rgb, vec3(0.0)), clamp(r.a, 0.0, 1.0));
}
void main() {
	vec4 a = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.0, 1.0);
	vec4 b = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 1.0, 1.0);
	vec3 dir = normalize(b.xyz / b.w - a.xyz / a.w);
	if (to_sun.w > 0.5) { out_rgba = vec4(horizon.rgb, 1.0); return; }   // sky drawing off: flat clear colour
	vec4 k = cloud.x > 0.5 ? cloud_up(in_uv) : vec4(0.0, 0.0, 0.0, 1.0);
	vec3 rd = vec3(env_rot.x * dir.x + env_rot.y * dir.z, dir.y, env_rot.x * dir.z - env_rot.y * dir.x);
	vec3 base = (cloud.y > 0.5 ? textureLod(tex_clear, rd, 0.0).rgb : textureLod(tex_env, vec4(rd, 0.0), env_rot.z).rgb) * env.y;
	if (env.x > 1.5) { out_rgba = vec4((base + sun_rgb.rgb * 64.0 * smoothstep(0.99985, 0.99993, dot(dir, normalize(to_sun.xyz)))) * k.a + k.rgb, 1.0); return; }
	if (env.x > 0.5) { out_rgba = vec4(base * k.a + k.rgb, 1.0); return; }
	vec3 c = sky_color(dir, normalize(to_sun.xyz), zenith.rgb, horizon.rgb, ground.rgb, sun_rgb.rgb);
	float s = dot(dir, normalize(to_sun.xyz));
	c += sun_rgb.rgb * 20.0 * smoothstep(0.9995, 0.99975, s);
	out_rgba = vec4(c * k.a + k.rgb, 1.0);
}
