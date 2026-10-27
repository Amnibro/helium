# Helium

**The lightweight, token-friendly alternative to C++, Rust, and Goose.**

Helium is a systems language tuned for code that language models read and write: no heap, no garbage collector, no lifetime annotations. Its compiler, `hc`, is written in Helium and builds itself. It writes x86-64 executables directly (its own code generator, optimizer and ELF writer, no C compiler, assembler or linker), WebAssembly for the browser and node, or C.

## Build

```bash
hc/bootstrap.sh
build/hcn run samples/01_tour.amni
```

`hc/bootstrap.sh` compiles the checked-in seed (`hc/seed/hc.c`) once with `cc` (clang by default, `CC=gcc` works too), rebuilds hc with itself until the output stops changing, and checks that the native build reproduces itself. `build/hcn` is the native self-built compiler; `build/hc` is the same compiler built through C.

## Use

| Command | What it does |
|---|---|
| `hc run file [-- args]` | compile natively into `~/.cache/hc` and run (`hc file` does the same) |
| `hc build file [-o out]` | build an executable; `-o out.c` writes C, `--web` writes `out.wasm` |
| `hc check file` | parse and typecheck only |
| `hc fetch [--update] file` | clone the git packages the program declares (`import name from "owner/repo@ref";`) |
| `hc lsp` | language server: diagnostics, hover, definition, references, rename, symbols, completion, signature help, inlay hints |

Options: `--debug` (overflow, range and tag checks naming the source line), `-DNAME=V` (runtime defines), `--offline` (fetch nothing). The library directory is `HC_LIB`, else `lib` beside the executable.

## The language

Two syntaxes with the same semantics: `.amni` (braces and `;`) and `.he` (indentation, no `;`, `x := e`, `fn` optional), which hc and its library are written in. [HELIUM.md](HELIUM.md) teaches the whole language in about 3.9k tokens; `hc/TODO.md` §0 lists what `.he` changes.

The library in `hc/lib` is Helium throughout: `std`, `os`, `math`, `json`, `regex`, `dictionary`, `csv`, `base64`, `binary`, `ffi`; `gfx` straight on SDL3's GPU API with a GLSL to SPIR-V/MSL/HLSL shader compiler inside hc; `ui` (a port of Nuklear); `physics` (a port of Box3D); `audio`; `web` and `webgl` for the browser.

## Tests

```bash
tools/hc/ci.sh
```

Bootstraps if needed, then runs the corpus in `test/` and `samples/` natively, through C and as WebAssembly (each against the pass lists in `tools/hc/baseline/`), hc's own tests in `hc/test`, the vectorizer fuzzer, the language server fixtures, the web host and git package fetching. Every one of the 645 corpus programs passes natively. CI runs on your machine; nothing uses hosted runners.

## License

Apache License 2.0. See [LICENSE](LICENSE).

## Credits

Helium began as a fork of [Goose](https://github.com/aardappel/goose) by Wouter van Oortmerssen. Its compiler, runtime and libraries are now Helium's own; the language design, the specification in `docs/` and the test corpus in `test/` derive from Goose, used under the Apache License 2.0.
