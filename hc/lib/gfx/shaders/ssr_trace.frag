layout(set = 2, binding = 0) uniform sampler2D tex_depth;
layout(set = 2, binding = 1) uniform sampler2D tex_h1;
layout(set = 2, binding = 2) uniform sampler2D tex_h2;
layout(set = 2, binding = 3) uniform sampler2D tex_h3;
layout(set = 2, binding = 4) uniform sampler2D tex_h4;
layout(set = 2, binding = 5) uniform sampler2D tex_h5;
layout(set = 2, binding = 6) uniform sampler2D tex_h6;
layout(set = 2, binding = 7) uniform sampler2D tex_h7;
layout(set = 2, binding = 8) uniform sampler2D tex_nd;
layout(set = 2, binding = 9) uniform sampler2D tex_motion;
layout(set = 3, binding = 0) uniform Ssr { vec4 lens; vec4 jit; vec4 tune; vec4 edge; mat4 inv_view; mat4 prev_vp; };
layout(location = 0) out vec4 out_hit;
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
void main() {
	out_hit = vec4(0.0);
	ivec2 x = ivec2(gl_FragCoord.xy);
	float z = texelFetch(tex_depth, x, 0).r;
	if (z <= 0.0) return;
	vec3 n = normalize(texelFetch(tex_nd, x, 0).xyz);
	vec3 p0 = view_pos(gl_FragCoord.xy + jit.xy, z);
	vec3 r = reflect(normalize(p0), n);
	if (dot(r, n) <= 0.0) return;
	vec3 p = p0 + n * (3.0 * z * lens.y / jit.w);
	float len = tune.z;
	if (r.z > 0.0 && p.z + r.z * len > -edge.y) len = (-edge.y - p.z) / r.z * 0.99;
	vec3 q = p + r * len;
	vec2 s0 = to_px(p);
	vec2 d = to_px(q) - s0;
	float i0 = -1.0 / p.z;
	float i1 = -1.0 / q.z;
	float dl = max(abs(d.x), abs(d.y));
	if (dl < 0.5) return;
	vec2 dd = vec2(abs(d.x) < 1e-5 ? 1e-5 : d.x, abs(d.y) < 1e-5 ? 1e-5 : d.y);
	vec2 te = (mix(vec2(0.0), jit.zw, step(0.0, d)) - s0) / dd;
	float tend = min(1.0, min(te.x, te.y));
	float teps = 0.01 / dl;
	float t = 1.0 / dl;
	int lv = 0;
	float th = -1.0;
	for (int i = 0; i < 128; i++) {
		if (i >= int(tune.x) || t >= tend) break;
		float cs = exp2(float(lv));
		vec2 cell = floor((s0 + d * t) / cs);
		vec2 tb = ((cell + step(0.0, d)) * cs - s0) / dd;
		float tx = min(min(tb.x, tb.y), tend);
		float ia = mix(i0, i1, t);
		float ib = mix(i0, i1, tx);
		float ci = hz(lv, ivec2(cell));
		if (min(ia, ib) > ci) { t = tx + teps; lv = min(lv + 1, 7); continue; }
		if (lv > 0) { t = i1 < i0 ? max(t, (ci - i0) / (i1 - i0)) : t; lv -= 1; continue; }
		if (1.0 / max(ia, ib) <= 1.0 / ci + tune.y) { th = i1 < i0 ? clamp((ci - i0) / (i1 - i0), t, tx) : t; break; }
		t = tx + teps;
	}
	if (th < 0.0) return;
	vec2 sh = s0 + d * th;
	ivec2 hx = clamp(ivec2(floor(sh)), ivec2(0), ivec2(jit.zw) - 1);
	float zh = texelFetch(tex_depth, hx, 0).r;
	if (zh <= 0.0) return;
	vec3 nh = texelFetch(tex_nd, hx, 0).xyz;
	vec3 ph = view_pos(sh + jit.xy, zh);
	float dist = length(ph - p);
	vec2 uv = sh / jit.zw;
	vec2 e = clamp(min(uv, 1.0 - uv) / max(edge.x, 1e-4), 0.0, 1.0);
	float conf = e.x * e.y * (1.0 - smoothstep(0.7, 1.0, dist / tune.z)) * smoothstep(0.0, 0.17, -dot(nh, r));
	vec4 c = prev_vp * (inv_view * vec4(ph, 1.0));
	vec2 pu = tune.w > 0.5 ? (sh + jit.xy) / jit.zw - texelFetch(tex_motion, hx, 0).xy : vec2(c.x / c.w * 0.5 + 0.5, 0.5 - c.y / c.w * 0.5);
	if (any(lessThan(pu, vec2(0.0))) || any(greaterThan(pu, vec2(1.0))) || conf <= 0.0) return;
	out_hit = vec4(pu, dist / zh, conf);
}
