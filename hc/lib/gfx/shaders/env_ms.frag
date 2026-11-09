#include "atmos.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 3, binding = 0) uniform EnvU { vec4 p; };
layout(location = 0) out vec4 out_rgba;
void main() {
	float mu = in_uv.x * 2.0 - 1.0;
	float mie = p.w;
	vec3 o = vec3(0.0, A_RG + max(in_uv.y * in_uv.y * 100.0, 0.01), 0.0);
	vec3 ld = vec3(sqrt(max(1.0 - mu * mu, 0.0)), mu, 0.0);
	vec3 l2 = vec3(0.0);
	vec3 fms = vec3(0.0);
	for (int i = 0; i < 64; i++) {
		float z = 1.0 - (2.0 * float(i) + 1.0) / 64.0;
		float s = sqrt(max(1.0 - z * z, 0.0));
		float ph = float(i) * 2.39996323;
		vec3 d = vec3(cos(ph) * s, z, sin(ph) * s);
		float tg = a_hit(o, d, A_RG, -1.0);
		float dt = (tg > 0.0 ? tg : a_hit(o, d, A_RT, 1.0)) / 20.0;
		vec3 tr = vec3(1.0);
		for (int j = 0; j < 20; j++) {
			vec3 q = o + d * ((float(j) + 0.5) * dt);
			float h = length(q) - A_RG;
			vec3 sc = a_ray(h) + vec3(3.996e-3 * a_mie(h, mie));
			vec3 stp = exp(-a_ext(h, mie) * dt);
			vec3 w = tr * (vec3(1.0) - stp) / max(a_ext(h, mie), vec3(1e-7)) * sc;
			fms += w;
			l2 += w * a_trans(q, ld, mie) * 0.0795774715;
			tr *= stp;
		}
		if (tg > 0.0) {
			vec3 q = o + d * tg;
			l2 += tr * a_trans(q, ld, mie) * max(dot(normalize(q), ld), 0.0) * p.z * 0.318309886;
		}
	}
	out_rgba = vec4((l2 / 64.0) / max(vec3(1.0) - fms / 64.0, vec3(0.05)), 1.0);
}
