// One triangle covering the target; uv (0,0) is the top-left corner.
layout(location = 0) out vec2 out_uv;
void main() {
	vec2 p = vec2(float((gl_VertexIndex << 1) & 2), float(gl_VertexIndex & 2));
	out_uv = p;
	gl_Position = vec4(p.x * 2.0 - 1.0, 1.0 - p.y * 2.0, 0.0, 1.0);
}
