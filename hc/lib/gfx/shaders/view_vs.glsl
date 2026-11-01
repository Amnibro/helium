layout(set = 1, binding = 0) uniform View { mat4 clip_from_world; mat4 world_from_view; mat4 view_from_world; mat4 clip_from_view; mat4 view_from_clip; vec3 view_world_position; float view_exposure; vec4 viewport; };
layout(set = 1, binding = 1) uniform Draw { ivec4 info; vec4 mw[16]; };
