#version 450
#define PI 3.141592653589793
layout(location = 0) in vec2 in_uv;
layout(location = 0) out vec4 out_color;
layout(set = 2, binding = 0) uniform samplerCube env_src;
layout(set = 3, binding = 0) uniform Filter { uint face; float mip_roughness; uint mode; float src_mips; };
vec3 face_dir(uint f, vec2 uv) {
	float u = uv.x * 2.0 - 1.0; float v = uv.y * 2.0 - 1.0;
	if (f == 0u) return normalize(vec3(1.0, -v, -u));
	if (f == 1u) return normalize(vec3(-1.0, -v, u));
	if (f == 2u) return normalize(vec3(u, 1.0, v));
	if (f == 3u) return normalize(vec3(u, -1.0, -v));
	if (f == 4u) return normalize(vec3(u, -v, 1.0));
	return normalize(vec3(-u, -v, -1.0));
}
vec2 hammersley(uint i, uint n) { uint b = (i << 16u) | (i >> 16u); b = ((b & 0x55555555u) << 1u) | ((b & 0xAAAAAAAAu) >> 1u); b = ((b & 0x33333333u) << 2u) | ((b & 0xCCCCCCCCu) >> 2u); b = ((b & 0x0F0F0F0Fu) << 4u) | ((b & 0xF0F0F0F0u) >> 4u); b = ((b & 0x00FF00FFu) << 8u) | ((b & 0xFF00FF00u) >> 8u); return vec2(float(i) / float(n), float(b) * 2.3283064365386963e-10); }
mat3 basis(vec3 n) { vec3 up = abs(n.z) < 0.999 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0); vec3 t = normalize(cross(up, n)); return mat3(t, cross(n, t), n); }
void main() {
	vec3 n = face_dir(face, in_uv);
	mat3 tbn = basis(n);
	float base = float(textureSize(env_src, 0).x);
	vec3 acc = vec3(0.0);
	float w = 0.0;
	if (mode == 1u) {
		uint count = 512u;
		for (uint i = 0u; i < count; i++) {
			vec2 h = hammersley(i, count);
			float phi = 2.0 * PI * h.x;
			float ct = sqrt(1.0 - h.y);
			float st = sqrt(h.y);
			vec3 l = tbn * vec3(cos(phi) * st, sin(phi) * st, ct);
			float pdf = ct / PI;
			float lod = clamp(0.5 * log2(4.0 * PI / (float(count) * pdf * 6.0 * base * base + 1e-5)) + 1.0, 0.0, src_mips - 1.0);
			acc += textureLod(env_src, l, lod).rgb;
			w += 1.0;
		}
		out_color = vec4(acc / w, 1.0);
		return;
	}
	float a = max(mip_roughness * mip_roughness, 0.0001);
	if (mip_roughness < 0.001) { out_color = vec4(textureLod(env_src, n, 0.0).rgb, 1.0); return; }
	uint count = 256u;
	for (uint i = 0u; i < count; i++) {
		vec2 h = hammersley(i, count);
		float phi = 2.0 * PI * h.x;
		float ct = sqrt((1.0 - h.y) / (1.0 + (a * a - 1.0) * h.y));
		float st = sqrt(1.0 - ct * ct);
		vec3 hv = tbn * vec3(cos(phi) * st, sin(phi) * st, ct);
		vec3 l = normalize(2.0 * dot(n, hv) * hv - n);
		float nl = dot(n, l);
		if (nl > 0.0) {
			float nh = max(dot(n, hv), 0.0);
			float d = (a * a) / (PI * pow(nh * nh * (a * a - 1.0) + 1.0, 2.0));
			float pdf = d * nh / (4.0 * nh) + 0.0001;
			float lod = clamp(0.5 * log2((4.0 * PI / (6.0 * base * base)) / (float(count) * pdf)) + 1.0, 0.0, src_mips - 1.0);
			acc += textureLod(env_src, l, lod).rgb * nl;
			w += nl;
		}
	}
	out_color = vec4(acc / max(w, 0.0001), 1.0);
}
