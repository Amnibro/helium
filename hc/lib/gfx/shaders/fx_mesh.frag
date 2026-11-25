layout(location = 0) in vec3 in_nrm;
layout(location = 1) in vec4 in_rgba;
layout(set = 3, binding = 0) uniform Lit { vec4 to_sun; vec4 sun; vec4 ambient; };
layout(location = 0) out vec4 out_rgba;
void main() {
	out_rgba = vec4(in_rgba.rgb * (ambient.rgb + sun.rgb * (max(dot(normalize(in_nrm), to_sun.xyz), 0.0) * 0.3183099)), 1.0);
}
