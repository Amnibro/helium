#include "env_face.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform ProbeCopyU { mat4 vp; vec4 p; };
layout(location = 0) out vec4 out_rgba;
void main() {
	vec4 c = vp * vec4(normalize(face_dir(int(p.x + 0.5), in_uv * 2.0 - 1.0)), 0.0);
	out_rgba = vec4(textureLod(tex_src, vec2(c.x / c.w * 0.5 + 0.5, 0.5 - c.y / c.w * 0.5), 0.0).rgb, 1.0);
}
