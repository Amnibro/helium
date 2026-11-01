// Final image: exposure, bloom mix, an extended-Reinhard curve on luminance with
// a white point (values at or above it map to 1), a small highlight
// desaturation, and the sRGB transfer function written by hand (the target is
// a linear RGBA8 texture).
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_hdr;
layout(set = 2, binding = 1) uniform sampler2D tex_glow;
layout(set = 3, binding = 0) uniform Grade { vec4 tone; }; // exposure, white point, bloom amount, desaturation
layout(location = 0) out vec4 out_rgba;

float encode_srgb(float x) {
	x = clamp(x, 0.0, 1.0);
	return x <= 0.0031308 ? 12.92 * x : 1.055 * pow(x, 1.0 / 2.4) - 0.055;
}

void main() {
	vec3 c = texture(tex_hdr, in_uv).rgb;
	c += texture(tex_glow, in_uv).rgb * tone.z;
	c *= tone.x;
	float lum = dot(c, vec3(0.2126, 0.7152, 0.0722));
	float w2 = tone.y * tone.y;
	float mapped = lum * (1.0 + lum / w2) / (1.0 + lum);
	vec3 o = lum > 1e-6 ? c * (mapped / lum) : vec3(0.0);
	// pull overly bright saturated colours toward their mapped grey
	float over = clamp(max(o.r, max(o.g, o.b)) - 1.0, 0.0, 1.0);
	o = mix(o, vec3(mapped), clamp(over * tone.w, 0.0, 1.0));
	out_rgba = vec4(encode_srgb(o.r), encode_srgb(o.g), encode_srgb(o.b), 1.0);
}
