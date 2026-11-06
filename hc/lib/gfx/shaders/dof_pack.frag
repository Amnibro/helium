layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_color;
layout(set = 2, binding = 1) uniform sampler2D tex_nd;
layout(location = 0) out vec4 out_rgba;
void main() {
	ivec2 x = ivec2(gl_FragCoord.xy);
	out_rgba = vec4(texelFetch(tex_color, x, 0).rgb, texelFetch(tex_nd, x, 0).w);
}
