// Double-size expansion with a 3x3 tent, added onto the larger level (additive blend).
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform Glow { vec4 texel; vec4 cut; }; // cut.w: weight
layout(location = 0) out vec4 out_rgb;
void main() {
	vec2 o = texel.xy;
	vec3 c = texture(tex_src, in_uv).rgb * 4.0;
	c += (texture(tex_src, in_uv + vec2(o.x, 0.0)).rgb + texture(tex_src, in_uv - vec2(o.x, 0.0)).rgb
		+ texture(tex_src, in_uv + vec2(0.0, o.y)).rgb + texture(tex_src, in_uv - vec2(0.0, o.y)).rgb) * 2.0;
	c += texture(tex_src, in_uv + o).rgb + texture(tex_src, in_uv - o).rgb
		+ texture(tex_src, in_uv + vec2(o.x, -o.y)).rgb + texture(tex_src, in_uv + vec2(-o.x, o.y)).rgb;
	out_rgb = vec4(c / 16.0 * cut.w, 1.0);
}
