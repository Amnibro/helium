#version 450
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform sampler2D hdr;
layout(set = 2, binding = 1) uniform sampler2D bloom0;
layout(set = 3, binding = 0) uniform Grade { vec4 bal0; vec4 bal1; vec4 bal2; vec4 saturation; vec4 contrast; vec4 gamma; vec4 gain; vec4 lift; vec4 midtone; vec4 misc; vec4 clearc; vec4 ldr; vec4 bloom; };
#include "up9.glsl"
vec3 powsafe(vec3 c, float p) { return pow(abs(c), vec3(p)) * sign(c); }
float luminance(vec3 v) { return dot(v, vec3(0.2126, 0.7152, 0.0722)); }
vec3 sectional(vec3 cin) {
	vec3 color = cin;
	float level = (color.r + color.g + color.b) / 3.0;
	vec3 levels = vec3(0.0);
	vec2 mr = midtone.xy;
	if (level < mr.x - 0.1) { levels.x = 1.0; }
	else if (level < mr.x + 0.1) { levels.y = (level - mr.x) * 5.0 + 0.5; levels.z = 1.0 - levels.y; }
	else if (level < mr.y - 0.1) { levels.y = 1.0; }
	else if (level < mr.y + 0.1) { levels.z = (level - mr.y) * 5.0 + 0.5; levels.y = 1.0 - levels.z; }
	else { levels.z = 1.0; }
	float ct = dot(levels, contrast.xyz);
	float sa = dot(levels, saturation.xyz);
	float ga = dot(levels, gamma.xyz);
	float gn = dot(levels, gain.xyz);
	float li = dot(levels, lift.xyz);
	float luma = luminance(color);
	color = luma + sa * (color - luma);
	color = 0.5 + (color - 0.5) * ct;
	color = powsafe(color * gn + li, 1.0 / ga);
	color = color * powsafe(vec3(2.0), misc.x);
	return max(color, vec3(0.0));
}
float tonemap_curve(float v) { return 1.0 - exp(-v); }
vec3 sbdt(vec3 col) {
	vec3 ycbcr = vec3(dot(col, vec3(0.2126, 0.7152, 0.0722)), dot(col, vec3(-0.1146, -0.3854, 0.5)), dot(col, vec3(0.5, -0.4542, -0.0458)));
	float bt = tonemap_curve(length(ycbcr.yz) * 2.4);
	float desat = max((bt - 0.7) * 0.8, 0.0);
	desat *= desat;
	vec3 desat_col = mix(col.rgb, ycbcr.xxx, desat);
	float tm_luma = tonemap_curve(ycbcr.x);
	vec3 tm0 = col.rgb * max(0.0, tm_luma / max(1e-5, luminance(col.rgb)));
	vec3 tm1 = vec3(tonemap_curve(desat_col.r), tonemap_curve(desat_col.g), tonemap_curve(desat_col.b));
	return mix(tm0, tm1, bt * bt) * 0.97;
}
vec3 aces(vec3 color) {
	mat3 i = mat3(vec3(0.59719, 0.07600, 0.02840), vec3(0.35458, 0.90834, 0.13383), vec3(0.04823, 0.01566, 0.83777));
	mat3 o = mat3(vec3(1.60475, -0.10208, -0.00327), vec3(-0.53108, 1.10813, -0.07276), vec3(-0.07367, -0.00605, 1.07602));
	vec3 v = i * color;
	vec3 a = v * (v + 0.0245786) - 0.000090537;
	vec3 b = v * (0.983729 * v + 0.4329510) + 0.238081;
	return clamp(o * (a / b), vec3(0.0), vec3(1.0));
}
// Analytic filmic tonemap (no LUT data). ACES
// fitted curve on a hue-preserving split: the per-channel curve keeps
// saturated midtones, the luminance-scaled curve keeps hot emissive cores and
// fungus from skewing hue; highlights blend towards it.
vec3 filmic(vec3 c) {
	vec3 a = aces(c);
	float l = luminance(c);
	vec3 h = c * (luminance(aces(vec3(l))) / max(l, 1e-5));
	float t = smoothstep(0.6, 4.0, max(c.r, max(c.g, c.b)));
	vec3 m = mix(a, clamp(h, vec3(0.0), vec3(1.0)), t * 0.6);
	float ml = luminance(m);
	return mix(vec3(ml), m, 1.0 - smoothstep(0.8, 1.0, ml) * 0.5);
}
vec3 srgb_enc(vec3 c) { return mix(c * 12.92, 1.055 * pow(c, vec3(1.0 / 2.4)) - 0.055, step(vec3(0.0031308), c)); }
vec3 dither(vec2 p) { vec3 d = vec3(dot(vec2(171.0, 231.0), p)); d = fract(d / vec3(103.0, 71.0, 97.0)); return (d - 0.5) / 255.0; }
void main() {
	vec4 src = textureLod(hdr, in_uv, 0.0);
	if (bloom.w > 0.5) { src.rgb = up9(bloom0, in_uv, bloom.xy) * bloom.z + src.rgb * (1.0 - bloom.z); }
	bool isldr = ldr.x > 0.5;
	vec3 color = max(src.rgb, vec3(0.0));
	if (isldr) { color = color / max(src.a, 0.0001); }
	color = max(mat3(bal0.xyz, bal1.xyz, bal2.xyz) * color, vec3(0.0));
	color = sectional(color);
	uint m = uint(misc.y);
	if (m == 1u || m == 2u) { color = filmic(color); }
	else if (m == 3u) { color = sbdt(color); }
	else if (m == 4u) { color = color / (1.0 + color); }
	color = mix(vec3(luminance(color)), color, vec3(misc.z));
	float a = src.a;
	if (isldr) { color = color * src.a + clearc.rgb * (1.0 - src.a); a = src.a + clearc.a * (1.0 - src.a); }
	if (misc.w > 0.5) { a = 1.0; }
	vec3 srgb = pow(max(color, vec3(0.0)), vec3(1.0 / 2.2));
	out_color = vec4(srgb_enc(clamp(pow(max(srgb + dither(gl_FragCoord.xy), vec3(0.0)), vec3(2.2)), vec3(0.0), vec3(1.0))), a);
}
