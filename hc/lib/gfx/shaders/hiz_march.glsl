vec3 view_pos(vec2 px, float z) { vec2 c = vec2(px.x * lens.z * 2.0 - 1.0, 1.0 - px.y * lens.w * 2.0); return vec3(c.x * lens.x * z, c.y * lens.y * z, -z); }
vec2 to_px(vec3 q) { float zq = -q.z; return vec2(q.x / (zq * lens.x) * 0.5 + 0.5, 0.5 - q.y / (zq * lens.y) * 0.5) * jit.zw - jit.xy; }
float hz(int lv, ivec2 c) {
	ivec2 o = ivec2(0);
	if (lv == 1) return texelFetch(tex_h1, clamp(c, o, textureSize(tex_h1, 0) - 1), 0).r;
	if (lv == 2) return texelFetch(tex_h2, clamp(c, o, textureSize(tex_h2, 0) - 1), 0).r;
	if (lv == 3) return texelFetch(tex_h3, clamp(c, o, textureSize(tex_h3, 0) - 1), 0).r;
	if (lv == 4) return texelFetch(tex_h4, clamp(c, o, textureSize(tex_h4, 0) - 1), 0).r;
	if (lv == 5) return texelFetch(tex_h5, clamp(c, o, textureSize(tex_h5, 0) - 1), 0).r;
	if (lv == 6) return texelFetch(tex_h6, clamp(c, o, textureSize(tex_h6, 0) - 1), 0).r;
	if (lv == 7) return texelFetch(tex_h7, clamp(c, o, textureSize(tex_h7, 0) - 1), 0).r;
	float d = texelFetch(tex_depth, clamp(c, o, textureSize(tex_depth, 0) - 1), 0).r;
	return d > 0.0 ? 1.0 / d : 0.0;
}
int hiz_march(vec3 p, vec3 r, float len, int steps, float thick, int lv0, out vec2 sh) {
	sh = vec2(0.0);
	float ln = len;
	if (r.z > 0.0 && p.z + r.z * ln > -edge.y) ln = (-edge.y - p.z) / r.z * 0.99;
	vec3 q = p + r * ln;
	vec2 s0 = to_px(p);
	vec2 d = to_px(q) - s0;
	float i0 = -1.0 / p.z;
	float i1 = -1.0 / q.z;
	float dl = max(abs(d.x), abs(d.y));
	if (dl < 0.5) return 2;
	vec2 dd = vec2(abs(d.x) < 1e-5 ? 1e-5 : d.x, abs(d.y) < 1e-5 ? 1e-5 : d.y);
	vec2 te = (mix(vec2(0.0), jit.zw, step(0.0, d)) - s0) / dd;
	float tend = min(1.0, min(te.x, te.y));
	float teps = 0.01 / dl;
	float t = 1.0 / dl;
	int lv = lv0;
	float th = -1.0;
	for (int i = 0; i < 128; i++) {
		if (i >= steps || t >= tend) break;
		float cs = exp2(float(lv));
		vec2 cell = floor((s0 + d * t) / cs);
		vec2 tb = ((cell + step(0.0, d)) * cs - s0) / dd;
		float tx = min(min(tb.x, tb.y), tend);
		float ia = mix(i0, i1, t);
		float ib = mix(i0, i1, tx);
		float ci = hz(lv, ivec2(cell));
		if (min(ia, ib) > ci) { t = tx + teps; lv = min(lv + 1, 7); continue; }
		if (lv > lv0) { t = i1 < i0 ? max(t, (ci - i0) / (i1 - i0)) : t; lv -= 1; continue; }
		if (1.0 / max(ia, ib) <= 1.0 / ci + thick) { th = i1 < i0 ? clamp((ci - i0) / (i1 - i0), t, tx) : t; break; }
		t = tx + teps;
	}
	if (th < 0.0) return t >= tend ? 2 : 1;
	sh = s0 + d * th;
	return 0;
}
