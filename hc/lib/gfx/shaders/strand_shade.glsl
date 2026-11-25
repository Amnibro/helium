float hI0(float x) { float v = 0.0, x2i = 1.0, fi = 1.0, i4 = 1.0; for (int i = 0; i < 16; i++) { if (i > 1) fi *= float(i); v += x2i / (i4 * fi * fi); x2i *= x * x; i4 *= 4.0; } return v; }
float hLogI0(float x) { return x > 12.0 ? x + 0.5 * (-log(6.2831853) + log(1.0 / x) + 1.0 / (8.0 * x)) : log(hI0(x)); }
float hMp(float cti, float cto, float sti, float sto, float v) {
	float a = cti * cto / v, b = sti * sto / v;
	if (v <= 0.1) return exp(hLogI0(a) - b - 1.0 / v + 0.6931 + log(1.0 / (2.0 * v)));
	return exp(-b) * hI0(a) / ((exp(1.0 / v) - exp(-1.0 / v)) * v);
}
float hLogi(float x, float s) { float e = exp(-abs(x) / s); return e / (s * (1.0 + e) * (1.0 + e)); }
float hNp(float phi, float p, float s, float go, float gt) {
	float d = phi - (2.0 * p * gt - 2.0 * go + p * 3.14159265);
	d = d - 6.2831853 * floor((d + 3.14159265) / 6.2831853);
	float c = 1.0 / (1.0 + exp(-3.14159265 / s)) - 1.0 / (1.0 + exp(3.14159265 / s));
	return hLogi(d, s) / c;
}
float hFr(float ci, float eta) {
	ci = clamp(ci, 0.0, 1.0);
	float st = sqrt(max(0.0, 1.0 - ci * ci)) / eta, ct = sqrt(max(0.0, 1.0 - st * st));
	float rpa = (eta * ci - ct) / (eta * ci + ct), rpe = (ci - eta * ct) / (ci + eta * ct);
	return st >= 1.0 ? 1.0 : 0.5 * (rpa * rpa + rpe * rpe);
}
vec2 hTilt(int p, float sto, float cto, float al) { float k = (p == 0 ? -2.0 : p == 1 ? 1.0 : p == 2 ? 4.0 : 0.0) * al, c = cos(k), n = sin(k); return vec2(sto * c + cto * n, abs(cto * c - sto * n)); }
void hPre(vec3 T, vec3 V, vec3 sig, float h, float bm, float bn, float ex, out vec3 X, out vec3 Y, out vec2 so, out vec2 g, out vec3 A[4], out vec4 vv, out float s) {
	so.x = clamp(dot(V, T), -0.9999, 0.9999); so.y = sqrt(1.0 - so.x * so.x);
	vec3 n0 = abs(T.y) < 0.9 ? vec3(0.0, 1.0, 0.0) : vec3(1.0, 0.0, 0.0); X = normalize(n0 - T * dot(n0, T)); Y = cross(T, X);
	float eta = 1.55, stt = so.x / eta, ctt = sqrt(max(0.0, 1.0 - stt * stt));
	float etp = sqrt(max(eta * eta - so.x * so.x, 1e-4)) / so.y, sgt = clamp(h / etp, -1.0, 1.0), cgt = sqrt(1.0 - sgt * sgt);
	g = vec2(asin(clamp(h, -1.0, 1.0)), asin(sgt));
	vec3 tr = exp(-sig * (2.0 * cgt / ctt));
	float f = hFr(so.y * sqrt(max(0.0, 1.0 - h * h)), eta);
	A[0] = vec3(f); A[1] = (1.0 - f) * (1.0 - f) * tr; A[2] = A[1] * f * tr; A[3] = A[2] * f * tr / (vec3(1.0) - f * tr);
	float v0 = 0.726 * bm + 0.812 * bm * bm + 3.7 * pow(bm, 20.0);
	vv = vec4(1.0, 0.25, 4.0, 4.0) * v0 * v0 + ex;
	s = 0.626657 * (0.265 * bn + 1.194 * bn * bn + 5.372 * pow(bn, 22.0));
	s = sqrt(s * s + 0.3 * ex);
}
vec4 hW(vec3 A[4]) { vec4 w = vec4(dot(A[0], vec3(0.2126, 0.7152, 0.0722)), dot(A[1], vec3(0.2126, 0.7152, 0.0722)), dot(A[2], vec3(0.2126, 0.7152, 0.0722)), dot(A[3], vec3(0.2126, 0.7152, 0.0722))); return w / max(w.x + w.y + w.z + w.w, 1e-30); }
vec3 chiang(vec3 T, vec3 L, vec3 V, vec3 sig, float h, float bm, float bn, float al, float ex, out vec3 af, out vec3 ab, out float pdf) {
	vec3 X, Y, A[4];
	vec2 so, g;
	vec4 vv;
	float s;
	hPre(T, V, sig, h, bm, bn, ex, X, Y, so, g, A, vv, s);
	float sti = clamp(dot(L, T), -0.9999, 0.9999), cti = sqrt(1.0 - sti * sti), phi = atan(dot(L, Y), dot(L, X)) - atan(dot(V, Y), dot(V, X));
	af = A[1];
	ab = A[0] + A[2] + A[3];
	vec4 w = hW(A);
	vec3 r = vec3(0.0);
	pdf = 0.0;
	for (int p = 0; p < 4; p++) { vec2 o = hTilt(p, so.x, so.y, al); float m = hMp(cti, o.y, sti, o.x, vv[p]) * (p < 3 ? hNp(phi, float(p), s, g.x, g.y) : 0.1591549); r += m * A[p]; pdf += m * w[p]; }
	return r;
}
vec3 chiang_dir(vec3 T, vec3 V, vec3 sig, float h, float bm, float bn, float al, vec4 u) {
	vec3 X, Y, A[4];
	vec2 so, g;
	vec4 vv;
	float s;
	hPre(T, V, sig, h, bm, bn, 0.0, X, Y, so, g, A, vv, s);
	vec4 w = hW(A);
	int p = u.x < w.x ? 0 : u.x < w.x + w.y ? 1 : u.x < w.x + w.y + w.z ? 2 : 3;
	vec2 o = hTilt(p, so.x, so.y, al);
	float v = vv[p], u1 = max(u.y, 1e-5), ct = 1.0 + v * log(u1 + (1.0 - u1) * exp(-2.0 / v)), st = sqrt(max(0.0, 1.0 - ct * ct));
	float sti = clamp(-ct * o.x + st * cos(6.2831853 * u.z) * o.y, -1.0, 1.0), cti = sqrt(1.0 - sti * sti);
	float ca = 1.0 / (1.0 + exp(3.14159265 / s)), k = 1.0 / (1.0 + exp(-3.14159265 / s)) - ca;
	float dp = p < 3 ? 2.0 * float(p) * g.y - 2.0 * g.x + float(p) * 3.14159265 + clamp(-s * log(1.0 / (u.w * k + ca) - 1.0), -3.14159265, 3.14159265) : 6.2831853 * u.w;
	float pi = atan(dot(V, Y), dot(V, X)) + dp;
	return T * sti + (X * cos(pi) + Y * sin(pi)) * cti;
}
