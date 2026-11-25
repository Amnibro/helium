vec3 c_rot(vec3 p) { return vec3(0.8 * p.y + 0.6 * p.z, 0.36 * p.y - 0.8 * p.x - 0.48 * p.z, 0.64 * p.z - 0.6 * p.x - 0.48 * p.y); }
float c_dens(vec3 q, vec4 sl, vec2 off, float lv) {
	float h = (q.y - sl.x) / sl.y;
	if (h <= 0.0 || h >= 1.0) return 0.0;
	vec3 p = c_rot((q + vec3(off.x, 0.0, off.y)) * vec3(0.32, 0.55, 0.32));
	float b = (0.75 * textureLod(tex_noise, p * 0.05, 0.0).r + 0.109375) / 0.96875 - 1.0 + sl.z * 0.7;
	if (lv < 0.0) return b > -0.1 ? 1.0 : 0.0;
	if (b <= (lv > 0.5 ? -0.1 : 0.0)) return 0.0;
	if (lv > 0.5) {
		p = c_rot(p) * 4.07 + vec3(3.3);
		float d = textureLod(tex_noise, p * 0.05, 0.0).g;
		p = c_rot(p) * 4.07;
		float e = textureLod(tex_noise, p * 0.05, 0.0).b;
		b += 0.3 * (0.83 * d + 0.17 * e - 0.3) * min(b * 10.0 + 1.0, 1.0);
		if (lv > 1.0 && b > -0.05 && b < 0.3) {
			float g = e;
			if (lv > 1.5) {
				p = c_rot(p) * 4.07;
				g = mix(e, textureLod(tex_noise, p * 0.05, 0.0).b, min(lv * 2.0 - 3.0, 1.0));
			}
			b += 0.3 * (0.5 * e + 0.5 * g - 0.3) * min(b * 20.0 + 1.0, 1.0) * smoothstep(0.3, 0.1, b) * min(lv * 2.0 - 2.0, 1.0);
		}
	}
	return max(b, 0.0) * smoothstep(0.0, 0.14, h) * smoothstep(1.0, 0.35, h) * sl.w;
}
float c_hg(float cs, float g) { return 0.0795774715 * (1.0 - g * g) / pow(max(1.0 + g * g - 2.0 * g * cs, 1e-4), 1.5); }
vec3 c_light(vec3 q, float de, vec3 ld, vec4 sl, vec2 off, float cs, vec3 sun, vec3 lo, vec3 hi, float lv) {
	float od = 0.0;
	float t = 0.0;
	float w = 0.08;
	float on = 0.0;
	for (int k = 0; k < 4; k++) { od += c_dens(q + ld * (t + 0.5 * w), sl, off, k < 2 ? min(lv, 1.5) : 0.0) * w; t += w; w *= 2.7; if (k == 1) on = od; }
	float ph = 0.8 * c_hg(cs, 0.6) + 0.2 * c_hg(cs, -0.3);
	float ms = 0.32 * exp(-0.12 * od) * (0.4 + 0.9 * exp(-0.5 * on)) * (1.0 - 0.75 * exp(-0.7 * de));
	return (sun * (ph * exp(-od) + ms) + mix(lo, hi, clamp((q.y - sl.x) / sl.y, 0.0, 1.0))) * 0.97;
}
float c_shadow(vec3 g, vec3 ld, vec4 sl, vec2 off) {
	float ly = max(ld.y, 0.05);
	float t0 = max((sl.x - g.y) / ly, 0.0);
	float dt = sl.y / ly / 34.0;
	float od = 0.0;
	for (int k = 0; k < 34; k++) {
		if (c_dens(g + ld * (t0 + (float(k) + 0.5) * dt), sl, off, -1.0) <= 0.0) continue;
		od += c_dens(g + ld * (t0 + (float(k) + 0.25) * dt), sl, off, 2.0) + c_dens(g + ld * (t0 + (float(k) + 0.75) * dt), sl, off, 2.0);
	}
	return exp(-od * dt * 0.5);
}
