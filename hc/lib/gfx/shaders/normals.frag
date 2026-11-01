// Prepass for screen-space AO: view-space normal and positive view depth.
layout(location = 0) in vec3 in_world;
layout(location = 1) in vec3 in_nrm;
layout(location = 3) in vec4 in_uv;
layout(location = 4) in vec4 in_col;
layout(set = 2, binding = 0) uniform sampler2D tex_base;
layout(set = 3, binding = 0) uniform Cutout { vec4 base; vec4 alpha; vec4 uv_sets; mat4 view; };
layout(location = 0) out vec4 out_nd;
void main() {
	if (alpha.x > 0.5 && alpha.x < 1.5) {
		vec2 uv = uv_sets.x > 0.5 ? in_uv.zw : in_uv.xy;
		if (base.a * in_col.a * texture(tex_base, uv).a < alpha.y) discard;
	}
	vec3 n = normalize(in_nrm);
	if (!gl_FrontFacing && alpha.z > 0.5) n = -n;
	vec3 vn = normalize((view * vec4(n, 0.0)).xyz);
	vec4 vp = view * vec4(in_world, 1.0);
	out_nd = vec4(vn, -vp.z);
}
