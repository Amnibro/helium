uint rs;
float rnd() { rs = rs * 747796405u + 2891336453u; uint w = ((rs >> ((rs >> 28u) + 4u)) ^ rs) * 277803737u; w = (w >> 22u) ^ w; return float(w >> 8u) * (1.0 / 16777216.0); }
uint hash(uint x) { x ^= x >> 16u; x *= 0x7feb352du; x ^= x >> 15u; x *= 0x846ca68bu; x ^= x >> 16u; return x; }
float falloff(float d) { float r = par[3].x; float q = clamp(1.0 - d * d / (r * r), 0.0, 1.0); return q * q / (1.0 + d * d); }
vec3 radiance(uvec2 px, vec2 wh)
{
	float th = par[1].w;
	float u = ((float(px.x) + rnd()) / wh.x * 2.0 - 1.0) * th;
	float v = (1.0 - (float(px.y) + rnd()) / wh.y * 2.0) * th;
	vec3 d = normalize(vec3(-u, v, 1.0));
	vec3 o = par[1].xyz;
	vec3 tp = vec3(1.0);
	vec3 L = vec3(0.0);
	int depth = 0;
	while (true)
	{
		int pr;
		float t = trace(o, d, 1e30, pr);
		if (pr < 0) break;
		vec3 p = o + d * t;
		vec3 n = tri_n(pr);
		if (dot(n, d) > 0.0) n = -n;
		vec3 al = tri_al(pr);
		vec3 l = par[2].xyz - p;
		float dl = length(l);
		float cl = dot(n, l) / dl;
		if (cl > 0.0 && vis(p, l / dl, dl - par[3].y)) L += tp * al * (par[2].w * falloff(dl) * cl / 3.14159265358979);
		tp *= al;
		depth++;
		if (depth >= 3) { float pq = min(max(tp.x, max(tp.y, tp.z)), 0.95); if (rnd() >= pq) break; tp /= pq; }
		float r1 = rnd();
		float r2 = rnd();
		float rr = sqrt(r1);
		float ph = 6.28318530717959 * r2;
		vec3 a = abs(n.x) > 0.9 ? vec3(0.0, 1.0, 0.0) : vec3(1.0, 0.0, 0.0);
		vec3 b = normalize(cross(a, n));
		vec3 c = cross(n, b);
		d = b * (rr * cos(ph)) + c * (rr * sin(ph)) + n * sqrt(max(1.0 - r1, 0.0));
		o = p;
	}
	return L;
}
void main()
{
	uvec2 px = gl_GlobalInvocationID.xy;
	vec2 wh = par[0].xy;
	if (px.x >= uint(wh.x) || px.y >= uint(wh.y)) return;
	uint pi = px.y * uint(wh.x) + px.x;
	int n = int(par[0].z);
	uint base = uint(par[0].w);
	vec4 s = vec4(0.0);
	float s2 = 0.0;
	for (int k = 0; k < n; k++)
	{
		rs = hash(pi * 0x9E3779B9u ^ hash(base + uint(k)));
		vec3 L = radiance(px, wh);
		float y = dot(L, vec3(0.2126, 0.7152, 0.0722));
		s += vec4(L, y);
		s2 += y * y;
	}
	acc[pi * 2u] = s;
	acc[pi * 2u + 1u] = vec4(s2, float(n), 0.0, 0.0);
}
