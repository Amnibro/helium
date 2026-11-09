const float A_RG = 6360.0;
const float A_RT = 6460.0;
vec3 a_ray(float h) { return vec3(5.802e-3, 13.558e-3, 33.1e-3) * exp(-h / 8.0); }
float a_mie(float h, float mie) { return mie * exp(-h / 1.2); }
vec3 a_ext(float h, float mie) { return a_ray(h) + vec3(4.44e-3 * a_mie(h, mie)) + vec3(0.650e-3, 1.881e-3, 0.085e-3) * max(1.0 - abs(h - 25.0) / 15.0, 0.0); }
float a_hit(vec3 o, vec3 d, float rad, float sgn) {
	float b = dot(o, d);
	float di = b * b - dot(o, o) + rad * rad;
	return di < 0.0 ? -1.0 : -b + sgn * sqrt(di);
}
vec3 a_trans(vec3 p, vec3 d, float mie) {
	if (a_hit(p, d, A_RG, -1.0) > 0.0) return vec3(0.0);
	float dt = a_hit(p, d, A_RT, 1.0) / 8.0;
	vec3 od = vec3(0.0);
	for (int i = 0; i < 8; i++) od += a_ext(length(p + d * ((float(i) + 0.5) * dt)) - A_RG, mie);
	return exp(-od * dt);
}
