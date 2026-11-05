layout(location = 0) in vec3 a_pos;
layout(location = 1) in ivec2 a_id;
layout(location = 2) in uvec4 a_u;
layout(set = 0, binding = 0) uniform sampler2D disp;
layout(std430, set = 0, binding = 1) readonly buffer Bones { vec4 bones[]; };
layout(set = 1, binding = 0) uniform View { mat4 vp; vec4 p; };
layout(location = 0) out vec4 v_a;
layout(location = 1) flat out int v_i;
layout(location = 2) flat out uint v_u;
void main() {
	vec4 d = texture(disp, a_pos.xy) + textureLod(disp, a_pos.xy, 0.0) + textureGrad(disp, a_pos.xy, vec2(0.0), vec2(0.0));
	v_a = vp * vec4(a_pos + d.xyz + bones[gl_VertexIndex % 4].xyz, 1.0) + p;
	v_i = a_id.x + gl_InstanceIndex;
	v_u = a_u.w;
	gl_Position = v_a;
}
