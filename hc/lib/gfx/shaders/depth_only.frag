// Shadow-map pass: depth only, with alpha-mask cut-outs.
layout(location = 3) in vec4 in_uv;
layout(location = 4) in vec4 in_col;
layout(set = 2, binding = 0) uniform sampler2D tex_base;
layout(set = 3, binding = 0) uniform Cutout { vec4 base; vec4 alpha; vec4 uv_sets; };
void main() {
	if (alpha.x > 0.5 && alpha.x < 1.5) {
		vec2 uv = uv_sets.x > 0.5 ? in_uv.zw : in_uv.xy;
		if (base.a * in_col.a * texture(tex_base, uv).a < alpha.y) discard;
	}
}
