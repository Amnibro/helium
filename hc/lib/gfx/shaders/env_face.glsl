vec3 face_dir(int f, vec2 c) {
	if (f == 0) return vec3(1.0, -c.y, -c.x);
	if (f == 1) return vec3(-1.0, -c.y, c.x);
	if (f == 2) return vec3(c.x, 1.0, c.y);
	if (f == 3) return vec3(c.x, -1.0, -c.y);
	if (f == 4) return vec3(c.x, -c.y, 1.0);
	return vec3(-c.x, -c.y, -1.0);
}
