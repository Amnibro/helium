#version 450
// Particle fragment. Premultiplied output: sparks are purely
// additive (alpha 0), dust occludes softly.
layout(location = 0) in vec4 v_col;
layout(location = 1) in vec2 v_q;
layout(location = 2) flat in float v_kind;
layout(location = 0) out vec4 o_color;

void main() {
	if (v_kind < 0.5) {
		float a = (1.0 - v_q.x * v_q.x) * (1.0 - abs(v_q.y));
		o_color = vec4(v_col.rgb * a * a, 0.0);
	} else {
		float r = length(v_q);
		float a = (1.0 - smoothstep(0.2, 1.0, r)) * v_col.a;
		o_color = vec4(v_col.rgb * a, a);
	}
}
