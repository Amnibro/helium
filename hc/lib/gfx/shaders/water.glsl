vec3 water_wave(vec2 p, float tm, vec3 wb, int n) {
	vec2 g = vec2(0.0);
	vec2 q = p;
	float h = 0.0;
	float f = wb.x;
	float a = wb.y;
	float ang = 0.7;
	for (int i = 0; i < n; i++) {
		vec2 d = vec2(cos(ang), sin(ang));
		float ph = dot(q, d) * f + tm * sqrt(9.81 * f) * wb.z;
		float s = sin(ph) * a / f;
		g += d * a * cos(ph);
		h += s;
		q += d * s * 0.5;
		f *= 1.31;
		a *= 0.87;
		ang += 2.4;
	}
	return vec3(g, h);
}
