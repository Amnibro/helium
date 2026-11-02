// Temporal resolve: accumulates jittered frames into a history image at the
// output resolution. With equal input and output sizes this is temporal
// anti-aliasing; with a larger output it is a temporal upscaler, because every
// frame's jitter puts the input samples at different places inside the output
// pixels.
//
// Per output pixel:
//  1. the input sample nearest to the pixel centre (input sample k sits at
//     k + 0.5 + jitter, in input pixels) and how far away it is, in output pixels
//  2. the 3x3 input neighbourhood around it: mean and standard deviation in
//     YCoCg, plus its min/max box
//  3. the motion of the nearest surface in that neighbourhood (smallest view
//     depth), so edges of moving objects carry the object's motion
//  4. last frame's result at uv - motion, read with a 4x4 Catmull-Rom filter;
//     history from outside the screen, or after a reset, is dropped
//  4b. depth rejection: the history alpha holds the view depth of the surface each
//     history pixel showed. If the history at this pixel's own previous position
//     (uv - its own motion) shows a surface nearer than this pixel's surface was
//     last frame (motion.w) by more than reject.x of its depth, and no pixel of the
//     3x3 neighbourhood has a surface at that depth now, this pixel was hidden last
//     frame (a disocclusion): the history is dropped as in 4. Checking the
//     neighbourhood keeps still silhouettes, where the jittered sample flips between
//     the two surfaces, from being rejected every other frame.
//  5. history is clipped to the box B = [max(min, mean - gamma * sigma),
//     min(max, mean + gamma * sigma)]: it is moved along the line toward the centre
//     of B (not the mean; the two differ where min/max cuts the sigma box) until it
//     lies inside B, which removes colours that are no longer present around the
//     pixel (ghosts after disocclusion or lighting changes)
//  6. blend: the current sample's weight falls off with its distance from the
//     pixel centre and rises with motion; colours are range-compressed
//     (c / (1 + max(c))) while filtering so single bright samples do not flicker
layout(location = 0) in vec2 in_uv;
layout(set = 2, binding = 0) uniform sampler2D tex_cur;      // this frame, input size, linear HDR
layout(set = 2, binding = 1) uniform sampler2D tex_hist;     // last result, output size
layout(set = 2, binding = 2) uniform sampler2D tex_motion;   // input size: uv motion, view depth, coverage
layout(set = 3, binding = 0) uniform Temporal {
	vec4 in_size;    // w, h, 1/w, 1/h of the input
	vec4 out_size;   // w, h, 1/w, 1/h of the output
	vec4 jitter;     // xy: this frame's sample offset in input pixels (y down); z: 1 = no history; w: base blend
	vec4 tune;       // x: clip gamma (0 = no clamp), y: blend added per output pixel of motion, z: max blend, w: sample footprint (output px)
	vec4 reject;     // x: depth rejection tolerance (0 = off), y: motion scale (1; 0 is a test control)
};
layout(location = 0) out vec4 out_rgba;

vec3 compress(vec3 c) { return c / (1.0 + max(c.r, max(c.g, c.b))); }
vec3 expand(vec3 c) { return c / max(1.0 - max(c.r, max(c.g, c.b)), 1e-4); }
vec3 to_ycocg(vec3 c) { return vec3(0.25 * c.r + 0.5 * c.g + 0.25 * c.b, 0.5 * c.r - 0.5 * c.b, -0.25 * c.r + 0.5 * c.g - 0.25 * c.b); }
vec3 from_ycocg(vec3 c) { return vec3(c.x + c.y - c.z, c.x + c.z, c.x - c.y - c.z); }

vec3 fetch_cur(ivec2 p) {
	ivec2 hi = ivec2(in_size.xy) - 1;
	return max(texelFetch(tex_cur, clamp(p, ivec2(0), hi), 0).rgb, vec3(0.0));
}

// Catmull-Rom weights for the four taps around a sample at fraction t.
vec4 catmull_rom(float t) {
	float t2 = t * t;
	float t3 = t2 * t;
	return vec4(-0.5 * t3 + t2 - 0.5 * t, 1.5 * t3 - 2.5 * t2 + 1.0, -1.5 * t3 + 2.0 * t2 + 0.5 * t, 0.5 * t3 - 0.5 * t2);
}

vec3 history_at(vec2 uv) {
	vec2 p = uv * out_size.xy - 0.5;
	vec2 f = floor(p);
	vec2 t = p - f;
	vec4 wx = catmull_rom(t.x);
	vec4 wy = catmull_rom(t.y);
	ivec2 base = ivec2(f) - 1;
	ivec2 hi = ivec2(out_size.xy) - 1;
	vec3 sum = vec3(0.0);
	for (int j = 0; j < 4; j++) {
		vec3 row = vec3(0.0);
		for (int i = 0; i < 4; i++) {
			row += texelFetch(tex_hist, clamp(base + ivec2(i, j), ivec2(0), hi), 0).rgb * wx[i];
		}
		sum += row * wy[j];
	}
	return max(sum, vec3(0.0));
}

// Moves h toward the centre c until it lies inside the box c +/- e.
vec3 clip_to_box(vec3 h, vec3 c, vec3 e) {
	vec3 d = h - c;
	vec3 a = abs(d) / max(e, vec3(1e-5));
	float m = max(a.x, max(a.y, a.z));
	return m > 1.0 ? c + d / m : h;
}

void main() {
	vec2 ip = in_uv * in_size.xy;                     // continuous input-pixel position
	ivec2 k = ivec2(floor(ip - jitter.xy));            // input sample nearest to this pixel centre
	vec2 off = (ip - (vec2(k) + 0.5 + jitter.xy)) * (out_size.x * in_size.z);

	vec3 m1 = vec3(0.0);
	vec3 m2 = vec3(0.0);
	vec3 lo = vec3(1e9);
	vec3 hi = vec3(-1e9);
	vec3 centre = vec3(0.0);
	float near_z = 1e9;
	ivec2 near_p = k;
	float was_z[9];                                    // last-frame depth of each neighbour's surface
	ivec2 top = ivec2(in_size.xy) - 1;
	for (int j = -1; j <= 1; j++) {
		for (int i = -1; i <= 1; i++) {
			ivec2 p = k + ivec2(i, j);
			vec3 c = to_ycocg(compress(fetch_cur(p)));
			if (i == 0 && j == 0) centre = c;
			m1 += c;
			m2 += c * c;
			lo = min(lo, c);
			hi = max(hi, c);
			vec4 mv = texelFetch(tex_motion, clamp(p, ivec2(0), top), 0);
			was_z[(j + 1) * 3 + i + 1] = mv.w;
			if (mv.z < near_z) { near_z = mv.z; near_p = p; }
		}
	}
	m1 /= 9.0;
	vec3 sigma = sqrt(max(m2 / 9.0 - m1 * m1, vec3(0.0)));
	vec2 motion = texelFetch(tex_motion, clamp(near_p, ivec2(0), top), 0).xy * reject.y;
	vec4 own = texelFetch(tex_motion, clamp(k, ivec2(0), top), 0);

	// current colour at this pixel: the nearest sample, or a bilinear read when
	// there is no history to refine it (so an upscaled first frame is not blocky)
	vec3 cur = centre;
	vec2 prev_uv = in_uv - motion;
	bool fresh = jitter.z > 0.5 || any(lessThan(prev_uv, vec2(0.0))) || any(greaterThan(prev_uv, vec2(1.0)));
	if (!fresh && reject.x > 0.0) {
		ivec2 hp = clamp(ivec2((in_uv - own.xy * reject.y) * out_size.xy), ivec2(0), ivec2(out_size.xy) - 1);
		float hz = texelFetch(tex_hist, hp, 0).a;
		if (hz < own.w * (1.0 - reject.x)) {
			bool present = false;
			for (int q = 0; q < 9; q++) { if (abs(was_z[q] - hz) <= reject.x * hz) present = true; }
			fresh = !present;
		}
	}
	if (fresh) {
		vec3 b = texture(tex_cur, in_uv - jitter.xy * in_size.zw).rgb;
		out_rgba = vec4(max(b, vec3(0.0)), own.z);
		return;
	}

	vec3 hist = to_ycocg(compress(history_at(prev_uv)));
	if (tune.x > 0.0) {
		vec3 box_lo = max(lo, m1 - tune.x * sigma);
		vec3 box_hi = min(hi, m1 + tune.x * sigma);
		hist = clip_to_box(hist, 0.5 * (box_lo + box_hi), max(0.5 * (box_hi - box_lo), vec3(1e-4)));
	}

	float moved = length(motion * out_size.xy);
	float near = exp(-dot(off, off) / (2.0 * tune.w * tune.w));   // how well the sample covers this pixel
	float a = min(jitter.w + tune.y * moved, tune.z) * near;
	vec3 o = mix(hist, cur, clamp(a, 0.0, 1.0));
	// alpha: the view depth of the surface this pixel shows, for step 4b next frame
	// (the blend does not touch it; post and bloom read rgb only)
	out_rgba = vec4(expand(from_ycocg(o)), own.z);
}
