#include "env_face.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform EnvU { vec4 p; };
layout(location = 0) out vec4 out_rgba;
void main() {
	vec3 d = normalize(face_dir(int(p.x + 0.5), in_uv * 2.0 - 1.0));
	vec2 uv = vec2(atan(d.z, d.x) / 6.2831853 + 0.5, 0.5 - asin(clamp(d.y, -1.0, 1.0)) / 3.14159265);
	out_rgba = vec4(textureLod(tex_src, uv, 0.0).rgb, 1.0);
}
