struct Part { vec4 pos; vec4 vel; vec4 misc; };
uint fx_hash(uint x) { x ^= x >> 16; x *= 0x7feb352du; x ^= x >> 15; x *= 0x846ca68bu; x ^= x >> 16; return x; }
float fx_rnd(inout uint s) { s = fx_hash(s); return float(s >> 8) / 16777216.0; }
vec3 fx_grad(vec3 c) { uint h = fx_hash(uint(int(c.x) * 73856093) ^ uint(int(c.y) * 19349663) ^ uint(int(c.z) * 83492791)); float a = float(h & 1023u) / 1023.0 * 6.2831853; float z = float((h >> 10) & 1023u) / 1023.0 * 2.0 - 1.0; float r = sqrt(max(1.0 - z * z, 0.0)); return vec3(r * cos(a), r * sin(a), z); }
float fx_noise(vec3 p) {
	vec3 i = floor(p); vec3 f = p - i;
	vec3 u = f * f * f * (f * (f * 6.0 - 15.0) + 10.0);
	float n000 = dot(fx_grad(i), f), n100 = dot(fx_grad(i + vec3(1, 0, 0)), f - vec3(1, 0, 0));
	float n010 = dot(fx_grad(i + vec3(0, 1, 0)), f - vec3(0, 1, 0)), n110 = dot(fx_grad(i + vec3(1, 1, 0)), f - vec3(1, 1, 0));
	float n001 = dot(fx_grad(i + vec3(0, 0, 1)), f - vec3(0, 0, 1)), n101 = dot(fx_grad(i + vec3(1, 0, 1)), f - vec3(1, 0, 1));
	float n011 = dot(fx_grad(i + vec3(0, 1, 1)), f - vec3(0, 1, 1)), n111 = dot(fx_grad(i + vec3(1, 1, 1)), f - vec3(1, 1, 1));
	return mix(mix(mix(n000, n100, u.x), mix(n010, n110, u.x), u.y), mix(mix(n001, n101, u.x), mix(n011, n111, u.x), u.y), u.z);
}
vec3 fx_pot(vec3 p) { return vec3(fx_noise(p), fx_noise(p + vec3(31.4, 47.2, 12.9)), fx_noise(p + vec3(-17.3, 23.1, 61.7))); }
vec3 fx_curl(vec3 p) {
	float h = 0.01;
	vec3 dx = (fx_pot(p + vec3(h, 0, 0)) - fx_pot(p - vec3(h, 0, 0))) / (2.0 * h);
	vec3 dy = (fx_pot(p + vec3(0, h, 0)) - fx_pot(p - vec3(0, h, 0))) / (2.0 * h);
	vec3 dz = (fx_pot(p + vec3(0, 0, h)) - fx_pot(p - vec3(0, 0, h))) / (2.0 * h);
	return vec3(dy.z - dz.y, dz.x - dx.z, dx.y - dy.x);
}
vec3 fx_gradfield(vec3 p) {
	float h = 0.01;
	return vec3(fx_noise(p + vec3(h, 0, 0)) - fx_noise(p - vec3(h, 0, 0)), fx_noise(p + vec3(0, h, 0)) - fx_noise(p - vec3(0, h, 0)), fx_noise(p + vec3(0, 0, h)) - fx_noise(p - vec3(0, 0, h))) / (2.0 * h);
}
vec4 fx_curve4(vec4 k0, vec4 k1, vec4 k2, vec4 k3, float t) { float x = clamp(t, 0.0, 1.0) * 3.0; return x < 1.0 ? mix(k0, k1, x) : (x < 2.0 ? mix(k1, k2, x - 1.0) : mix(k2, k3, x - 2.0)); }
float fx_curve1(vec4 k, float t) { float x = clamp(t, 0.0, 1.0) * 3.0; return x < 1.0 ? mix(k.x, k.y, x) : (x < 2.0 ? mix(k.y, k.z, x - 1.0) : mix(k.z, k.w, x - 2.0)); }
