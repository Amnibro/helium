layout(location = 0) in vec3 in_pos;
layout(location = 1) in vec3 in_nrm;
layout(location = 2) in vec2 in_uv0;
layout(location = 3) in vec2 in_uv1;
layout(location = 4) in vec4 in_tan;
layout(location = 5) in vec4 in_col;
layout(location = 6) in vec4 in_joint;
layout(location = 7) in vec4 in_weight;

layout(std430, set = 0, binding = 0) readonly buffer Joints { vec4 joint_cols[]; };
layout(std430, set = 0, binding = 1) readonly buffer Morphs { vec4 morph_data[]; };
layout(std430, set = 0, binding = 2) readonly buffer Insts { vec4 inst_cols[]; };
layout(std430, set = 0, binding = 3) readonly buffer InstIds { vec4 inst_ids[]; };

layout(set = 1, binding = 0) uniform Draw {
	mat4 model;
	mat4 model_normal;
	mat4 view_proj;
	mat4 prev_model;
	vec4 deform;
	vec4 misc;
	mat4 cur_vp;
	mat4 prev_vp;
	vec4 weights[16];
	vec4 prev_weights[16];
	vec4 inst;
	vec4 sway_o;
	vec4 wind;
	vec4 wind_t;
	vec4 push[4];
	vec4 prev_push[4];
	vec4 water;
	vec4 water_t;
};
#include "water.glsl"

layout(location = 3) out vec4 out_uv;
layout(location = 4) out vec4 out_col;

mat4 joint(int j) {
	return mat4(joint_cols[j * 4], joint_cols[j * 4 + 1], joint_cols[j * 4 + 2], joint_cols[j * 4 + 3]);
}
mat4 skin(int base) {
	return joint(base + int(in_joint.x)) * in_weight.x
		+ joint(base + int(in_joint.y)) * in_weight.y
		+ joint(base + int(in_joint.z)) * in_weight.z
		+ joint(base + int(in_joint.w)) * in_weight.w;
}
vec3 bend(vec3 wp, vec3 o, float hw, float sw) {
	float t = clamp((wp.y - o.y) / max(hw, 0.0001), 0.0, 1.0);
	float w = t * t;
	float g = 0.6 + 0.4 * sin(wind_t.x * wind.w + 0.7 * (o.x + o.z));
	vec3 q = wp + vec3(wind.x, 0.0, wind.z) * (g * w * sw * hw);
	int n = int(wind_t.z);
	vec3 a = vec3(o.x, wp.y, o.z);
	for (int i = 0; i < 4; i++) {
		if (i < n) {
			vec4 c = push[i];
			vec3 d = a - c.xyz;
			float l = length(d);
			float hl = length(d.xz);
			vec2 h = hl > 0.0001 ? d.xz / max(hl, 0.0001) : vec2(1.0, 0.0);
			if (l < c.w) q += vec3(h.x, 0.0, h.y) * ((c.w - l) * w * min(sw, 1.0));
		}
	}
	return q;
}
void main() {
	vec3 p = in_pos;
	int targets = int(deform.z);
	if (targets > 0) {
		int local_v = gl_VertexIndex - int(deform.w);
		int count = int(misc.x);
		for (int t = 0; t < targets && t < 64; t++) {
			float w = weights[t >> 2][t & 3];
			if (w == 0.0) continue;
			p += morph_data[(int(deform.y) + t * count + local_v) * 2].xyz * w;
		}
	}
	mat4 m = deform.x >= 0.0 ? skin(int(deform.x)) : model;
	vec4 w = m * vec4(p, 1.0);
	vec3 so = sway_o.xyz;
	float sh = sway_o.w;
	if (inst.y >= 0.0) {
		int q = int(inst.y) + gl_InstanceIndex;
		int k = (int(inst.x) + int(inst_ids[q >> 2][q & 3])) * 4;
		mat4 im = mat4(inst_cols[k], inst_cols[k + 1], inst_cols[k + 2], inst_cols[k + 3]);
		im[0].w = 0.0; im[1].w = 0.0; im[2].w = 0.0;
		w = im * w;
		if (inst.z > 0.0) {
			so = im[3].xyz;
			sh = inst.w * length(im[1].xyz);
		}
	}
	if (inst.z > 0.0) w = vec4(bend(w.xyz, so, sh, inst.z), 1.0);
	if (water.w > 0.5) w.y += sea_wave(w.xz, water_t.x, water.xyz).z;
	out_uv = vec4(in_uv0, in_uv1);
	out_col = in_col;
	gl_Position = view_proj * w;
}
