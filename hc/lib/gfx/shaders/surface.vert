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

void main() {
	vec3 p = in_pos;
	vec3 n = in_nrm;
	int targets = int(deform.z);
	if (targets > 0) {
		int local_v = gl_VertexIndex - int(deform.w);
		int count = int(misc.x);
		for (int t = 0; t < targets && t < 64; t++) {
			float w = morph_weight(t);
			if (w == 0.0) continue;
			int e = (int(deform.y) + t * count + local_v) * 2;
			p += morph_data[e].xyz * w;
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
	vec4 w = m * vec4(p, 1.0);
	out_world = w.xyz;
	out_nrm = wn;
	out_tan = vec4((m * vec4(in_tan.xyz, 0.0)).xyz, in_tan.w);
	out_uv = vec4(in_uv0, in_uv1);
	out_col = in_col;
	out_cur = cur_vp * w;
	out_prev = prev_vp * (pm * vec4(p, 1.0));
	gl_Position = view_proj * w;
}
