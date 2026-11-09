// Mesh vertex stage shared by every scene pass (shadow, prepass, colour).
// The vertex record is the gltf module's 26-float layout; every attribute is
// declared so all passes see the same stride.
layout(location = 0) in vec3 in_pos;
layout(location = 1) in vec3 in_nrm;
layout(location = 2) in vec2 in_uv0;
layout(location = 3) in vec2 in_uv1;
layout(location = 4) in vec4 in_tan;
layout(location = 5) in vec4 in_col;
layout(location = 6) in vec4 in_joint;
layout(location = 7) in vec4 in_weight;

layout(std430, set = 0, binding = 0) readonly buffer Joints { vec4 joint_cols[]; };   // four columns per matrix
layout(std430, set = 0, binding = 1) readonly buffer Morphs { vec4 morph_data[]; };
layout(std430, set = 0, binding = 2) readonly buffer Insts { vec4 inst_cols[]; };
layout(std430, set = 0, binding = 3) readonly buffer InstIds { vec4 inst_ids[]; };

layout(set = 1, binding = 0) uniform Draw {
	mat4 model;
	mat4 model_normal;
	mat4 view_proj;
	mat4 prev_model;     // last frame's model matrix (velocity)
	vec4 deform;         // x joint base (-1 none), y morph first, z targets, w first vertex
	vec4 misc;           // x vertex count, y last frame's joint base (-1: reuse this frame's)
	mat4 cur_vp;         // this frame's view-projection without the sub-pixel jitter
	mat4 prev_vp;        // last frame's view-projection without jitter
	vec4 weights[16];    // morph weights, four per vec4
	vec4 prev_weights[16];
	vec4 inst;
	vec4 sway_o;
	vec4 wind;
	vec4 wind_t;
	vec4 push[4];
	vec4 prev_push[4];
};

layout(location = 0) out vec3 out_world;
layout(location = 1) out vec3 out_nrm;
layout(location = 2) out vec4 out_tan;
layout(location = 3) out vec4 out_uv;
layout(location = 4) out vec4 out_col;
layout(location = 5) out vec4 out_cur;   // unjittered clip position, this frame
layout(location = 6) out vec4 out_prev;  // unjittered clip position, last frame

mat4 joint(int j) {
	return mat4(joint_cols[j * 4], joint_cols[j * 4 + 1], joint_cols[j * 4 + 2], joint_cols[j * 4 + 3]);
}

// linear blend of the four joint matrices the vertex is bound to
mat4 skin(int base) {
	return joint(base + int(in_joint.x)) * in_weight.x
		+ joint(base + int(in_joint.y)) * in_weight.y
		+ joint(base + int(in_joint.z)) * in_weight.z
		+ joint(base + int(in_joint.w)) * in_weight.w;
}

float morph_weight(int t) {
	return weights[t >> 2][t & 3];
}

vec3 bend(vec3 wp, vec3 o, float hw, float sw, bool prev) {
	float t = clamp((wp.y - o.y) / max(hw, 0.0001), 0.0, 1.0);
	float w = t * t;
	float time = prev ? wind_t.y : wind_t.x;
	float g = 0.6 + 0.4 * sin(time * wind.w + 0.7 * (o.x + o.z));
	vec3 q = wp + vec3(wind.x, 0.0, wind.z) * (g * w * sw * hw);
	int n = int(prev ? wind_t.w : wind_t.z);
	vec3 a = vec3(o.x, wp.y, o.z);
	for (int i = 0; i < 4; i++) {
		if (i < n) {
			vec4 c = prev ? prev_push[i] : push[i];
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
	vec3 pp = in_pos;
	vec3 n = in_nrm;
	int targets = int(deform.z);
	if (targets > 0) {
		int local_v = gl_VertexIndex - int(deform.w);
		int count = int(misc.x);
		for (int t = 0; t < targets && t < 64; t++) {
			float w = morph_weight(t);
			float pw = prev_weights[t >> 2][t & 3];
			if (w == 0.0 && pw == 0.0) continue;
			int e = (int(deform.y) + t * count + local_v) * 2;
			p += morph_data[e].xyz * w;
			pp += morph_data[e].xyz * pw;
			n += morph_data[e + 1].xyz * w;
		}
	}
	mat4 m = model;
	mat4 pm = prev_model;
	vec3 wn = (model_normal * vec4(n, 0.0)).xyz;
	if (deform.x >= 0.0) {
		mat4 s = skin(int(deform.x));
		m = s;
		pm = misc.y >= 0.0 ? skin(int(misc.y)) : s;
		// cofactor columns: the inverse transpose up to a positive scale
		vec3 c0 = s[0].xyz;
		vec3 c1 = s[1].xyz;
		vec3 c2 = s[2].xyz;
		wn = cross(c1, c2) * n.x + cross(c2, c0) * n.y + cross(c0, c1) * n.z;
	}
	vec3 so = sway_o.xyz;
	float sh = sway_o.w;
	if (inst.y >= 0.0) {
		int q = int(inst.y) + gl_InstanceIndex;
		int k = (int(inst.x) + int(inst_ids[q >> 2][q & 3])) * 4;
		mat4 im = mat4(inst_cols[k], inst_cols[k + 1], inst_cols[k + 2], inst_cols[k + 3]);
		m = im * model;
		pm = im * prev_model;
		vec3 i0 = m[0].xyz;
		vec3 i1 = m[1].xyz;
		vec3 i2 = m[2].xyz;
		wn = cross(i1, i2) * n.x + cross(i2, i0) * n.y + cross(i0, i1) * n.z;
		so = im[3].xyz;
		sh = inst.w * length(im[1].xyz);
	}
	vec4 w = m * vec4(p, 1.0);
	vec4 pw = pm * vec4(pp, 1.0);
	if (inst.z > 0.0) {
		w = vec4(bend(w.xyz, so, sh, inst.z, false), 1.0);
		pw = vec4(bend(pw.xyz, so, sh, inst.z, true), 1.0);
	}
	out_world = w.xyz;
	out_nrm = wn;
	out_tan = vec4((m * vec4(in_tan.xyz, 0.0)).xyz, in_tan.w);
	out_uv = vec4(in_uv0, in_uv1);
	out_col = in_col;
	out_cur = cur_vp * w;
	out_prev = prev_vp * pw;
	gl_Position = view_proj * w;
}
