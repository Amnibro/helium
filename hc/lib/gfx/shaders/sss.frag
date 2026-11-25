layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_irr;
layout(set = 2, binding = 1) uniform sampler2D tex_set;
layout(set = 2, binding = 2) uniform sampler2D tex_depth;
layout(set = 3, binding = 0) uniform Sss { vec4 lens; vec4 tune; vec4 ctr; vec4 prof[8]; vec4 tap[64]; };
layout(location = 0) out vec4 out_rgba;
float zat(ivec2 p) { return texelFetch(tex_depth, clamp(p, ivec2(0), ivec2(lens.yz) - 1), 0).r; }
float pick(float a, float b) { return abs(a) < abs(b) ? a : b; }
void main() {
	ivec2 p = ivec2(gl_FragCoord.xy);
	vec4 c = texelFetch(tex_irr, p, 0);
	out_rgba = vec4(0.0);
	if (c.a < 0.5) return;
	vec4 pr = prof[clamp(int(c.a - 0.5), 0, 7)];
	float z0 = zat(p);
	if (pr.w * lens.x < 0.5 * z0) return;
	vec2 g = tune.z < 0.5 ? vec2(0.0) : vec2(pick(z0 - zat(p + ivec2(-1, 0)), zat(p + ivec2(1, 0)) - z0), pick(z0 - zat(p + ivec2(0, -1)), zat(p + ivec2(0, 1)) - z0));
	vec2 c0 = vec2(p) + 0.5;
	vec2 o = c0 - ctr.xy;
	vec3 a = vec3(z0 + o.x * g.x, o.y * g.x, g.x * lens.x) / lens.x;
	vec3 b = vec3(o.x * g.y, z0 + o.y * g.y, g.y * lens.x) / lens.x;
	float la = length(a);
	float lb = dot(a, b) / la;
	float lc = sqrt(max(dot(b, b) - lb * lb, 1e-12));
	float l2 = 0.5 * log2(pr.w * pr.w / (la * lc));
	float ia = pr.w / la;
	float ic = pr.w / lc;
	float ib = -lb / la * ic;
	float rot = tune.w > 0.5 ? 6.2831853 * fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715))) + tune.w * 0.61803399) : 0.0;
	float cr = cos(rot);
	float sr = sin(rot);
	vec3 sw = vec3(0.0);
	vec3 sv = vec3(0.0);
	int n = int(lens.w + 0.5);
	for (int i = 0; i < 64; i++) {
		if (i >= n) break;
		vec4 t = tap[i];
		vec2 r = vec2(t.x * cr - t.y * sr, t.x * sr + t.y * cr);
		vec2 q = c0 + vec2(r.x * ia + r.y * ib, r.y * ic);
		if (q.x < 0.0 || q.y < 0.0 || q.x >= lens.y || q.y >= lens.z) continue;
		ivec2 ip = ivec2(q);
		vec4 s = textureLod(tex_set, q / lens.yz, clamp(t.w + l2, 0.0, tune.x));
		if (s.a > 1e-4) { s = texelFetch(tex_set, ip, 0); if (s.a > 0.75) continue; }
		float zt = tune.z < 0.5 ? z0 : zat(ip) + dot(g, q - vec2(ip) - 0.5);
		float rt = max(length(vec3((q - ctr.xy) * zt - o * z0, (zt - z0) * lens.x)) / lens.x, 1e-7);
		vec3 e3 = exp(-rt / (3.0 * pr.rgb));
		vec3 w = (e3 * e3 * e3 + e3) / rt * t.z;
		sw += w;
		sv += w * s.rgb;
	}
	out_rgba = vec4(sw.r > 0.0 ? sv.r / sw.r : c.r, sw.g > 0.0 ? sv.g / sw.g : c.g, sw.b > 0.0 ? sv.b / sw.b : c.b, 1.0);
}
