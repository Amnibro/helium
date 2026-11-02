layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_ao;
layout(set = 2, binding = 1) uniform sampler2D tex_bent;
layout(set = 3, binding = 0) uniform Blur { vec4 texel; };
layout(location = 0) out vec4 out_ao;
layout(location = 1) out vec4 out_bent;
void main() {
	vec2 c = texture(tex_ao, in_uv).rg;
	vec4 cb = texture(tex_bent, in_uv);
	if (c.g <= 0.0) { out_ao = vec4(1.0); out_bent = vec4(cb.xyz, 1.0); return; }
	float sum = 0.0;
	vec4 bsum = vec4(0.0);
	float wsum = 0.0;
	for (int y = -2; y <= 2; y++)
		for (int x = -2; x <= 2; x++) {
			vec2 uv = in_uv + vec2(x, y) * texel.xy;
			vec2 s = texture(tex_ao, uv).rg;
			vec4 b = texture(tex_bent, uv);
			float w = (s.g > 0.0 ? 1.0 : 0.0) / (1.0 + 40.0 * abs(s.g - c.g) / c.g);
			sum += s.r * w;
			bsum += b * w;
			wsum += w;
		}
	out_ao = vec4(wsum > 0.0 ? sum / wsum : c.r);
	vec3 bn = wsum > 0.0 && length(bsum.xyz) > 1e-6 ? normalize(bsum.xyz) : cb.xyz;
	out_bent = vec4(bn, wsum > 0.0 ? bsum.w / wsum : cb.w);
}
