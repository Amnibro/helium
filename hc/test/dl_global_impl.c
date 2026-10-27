#include <stdint.h>
extern const char *zlibVersion(void);
int64_t dl_global_zv(void) { const char *v = zlibVersion(); return v && v[0] >= '1' ? 1 : 0; }
