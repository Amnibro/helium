// Half-size reduction: four bilinear taps around the destination texel centre.
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform Glow { vec4 texel; vec4 cut; };
layout(location = 0) out vec4 out_rgb;
void main() {
	vec2 o = texel.xy;
	vec3 c = texture(tex_src, in_uv + vec2(-o.x, -o.y)).rgb + texture(tex_src, in_uv + vec2(o.x, -o.y)).rgb
		+ texture(tex_src, in_uv + vec2(-o.x, o.y)).rgb + texture(tex_src, in_uv + vec2(o.x, o.y)).rgb;
	out_rgb = vec4(c * 0.25, 1.0);
}
