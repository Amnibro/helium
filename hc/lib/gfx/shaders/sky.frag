#version 450
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform samplerCube sky_tex;
layout(set = 3, binding = 0) uniform Sky { mat4 world_from_clip; vec4 rotation; vec4 brightness; };
vec3 quat_rotate(vec4 q, vec3 v) { vec3 t = 2.0 * cross(q.xyz, v); return v + q.w * t + cross(q.xyz, t); }
void main() {
	vec4 ndc = vec4(in_uv.x * 2.0 - 1.0, 1.0 - in_uv.y * 2.0, 1.0, 1.0);
	vec4 far = vec4(ndc.xy, 0.0001, 1.0);
	vec4 a = world_from_clip * ndc;
	vec4 b = world_from_clip * far;
	vec3 d = quat_rotate(rotation, normalize(b.xyz / b.w - a.xyz / a.w));
	vec4 c = textureLod(sky_tex, d * vec3(1.0, 1.0, -1.0), 0.0);
	out_color = vec4(c.rgb * brightness.x, 1.0);
}
