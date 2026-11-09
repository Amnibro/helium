layout(set = 2, binding = 0) uniform sampler2D tex_new;
layout(set = 2, binding = 1) uniform sampler2D tex_hc;
layout(set = 2, binding = 2) uniform sampler2D tex_hz;
layout(set = 2, binding = 3) uniform sampler2D tex_depth;
layout(set = 2, binding = 4) uniform sampler2D tex_motion;
layout(set = 3, binding = 0) uniform SsgiA { vec4 size; vec4 tune; vec4 jit; };
layout(location = 0) out vec4 out_c;
layout(location = 1) out vec4 out_z;
void main() {
	ivec2 h = ivec2(gl_FragCoord.xy);
	ivec2 x = min(h * 2, ivec2(size.xy) - 1);
	vec4 nw = texelFetch(tex_new, h, 0);
	float z = texelFetch(tex_depth, x, 0).r;
	out_c = nw;
	out_z = vec4(z, 1.0, 0.0, 0.0);
	if (z <= 0.0 || tune.x < 0.5) return;
	vec2 pu = (vec2(x) + 0.5 + jit.xy) * size.zw - texelFetch(tex_motion, x, 0).xy;
	if (any(lessThan(pu, vec2(0.0))) || any(greaterThan(pu, vec2(1.0)))) return;
	ivec2 hs = textureSize(tex_hz, 0);
	vec2 hp = (pu * size.xy - 0.5) * 0.5;
	vec2 hz = texelFetch(tex_hz, clamp(ivec2(floor(hp + 0.5)), ivec2(0), hs - 1), 0).rg;
	if (abs(hz.x - z) > tune.y * z) return;
	float cnt = min(hz.y + 1.0, tune.z);
	out_c = mix(texture(tex_hc, (hp + 0.5) / vec2(hs)), nw, 1.0 / cnt);
	out_z = vec4(z, cnt, 0.0, 0.0);
}
