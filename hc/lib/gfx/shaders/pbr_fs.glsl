#define PI 3.141592653589793
layout(set = 3, binding = 0) uniform View { mat4 clip_from_world; mat4 world_from_view; mat4 view_from_world; mat4 clip_from_view; mat4 view_from_clip; vec3 view_world_position; float view_exposure; vec4 viewport; };
layout(set = 3, binding = 1) uniform Frame { vec3 sun_dir; uint sun_flags; vec4 sun_color; vec4 ambient_color; mat4 cascade_from_world[4]; vec4 cascade_far; vec4 cascade_texel; vec4 shadow_cfg; vec4 env_cfg; vec4 env_rotation; vec4 fog_base_color; vec4 fog_dl_color; vec3 fog_be; float fog_dl_exponent; vec3 fog_bi; uint fog_mode; float g_time; float g_delta; float g_frame; float g_pad; vec4 pl_info; vec4 pl_pos[12]; vec4 pl_col[12]; };
layout(set = 3, binding = 2) uniform Material { vec4 m_base_color; vec4 m_emissive; vec4 m_uv0; vec4 m_uv1; float m_roughness; float m_metallic; float m_reflectance; float m_alpha_cutoff; uint m_flags; uint m_p0; uint m_p1; uint m_p2; };
layout(set = 2, binding = 0) uniform sampler2DShadow shadow_map0;
layout(set = 2, binding = 1) uniform sampler2DShadow shadow_map1;
layout(set = 2, binding = 2) uniform samplerCube env_diffuse;
layout(set = 2, binding = 3) uniform samplerCube env_specular;
layout(set = 2, binding = 4) uniform sampler2D base_color_texture;
layout(location = 0) in vec4 in_world_position;
layout(location = 1) in vec3 in_world_normal;
layout(location = 2) in vec2 in_uv;
layout(location = 3) in vec2 in_uv_b;
layout(location = 4) in vec4 in_world_tangent;
layout(location = 5) in vec4 in_color;
layout(location = 6) flat in uint in_flags;
layout(location = 0) out vec4 out_color;
#define SM_BASE_TEX 1u
#define SM_DOUBLE 16u
#define SM_UNLIT 32u
#define SM_FOG 256u
#define SM_ALPHA_BITS 3758096384u
#define SM_ALPHA_OPAQUE 0u
#define SM_ALPHA_MASK 536870912u
#define SM_ALPHA_BLEND 1073741824u
#define SM_ALPHA_PREMUL 1610612736u
#define SM_ALPHA_ADD 2147483648u
#define SM_ALPHA_MULTIPLY 2684354560u
struct PbrMaterial { vec4 base_color; vec4 emissive; float perceptual_roughness; float metallic; float reflectance; uint flags; float alpha_cutoff; };
struct PbrInput { PbrMaterial material; vec3 diffuse_occlusion; float specular_occlusion; vec4 frag_coord; vec4 world_position; vec3 world_normal; vec3 N; vec3 V; uint flags; };
float saturate(float x) { return clamp(x, 0.0, 1.0); }
vec3 saturate(vec3 x) { return clamp(x, vec3(0.0), vec3(1.0)); }
PbrInput pbr_input_from_standard_material(bool is_front) {
	PbrInput p;
	uint flags = m_flags;
	vec2 uv = vec2(dot(m_uv0.xy, vec2(in_uv.x, 0.0)) + m_uv0.z * in_uv.y + m_uv1.x, m_uv0.y * in_uv.x + m_uv0.w * in_uv.y + m_uv1.y);
	p.material.flags = flags;
	p.material.alpha_cutoff = m_alpha_cutoff;
	p.material.reflectance = m_reflectance;
	p.frag_coord = gl_FragCoord;
	p.world_position = in_world_position;
	p.flags = in_flags;
	vec4 base = m_base_color * in_color;
	if ((flags & SM_BASE_TEX) != 0u) { base *= texture(base_color_texture, uv); }
	p.material.base_color = base;
	p.material.emissive = m_emissive;
	p.material.metallic = m_metallic;
	p.material.perceptual_roughness = m_roughness;
	p.diffuse_occlusion = vec3(1.0);
	p.specular_occlusion = 1.0;
	vec3 n = normalize(in_world_normal);
	if ((flags & SM_DOUBLE) != 0u && !is_front) { n = -n; }
	p.world_normal = n;
	p.N = n;
	p.V = normalize(view_world_position - in_world_position.xyz);
	return p;
}
vec4 alpha_discard(uint flags, float cutoff, vec4 color) {
	vec4 c = color;
	uint mode = flags & SM_ALPHA_BITS;
	if (mode == SM_ALPHA_OPAQUE) { c.a = 1.0; }
	else if (mode == SM_ALPHA_MASK) { if (c.a >= cutoff) { c.a = 1.0; } else { discard; } }
	return c;
}
float perceptualRoughnessToRoughness(float pr) { float c = clamp(pr, 0.089, 1.0); return c * c; }
float D_GGX(float roughness, float NdotH) { float o = 1.0 - NdotH * NdotH; float a = NdotH * roughness; float k = roughness / (o + a * a); return k * k * (1.0 / PI); }
float V_SmithGGXCorrelated(float roughness, float NdotV, float NdotL) { float a2 = roughness * roughness; float lv = NdotL * sqrt((NdotV - a2 * NdotV) * NdotV + a2); float ll = NdotV * sqrt((NdotL - a2 * NdotL) * NdotL + a2); return 0.5 / (lv + ll); }
vec3 F_Schlick_vec(vec3 f0, float f90, float VdotH) { return f0 + (f90 - f0) * pow(1.0 - VdotH, 5.0); }
float F_Schlick(float f0, float f90, float VdotH) { return f0 + (f90 - f0) * pow(1.0 - VdotH, 5.0); }
vec3 fresnel(vec3 f0, float LdotH) { float f90 = saturate(dot(f0, vec3(50.0 * 0.33))); return F_Schlick_vec(f0, f90, LdotH); }
vec2 F_AB(float pr, float NdotV) {
	vec4 c0 = vec4(-1.0, -0.0275, -0.572, 0.022);
	vec4 c1 = vec4(1.0, 0.0425, 1.04, -0.04);
	vec4 r = pr * c0 + c1;
	float a004 = min(r.x * r.x, exp2(-9.28 * NdotV)) * r.x + r.y;
	return max(vec2(-1.04, 1.04) * a004 + r.zw, vec2(0.00005));
}
vec3 EnvBRDFApprox(vec3 F0, vec2 F_ab) { return F0 * F_ab.x + F_ab.y; }
vec3 quat_rotate(vec4 q, vec3 v) { vec3 t = 2.0 * cross(q.xyz, v); return v + q.w * t + cross(q.xyz, t); }
float castano13(vec2 light_local, float depth, int layer) {
	vec2 size = vec2(textureSize(shadow_map0, 0).xy);
	vec2 inv = 1.0 / size;
	vec2 uv = light_local * size;
	vec2 base = floor(uv + 0.5);
	float s = uv.x + 0.5 - base.x;
	float t = uv.y + 0.5 - base.y;
	base = (base - 0.5) * inv;
	vec3 uw = vec3(4.0 - 3.0 * s, 7.0, 1.0 + 3.0 * s);
	vec3 u = vec3((3.0 - 2.0 * s) / uw.x - 2.0, (3.0 + s) / uw.y, s / uw.z + 2.0);
	vec3 vw = vec3(4.0 - 3.0 * t, 7.0, 1.0 + 3.0 * t);
	vec3 v = vec3((3.0 - 2.0 * t) / vw.x - 2.0, (3.0 + t) / vw.y, t / vw.z + 2.0);
	float sum = 0.0;
	for (int j = 0; j < 3; j++) { for (int k = 0; k < 3; k++) { vec3 q = vec3(base + vec2(u[k], v[j]) * inv, depth); sum += uw[k] * vw[j] * (layer == 0 ? texture(shadow_map0, q) : texture(shadow_map1, q)); } }
	return sum * (1.0 / 144.0);
}
float sample_cascade(int i, vec4 world_position, vec3 normal) {
	vec3 normal_offset = shadow_cfg.y * cascade_texel[i] * normal;
	vec3 depth_offset = shadow_cfg.x * sun_dir;
	vec4 p = cascade_from_world[i] * vec4(world_position.xyz + normal_offset + depth_offset, 1.0);
	vec3 ndc = p.xyz / p.w;
	vec2 uv = ndc.xy * vec2(0.5, -0.5) + vec2(0.5);
	if (any(lessThan(uv, vec2(0.0))) || any(greaterThan(uv, vec2(1.0))) || ndc.z > 1.0) { return 1.0; }
	return castano13(uv, ndc.z, i);
}
float fetch_directional_shadow(vec4 world_position, vec3 normal, float view_z) {
	int n = int(cascade_far.w);
	float d = -view_z;
	for (int i = 0; i < n; i++) {
		float far = cascade_far[i];
		if (d < far) {
			float s = sample_cascade(i, world_position, normal);
			float blend_start = far * (1.0 - shadow_cfg.w);
			if (i + 1 < n && d > blend_start) { s = mix(s, sample_cascade(i + 1, world_position, normal), (d - blend_start) / (far - blend_start)); }
			else if (i + 1 == n && d > blend_start) { s = mix(s, 1.0, (d - blend_start) / (far - blend_start)); }
			return s;
		}
	}
	return 1.0;
}
vec4 apply_pbr_lighting(PbrInput pin) {
	vec4 output_color = pin.material.base_color;
	vec4 emissive = pin.material.emissive;
	float metallic = pin.material.metallic;
	float pr = pin.material.perceptual_roughness;
	float roughness = perceptualRoughnessToRoughness(pr);
	float NdotV = max(dot(pin.N, pin.V), 0.0001);
	vec3 R = reflect(-pin.V, pin.N);
	vec3 diffuse_color = output_color.rgb * (1.0 - metallic);
	vec3 F0 = 0.16 * pin.material.reflectance * pin.material.reflectance * (1.0 - metallic) + output_color.rgb * metallic;
	vec3 F0_dielectric = vec3(0.16 * pin.material.reflectance * pin.material.reflectance);
	vec2 F_ab = F_AB(pr, NdotV);
	vec3 direct_light = vec3(0.0);
	float view_z = dot(vec4(view_from_world[0].z, view_from_world[1].z, view_from_world[2].z, view_from_world[3].z), pin.world_position);
	if (sun_color.a > 0.0) {
		float shadow = 1.0;
		if ((pin.flags & 1u) != 0u && (sun_flags & 1u) != 0u) { shadow = fetch_directional_shadow(pin.world_position, pin.world_normal, view_z); }
		vec3 L = sun_dir;
		vec3 H = normalize(L + pin.V);
		float NdotL = saturate(dot(pin.N, L));
		float NdotH = saturate(dot(pin.N, H));
		float LdotH = saturate(dot(L, H));
		float f90 = 0.5 + 2.0 * roughness * LdotH * LdotH;
		vec3 diffuse = diffuse_color * F_Schlick(1.0, f90, NdotL) * F_Schlick(1.0, f90, NdotV) * (1.0 / PI);
		vec3 F0m = mix(F0_dielectric, output_color.rgb, metallic);
		vec3 spec = (D_GGX(roughness, NdotH) * V_SmithGGXCorrelated(roughness, NdotV, NdotL)) * fresnel(F0m, LdotH);
		spec = spec * (1.0 + F0m * (1.0 / (F_ab.x + F_ab.y) - 1.0));
		direct_light = (diffuse + spec) * NdotL * sun_color.rgb * shadow;
	}
	int npl = int(pl_info.x);
	for (int li = 0; li < npl; li++) {
		vec3 dl = pl_pos[li].xyz - pin.world_position.xyz;
		float d2 = max(dot(dl, dl), 0.0001);
		float rr = pl_pos[li].w;
		float win = saturate(1.0 - (d2 * d2) / (rr * rr * rr * rr));
		float att = win * win / d2;
		if (att <= 0.0) { continue; }
		vec3 L = dl * inversesqrt(d2);
		vec3 H = normalize(L + pin.V);
		float NdotL = saturate(dot(pin.N, L));
		float NdotH = saturate(dot(pin.N, H));
		float LdotH = saturate(dot(L, H));
		float f90 = 0.5 + 2.0 * roughness * LdotH * LdotH;
		vec3 diffuse = diffuse_color * F_Schlick(1.0, f90, NdotL) * F_Schlick(1.0, f90, NdotV) * (1.0 / PI);
		vec3 F0m = mix(F0_dielectric, output_color.rgb, metallic);
		vec3 spec = (D_GGX(roughness, NdotH) * V_SmithGGXCorrelated(roughness, NdotV, NdotL)) * fresnel(F0m, LdotH);
		direct_light += (diffuse + spec) * NdotL * pl_col[li].rgb * att;
	}
	vec3 indirect_light = vec3(0.0);
	if (env_cfg.z > 0.5) {
		float intensity = env_cfg.x;
		vec3 idir = quat_rotate(env_rotation, pin.N);
		idir.z = -idir.z;
		vec3 irradiance = textureLod(env_diffuse, idir, 0.0).rgb * intensity;
		float smoothness = saturate(1.0 - roughness);
		vec3 rdir = mix(pin.N, R, smoothness * (sqrt(smoothness) + roughness));
		rdir = quat_rotate(env_rotation, rdir);
		rdir.z = -rdir.z;
		vec3 radiance = textureLod(env_specular, rdir, pr * env_cfg.y).rgb * intensity;
		vec3 F0_surface = mix(F0_dielectric, output_color.rgb, metallic);
		float spec_occ = saturate(dot(F0_surface, vec3(50.0 * 0.33)));
		float Ems = 1.0 - (F_ab.x + F_ab.y);
		vec3 d_FssEss = (F0_dielectric * F_ab.x + F_ab.y) * spec_occ;
		vec3 d_Favg = F0_dielectric + (1.0 - F0_dielectric) / 21.0;
		vec3 d_FmsEms = d_FssEss * d_Favg / (1.0 - Ems * d_Favg) * Ems;
		vec3 d_Edss = 1.0 - (d_FssEss + d_FmsEms);
		vec3 m_FssEss = (output_color.rgb * F_ab.x + F_ab.y) * spec_occ;
		vec3 m_Favg = output_color.rgb + (1.0 - output_color.rgb) / 21.0;
		vec3 m_FmsEms = m_FssEss * m_Favg / (1.0 - Ems * m_Favg) * Ems;
		vec3 FssEss = mix(d_FssEss, m_FssEss, metallic);
		vec3 FmsEms = mix(d_FmsEms, m_FmsEms, metallic);
		vec3 kD = diffuse_color * d_Edss;
		indirect_light += (FmsEms + kD) * irradiance * pin.diffuse_occlusion + FssEss * radiance * pin.specular_occlusion;
	}
	vec3 diffuse_ambient = EnvBRDFApprox(diffuse_color, F_AB(1.0, NdotV));
	vec3 specular_ambient = EnvBRDFApprox(F0, F_AB(pr, NdotV));
	float specular_occlusion = saturate(dot(F0, vec3(50.0 * 0.33)));
	indirect_light += (diffuse_ambient + specular_ambient * specular_occlusion) * ambient_color.rgb * pin.diffuse_occlusion;
	// Rim light (flag 1024), colour in pl_info.yzw.
	if ((pin.material.flags & 1024u) != 0u) { float rf = pow(1.0 - NdotV, 3.0); direct_light += pl_info.yzw * rf * (0.35 + 0.65 * saturate(pin.N.y + 0.6)); }
	vec3 emissive_light = emissive.rgb * output_color.a;
	emissive_light *= mix(1.0, view_exposure, emissive.a);
	return vec4(view_exposure * (direct_light + indirect_light) + emissive_light, output_color.a);
}
vec4 apply_fog(vec4 input_color, vec3 world_pos) {
	vec3 v = world_pos - view_world_position;
	float distance = length(v);
	vec3 scattering = vec3(0.0);
	if (fog_dl_color.a > 0.0) { scattering = pow(max(dot(v / distance, sun_dir), 0.0), fog_dl_exponent) * sun_color.rgb * view_exposure; }
	vec4 fc = fog_dl_color.a > 0.0 ? vec4(fog_base_color.rgb + scattering * fog_dl_color.rgb * fog_dl_color.a, fog_base_color.a) : fog_base_color;
	if (fog_mode == 1u) { fc.a *= (1.0 - clamp((fog_be.y - distance) / (fog_be.y - fog_be.x), 0.0, 1.0)); return vec4(mix(input_color.rgb, fc.rgb, fc.a), input_color.a); }
	if (fog_mode == 2u) { fc.a *= (1.0 - 1.0 / exp(distance * fog_be.x)); return vec4(mix(input_color.rgb, fc.rgb, fc.a), input_color.a); }
	if (fog_mode == 3u) { float dd = distance * fog_be.x; fc.a *= (1.0 - 1.0 / exp(dd * dd)); return vec4(mix(input_color.rgb, fc.rgb, fc.a), input_color.a); }
	if (fog_mode == 4u) { vec3 ext = 1.0 - 1.0 / exp(distance * fog_be); vec3 ins = 1.0 - 1.0 / exp(distance * fog_bi); return vec4(input_color.rgb * (1.0 - ext * fc.a) + fc.rgb * ins * fc.a, input_color.a); }
	return input_color;
}
vec4 main_pass_post_lighting_processing(PbrInput pin, vec4 input_color) {
	vec4 c = input_color;
	if ((pin.material.flags & SM_FOG) != 0u) { c = apply_fog(c, pin.world_position.xyz); }
	uint mode = pin.material.flags & SM_ALPHA_BITS;
	if (mode == SM_ALPHA_ADD) { c = vec4(c.rgb * c.a, 0.0); }
	else if (mode == SM_ALPHA_PREMUL || mode == SM_ALPHA_MULTIPLY) { c = vec4(c.rgb * c.a, c.a); }
	return c;
}
