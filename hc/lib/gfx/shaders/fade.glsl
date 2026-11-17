#ifndef FADE_GLSL
#define FADE_GLSL 1
float imp_dither(vec2 p) { return fract(52.9829189 * fract(dot(p, vec2(0.06711056, 0.00583715)))); }
#endif
