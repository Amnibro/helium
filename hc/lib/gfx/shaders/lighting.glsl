// Shared shading math for the surface shaders.
// Microfacet specular: Cook-Torrance with the GGX / Trowbridge-Reitz normal
// distribution, the Smith height-uncorrelated masking term using the
// Schlick-GGX approximation per direction, and Schlick's Fresnel.

const float PI_F = 3.14159265;

float ggx_d(float n_h, float alpha) {
	float a2 = alpha * alpha;
	float t = n_h * n_h * (a2 - 1.0) + 1.0;
	return a2 / (PI_F * t * t);
}

float schlick_g1(float n_x, float k) {
	return n_x / (n_x * (1.0 - k) + k);
}

float smith_g(float n_l, float n_v, float rough) {
	// k = alpha / 2 with alpha = rough^2 (the image-based variant of the remap)
	float k = rough * rough * 0.5;
	return schlick_g1(n_l, k) * schlick_g1(n_v, k);
}

vec3 schlick_f(vec3 f0, float cos_t) {
	float m = 1.0 - cos_t;
	float m2 = m * m;
	return f0 + (1.0 - f0) * (m2 * m2 * m);
}

// Radiance reflected toward v from a light arriving along l with irradiance e.
// ms scales the specular lobe to put back the energy that single scattering loses
// (see ms_factor in surface.frag); vec3(1.0) is the plain single-scatter model.
// kd weights the Lambertian lobe by the energy the specular lobe leaves for it, per view
// direction (diffuse_weight in surface.frag); a negative kd selects the per-light
// 1 - F(v.h) weight instead, which is kept only as a furnace-test control.
vec3 light_term(vec3 n, vec3 v, vec3 l, vec3 e, vec3 albedo, vec3 f0, float rough, vec3 ms, vec3 kd) {
	float n_l = max(dot(n, l), 0.0);
	if (n_l <= 0.0) return vec3(0.0);
	vec3 h = normalize(v + l);
	float n_v = max(dot(n, v), 1e-4);
	float n_h = max(dot(n, h), 0.0);
	float alpha = max(rough * rough, 0.002);
	vec3 f = schlick_f(f0, max(dot(h, v), 0.0));
	vec3 spec = ms * f * (ggx_d(n_h, alpha) * smith_g(n_l, n_v, rough) / (4.0 * n_l * n_v + 1e-4));
	vec3 diff = (kd.x < 0.0 ? 1.0 - f : kd) * albedo / PI_F;
	return (diff + spec) * e * n_l;
}

// Smooth falloff that reaches zero at the light's range: an inverse-square core
// shaped by a (1 - (d/range)^2)^2 window.
float range_falloff(float d, float range) {
	float q = clamp(1.0 - (d * d) / (range * range), 0.0, 1.0);
	return q * q / (1.0 + d * d);
}

// Analytic sky: a zenith/horizon gradient, a darker ground, and a glow around the sun.
vec3 sky_color(vec3 dir, vec3 to_sun, vec3 zenith, vec3 horizon, vec3 ground, vec3 sun_rgb) {
	float y = dir.y;
	vec3 c = y >= 0.0 ? mix(horizon, zenith, pow(clamp(y, 0.0, 1.0), 0.6)) : mix(horizon, ground, clamp(-y * 3.0, 0.0, 1.0));
	float s = max(dot(dir, to_sun), 0.0);
	c += sun_rgb * (0.04 * pow(s, 8.0) + 0.25 * pow(s, 64.0));
	return c;
}
