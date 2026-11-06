layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_depth;
layout(set = 2, binding = 1) uniform sampler2D tex_nd;
layout(set = 2, binding = 2) uniform sampler2D tex_ao;
layout(set = 3, binding = 0) uniform Contact { vec4 lens; vec4 jit; vec4 sun_v; vec4 tune; };
layout(location = 0) out vec4 out_rg;
vec3 view_pos(vec2 px, float z) { vec2 c = vec2(px.x * lens.z * 2.0 - 1.0, 1.0 - px.y * lens.w * 2.0); return vec3(c.x * lens.x * z, c.y * lens.y * z, -z); }
void main() {
	ivec2 x = ivec2(gl_FragCoord.xy);
	ivec2 lim = ivec2(jit.zw) - 1;
	float a = tune.z > 0.5 ? texelFetch(tex_ao, x, 0).r : 1.0;
	float z = texelFetch(tex_depth, x, 0).r;
	vec3 n = texelFetch(tex_nd, x, 0).xyz;
	vec3 l = sun_v.xyz;
	if (z <= 0.0 || dot(n, l) <= 0.0) { out_rg = vec4(a, 1.0, 0.0, 1.0); return; }
	float fp = 2.0 * z * lens.y / jit.w;
	vec3 p = view_pos(gl_FragCoord.xy + jit.xy, z) + n * (1.5 * fp);
	int steps = int(tune.x);
	float j = tune.w > 0.5 ? fract(52.9829189 * fract(dot(gl_FragCoord.xy, vec2(0.06711056, 0.00583715)))) : 0.5;
	float bias = max(z * 0.0007, fp);
	float occ = 0.0;
	for (int i = 0; i < 32; i++) {
		if (i >= steps) break;
		float t = (float(i) + j) / float(steps);
		t *= t;
		vec3 q = p + l * (sun_v.w * t);
		float zq = -q.z;
		if (zq <= 1e-3) break;
		vec2 s = vec2(q.x / (zq * lens.x) * 0.5 + 0.5, 0.5 - q.y / (zq * lens.y) * 0.5) * jit.zw - jit.xy;
		ivec2 y = ivec2(floor(s));
		if (any(lessThan(y, ivec2(0))) || any(greaterThan(y, lim))) break;
		float zs = texelFetch(tex_depth, y, 0).r;
		float dz = zq - zs;
		float hit = zs > 0.0 ? clamp((dz - bias) / (2.0 * bias), 0.0, 1.0) * clamp((tune.y - dz) / (0.5 * tune.y), 0.0, 1.0) : 0.0;
		occ = max(occ, hit * (1.0 - t * t));
	}
	out_rg = vec4(a, 1.0 - occ, 0.0, 1.0);
}
