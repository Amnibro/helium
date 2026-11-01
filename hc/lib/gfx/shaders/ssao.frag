// Hemisphere screen-space ambient occlusion: sample points in a normal-oriented
// hemisphere around each pixel's view-space position and count how many land
// behind the stored depth, with a range check so distant occluders fade out.
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_nd;
layout(set = 3, binding = 0) uniform Occlusion { vec4 lens; vec4 tune; }; // lens: tan(fov_x/2), tan(fov_y/2), 1/w, 1/h; tune: radius, bias, power, samples
layout(location = 0) out vec4 out_ao;

// hash12: "Hash without Sine" by David Hoskins, https://www.shadertoy.com/view/4djSRW,
// Copyright (c) 2014 David Hoskins, MIT License (full text in NOTICE).
float hash12(vec2 p) {
	vec3 q = fract(vec3(p.xyx) * 0.1031);
	q += dot(q, q.yzx + 33.33);
	return fract((q.x + q.y) * q.z);
}

vec3 view_pos(vec2 uv, float d) {
	return vec3((uv.x * 2.0 - 1.0) * lens.x * d, (1.0 - uv.y * 2.0) * lens.y * d, -d);
}

void main() {
	vec4 nd = texture(tex_nd, in_uv);
	if (nd.w <= 0.0) { out_ao = vec4(1.0); return; }
	vec3 p = view_pos(in_uv, nd.w);
	vec3 n = normalize(nd.xyz);
	float angle = hash12(gl_FragCoord.xy) * 6.2831853;
	vec3 r = vec3(cos(angle), sin(angle), 0.0);
	vec3 t = normalize(r - n * dot(r, n) + vec3(1e-4, 0.0, 0.0));
	vec3 b = cross(n, t);
	mat3 frame = mat3(t, b, n);
	int count = int(tune.w);
	float hidden = 0.0;
	for (int i = 0; i < 32; i++) {
		if (i >= count) break;
		// a fixed spiral of directions over the hemisphere, denser near the centre
		float fi = float(i) + 0.5;
		float z = sqrt(1.0 - fi / float(count));
		float phi = fi * 2.39996323;
		float ring = sqrt(max(1.0 - z * z, 0.0));
		float len = mix(0.15, 1.0, (fi / float(count)) * (fi / float(count)));
		vec3 s = p + frame * (vec3(cos(phi) * ring, sin(phi) * ring, z) * len * tune.x);
		float sd = -s.z;
		if (sd <= 1e-3) continue;
		vec2 suv = vec2(s.x / (sd * lens.x) * 0.5 + 0.5, 0.5 - s.y / (sd * lens.y) * 0.5);
		if (any(lessThan(suv, vec2(0.0))) || any(greaterThan(suv, vec2(1.0)))) continue;
		float scene = texture(tex_nd, suv).w;
		if (scene <= 0.0) continue;
		float near_enough = smoothstep(0.0, 1.0, tune.x / max(abs(p.z + scene), 1e-4));
		hidden += (scene < sd - tune.y ? 1.0 : 0.0) * near_enough;
	}
	float ao = pow(clamp(1.0 - hidden / float(max(count, 1)), 0.0, 1.0), tune.z);
	out_ao = vec4(ao, nd.w, 0.0, 1.0);
}
