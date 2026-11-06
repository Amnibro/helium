layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform Hiz { vec4 hz; };
layout(location = 0) out vec4 out_iz;
float iz_at(ivec2 p) {
	float d = texelFetch(tex_src, min(p, ivec2(hz.yz)), 0).r;
	return hz.x > 0.5 ? (d > 0.0 ? 1.0 / d : 0.0) : d;
}
void main() {
	ivec2 p = ivec2(gl_FragCoord.xy) * 2;
	out_iz = vec4(max(max(iz_at(p), iz_at(p + ivec2(1, 0))), max(iz_at(p + ivec2(0, 1)), iz_at(p + ivec2(1, 1)))), 0.0, 0.0, 1.0);
}
