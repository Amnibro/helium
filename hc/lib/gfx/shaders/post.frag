// Final image: exposure, bloom mix, an extended-Reinhard curve on luminance with
// a white point (values at or above it map to 1), a small highlight
// desaturation, and the sRGB transfer function written by hand (the target is
// a linear RGBA8 texture).
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_glow;
layout(set = 2, binding = 2) uniform sampler3D tex_lut;
layout(std430, set = 2, binding = 3) readonly buffer Expo { float expo[]; };
layout(set = 3, binding = 0) uniform Grade { vec4 tone; vec4 mode; vec4 lens; vec4 color; vec4 frame; vec4 drops; }; // exposure, white point, bloom amount, desaturation
layout(location = 0) out vec4 out_rgba;

float encode_srgb(float x) {
	x = clamp(x, 0.0, 1.0);
	return x <= 0.0031308 ? 12.92 * x : 1.055 * pow(x, 1.0 / 2.4) - 0.055;
}
float hash_px(vec2 p) { vec3 q = fract(vec3(p.xyx) * 0.1031); q += dot(q, q.yzx + 33.33); return fract((q.x + q.y) * q.z); }
vec4 graded(vec3 o) {
	vec3 e = vec3(encode_srgb(o.r), encode_srgb(o.g), encode_srgb(o.b));
	vec2 px = in_uv * frame.xy;
	return vec4((mode.z > 0.0 ? mix(e, texture(tex_lut, e * ((mode.w - 1.0) / mode.w) + 0.5 / mode.w).rgb, mode.z) : e) + (hash_px(px) + hash_px(px + 17.3) - 1.0) / 255.0, 1.0) * vec4(vec3(drops.w > 0.0 && abs(in_uv.y - 0.5) * drops.w * frame.y > 0.5 * frame.x ? 0.0 : 1.0), 1.0);
}

vec3 agx(vec3 c) {
	mat3 m = mat3(vec3(0.842479062253094, 0.0423282422610123, 0.0423756549057051), vec3(0.0784335999999992, 0.878468636469772, 0.0784336), vec3(0.0792237451477643, 0.0791661274605434, 0.879142973793104));
	mat3 o = mat3(vec3(1.19687900512017, -0.0528968517574562, -0.0529716355144438), vec3(-0.0980208811401368, 1.15190312990417, -0.0980434501171241), vec3(-0.0990297440797205, -0.0989611768448433, 1.15107367264116));
	vec3 v = m * max(c, vec3(1e-10));
	v = (clamp(log2(v), vec3(-12.47393), vec3(4.026069)) + 12.47393) / 16.5;
	vec3 v2 = v * v;
	vec3 v4 = v2 * v2;
	v = 15.5 * v4 * v2 - 40.14 * v4 * v + 31.96 * v4 - 6.868 * v2 * v + 0.4298 * v2 + 0.1191 * v - 0.00232;
	return pow(max(o * v, vec3(0.0)), vec3(2.2));
}
vec3 neutral(vec3 c) {
	float x = min(c.r, min(c.g, c.b));
	float off = x < 0.08 ? x - 6.25 * x * x : 0.04;
	vec3 r = c - off;
	float peak = max(r.r, max(r.g, r.b));
	if (peak < 0.76) return r;
	float np = 1.0 - 0.0576 / (peak - 0.52);
	r *= np / peak;
	return mix(r, vec3(np), 1.0 - 1.0 / (0.15 * (peak - np) + 1.0));
}
vec3 lens_drop(vec2 uv, float asp, float amt, float t) {
	vec3 o = vec3(0.0, 0.0, 1.0);
	for (int l = 2; l >= 0; l--) {
		float n = l == 0 ? 7.0 : (l == 1 ? 15.0 : 29.0);
		vec2 q = vec2(uv.x * asp, uv.y) * n + float(l) * 3.7;
		float col = floor(q.x);
		if (l == 0) q.y -= t * n * (0.02 + 0.1 * hash_px(vec2(col, 7.7))) - hash_px(vec2(col, 2.9));
		vec2 id = floor(q);
		float life = 7.0 + 5.0 * hash_px(id + 11.3);
		float lt = t / life + hash_px(id + 5.1);
		float ph = l == 0 ? 0.5 : fract(lt);
		vec2 rid = id + (l == 0 ? 0.0 : floor(lt)) * 0.37;
		if (hash_px(rid + 1.7) > amt * 0.7) continue;
		vec2 d = q - (id + 0.5 + (vec2(hash_px(rid + 3.1), hash_px(rid + 8.3)) - 0.5) * 0.2);
		float r = 0.17 + 0.17 * hash_px(rid + 4.9);
		vec2 dn = vec2(d.x * (0.85 + 0.3 * hash_px(rid + 2.3)), d.y * (1.0 + 0.12 * d.y / r)) / r;
		float k = length(dn);
		if (k >= 1.0) continue;
		float m = smoothstep(1.0, 0.9, k) * smoothstep(0.0, 0.1, ph) * smoothstep(1.0, 0.8, ph);
		o = vec3(mix(o.xy, vec2(dn.x / asp, dn.y) * (-0.08 - 0.3 * k * k), m), mix(o.z, 1.0 - 0.35 * smoothstep(0.8, 1.0, k), m));
	}
	return o;
}
void main() {
	vec2 cen = in_uv - 0.5;
	vec2 suv = in_uv; float dk = 1.0;
	if (drops.x > 0.0) { vec3 ld = lens_drop(in_uv, frame.x / frame.y, drops.x, drops.y); suv = clamp(in_uv + ld.xy, vec2(0.001), vec2(0.999)); dk = ld.z; }
	vec3 c;
	if (lens.y > 0.0) {
		vec2 cd = cen * dot(cen, cen) * lens.y;
		c = vec3(textureLod(tex_hdr, suv + cd, 0.0).r + textureLod(tex_glow, suv + cd, 0.0).r * tone.z, textureLod(tex_hdr, suv, 0.0).g + textureLod(tex_glow, suv, 0.0).g * tone.z, textureLod(tex_hdr, suv - cd, 0.0).b + textureLod(tex_glow, suv - cd, 0.0).b * tone.z);
	} else {
		c = texture(tex_hdr, suv).rgb;
		c += texture(tex_glow, suv).rgb * tone.z;
	}
	if (lens.w > 0.0) {
		vec2 tx = 1.0 / vec2(textureSize(tex_hdr, 0));
		float lc = log(max(dot(c, vec3(0.2126, 0.7152, 0.0722)), 1e-4));
		float la = 0.25 * (log(max(dot(textureLod(tex_hdr, suv + vec2(tx.x, 0.0), 0.0).rgb, vec3(0.2126, 0.7152, 0.0722)), 1e-4)) + log(max(dot(textureLod(tex_hdr, suv - vec2(tx.x, 0.0), 0.0).rgb, vec3(0.2126, 0.7152, 0.0722)), 1e-4)) + log(max(dot(textureLod(tex_hdr, suv + vec2(0.0, tx.y), 0.0).rgb, vec3(0.2126, 0.7152, 0.0722)), 1e-4)) + log(max(dot(textureLod(tex_hdr, suv - vec2(0.0, tx.y), 0.0).rgb, vec3(0.2126, 0.7152, 0.0722)), 1e-4)));
		c *= exp(clamp((lc - la) * lens.w, -0.5, 0.5));
	}
	c *= dk;
	c *= tone.x * (mode.y > 0.5 ? expo[0] : 1.0);
	if (lens.x > 0.0) c *= mix(1.0, 1.0 - smoothstep(0.1, 0.9, dot(cen, cen) * 2.0), lens.x);
	if (color.z != 0.0) c *= vec3(1.0 + color.z, 1.0, 1.0 - color.z);
	if (color.x != 1.0) c = max(mix(vec3(dot(c, vec3(0.2126, 0.7152, 0.0722))), c, color.x), vec3(0.0));
	if (color.y != 1.0) c = 0.18 * pow(max(c, vec3(0.0)) / 0.18, vec3(color.y));
	if (lens.z > 0.0) c *= 1.0 + lens.z * (hash_px(in_uv * frame.xy + frame.z * 7.13) - 0.5) * 2.0 / (1.0 + 4.0 * dot(c, vec3(0.2126, 0.7152, 0.0722)));
	if (mode.x > 2.5) { out_rgba = graded(clamp(neutral(c), vec3(0.0), vec3(1.0))); return; }
	if (mode.x > 1.5) { out_rgba = graded(clamp(agx(c), vec3(0.0), vec3(1.0))); return; }
	if (mode.x > 0.5) {
		vec3 v = mat3(vec3(0.59719, 0.07600, 0.02840), vec3(0.35458, 0.90834, 0.13383), vec3(0.04823, 0.01566, 0.83777)) * (c / 0.6);
		v = (v * (v + 0.0245786) - 0.000090537) / (v * (0.983729 * v + 0.4329510) + 0.238081);
		v = clamp(mat3(vec3(1.60475, -0.10208, -0.00327), vec3(-0.53108, 1.10813, -0.07276), vec3(-0.07367, -0.00605, 1.07602)) * v, 0.0, 1.0);
		out_rgba = graded(v);
		return;
	}
	float lum = dot(c, vec3(0.2126, 0.7152, 0.0722));
	float w2 = tone.y * tone.y;
	float mapped = lum * (1.0 + lum / w2) / (1.0 + lum);
	vec3 o = lum > 1e-6 ? c * (mapped / lum) : vec3(0.0);
	// pull overly bright saturated colours toward their mapped grey
	float over = clamp(max(o.r, max(o.g, o.b)) - 1.0, 0.0, 1.0);
	o = mix(o, vec3(mapped), clamp(over * tone.w, 0.0, 1.0));
	out_rgba = graded(o);
}
