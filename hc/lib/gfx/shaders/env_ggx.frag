#include "env_face.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform samplerCube tex_src;
layout(set = 3, binding = 0) uniform EnvU { vec4 p; };
layout(location = 0) out vec4 out_rgba;
float radical(uint b) {
	uint v = (b << 16u) | (b >> 16u);
	v = ((v & 0x55555555u) << 1u) | ((v & 0xAAAAAAAAu) >> 1u);
	v = ((v & 0x33333333u) << 2u) | ((v & 0xCCCCCCCCu) >> 2u);
	v = ((v & 0x0F0F0F0Fu) << 4u) | ((v & 0xF0F0F0F0u) >> 4u);
	v = ((v & 0x00FF00FFu) << 8u) | ((v & 0xFF00FF00u) >> 8u);
	return float(v) * 2.3283064365386963e-10;
}
void main() {
	vec3 n = normalize(face_dir(int(p.x + 0.5), in_uv * 2.0 - 1.0));
	float rough = p.y;
	if (rough == 0.0) { out_rgba = vec4(textureLod(tex_src, n, 0.0).rgb, 1.0); return; }
	vec3 tx = normalize(cross(abs(n.z) < 0.999 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0), n));
	vec3 ty = cross(n, tx);
	int count = int(p.z + 0.5);
	float texel = 12.566371 / (6.0 * p.w * p.w);
	float maxlod = log2(p.w);
	vec3 sum = vec3(0.0);
	float wt = 0.0;
	float a = rough * rough;
	float a2 = max(a * a, 1e-7);
	for (int i = 0; i < count; i++) {
		float u = (float(i) + 0.5) / float(count);
		float w = radical(uint(i));
		float ph = 6.2831853 * w;
		vec3 l;
		float pdf;
		float wgt;
		if (rough < 0.0) {
			float r = sqrt(u);
			float z = sqrt(max(1.0 - u, 0.0));
			l = tx * (r * cos(ph)) + ty * (r * sin(ph)) + n * z;
			pdf = z / 3.14159265;
			wgt = 1.0;
		} else {
			float ct = sqrt((1.0 - u) / (1.0 + (a2 - 1.0) * u));
			float st = sqrt(max(1.0 - ct * ct, 0.0));
			vec3 h = tx * (st * cos(ph)) + ty * (st * sin(ph)) + n * ct;
			l = h * (2.0 * ct) - n;
			float nl = dot(n, l);
			float d = ct * ct * (a2 - 1.0) + 1.0;
			pdf = max(a2 / (3.14159265 * d * d) * 0.25, 1e-7);
			wgt = max(nl, 0.0);
		}
		if (wgt <= 0.0) continue;
		float lod = clamp(0.5 * log2(max(1.0 / (float(count) * max(pdf, 1e-7)) / texel, 1.0)), 0.0, maxlod);
		sum += textureLod(tex_src, l, lod).rgb * wgt;
		wt += wgt;
	}
	out_rgba = vec4(sum / max(wt, 1e-4), 1.0);
}
