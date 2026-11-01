#version 450
layout(location = 0) in vec3 v_view_normal;
layout(location = 1) in vec3 v_view_position;
layout(location = 0) out vec4 out_color;
void main() {
	vec3 n = length(v_view_normal) > 1e-4 ? normalize(v_view_normal) : vec3(0.0, 0.0, 1.0);
	out_color = vec4(n, max(-v_view_position.z, 0.0));
}
