const int GI_IRR = 8;
const int GI_DIST = 16;
float gi_any(vec3 o, vec3 d, float tmax, bool any_hit, out int tri) {
	vec3 inv = 1.0 / vec3(abs(d.x) < 1e-12 ? 1e-12 : d.x, abs(d.y) < 1e-12 ? 1e-12 : d.y, abs(d.z) < 1e-12 ? 1e-12 : d.z);
	int st[32];
	int sp = 0;
	st[sp++] = 0;
	float best = tmax;
	tri = -1;
	while (sp > 0) {
		int nd = st[--sp];
		vec4 a = bvh_nodes[nd * 2];
		vec4 b = bvh_nodes[nd * 2 + 1];
		vec3 t0 = (a.xyz - o) * inv;
		vec3 t1 = (b.xyz - o) * inv;
		vec3 tl = min(t0, t1);
		vec3 th = max(t0, t1);
		float tn = max(max(tl.x, tl.y), max(tl.z, 0.0));
		float tf = min(min(th.x, th.y), min(th.z, best));
		if (tn > tf) continue;
		int c = int(b.w);
		int f = int(a.w);
		if (c == 0) { if (sp < 31) { st[sp++] = f; st[sp++] = f + 1; } continue; }
		for (int k = 0; k < c; k++) {
			int q = (f + k) * 4;
			vec3 v0 = bvh_tris[q].xyz;
			vec3 e1 = bvh_tris[q + 1].xyz;
			vec3 e2 = bvh_tris[q + 2].xyz;
			vec3 p = cross(d, e2);
			float det = dot(e1, p);
			if (abs(det) < 1e-12) continue;
			float id = 1.0 / det;
			vec3 s = o - v0;
			float u = dot(s, p) * id;
			if (u < 0.0 || u > 1.0) continue;
			vec3 qv = cross(s, e1);
			float v = dot(d, qv) * id;
			if (v < 0.0 || u + v > 1.0) continue;
			float t = dot(e2, qv) * id;
			if (t > 1e-4 && t < best) { best = t; tri = f + k; if (any_hit) return best; }
		}
	}
	return best;
}
bool gi_visible(vec3 o, vec3 d, float tmax) { int t; gi_any(o, d, tmax, true, t); return t < 0; }
vec2 gi_oct(vec3 n) {
	n /= abs(n.x) + abs(n.y) + abs(n.z);
	vec2 e = n.z >= 0.0 ? n.xy : (1.0 - abs(n.yx)) * vec2(n.x >= 0.0 ? 1.0 : -1.0, n.y >= 0.0 ? 1.0 : -1.0);
	return e * 0.5 + 0.5;
}
vec3 gi_unoct(vec2 uv) {
	vec2 f = uv * 2.0 - 1.0;
	vec3 n = vec3(f, 1.0 - abs(f.x) - abs(f.y));
	float t = max(-n.z, 0.0);
	n.x += n.x >= 0.0 ? -t : t;
	n.y += n.y >= 0.0 ? -t : t;
	return normalize(n);
}
vec4 gi_texel_irr(int probe, ivec2 c) { c = clamp(c, ivec2(0), ivec2(GI_IRR - 1)); return probe_irr[probe * GI_IRR * GI_IRR + c.y * GI_IRR + c.x]; }
vec2 gi_texel_dist(int probe, ivec2 c) { c = clamp(c, ivec2(0), ivec2(GI_DIST - 1)); return probe_dist[probe * GI_DIST * GI_DIST + c.y * GI_DIST + c.x]; }
vec3 gi_sample_irr(int probe, vec3 dir) {
	vec2 x = gi_oct(dir) * float(GI_IRR) - 0.5;
	ivec2 i = ivec2(floor(x));
	vec2 f = x - vec2(i);
	return mix(mix(gi_texel_irr(probe, i).rgb, gi_texel_irr(probe, i + ivec2(1, 0)).rgb, f.x), mix(gi_texel_irr(probe, i + ivec2(0, 1)).rgb, gi_texel_irr(probe, i + ivec2(1, 1)).rgb, f.x), f.y);
}
vec2 gi_sample_dist(int probe, vec3 dir) {
	vec2 x = gi_oct(dir) * float(GI_DIST) - 0.5;
	ivec2 i = ivec2(floor(x));
	vec2 f = x - vec2(i);
	return mix(mix(gi_texel_dist(probe, i), gi_texel_dist(probe, i + ivec2(1, 0)), f.x), mix(gi_texel_dist(probe, i + ivec2(0, 1)), gi_texel_dist(probe, i + ivec2(1, 1)), f.x), f.y);
}
vec3 gi_probe_pos(ivec3 c, vec4 origin, vec4 step) { return origin.xyz + vec3(c) * step.xyz; }
int gi_probe_index(ivec3 c, vec4 dims) { return (c.z * int(dims.y) + c.y) * int(dims.x) + c.x; }
vec3 gi_irradiance(vec3 p, vec3 n, vec3 v, vec4 origin, vec4 step, vec4 dims) {
	float sp = min(step.x, min(step.y, step.z));
	vec3 bp = p + (n * 0.2 + v * 0.8) * (step.w * sp);
	ivec3 lim = ivec3(dims.xyz) - 1;
	vec3 g = (bp - origin.xyz) / step.xyz;
	ivec3 base = clamp(ivec3(floor(g)), ivec3(0), max(lim - 1, ivec3(0)));
	vec3 a = clamp(g - vec3(base), 0.0, 1.0);
	vec3 sum = vec3(0.0);
	float wsum = 0.0;
	vec3 rsum = vec3(0.0);
	float rwsum = 0.0;
	bool rtv = origin.w > 0.5;
	for (int k = 0; k < 8; k++) {
		ivec3 o = ivec3(k & 1, (k >> 1) & 1, (k >> 2) & 1);
		ivec3 c = min(base + o, lim);
		vec3 pp = gi_probe_pos(c, origin, step);
		int pi = gi_probe_index(c, dims);
		vec3 tri = mix(1.0 - a, a, vec3(o));
		float w = tri.x * tri.y * tri.z;
		vec3 to = normalize(pp - p);
		float bf = (dot(to, n) + 1.0) * 0.5;
		float vw = bf * bf + 0.2;
		vec3 dl = bp - pp;
		float r = length(dl);
		vec3 irr = gi_sample_irr(pi, n);
		if (rtv && r > 1e-4 && gi_visible(bp, -dl / r, r)) { float rw = w * vw; rsum += rw * irr; rwsum += rw; }
		vec2 m = gi_sample_dist(pi, dl / max(r, 1e-6));
		float cheb = 1.0;
		if (r > m.x) { float var = abs(m.y - m.x * m.x); float dd = r - m.x; cheb = var / (var + dd * dd); cheb = max(cheb * cheb * cheb, 0.0); }
		vw *= max(0.05, cheb);
		vw = max(vw, 1e-6);
		if (vw < 0.2) vw *= vw * vw * 25.0;
		w *= vw;
		sum += w * irr;
		wsum += w;
	}
	if (rwsum > 1e-4) return rsum / rwsum;
	return wsum > 0.0 ? sum / wsum : vec3(0.0);
}
