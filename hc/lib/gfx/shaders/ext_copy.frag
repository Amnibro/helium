layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(location = 0) out vec4 out_rgba;
void main() { out_rgba = texture(tex_src, in_uv); }
