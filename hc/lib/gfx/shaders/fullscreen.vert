#version 450
layout(location = 0) out vec2 o_uv;
void main() { vec2 uv = vec2(float(gl_VertexIndex >> 1), float(gl_VertexIndex & 1)) * 2.0; gl_Position = vec4(uv * vec2(2.0, -2.0) + vec2(-1.0, 1.0), 0.0, 1.0); o_uv = uv; }
