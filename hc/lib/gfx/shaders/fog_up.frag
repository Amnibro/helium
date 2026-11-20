layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_nd;
layout(set = 2, binding = 2) uniform sampler2D tex_fog;
layout(set = 3, binding = 0) uniform FogUp { vec4 size; };
layout(location = 0) out vec4 out_rgba;
void main() {
	vec3 src = texture(tex_hdr, in_uv).rgb;
	float z = texture(tex_nd, in_uv).w;
	vec2 fp = in_uv * size.xy - 0.5;
	ivec2 b = ivec2(floor(fp));
	vec2 f = fp - vec2(b);
	ivec2 hi = ivec2(size.xy) - 1;
	vec4 sum = vec4(0.0);
	float ws = 0.0;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 2; i++) {
			ivec2 q = clamp(b + ivec2(i, j), ivec2(0), hi);
			vec4 fg = texelFetch(tex_fog, q, 0);
			float zs = texture(tex_nd, (vec2(q) + 0.5) * size.zw).w;
			float dw = (z <= 0.0 && zs <= 0.0) ? 1.0 : ((z <= 0.0 || zs <= 0.0) ? 0.001 : 1.0 / (1.0 + 30.0 * abs(zs - z) / max(z, 0.1)));
			float w = (i == 0 ? 1.0 - f.x : f.x) * (j == 0 ? 1.0 - f.y : f.y) * dw;
			sum += fg * w;
			ws += w;
		}
	}
	vec4 res = ws > 0.0 ? sum / ws : texture(tex_fog, in_uv);
	out_rgba = vec4(src * res.a + res.rgb, 1.0);
}
