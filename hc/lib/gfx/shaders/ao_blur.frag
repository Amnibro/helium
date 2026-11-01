#version 450
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform sampler2D ao_in;
layout(set = 3, binding = 0) uniform BlurU {
	vec4 texel;
};

void main() {
	vec4 center = textureLod(ao_in, in_uv, 0.0);
	float center_ao = center.r;
	float center_depth = center.w;

	if (center_depth >= 500.0) {
		out_color = vec4(1.0, 1.0, 1.0, 1.0);
		return;
	}

	vec2 t = texel.xy;
	float sum = center_ao * 0.25;
	float total_w = 0.25;

	vec2 offsets[8] = vec2[](
		vec2(-1.0,  0.0), vec2( 1.0,  0.0),
		vec2( 0.0, -1.0), vec2( 0.0,  1.0),
		vec2(-1.0, -1.0), vec2( 1.0, -1.0),
		vec2(-1.0,  1.0), vec2( 1.0,  1.0)
	);
	float spatial_w[8] = float[](
		0.125, 0.125,
		0.125, 0.125,
		0.0625, 0.0625,
		0.0625, 0.0625
	);

	for (int i = 0; i < 8; i++) {
		vec2 uv = in_uv + offsets[i] * t;
		vec4 samp = textureLod(ao_in, uv, 0.0);
		float depth_diff = abs(samp.w - center_depth);
		float edge_w = exp(-depth_diff * 8.0);
		float w = spatial_w[i] * edge_w;
		sum += samp.r * w;
		total_w += w;
	}

	float final_ao = sum / max(total_w, 0.001);
	out_color = vec4(final_ao, final_ao, final_ao, 1.0);
}
