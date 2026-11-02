layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_color;
layout(set = 2, binding = 1) uniform sampler2D tex_motion;
layout(set = 2, binding = 2) uniform sampler2D tex_near;
layout(set = 3, binding = 0) uniform Blur { vec4 size; vec4 tune; };
layout(location = 0) out vec4 out_rgba;
float ign(vec2 p) { return fract(52.9829189 * fract(dot(p, vec2(0.06711056, 0.00583715)))); }
float len_px(ivec2 p) { float l = length(texelFetch(tex_motion, p, 0).xy * size.xy) * tune.x * 0.5; return min(l, tune.y); }
float front(float zx, float zy) { return clamp(0.5 + (zx - zy) / (tune.w * max(min(zx, zy), 1e-3)), 0.0, 1.0); }
float spread(float l, float d) { return clamp(l - d + 0.5, 0.0, 1.0); }
void main() {
	ivec2 x = ivec2(gl_FragCoord.xy);
	ivec2 lim = ivec2(size.xy) - 1;
	vec4 c = texelFetch(tex_color, x, 0);
	vec2 vmax = texelFetch(tex_near, x / int(size.w), 0).xy;
	float lm = length(vmax);
	if (lm > tune.y) { vmax *= tune.y / lm; lm = tune.y; }
	if (lm <= 0.5) { out_rgba = c; return; }
	float lx = len_px(x);
	float zx = texelFetch(tex_motion, x, 0).z;
	int pairs = max(int(tune.z) / 2, 1);
	float j = ign(gl_FragCoord.xy) - 0.5;
	vec3 sum = vec3(0.0);
	float w = 0.0;
	for (int i = 0; i < 32; i++) {
		if (i >= pairs) break;
		float t = (float(i) + 0.5 + 0.5 * j) / float(pairs);
		ivec2 o = ivec2(round(vmax * t));
		ivec2 y1 = clamp(x + o, ivec2(0), lim);
		ivec2 y2 = clamp(x - o, ivec2(0), lim);
		float d = length(vec2(o));
		float l1 = len_px(y1), l2 = len_px(y2);
		float z1 = texelFetch(tex_motion, y1, 0).z, z2 = texelFetch(tex_motion, y2, 0).z;
		float f1 = front(zx, z1), f2 = front(zx, z2);
		float w1 = f1 * spread(l1, d) + (1.0 - f1) * spread(lx, d);
		float w2 = f2 * spread(l2, d) + (1.0 - f2) * spread(lx, d);
		bool m1 = z1 > z2, m2 = l2 > l1;
		w1 = m1 && m2 ? w2 : w1;
		w2 = m1 || m2 ? w2 : w1;
		sum += w1 * texelFetch(tex_color, y1, 0).rgb + w2 * texelFetch(tex_color, y2, 0).rgb;
		w += w1 + w2;
	}
	float n = float(2 * pairs);
	out_rgba = vec4((sum + max(n - w, 0.0) * c.rgb) / max(n, w), c.a);
}
