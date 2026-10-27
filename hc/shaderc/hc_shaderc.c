#include "shaderc.c"
int main(int argc, char **argv) {
    if (argc != 5) { fputs("usage: hc-shaderc stage path source.glsl out.blob\n", stderr); return 2; }
    char *src = shaderc_read(argv[3]);
    if (!src) { fprintf(stderr, "%s: cannot read the shader source\n", argv[2]); return 1; }
    gs_shaderc_result r = gs_shaderc_compile(src, argv[2], atoi(argv[1]));
    free(src);
    if (!r.blob) { fputs(r.error ? r.error : "shader compilation failed", stderr); gs_shaderc_free(&r); return 1; }
    FILE *o = fopen(argv[4], "wb");
    int ok = o && fwrite(r.blob, 1, r.size, o) == r.size;
    if (o) fclose(o);
    gs_shaderc_free(&r);
    return ok ? 0 : 1;
}
