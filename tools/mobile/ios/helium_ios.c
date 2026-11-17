#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
extern int SDL_main(int argc, char **argv);
extern int SDL_RunApp(int argc, char **argv, int (*fn)(int, char **), void *reserved);
int main(int argc, char **argv) {
	char p[1024], d[1024];
	const char *h = getenv("HOME"), *s = argc > 0 ? strrchr(argv[0], '/') : 0;
	if (s && s - argv[0] < 1000) { snprintf(p, sizeof p, "%.*s/assets", (int)(s - argv[0]), argv[0]); setenv("HELIUM_ASSETS", p, 0); }
	if (h) { snprintf(d, sizeof d, "%s/Library/Application Support", h); mkdir(d, 0755); setenv("HELIUM_DATA", d, 0); }
	return SDL_RunApp(argc, argv, SDL_main, NULL);
}
