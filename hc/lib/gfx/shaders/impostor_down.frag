layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_a;
layout(set = 2, binding = 1) uniform sampler2D tex_b;
layout(set = 3, binding = 0) uniform Down { vec4 k; };
layout(location = 0) out vec4 out_a;
layout(location = 1) out vec4 out_b;
void main() {
	int s = int(k.x);
	ivec2 o = ivec2(gl_FragCoord.xy) * s;
	vec4 sa = vec4(0.0);
	vec4 sb = vec4(0.0);
	for (int y = 0; y < s; y++) {
		for (int x = 0; x < s; x++) {
			vec4 a = texelFetch(tex_a, o + ivec2(x, y), 0);
			vec4 b = texelFetch(tex_b, o + ivec2(x, y), 0);
			sa += vec4(a.rgb * a.a, a.a);
			sb += vec4(b.rgb * 0.5 + 0.5, b.a) * a.a;
		}
	}
	float q = 1.0 / float(s * s);
	out_a = sa * q;
	out_b = sb * q;
}
