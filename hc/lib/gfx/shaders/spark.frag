layout(location = 0) in vec2 in_corner;
layout(location = 1) in vec4 in_rgba;
layout(location = 0) out vec4 out_rgba;
void main() {
	float d2 = dot(in_corner, in_corner);
	if (d2 > 1.0) discard;
	float glow = (1.0 - d2) * (1.0 - d2);
	out_rgba = vec4(in_rgba.rgb * in_rgba.a * glow, 0.0);
}
