#version 450
#include "pbr_fs.glsl"
layout(set = 2, binding = 5) uniform sampler2D mr_texture;
layout(set = 2, binding = 6) uniform sampler2D occlusion_texture;
layout(set = 2, binding = 7) uniform sampler2D emissive_texture;
layout(set = 2, binding = 8) uniform sampler2D normal_texture;
layout(set = 2, binding = 9) uniform sampler2D ao_texture;
void main() {
	PbrInput pin = pbr_input_from_standard_material(gl_FrontFacing);
	uint flags = m_flags;
	vec2 uv = vec2(dot(m_uv0.xy, vec2(in_uv.x, 0.0)) + m_uv0.z * in_uv.y + m_uv1.x, m_uv0.y * in_uv.x + m_uv0.w * in_uv.y + m_uv1.y);
	if ((flags & 2u) != 0u) { pin.material.emissive = vec4(pin.material.emissive.rgb * texture(emissive_texture, uv).rgb, pin.material.emissive.a); }
	if ((flags & 4u) != 0u) { vec4 mr = texture(mr_texture, uv); pin.material.metallic = pin.material.metallic * mr.b; pin.material.perceptual_roughness = pin.material.perceptual_roughness * mr.g; }
	if ((flags & 8u) != 0u) { pin.diffuse_occlusion = vec3(texture(occlusion_texture, uv).r); }
	if ((flags & 64u) != 0u) {
		vec3 tn = texture(normal_texture, uv).xyz * 2.0 - 1.0;
		vec3 p = pin.world_position.xyz;
		vec3 dp1 = dFdx(p); vec3 dp2 = dFdy(p); vec2 du1 = dFdx(uv); vec2 du2 = dFdy(uv);
		vec3 N = pin.N;
		vec3 a = cross(dp2, N); vec3 b = cross(N, dp1);
		vec3 T = a * du1.x + b * du2.x;
		vec3 B = -(a * du1.y + b * du2.y);
		float im = inversesqrt(max(max(dot(T, T), dot(B, B)), 1e-20));
		pin.N = normalize(mat3(T * im, B * im, N) * tn);
	}
	if ((flags & 128u) != 0u) {
		vec2 screen_uv = gl_FragCoord.xy / viewport.zw;
		float ao = texture(ao_texture, screen_uv).r;
		pin.diffuse_occlusion *= ao;
		pin.specular_occlusion *= ao;
	}
	pin.material.base_color = alpha_discard(pin.material.flags, pin.material.alpha_cutoff, pin.material.base_color);
	vec4 c = (pin.material.flags & SM_UNLIT) == 0u ? apply_pbr_lighting(pin) : pin.material.base_color;
	out_color = main_pass_post_lighting_processing(pin, c);
}
