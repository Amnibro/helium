layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_irr;
layout(set = 2, binding = 1) uniform sampler2D tex_depth;
layout(set = 3, binding = 0) uniform Sss { vec4 lens; vec4 tune; vec4 ctr; vec4 prof[8]; vec4 tap[64]; };
layout(location = 0) out vec4 out_rgba;
float zat(ivec2 p) { return texelFetch(tex_depth, clamp(p, ivec2(0), ivec2(lens.yz) - 1), 0).r; }
void main() {
	ivec2 p = ivec2(gl_FragCoord.xy);
	vec4 c = texelFetch(tex_irr, p, 0);
	if (c.a < 0.5) { out_rgba = vec4(0.0, 0.0, 0.0, 1.0); return; }
	float z = zat(p);
	float e = max(abs(zat(p + ivec2(-1, 0)) + zat(p + ivec2(1, 0)) - 2.0 * z), abs(zat(p + ivec2(0, -1)) + zat(p + ivec2(0, 1)) - 2.0 * z));
	out_rgba = vec4(c.rgb, e > tune.y * prof[clamp(int(c.a - 0.5), 0, 7)].w ? 0.5 : 0.0);
}
