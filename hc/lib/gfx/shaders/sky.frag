#include "lighting.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform samplerCube tex_env;
layout(set = 3, binding = 0) uniform Sky { mat4 inv_view_proj; mat4 prev_view_proj; vec4 to_sun; vec4 sun_rgb; vec4 zenith; vec4 horizon; vec4 ground; vec4 env; vec4 env_rot; };
layout(location = 0) out vec4 out_rgba;
void main() {
	vec4 a = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.0, 1.0);
	vec4 b = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 1.0, 1.0);
	vec3 dir = normalize(b.xyz / b.w - a.xyz / a.w);
	if (to_sun.w > 0.5) { out_rgba = vec4(horizon.rgb, 1.0); return; }   // sky drawing off: flat clear colour
	if (env.x > 0.5) { out_rgba = vec4(textureLod(tex_env, vec3(env_rot.x * dir.x + env_rot.y * dir.z, dir.y, env_rot.x * dir.z - env_rot.y * dir.x), env_rot.z).rgb * env.y, 1.0); return; }
	vec3 c = sky_color(dir, normalize(to_sun.xyz), zenith.rgb, horizon.rgb, ground.rgb, sun_rgb.rgb);
	float s = dot(dir, normalize(to_sun.xyz));
	c += sun_rgb.rgb * 20.0 * smoothstep(0.9995, 0.99975, s);
	out_rgba = vec4(c, 1.0);
}
