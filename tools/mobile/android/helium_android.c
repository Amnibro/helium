#include <android/log.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
static int he_pfd[2];
static void *he_pump(void *a) {
	char buf[1024], line[2048];
	size_t l = 0;
	ssize_t n;
	(void)a;
	while ((n = read(he_pfd[0], buf, sizeof buf)) > 0)
		for (ssize_t i = 0; i < n; i++)
			if (buf[i] == '\n' || l == sizeof line - 1) { line[l] = 0; __android_log_write(ANDROID_LOG_INFO, "helium", line); l = 0; }
			else line[l++] = buf[i];
	return 0;
}
__attribute__((constructor)) static void he_log_init(void) {
	pthread_t t;
	setvbuf(stdout, 0, _IOLBF, 0);
	setvbuf(stderr, 0, _IONBF, 0);
	if (pipe(he_pfd) != 0) return;
	dup2(he_pfd[1], 1);
	dup2(he_pfd[1], 2);
	if (pthread_create(&t, 0, he_pump, 0) == 0) pthread_detach(t);
}
