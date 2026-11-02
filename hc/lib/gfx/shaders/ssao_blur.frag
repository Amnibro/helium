// Depth-aware 5x5 blur of the AO term (stored with its depth in .g).
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_ao;
layout(set = 3, binding = 0) uniform Blur { vec4 texel; };
layout(location = 0) out vec4 out_ao;
void main() {
	vec2 c = texture(tex_ao, in_uv).rg;
	if (c.g <= 0.0) { out_ao = vec4(1.0); return; }
	float sum = 0.0;
	float wsum = 0.0;
	for (int y = -2; y <= 2; y++)
		for (int x = -2; x <= 2; x++) {
			vec2 s = texture(tex_ao, in_uv + vec2(x, y) * texel.xy).rg;
			float w = (s.g > 0.0 ? 1.0 : 0.0) / (1.0 + 40.0 * abs(s.g - c.g) / c.g);
			sum += s.r * w;
			wsum += w;
		}
	out_ao = vec4(wsum > 0.0 ? sum / wsum : c.r);
}
