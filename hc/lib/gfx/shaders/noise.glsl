float hash3(vec3 q) { vec3 r = fract(q * 0.3183099 + vec3(0.1, 0.2, 0.3)) * 17.0; return fract(r.x * r.y * r.z * (r.x + r.y + r.z)); }
float vnoise(vec3 q) {
	vec3 i = floor(q);
	vec3 f = fract(q);
	vec3 u = f * f * (3.0 - 2.0 * f);
	float a = mix(mix(hash3(i), hash3(i + vec3(1.0, 0.0, 0.0)), u.x), mix(hash3(i + vec3(0.0, 1.0, 0.0)), hash3(i + vec3(1.0, 1.0, 0.0)), u.x), u.y);
	float b = mix(mix(hash3(i + vec3(0.0, 0.0, 1.0)), hash3(i + vec3(1.0, 0.0, 1.0)), u.x), mix(hash3(i + vec3(0.0, 1.0, 1.0)), hash3(i + vec3(1.0, 1.0, 1.0)), u.x), u.y);
	return mix(a, b, u.z);
}
