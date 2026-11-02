// Bloom input: keeps the part of the HDR image above a threshold, with a
// quadratic knee so the cut is soft, and box-filters 2x2 into half size.
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 3, binding = 0) uniform Glow { vec4 texel; vec4 cut; }; // cut: threshold, knee, clamp
layout(location = 0) out vec4 out_rgb;
vec3 keep(vec3 c) {
	c = min(c, vec3(cut.z));
	float m = max(c.r, max(c.g, c.b));
	float lo = cut.x - cut.y;
	float soft = clamp(m - lo, 0.0, 2.0 * cut.y);
	soft = soft * soft / (4.0 * cut.y + 1e-5);
	float w = max(soft, m - cut.x) / max(m, 1e-5);
	return c * w;
}
void main() {
	vec2 o = texel.xy * 0.5;
	vec3 c = keep(texture(tex_hdr, in_uv + vec2(-o.x, -o.y)).rgb) + keep(texture(tex_hdr, in_uv + vec2(o.x, -o.y)).rgb)
		+ keep(texture(tex_hdr, in_uv + vec2(-o.x, o.y)).rgb) + keep(texture(tex_hdr, in_uv + vec2(o.x, o.y)).rgb);
	out_rgb = vec4(c * 0.25, 1.0);
}
