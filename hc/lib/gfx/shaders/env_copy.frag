#include "env_face.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform samplerCubeArray tex_src;
layout(set = 3, binding = 0) uniform CopyU { vec4 p; };
layout(location = 0) out vec4 out_rgba;
void main() {
	out_rgba = vec4(textureLod(tex_src, vec4(normalize(face_dir(int(p.x + 0.5), in_uv * 2.0 - 1.0)), p.y), p.z).rgb, 1.0);
}
