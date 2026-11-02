layout(location = 0) in vec2 in_corner;
layout(location = 1) in vec4 in_rgba;
layout(location = 2) in vec2 in_depth_fade;
layout(set = 2, binding = 0) uniform sampler2D tex_nd;
layout(set = 3, binding = 0) uniform Frag { vec4 screen; vec4 mode; };
layout(location = 0) out vec4 out_rgba;
void main() {
	float d2 = dot(in_corner, in_corner);
	if (d2 > 1.0) discard;
	float shape = mode.y > 0.5 ? 1.0 : (1.0 - d2) * (1.0 - d2);
	float fade = 1.0;
	if (in_depth_fade.y > 0.0 && screen.z > 0.5) {
		float zs = texelFetch(tex_nd, ivec2(gl_FragCoord.xy * screen.w), 0).w;
		if (zs > 0.0) fade = clamp((zs - in_depth_fade.x) / in_depth_fade.y, 0.0, 1.0);
	}
	float a = in_rgba.a * shape * fade;
	out_rgba = mode.x < 0.5 ? vec4(in_rgba.rgb * a, 0.0) : vec4(in_rgba.rgb, a);
}
