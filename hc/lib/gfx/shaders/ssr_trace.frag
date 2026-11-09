layout(set = 2, binding = 0) uniform sampler2D tex_depth;
layout(set = 2, binding = 1) uniform sampler2D tex_h1;
layout(set = 2, binding = 2) uniform sampler2D tex_h2;
layout(set = 2, binding = 3) uniform sampler2D tex_h3;
layout(set = 2, binding = 4) uniform sampler2D tex_h4;
layout(set = 2, binding = 5) uniform sampler2D tex_h5;
layout(set = 2, binding = 6) uniform sampler2D tex_h6;
layout(set = 2, binding = 7) uniform sampler2D tex_h7;
layout(set = 2, binding = 8) uniform sampler2D tex_nd;
layout(set = 2, binding = 9) uniform sampler2D tex_motion;
layout(set = 3, binding = 0) uniform Ssr { vec4 lens; vec4 jit; vec4 tune; vec4 edge; mat4 inv_view; mat4 prev_vp; };
layout(location = 0) out vec4 out_hit;
#include "hiz_march.glsl"
void main() {
	out_hit = vec4(0.0);
	ivec2 x = ivec2(gl_FragCoord.xy);
	float z = texelFetch(tex_depth, x, 0).r;
	if (z <= 0.0) return;
	vec3 n = normalize(texelFetch(tex_nd, x, 0).xyz);
	vec3 p0 = view_pos(gl_FragCoord.xy + jit.xy, z);
	vec3 r = reflect(normalize(p0), n);
	if (dot(r, n) <= 0.0) return;
	vec3 p = p0 + n * (3.0 * z * lens.y / jit.w);
	vec2 sh;
	if (hiz_march(p, r, tune.z, int(tune.x), tune.y, 0, sh) != 0) return;
	ivec2 hx = clamp(ivec2(floor(sh)), ivec2(0), ivec2(jit.zw) - 1);
	float zh = texelFetch(tex_depth, hx, 0).r;
	if (zh <= 0.0) return;
	vec3 nh = texelFetch(tex_nd, hx, 0).xyz;
	vec3 ph = view_pos(sh + jit.xy, zh);
	float dist = length(ph - p);
	vec2 uv = sh / jit.zw;
	vec2 e = clamp(min(uv, 1.0 - uv) / max(edge.x, 1e-4), 0.0, 1.0);
	float conf = e.x * e.y * (1.0 - smoothstep(0.7, 1.0, dist / tune.z)) * smoothstep(0.0, 0.17, -dot(nh, r));
	vec4 c = prev_vp * (inv_view * vec4(ph, 1.0));
	vec2 pu = tune.w > 0.5 ? (sh + jit.xy) / jit.zw - texelFetch(tex_motion, hx, 0).xy : vec2(c.x / c.w * 0.5 + 0.5, 0.5 - c.y / c.w * 0.5);
	if (any(lessThan(pu, vec2(0.0))) || any(greaterThan(pu, vec2(1.0))) || conf <= 0.0) return;
	out_hit = vec4(pu, dist / zh, conf);
}
