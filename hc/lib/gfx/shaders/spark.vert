// Camera-facing quads, six vertices per particle, read straight from the
// simulation buffer. Dead particles collapse outside the clip volume.
struct Spark { vec4 pos_life; vec4 vel_span; vec4 rgba; vec4 size; };
layout(std430, set = 0, binding = 0) readonly buffer Sparks { Spark sparks[]; };
layout(set = 1, binding = 0) uniform View { mat4 view_proj; vec4 right; vec4 up; };
layout(location = 0) out vec2 out_corner;
layout(location = 1) out vec4 out_rgba;
void main() {
	int i = gl_VertexIndex / 6;
	int k = gl_VertexIndex % 6;
	Spark s = sparks[i];
	if (s.pos_life.w <= 0.0) { gl_Position = vec4(2.0, 2.0, 2.0, 1.0); out_corner = vec2(0.0); out_rgba = vec4(0.0); return; }
	vec2 corners[6] = vec2[6](vec2(-1, -1), vec2(1, -1), vec2(1, 1), vec2(-1, -1), vec2(1, 1), vec2(-1, 1));
	vec2 c = corners[k];
	float age = clamp(s.pos_life.w / max(s.vel_span.w, 1e-4), 0.0, 1.0);
	float r = mix(s.size.y, s.size.x, age);
	vec3 p = s.pos_life.xyz + (right.xyz * c.x + up.xyz * c.y) * r;
	out_corner = c;
	out_rgba = vec4(s.rgba.rgb, s.rgba.a * age);
	gl_Position = view_proj * vec4(p, 1.0);
}
