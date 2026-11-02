layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_nd;
layout(set = 2, binding = 1) uniform sampler2D tex_depth;
layout(set = 3, binding = 0) uniform Gtao { vec4 lens; vec4 tune; vec4 size; };
layout(location = 0) out vec4 out_ao;
layout(location = 1) out vec4 out_bent;
const float PI = 3.14159265;
const float HALF_PI = 1.57079633;
float ign(vec2 p, float k) { return fract(52.9829189 * fract(dot(p + k * vec2(5.588238, 5.588238), vec2(0.06711056, 0.00583715)))); }
vec3 view_pos(vec2 uv, float d) { return vec3((uv.x * 2.0 - 1.0) * lens.x * d, (1.0 - uv.y * 2.0) * lens.y * d, -d); }
float depth_at(vec2 uv) { return texture(tex_depth, uv).r; }
void main() {
	vec4 nd = texture(tex_nd, in_uv);
	float d = depth_at(in_uv);
	if (nd.w <= 0.0 || d <= 0.0) { out_ao = vec4(1.0, 0.0, 0.0, 1.0); out_bent = vec4(0.0, 0.0, 1.0, 0.0); return; }
	vec3 p = view_pos(in_uv, d);
	vec3 v = normalize(-p);
	vec3 n = normalize(nd.xyz);
	float radius = tune.x;
	int slices = int(size.z);
	int steps = int(size.w);
	vec2 ruv = vec2(radius / (2.0 * d * lens.x), radius / (2.0 * d * lens.y));
	float min_t = max(1.5 * size.x / ruv.x, 1.5 * size.y / ruv.y);
	float fall = 1.0 / max(radius * tune.y, 1e-4);
	float jr = ign(gl_FragCoord.xy, 0.0);
	float js = ign(gl_FragCoord.xy, 1.0);
	float vis = 0.0;
	vec3 bent = vec3(0.0);
	for (int s = 0; s < 16; s++) {
		if (s >= slices) break;
		float phi = (float(s) + jr) * PI / float(slices);
		vec3 dv = vec3(cos(phi), sin(phi), 0.0);
		vec2 du = vec2(dv.x * ruv.x, -dv.y * ruv.y);
		vec3 o = dv - dot(dv, v) * v;
		vec3 on = normalize(o);
		vec3 axis = normalize(cross(o, v));
		vec3 np = n - axis * dot(n, axis);
		float npl = length(np);
		float cn = clamp(dot(np, v) / max(npl, 1e-6), -1.0, 1.0);
		float sn = (dot(on, np) < 0.0 ? -1.0 : 1.0) * acos(cn);
		float low0 = cos(sn + HALF_PI);
		float low1 = cos(sn - HALF_PI);
		float hc0 = low0;
		float hc1 = low1;
		for (int k = 0; k < 32; k++) {
			if (k >= steps) break;
			float t = (float(k) + js) / float(steps);
			t = max(t * t, min_t);
			for (int side = 0; side < 2; side++) {
				vec2 suv = in_uv + (side == 0 ? du : -du) * t;
				if (any(lessThan(suv, vec2(0.0))) || any(greaterThan(suv, vec2(1.0)))) continue;
				float sd = depth_at(suv);
				if (sd <= 0.0) continue;
				vec3 dl = view_pos(suv, sd) - p;
				float dist = length(dl);
				if (dist < 1e-5) continue;
				float w = clamp((radius - dist) * fall, 0.0, 1.0);
				float c = dot(dl / dist, v);
				if (side == 0) hc0 = max(hc0, mix(low0, c, w)); else hc1 = max(hc1, mix(low1, c, w));
			}
		}
		float h0 = -acos(clamp(hc1, -1.0, 1.0));
		float h1 = acos(clamp(hc0, -1.0, 1.0));
		h0 = sn + clamp(h0 - sn, -HALF_PI, HALF_PI);
		h1 = sn + clamp(h1 - sn, -HALF_PI, HALF_PI);
		float ssn = sin(sn);
		float ia0 = (cn + 2.0 * h0 * ssn - cos(2.0 * h0 - sn)) * 0.25;
		float ia1 = (cn + 2.0 * h1 * ssn - cos(2.0 * h1 - sn)) * 0.25;
		vis += npl * (ia0 + ia1);
		float t0 = (6.0 * sin(h0 - sn) - sin(3.0 * h0 - sn) + 6.0 * sin(h1 - sn) - sin(3.0 * h1 - sn) + 16.0 * ssn - 3.0 * (sin(h0 + sn) + sin(h1 + sn))) / 12.0;
		float t1 = (-cos(3.0 * h0 - sn) - cos(3.0 * h1 - sn) + 8.0 * cos(sn) - 3.0 * (cos(h0 + sn) + cos(h1 + sn))) / 12.0;
		bent += (on * t0 + v * t1) * npl;
	}
	float ao = clamp(vis / float(max(slices, 1)), 0.0, 1.0);
	vec3 b = length(bent) > 1e-6 ? normalize(bent) : n;
	out_ao = vec4(pow(ao, tune.z), d, 0.0, 1.0);
	out_bent = vec4(b, ao);
}
