struct Hit { vec3 p; float t; };
layout(set = 2, binding = 0) uniform sampler2D t2;
layout(set = 2, binding = 1) uniform samplerCube tc;
layout(set = 2, binding = 2) uniform sampler3D t3;
layout(set = 2, binding = 3) uniform sampler2DArray ta;
layout(set = 2, binding = 4) uniform sampler2DShadow ts;
layout(set = 2, binding = 5) uniform samplerCubeShadow tcs;
layout(set = 2, binding = 6) uniform sampler2DArrayShadow tas;
layout(set = 2, binding = 7) uniform usampler2D tu;
layout(std430, set = 2, binding = 8) readonly buffer Data { vec4 data[]; };
layout(set = 3, binding = 0) uniform Params { mat4 m; vec4 k; vec4 arr[3]; };
layout(location = 0) in vec4 v_a;
layout(location = 1) flat in int v_i;
layout(location = 2) flat in uint v_u;
layout(location = 0) out vec4 o_c;
layout(location = 1) out uint o_u;
const float W[3] = float[](0.25, 0.5, 0.25);
float filter(float x) { return x * 2.0; }
Hit pick(bool c, Hit a, Hit b) { return c ? a : b; }
void bump(inout vec2 v, out float s) { v.yx += vec2(1.0, 2.0); s = v.x; }
vec4 samp(sampler2D s, vec2 uv) { return texture(s, uv); }
float sgn(float x) { if (x < 0.0) return -1.0; else return 1.0; }
void main() {
	vec4 c = texture(t2, v_a.xy) + textureLod(t2, v_a.xy, 1.0) + textureGrad(t2, v_a.xy, vec2(0.1), vec2(0.1)) + textureOffset(t2, v_a.xy, ivec2(1, -1)) + texelFetch(t2, ivec2(v_a.zw), 0);
	c += texture(tc, v_a.xyz) + textureLod(tc, v_a.xyz, 0.0) + texture(t3, v_a.xyz) + texture(ta, v_a.xyz) + textureLod(ta, v_a.xyz, 2.0) + texelFetch(ta, ivec3(1, 2, 3), 0) + texelFetch(t3, ivec3(1), 0);
	c.x += texture(ts, v_a.xyz) + textureLod(ts, v_a.xyz, 0.0) + texture(tcs, v_a) + texture(tas, v_a);
	ivec2 sz = textureSize(t2, 0) + textureSize(tc, 0);
	ivec3 sa = textureSize(ta, 0) + textureSize(t3, 0);
	uvec4 u = texelFetch(tu, ivec2(0), 0);
	c += samp(t2, v_a.yx);
	int i = v_i;
	int sh = i << i;
	uint us = v_u >> i;
	i <<= 2;
	us >>= i;
	float m1 = mod(v_a.x, 3.0);
	vec3 m3 = mod(v_a.xyz, 2.0);
	vec3 m3b = mod(v_a.xyz, vec3(1.0, 2.0, 3.0));
	mat3 r = mat3(m[0].xyz, m[1].xyz, m[2].xyz);
	mat4 id = mat4(1.0);
	mat3 r2 = r * mat3(2.0);
	bool nan = isnan(v_a.x) || any(isinf(v_a.xy));
	int bi = floatBitsToInt(v_a.x);
	uvec2 bu = floatBitsToUint(v_a.xy);
	float bf = intBitsToFloat(bi) + uintBitsToFloat(bu.x);
	uint pk = packUnorm4x8(c) ^ packHalf2x16(v_a.xy);
	vec4 up = unpackSnorm4x8(pk);
	Hit h = pick(v_a.x > 0.0, Hit(vec3(1.0), 2.0), Hit(vec3(0.0), 3.0));
	vec2 v = vec2(1.0);
	float s;
	bump(v, s);
	vec3 sw = vec3(0.0);
	sw.zx = v;
	sw.xy *= 2.0;
	sw.st += vec2(1.0);
	float acc = 0.0;
	int n = 0;
	do { acc += W[n % 3]; n++; } while (n < 4);
	switch (v_i) { case 0: acc += 1.0; break; case 1: case 2: acc -= 1.0; break; default: acc *= 2.0; break; }
	switch (v_u) { case 3u: acc += 0.5; break; }
	float arrs[4];
	arrs[n & 3] = 1.0;
	int sp = 0;
	arrs[sp++] = 2.0;
	float t = arrs[--sp];
	for (int j = 0; j < 3; ++j) { acc += arr[j].x * W[j] + data[j].y; }
	vec4 sel = mix(c, up, lessThan(c, up));
	bvec4 nb = not(greaterThanEqual(c, up));
	if (all(equal(sz, ivec2(4))) && nb.x || nan) discard;
	float var = 1.0, let = 2.0;
	acc += filter(s) + r[0].x + id[1].y + r2[2].z + float(sa.x) + float(u.x) + float(bi) + bf + h.t + float(us) + t + float(sh) + m1 + m3.x + m3b.y + sel.w + float(data.length()) + var + let + sgn(sw.z);
	o_c = c * acc + vec4(m * k);
	o_u = u.y + uint(i);
}
