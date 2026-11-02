// Prepass background: the sky's nd (normal +z, depth 0: no geometry) and its motion.
// The sky is infinitely far away: only camera rotation moves it on screen. Its view
// depth, now and last frame, is written as 60000 (inside the fp16 range).
layout(location = 0) in vec2 in_uv;
layout(set = 3, binding = 0) uniform Sky { mat4 inv_view_proj; mat4 prev_view_proj; vec4 to_sun; vec4 sun_rgb; vec4 zenith; vec4 horizon; vec4 ground; };
layout(location = 0) out vec4 out_nd;
layout(location = 1) out vec4 out_motion;
void main() {
	vec4 a = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 0.0, 1.0);
	vec4 b = inv_view_proj * vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 1.0, 1.0);
	vec3 dir = normalize(b.xyz / b.w - a.xyz / a.w);
	vec4 then = prev_view_proj * vec4(dir, 0.0);
	vec2 prev_uv = then.w > 1e-6 ? vec2(0.5 + 0.5 * then.x / then.w, 0.5 - 0.5 * then.y / then.w) : vec2(-4.0);
	out_nd = vec4(0.0, 0.0, 1.0, 0.0);
	out_motion = vec4(in_uv - prev_uv, 60000.0, 60000.0);
}
