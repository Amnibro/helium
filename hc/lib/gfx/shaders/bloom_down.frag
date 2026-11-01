#version 450
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform sampler2D bloom_in;
layout(set = 3, binding = 0) uniform BloomU { vec4 threshold; vec4 texel; };
vec3 s(vec2 uv) { return textureLod(bloom_in, uv, 0.0).rgb; }
float luminance(vec3 v) { return dot(v, vec3(0.2126, 0.7152, 0.0722)); }
float karis(vec3 c) { return 1.0 / (1.0 + luminance(c) * 0.25); }
void main() {
	vec2 t = texel.xy;
	vec2 uv = in_uv;
	vec3 a = s(uv + t * vec2(-2.0, -2.0)); vec3 b = s(uv + t * vec2(0.0, -2.0)); vec3 c = s(uv + t * vec2(2.0, -2.0));
	vec3 d = s(uv + t * vec2(-2.0, 0.0)); vec3 e = s(uv); vec3 f = s(uv + t * vec2(2.0, 0.0));
	vec3 g = s(uv + t * vec2(-2.0, 2.0)); vec3 h = s(uv + t * vec2(0.0, 2.0)); vec3 i = s(uv + t * vec2(2.0, 2.0));
	vec3 j = s(uv + t * vec2(-1.0, -1.0)); vec3 k = s(uv + t * vec2(1.0, -1.0)); vec3 l = s(uv + t * vec2(-1.0, 1.0)); vec3 m = s(uv + t * vec2(1.0, 1.0));
	if (texel.z > 0.5) {
		vec3 g0 = (a + b + d + e) * 0.125 * 0.25; vec3 g1 = (b + c + e + f) * 0.125 * 0.25; vec3 g2 = (d + e + g + h) * 0.125 * 0.25; vec3 g3 = (e + f + h + i) * 0.125 * 0.25; vec3 g4 = (j + k + l + m) * 0.5 * 0.25;
		g0 *= karis(g0 * 4.0); g1 *= karis(g1 * 4.0); g2 *= karis(g2 * 4.0); g3 *= karis(g3 * 4.0); g4 *= karis(g4 * 4.0);
		out_color = vec4(g0 + g1 + g2 + g3 + g4, 1.0);
		return;
	}
	out_color = vec4(e * 0.125 + (a + c + g + i) * 0.03125 + (b + d + f + h) * 0.0625 + (j + k + l + m) * 0.125, 1.0);
}
