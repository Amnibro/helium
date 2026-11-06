// Final image: exposure, bloom mix, an extended-Reinhard curve on luminance with
// a white point (values at or above it map to 1), a small highlight
// desaturation, and the sRGB transfer function written by hand (the target is
// a linear RGBA8 texture).
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_glow;
layout(set = 2, binding = 2) uniform sampler3D tex_lut;
layout(std430, set = 2, binding = 3) readonly buffer Expo { float expo[]; };
layout(set = 3, binding = 0) uniform Grade { vec4 tone; vec4 mode; }; // exposure, white point, bloom amount, desaturation
layout(location = 0) out vec4 out_rgba;

float encode_srgb(float x) {
	x = clamp(x, 0.0, 1.0);
	return x <= 0.0031308 ? 12.92 * x : 1.055 * pow(x, 1.0 / 2.4) - 0.055;
}
vec4 graded(vec3 o) {
	vec3 e = vec3(encode_srgb(o.r), encode_srgb(o.g), encode_srgb(o.b));
	return vec4(mode.z > 0.0 ? mix(e, texture(tex_lut, e * ((mode.w - 1.0) / mode.w) + 0.5 / mode.w).rgb, mode.z) : e, 1.0);
}

void main() {
	vec3 c = texture(tex_hdr, in_uv).rgb;
	c += texture(tex_glow, in_uv).rgb * tone.z;
	c *= tone.x * (mode.y > 0.5 ? expo[0] : 1.0);
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
