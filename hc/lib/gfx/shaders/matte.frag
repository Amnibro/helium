layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_motion;
layout(set = 2, binding = 1) uniform sampler2D tex_layer;
layout(set = 3, binding = 0) uniform Matte { vec4 k; };
layout(location = 0) out vec4 out_rgba;
void main() {
	ivec2 p = ivec2(gl_FragCoord.xy);
	float g = texelFetch(tex_motion, p, 0).z < 50000.0 ? 1.0 : 0.0;
	float l = k.x > 0.5 ? clamp(texelFetch(tex_layer, p, 0).a, 0.0, 1.0) : 0.0;
	out_rgba = vec4(vec3(1.0 - (1.0 - g) * (1.0 - l)), 1.0);
}
