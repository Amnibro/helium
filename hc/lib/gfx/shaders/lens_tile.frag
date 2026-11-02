layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform Tile { vec4 size; vec4 lens; vec4 mode; };
layout(location = 0) out vec4 out_tile;
float coc_px(float z) { return min(z > 0.0 ? lens.x * abs(1.0 / z - 1.0 / lens.y) : lens.x / lens.y, lens.z); }
void main() {
	ivec2 t = ivec2(gl_FragCoord.xy);
	int k = int(size.z);
	ivec2 lim = ivec2(size.xy) - 1;
	vec2 best = vec2(0.0);
	float bl = 0.0;
	float cm = 0.0;
	for (int y = 0; y < 64; y++) {
		if (y >= k) break;
		for (int x = 0; x < 64; x++) {
			if (x >= k) break;
			ivec2 p = min(t * k + ivec2(x, y), lim);
			vec4 s = texelFetch(tex_src, p, 0);
			if (mode.x < 0.5) { vec2 v = s.xy * size.xy * vec2(1.0, 1.0) * lens.w * 0.5; float l = dot(v, v); if (l > bl) { bl = l; best = v; } }
			else cm = max(cm, coc_px(s.w));
		}
	}
	out_tile = mode.x < 0.5 ? vec4(best, 0.0, 1.0) : vec4(cm, 0.0, 0.0, 1.0);
}
