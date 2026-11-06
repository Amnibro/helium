layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_color;
layout(set = 2, binding = 1) uniform sampler2D tex_near;
layout(set = 3, binding = 0) uniform Dof { vec4 size; vec4 lens; vec4 tune; };
layout(location = 0) out vec4 out_rgba;
float coc_px(float z) { return min(z > 0.0 ? lens.x * abs(1.0 / z - 1.0 / lens.y) : lens.x / lens.y, lens.z); }
void main() {
	ivec2 x = ivec2(gl_FragCoord.xy);
	ivec2 lim = ivec2(size.xy) - 1;
	vec4 c = texelFetch(tex_color, x, 0);
	float rmax = texelFetch(tex_near, x / int(size.w), 0).x;
	if (rmax <= 0.5) { out_rgba = vec4(c.rgb, 1.0); return; }
	float zc = c.a;
	float cc = coc_px(zc);
	float wc = 1.0 / max(cc * cc, 1.0);
	vec3 sum = c.rgb * wc;
	float w = wc;
	int n = min(int(tune.x), max(16, int(rmax * rmax * 1.5)));
	float rot = fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)))) * 6.2831853;
	for (int i = 0; i < 128; i++) {
		if (i >= n) break;
		float fi = float(i) + 0.5;
		float r = rmax * sqrt(fi / float(n));
		float a = fi * 2.39996323 + rot;
		ivec2 y = clamp(x + ivec2(round(vec2(cos(a), sin(a)) * r)), ivec2(0), lim);
		float d = length(vec2(y - x));
		vec4 cs4 = texelFetch(tex_color, y, 0);
		float zs = cs4.a;
		float cs = coc_px(zs);
		float cov = clamp(cs - d + 0.5, 0.0, 1.0);
		if (zs > zc && zc > 0.0 || zs <= 0.0 && zc > 0.0) cov *= clamp(cc - d + 0.5, 0.0, 1.0);
		float ws = cov / max(cs * cs, 1.0);
		w += ws;
		sum += ws * cs4.rgb;
	}
	out_rgba = vec4(sum / w, 1.0);
}
