#version 450
// Screen-space text and flat quads for lib/gfx/sdf_font (TextVtx: pos, uv, col).
layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_uv;
layout(location = 2) in vec4 a_col;
layout(set = 1, binding = 0) uniform SdfProj { mat4 proj; };
layout(location = 0) out vec4 v_col;
layout(location = 1) out vec2 v_uv;
void main() { v_col = a_col; v_uv = a_uv; gl_Position = proj * vec4(a_pos, 0.0, 1.0); }
