layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_tile;
layout(set = 3, binding = 0) uniform Near { vec4 size; vec4 mode; };
layout(location = 0) out vec4 out_tile;
void main() {
	ivec2 t = ivec2(gl_FragCoord.xy);
	ivec2 lim = ivec2(size.xy) - 1;
	vec2 best = vec2(0.0);
	float bl = 0.0;
	float cm = 0.0;
	for (int y = -1; y <= 1; y++)
		for (int x = -1; x <= 1; x++) {
			vec4 s = texelFetch(tex_tile, clamp(t + ivec2(x, y), ivec2(0), lim), 0);
			float l = dot(s.xy, s.xy);
			if (mode.x < 0.5 && l > bl) { bl = l; best = s.xy; }
			cm = max(cm, s.x);
		}
	out_tile = mode.x < 0.5 ? vec4(best, 0.0, 1.0) : vec4(cm, 0.0, 0.0, 1.0);
}
