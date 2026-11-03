layout(location = 0) in vec2 in_uv;
layout(location = 1) in vec4 in_rgba;
layout(location = 2) flat in float in_shape;
layout(location = 0) out vec4 out_rgba;
void main() {
	vec2 c = in_uv * 2.0 - 1.0;
	float r = length(c);
	float a = 1.0;
	int s = int(in_shape + 0.5) % 8;
	if (s == 0) { float v = c.y / 0.55; a = exp(-v * v) * smoothstep(1.0, 0.85, abs(c.x)); }
	else if (s == 1) { float d = (r - 0.72) / 0.12; a = r > 0.95 || r < 0.25 ? 0.0 : exp(-d * d); }
	else if (s == 2) { a = r >= 1.0 ? 0.0 : (1.0 - r * r) * (1.0 - r * r); }
	if (a <= 0.0) discard;
	if (in_shape >= 7.5) out_rgba = vec4(mix(vec3(1.0), vec3(1.0 - in_rgba.a), a), 1.0);
	else out_rgba = vec4(in_rgba.rgb * in_rgba.a * a, 1.0);
}
