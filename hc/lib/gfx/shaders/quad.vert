layout(std430, set = 0, binding = 0) readonly buffer Quads { vec4 qv[]; };
layout(set = 1, binding = 0) uniform View { mat4 view_proj; vec4 right; vec4 up; };
layout(location = 0) out vec2 out_uv;
layout(location = 1) out vec4 out_rgba;
layout(location = 2) flat out float out_shape;
void main() {
	int i = gl_VertexIndex / 6;
	int k = gl_VertexIndex % 6;
	int j = k == 0 || k == 3 ? 0 : (k == 1 ? 1 : (k == 5 ? 3 : 2));
	out_uv = vec2(j >= 2 ? 1.0 : 0.0, j == 1 || j == 2 ? 1.0 : 0.0);
	out_rgba = qv[i * 9 + 4 + j];
	out_shape = qv[i * 9 + 8].x;
	gl_Position = view_proj * vec4(qv[i * 9 + j].xyz, 1.0);
}
