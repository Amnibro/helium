#include "ms_lut.glsl"
vec2 ms_lut(float n_v, float rough) {
	float x = sqrt(clamp(n_v, 0.0, 1.0)) * float(MS_N - 1);
	float y = clamp(rough, 0.0, 1.0) * float(MS_N - 1);
	int x0 = min(int(x), MS_N - 2);
	int y0 = min(int(y), MS_N - 2);
	float fx = x - float(x0);
	float fy = y - float(y0);
	int i = y0 * MS_N + x0;
	vec2 a = mix(unpackUnorm2x16(MS_EB[i]), unpackUnorm2x16(MS_EB[i + 1]), fx);
	vec2 b = mix(unpackUnorm2x16(MS_EB[i + MS_N]), unpackUnorm2x16(MS_EB[i + MS_N + 1]), fx);
	return mix(a, b, fy);
}
float ms_e(float n_v, float rough, float e) {
	float x = sqrt(clamp(n_v, 0.0, 1.0)) * float(MS_N - 1);
	if (x >= 3.0) return e;
	float y = clamp(rough, 0.0, 1.0) * float(MS_N - 1);
	int x0 = min(int(x), MS_N - 2);
	int y0 = min(int(y), MS_N - 2);
	int i = y0 * MS_N + x0;
	float a = max(unpackUnorm2x16(MS_EB[i]).x, unpackUnorm2x16(MS_EB[i + 1]).x);
	float b = max(unpackUnorm2x16(MS_EB[i + MS_N]).x, unpackUnorm2x16(MS_EB[i + MS_N + 1]).x);
	return max(a, b);
}
vec3 ms_factor(vec3 f0, float e, bool on) {
	if (!on) return vec3(1.0);
	return 1.0 + f0 * (1.0 / max(e, 0.25) - 1.0);
}
