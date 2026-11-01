#version 450
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform sampler2D pre_col;
layout(set = 3, binding = 0) uniform AoU {
	vec4 params;
	vec4 screen;
};

void main() {
	vec4 center = textureLod(pre_col, in_uv, 0.0);
	float depth = center.w;
	vec3 N = center.xyz;
	if (depth <= 0.05 || depth >= 500.0 || length(N) < 0.2) {
		out_color = vec4(1.0, 1.0, 1.0, depth);
		return;
	}
	N = normalize(N);

	float th = params.x;
	float asp = params.y;
	float radius = params.z;
	float intensity = params.w;
	float bias = screen.z;

	vec3 P;
	P.z = -depth;
	P.x = (in_uv.x * 2.0 - 1.0) * depth * th * asp;
	P.y = (1.0 - in_uv.y * 2.0) * depth * th;

	float angle = fract(sin(dot(gl_FragCoord.xy, vec2(12.9898, 78.233))) * 43758.5453) * 6.2831853;
	vec2 rot = vec2(cos(angle), sin(angle));

	vec3 up = abs(N.z) < 0.99 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0);
	vec3 T = normalize(cross(up, N));
	vec3 B = cross(N, T);
	vec3 rT = T * rot.x + B * rot.y;
	vec3 rB = -T * rot.y + B * rot.x;

	float occlusion = 0.0;
	float total_w = 0.0;
	const int SAMPLES = 12;

	for (int i = 0; i < SAMPLES; i++) {
		float fi = (float(i) + 0.5) / float(SAMPLES);
		float r = sqrt(fi);
		float phi = float(i) * 2.39996323;
		vec2 disk = vec2(cos(phi), sin(phi)) * r;
		float z_hemi = sqrt(max(1.0 - dot(disk, disk), 0.05));
		vec3 dir = normalize(rT * disk.x + rB * disk.y + N * z_hemi);

		float dist = radius * (0.2 + 0.8 * (fi * fi));
		vec3 S = P + dir * dist;
		float s_depth = -S.z;
		if (s_depth <= 0.05) continue;

		vec2 s_uv = vec2((S.x / (s_depth * th * asp) + 1.0) * 0.5, (1.0 - S.y / (s_depth * th)) * 0.5);
		if (s_uv.x < 0.0 || s_uv.x > 1.0 || s_uv.y < 0.0 || s_uv.y > 1.0) continue;

		float sample_depth = textureLod(pre_col, s_uv, 0.0).w;
		float diff = s_depth - sample_depth;

		float ndotl = max(dot(N, dir), 0.0);
		if (diff > bias && diff < radius * 1.5) {
			float atten = 1.0 - smoothstep(0.0, radius * 1.5, diff);
			occlusion += atten * ndotl;
		}
		total_w += ndotl;
	}

	float ao = 1.0 - (occlusion / max(total_w, 0.001)) * intensity;
	ao = clamp(ao, 0.0, 1.0);
	out_color = vec4(ao, ao, ao, depth);
}
