vec3 up9(sampler2D src, vec2 uv, vec2 t) {
	vec3 c = textureLod(src, uv, 0.0).rgb * 4.0 + (textureLod(src, uv + vec2(-t.x, 0.0), 0.0).rgb + textureLod(src, uv + vec2(t.x, 0.0), 0.0).rgb + textureLod(src, uv + vec2(0.0, -t.y), 0.0).rgb + textureLod(src, uv + vec2(0.0, t.y), 0.0).rgb) * 2.0 + textureLod(src, uv + vec2(-t.x, -t.y), 0.0).rgb + textureLod(src, uv + vec2(t.x, -t.y), 0.0).rgb + textureLod(src, uv + vec2(-t.x, t.y), 0.0).rgb + textureLod(src, uv + vec2(t.x, t.y), 0.0).rgb;
	return c / 16.0;
}
