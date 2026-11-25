layout(set = 2, binding = 0) uniform sampler3D tex_noise;
#include "cloud.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 3, binding = 0) uniform CloudShadow { vec4 area; vec4 to_sun; vec4 slab; vec4 wind; };
layout(location = 0) out vec4 out_rgba;
void main() {
	vec3 g = vec3(area.x + (in_uv.x - 0.5) * area.z, area.w, area.y + (in_uv.y - 0.5) * area.z);
	out_rgba = vec4(vec3(c_shadow(g, to_sun.xyz, slab, wind.xy)), 1.0);
}
