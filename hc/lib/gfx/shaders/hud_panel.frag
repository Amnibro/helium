#version 450
layout(location = 0) in vec2 v_loc;
layout(location = 1) in vec2 v_half;
layout(location = 2) in vec2 v_rb;
layout(location = 3) in vec4 v_fill;
layout(location = 4) in vec4 v_edge;
layout(location = 0) out vec4 result;
void main() {
	float r = min(v_rb.x, min(v_half.x, v_half.y));
	vec2 q = abs(v_loc) - v_half + vec2(r);
	float d = length(max(q, vec2(0.0))) + min(max(q.x, q.y), 0.0) - r;
	float cover = clamp(0.5 - d, 0.0, 1.0);
	float inner = v_rb.y > 0.0 ? clamp(-(d + v_rb.y) + 0.5, 0.0, 1.0) : 1.0;
	vec4 c = mix(v_edge, v_fill, inner);
	result = vec4(c.rgb, c.a * cover);
}
