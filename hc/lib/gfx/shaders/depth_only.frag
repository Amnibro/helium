// Shadow-map pass: depth only, with alpha-mask cut-outs.
layout(location = 3) in vec4 in_uv;
layout(location = 4) in vec4 in_col;
layout(set = 2, binding = 0) uniform sampler2D tex_base;
layout(set = 3, binding = 0) uniform Cutout { vec4 base; vec4 alpha; vec4 uv_sets; vec4 xm; vec4 xo; };
void main() {
	if (alpha.x > 0.5 && alpha.x < 1.5) {
		vec2 u0 = uv_sets.x > 0.5 ? in_uv.zw : in_uv.xy;
		vec2 uv = vec2(dot(xm.xy, u0), dot(xm.zw, u0)) + xo.xy;
		if (base.a * in_col.a * texture(tex_base, uv).a < alpha.y) discard;
	}
}
