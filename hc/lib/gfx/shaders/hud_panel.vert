#version 450
layout(location = 0) in vec2 a_pos;
layout(location = 1) in vec2 a_loc;
layout(location = 2) in vec2 a_half;
layout(location = 3) in vec2 a_rb;
layout(location = 4) in vec4 a_fill;
layout(location = 5) in vec4 a_edge;
layout(set = 1, binding = 0) uniform HudProj { mat4 proj; };
layout(location = 0) out vec2 v_loc;
layout(location = 1) out vec2 v_half;
layout(location = 2) out vec2 v_rb;
layout(location = 3) out vec4 v_fill;
layout(location = 4) out vec4 v_edge;
void main() { v_loc = a_loc; v_half = a_half; v_rb = a_rb; v_fill = a_fill; v_edge = a_edge; gl_Position = proj * vec4(a_pos, 0.0, 1.0); }
