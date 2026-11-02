#version 450
// uv.x < 0: flat colour; uv.x >= 2: outline (wider threshold); else glyph fill.
// The edge is antialiased over one screen pixel with fwidth, so text stays
// crisp from small HUD sizes to large titles.
layout(location = 0) in vec4 v_col;
layout(location = 1) in vec2 v_uv;
layout(set = 2, binding = 0) uniform sampler2D sdf_atlas;
layout(location = 0) out vec4 result;
void main() {
	if (v_uv.x < 0.0) { result = v_col; return; }
	bool outline = v_uv.x >= 2.0;
	vec2 uv = outline ? vec2(v_uv.x - 2.0, v_uv.y) : v_uv;
	float d = texture(sdf_atlas, uv).r;
	float w = clamp(fwidth(d) * 0.75, 0.001, 0.2);
	float edge = outline ? 0.35 : 0.5;
	result = vec4(v_col.rgb, v_col.a * smoothstep(edge - w, edge + w, d));
}
