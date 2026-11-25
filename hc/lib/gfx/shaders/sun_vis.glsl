float sun_vis(vec3 p) {
	if (to_sun.w < 0.5) return 1.0;
	float depth = dot(p - eye.xyz, view_dir.xyz);
	int c = depth > cascade_far.y ? 2 : (depth > cascade_far.x ? 1 : 0);
	if (depth > cascade_far.z) return 1.0;
	vec4 s = cascade_mat[c] * vec4(p, 1.0);
	vec3 ndc = s.xyz / s.w;
	vec2 uv = vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0)))) return 1.0;
	return texture(tex_shadow, vec4(uv, float(c), ndc.z - 0.001));
}
