# TinyCC

The sources of the Tiny C Compiler that `cmake/libtcc.cmake` builds into the
compiler as its in-process C backend (`docs/design/jit_backend.md`), copied
unmodified from [TinyCC/tinycc](https://github.com/TinyCC/tinycc) at commit
`0fb54300b56512754221d80adda85ddb9815bceb` (2026-09-04, `release_0_9_26-2610`):
the `.c`, `.h` and `.def` files of the repository root, `include/`, `lib/`,
`win32/include/` and `win32/lib/`, with `VERSION`, `COPYING`, `RELICENSING`
and upstream's `README`. Its tests, examples, documentation and build scripts
are left out; the CMake file replaces its configure and makefile.

The backend is not optional: every Goose compiler is built with it.

License: LGPL 2.1 (`COPYING`), with the relicensing notes in `RELICENSING`.

To update, copy the same files from a newer TinyCC commit and record that
commit here.
