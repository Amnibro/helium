// Prepass (one sample per pixel): view-space normal and positive view depth for
// screen-space AO, and the motion target for the temporal pass.
layout(location = 0) in vec3 in_world;
layout(location = 1) in vec3 in_nrm;
layout(location = 3) in vec4 in_uv;
layout(location = 4) in vec4 in_col;
layout(location = 5) in vec4 in_cur;    // unjittered clip position, this frame
layout(location = 6) in vec4 in_prev;   // unjittered clip position, last frame
layout(set = 2, binding = 0) uniform sampler2D tex_base;
layout(set = 3, binding = 0) uniform Cutout { vec4 base; vec4 alpha; vec4 uv_sets; mat4 view; };
layout(location = 0) out vec4 out_nd;
// xy: uv now minus uv last frame (x right, y down); z: view depth now; w: view depth of
// the same surface point last frame (clip w). A point that was behind the camera last
// frame gets a large vector, so the temporal pass treats its history as missing.
layout(location = 1) out vec4 out_motion;
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
	vec2 now = in_cur.xy / in_cur.w;
	bool seen = in_prev.w > 1e-5;
	vec2 d = seen ? (now - in_prev.xy / in_prev.w) * vec2(0.5, -0.5) : vec2(4.0);
	out_motion = vec4(d, in_cur.w, seen ? in_prev.w : in_cur.w);
}
