#include "env_face.glsl"
#include "atmos.glsl"
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_src;
layout(set = 3, binding = 0) uniform EnvSkyU { vec4 p; vec4 sun; vec4 cloud; };
layout(location = 0) out vec4 out_rgba;
float c_hash(vec3 q) {
	vec3 r = fract(q * 0.1031);
	r += dot(r, r.zyx + 31.32);
	return fract((r.x + r.y) * r.z);
}
float c_noise(vec3 q) {
	vec3 i = floor(q);
	vec3 f = q - i;
	f = f * f * (3.0 - 2.0 * f);
	float a = mix(mix(c_hash(i), c_hash(i + vec3(1.0, 0.0, 0.0)), f.x), mix(c_hash(i + vec3(0.0, 1.0, 0.0)), c_hash(i + vec3(1.0, 1.0, 0.0)), f.x), f.y);
	float b = mix(mix(c_hash(i + vec3(0.0, 0.0, 1.0)), c_hash(i + vec3(1.0, 0.0, 1.0)), f.x), mix(c_hash(i + vec3(0.0, 1.0, 1.0)), c_hash(i + vec3(1.0, 1.0, 1.0)), f.x), f.y);
	return mix(a, b, f.z);
}
float c_dens(vec3 q) {
	float h = (q.y - 1.5) / 2.0;
	if (h <= 0.0 || h >= 1.0) return 0.0;
	vec3 s = (q + vec3(cloud.y, 0.0, cloud.z)) * vec3(0.32, 0.55, 0.32);
	float n = 0.5 * c_noise(s) + 0.25 * c_noise(s * 2.03 + vec3(7.1)) + 0.125 * c_noise(s * 4.07 + vec3(3.3)) + 0.0625 * c_noise(s * 8.11 + vec3(1.7)) + 0.03125 * c_noise(s * 16.3 + vec3(5.9));
	return max(n / 0.96875 - (1.0 - cloud.x * 0.7), 0.0) * smoothstep(0.0, 0.14, h) * smoothstep(1.0, 0.35, h) * 42.0;
}
float c_hg(float cs, float g) { return 0.0795774715 * (1.0 - g * g) / pow(max(1.0 + g * g - 2.0 * g * cs, 1e-4), 1.5); }
void main() {
	vec3 d = normalize(face_dir(int(p.x + 0.5), in_uv * 2.0 - 1.0));
	vec3 o = vec3(0.0, A_RG + p.y, 0.0);
	vec3 ld = sun.xyz;
	float mie = p.w;
	float cs = dot(d, ld);
	float pr = 0.0596831037 * (1.0 + cs * cs);
	float pm = 0.119366207 * 0.36 * (1.0 + cs * cs) / (2.64 * pow(max(1.64 - 1.6 * cs, 1e-4), 1.5));
	float tg = a_hit(o, d, A_RG, -1.0);
	float tm = tg > 0.0 ? tg : a_hit(o, d, A_RT, 1.0);
	vec3 l = vec3(0.0);
	vec3 tr = vec3(1.0);
	float t0 = 0.0;
	for (int i = 0; i < 32; i++) {
		float u = (float(i) + 1.0) / 32.0;
		float t1 = tm * u * u;
		float dt = t1 - t0;
		vec3 q = o + d * (0.5 * (t0 + t1));
		float h = length(q) - A_RG;
		vec3 sr = a_ray(h);
		float sm = 3.996e-3 * a_mie(h, mie);
		vec3 ex = a_ext(h, mie);
		vec3 stp = exp(-ex * dt);
		vec3 ms = texture(tex_src, vec2(dot(normalize(q), ld) * 0.5 + 0.5, sqrt(clamp(h / 100.0, 0.0, 1.0)))).rgb;
		vec3 sc = (sr * pr + vec3(sm * pm)) * a_trans(q, ld, mie) + (sr + vec3(sm)) * ms;
		l += tr * sc * (vec3(1.0) - stp) / max(ex, vec3(1e-7));
		tr *= stp;
		t0 = t1;
	}
	if (tg > 0.0) {
		vec3 q = o + d * tg;
		vec3 up = normalize(q);
		float mg = dot(up, ld);
		l += tr * p.z * 0.318309886 * (a_trans(q, ld, mie) * max(mg, 0.0) + 12.566 * texture(tex_src, vec2(mg * 0.5 + 0.5, 0.0)).rgb);
	}
	if (cloud.x > 0.0 && d.y > 0.015) {
		float s0 = (1.5 - p.y) / d.y;
		float s1 = min((3.5 - p.y) / d.y, s0 + 14.0);
		float fade = smoothstep(70.0, 18.0, s0);
		if (fade > 0.0) {
			vec3 oc = vec3(0.0, p.y, 0.0);
			float dt = (s1 - s0) / 28.0;
			float ct = 1.0;
			vec3 cl = vec3(0.0);
			vec3 sun_t = a_trans(o + vec3(0.0, 2.5, 0.0), ld, mie);
			vec3 amb = 12.566 * texture(tex_src, vec2(ld.y * 0.5 + 0.5, sqrt(0.025))).rgb;
			float ph = 0.8 * c_hg(cs, 0.6) + 0.2 * c_hg(cs, -0.3);
			for (int i = 0; i < 28; i++) {
				if (ct < 0.01) break;
				vec3 q = oc + d * (s0 + (float(i) + 0.5) * dt);
				float de = c_dens(q);
				if (de <= 0.0) continue;
				float od = 0.0;
				for (int k = 0; k < 4; k++) od += c_dens(q + ld * (0.09 + 0.22 * float(k)));
				od *= 0.22;
				float beer = max(exp(-od), 0.7 * exp(-od * 0.25));
				float pow_t = 1.0 - exp(-2.0 * od - 0.5);
				vec3 s = (sun_t * ph * 12.566 * beer * pow_t + amb * mix(0.6, 1.7, clamp((q.y - 1.5) / 1.4, 0.0, 1.0))) * 0.0795774715 * 0.97;
				float stp = exp(-de * dt);
				cl += ct * s * (1.0 - stp);
				ct *= stp;
			}
			float keep = mix(1.0, ct, fade);
			float air = exp(-s0 * 0.05);
			l = l * keep + cl * fade * mix(1.0, air, 0.7);
		}
	}
	out_rgba = vec4(l * sun.w, 1.0);
}
