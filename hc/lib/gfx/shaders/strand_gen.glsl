float hsh(uint a, uint b) { uint h = a * 747796405u + b * 2891336453u + 1u; h ^= h >> 16; h *= 2246822519u; h ^= h >> 13; h *= 3266489917u; h ^= h >> 16; return float(h & 0xffffffu) / 16777216.0; }
vec3 hSigma(vec2 m) { return m.x * vec3(0.419, 0.697, 1.37) + m.y * vec3(0.187, 0.4, 1.05) + ext.xyz; }
float seg_g;
float seg_w;
uint sP;
uint sG;
float sT0;
float sT1;
float sLk;
float sCvs;
vec3 sA;
vec3 sB;
vec3 ptan(uint p) { return normalize(cross(pts[p * 3u + 1u].xyz, pts[p * 3u + 2u].xyz) + vec3(0.0, -1e-7, 0.0)); }
vec3 partShift(uint p, float u) {
	vec4 a = pts[p * 3u], sd = pts[p * 3u + 1u];
	vec3 x = a.xyz + sd.xyz * u;
	float w = smoothstep(0.004, 0.0, abs(x.x)) * smoothstep(shape.y + 0.012, shape.y + 0.042, x.z) * smoothstep(shape.x - 0.064, shape.x - 0.024, x.y) * (1.0 - smoothstep(0.0, 0.6, sd.w));
	return vec3(sign(x.x + 1e-6) * shape.z * w, 0.0, 0.0);
}
vec3 strandPos(uint p, float u, float dz, float wob, float ph, float fo) {
	vec4 a = pts[p * 3u], s = pts[p * 3u + 1u], n = pts[p * 3u + 2u];
	float t = s.w;
	return a.xyz + s.xyz * u + n.xyz * (dz + fo * t * t + wob * t * sin(ph + t * 23.0)) + normalize(s.xyz + vec3(1e-7)) * wob * 0.5 * t * cos(ph * 1.7 + t * 17.0);
}
bool strandSeg(uint si, uint j) {
	if (si >= uint(size.w) || float(j) >= size.z) return false;
	uvec4 sg = segs[si];
	uint p = sg.x, g = sg.y, kz = sg.z & 255u, kg = (sg.z >> 8) & 255u, kw = (sg.z >> 16) & 255u;
	seg_g = kg > 0u ? float(kg) / 64.0 : 1.0;
	seg_w = kw > 0u ? float(kw) / 64.0 : 1.0;
	float sc = kz > 0u ? min(float(kz), size.z) : size.z, lk = pts[p * 3u + 2u].w, sn = lk > 0.5 ? sc * 0.45 : sc, sx = max(sn * (ext.w > 0.0 ? min(ext.w, 1.0) : 1.0), min(sn, 1.0));
	if (float(j) >= sx) return false;
	float cvs = sn / sx * min(sx - float(j), 1.0);
	float h1 = hsh(g, j * 4u + 1u), h2 = hsh(g, j * 4u + 2u), h3 = hsh(g, j * 4u + 3u);
	float t0 = pts[p * 3u + 1u].w, t1 = pts[p * 3u + 4u].w;
	float tend = 1.0 - 0.32 * h2 * h2;
	if (t0 >= tend) return false;
	float fly = step(0.965 - 0.1 * sun_rgb.w, hsh(g, j * 4u + 31u));
	float nc = 3.0 + floor(hsh(g, 999u) * 5.0), cl = floor(h3 * nc), cc = (hsh(g, 1000u + uint(cl)) * 2.0 - 1.0) * 1.2, cz = (hsh(g, 2000u + uint(cl)) - 0.5) * params.z;
	float u0 = (fract(hsh(g, 7u) + float(j) * 0.6180339887) * 2.0 - 1.0) * 1.4, cs = (lk > 0.5 ? 0.18 : 0.62) + 0.25 * hsh(g, j * 4u + 77u) - fly * 0.4;
	float ua = mix(u0, cc, min(cs + 0.3 * t0, 0.97)), ub = mix(u0, cc, min(cs + 0.3 * t1, 0.97));
	float dz = mix((h1 - 0.5) * params.z, cz, lk > 0.5 ? 0.3 : 0.75) * (lk > 0.5 ? 2.2 : 1.0), wob = (0.0007 + fly * (0.0047 + 0.004 * sun_rgb.w) + lk * 0.0011) * hsh(g, j + 500u), ph = 6.2831 * h3, fo = fly * sun_rgb.w * 0.012 * (0.3 + hsh(g, j * 4u + 41u));
	vec3 A = strandPos(p, ua, dz, wob, ph, fo) + partShift(p, ua), B = strandPos(p + 1u, ub, dz, wob, ph, fo) + partShift(p + 1u, ub);
	if (t1 > tend) B = mix(A, B, (tend - t0) / max(t1 - t0, 1e-5));
	sP = p; sG = g; sT0 = t0; sT1 = t1; sLk = lk; sCvs = cvs; sA = A; sB = B;
	return true;
}
vec3 strandSig(uint g, uint j, float t) {
	float hs = hsh(g, j * 4u + 9u), hm = hsh(g, j * 4u + 11u);
	vec2 mm = mel.xy * (1.0 + 0.05 * (hsh(g, 3u) * 2.0 - 1.0)) * (1.0 + 0.22 * (hs * 2.0 - 1.0)) * vec2(1.0, 1.0 + 0.5 * hm * hm);
	return hSigma(mm * mix(1.7, 1.0, smoothstep(0.0, 0.35, t)) * mix(1.0, 0.85, smoothstep(0.6, 1.0, t))) * 1.7;
}
