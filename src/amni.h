#pragma once
#include <fstream>
#include "amni_gpu.h"
namespace goose {
inline string LutSpirv(const string &src, const string &name, const vector<LutParam> &ps, const string &ret) {
    string why;
    auto glsl = LutGlsl(src, name, ps, ret, why);
    auto log = getenv("HELIUM_GPU_LOG");
    if (glsl.empty()) { if (log) fprintf(stderr, "lut fn %s stays on the CPU: %s\n", name.c_str(), why.c_str()); return ""; }
    auto glslc = FindOnPath("glslc");
    if (glslc.empty()) { if (log) fprintf(stderr, "lut fn %s stays on the CPU: no glslc\n", name.c_str()); return ""; }
    std::error_code ec;
    auto dir = cat(GooseHome(), "/build/lut");
    filesystem::create_directories(filesystem::path(dir), ec);
    auto base = cat(dir, "/", name, "-", Hex8(glsl));
    string spv;
    if (!LoadFile(cat(base, ".spv"), spv)) {
        { std::ofstream f(cat(base, ".comp"), std::ios::binary); f << glsl; }
        auto r = RunProcess({ glslc, "-fshader-stage=compute", "--target-env=vulkan1.1", "-O", cat(base, ".comp"), "-o", cat(base, ".spv") });
        if (!LoadFile(cat(base, ".spv"), spv)) { if (log) fprintf(stderr, "lut fn %s stays on the CPU: glslc failed on %s.comp\n", name.c_str(), base.c_str()); return ""; }
    }
    if (log) fprintf(stderr, "lut fn %s fills on the GPU (%s.comp)\n", name.c_str(), base.c_str());
    string lit;
    for (auto c : spv) lit += cat(lit.empty() ? "" : ", ", (int)(unsigned char)c);
    return lit;
}
inline int LutBits(string_view t) { return t == "bool" ? 1 : t == "byte" || t == "u8" || t == "i8" ? 8 : t == "u16" || t == "i16" ? 16 : 0; }
inline string LutTrim(string_view s) { auto b = s.find_first_not_of(" \t\r\n"), e = s.find_last_not_of(" \t\r\n"); return b == string_view::npos ? string() : string(s.substr(b, e - b + 1)); }
inline string LutKey(const LutParam &p, int shift) {
    auto v = cat("lut__", p.name);
    return shift ? cat("(", v, " << ", shift, ")") : v;
}
inline string AmniDesugar(const string &src, const string &path, bool root) {
    string out = src, gen, saves;
    auto lineof = [&](size_t at) { return 1 + (int)std::count(src.begin(), src.begin() + at, '\n'); };
    size_t pos = 0, shift = 0;
    auto gpudecl = false;
    for (;;) {
        auto at = src.find("lut fn ", pos);
        if (at == string::npos) break;
        pos = at + 7;
        auto ls = src.rfind('\n', at);
        ls = ls == string::npos ? 0 : ls + 1;
        if (LutTrim(src.substr(ls, at - ls)) != "") continue;
        auto lp = src.find('(', at), rp = src.find(')', lp), lb = src.find('{', rp);
        if (lp == string::npos || rp == string::npos || lb == string::npos) throw CompileError { cat(path, ":", lineof(at), ": error: malformed lut fn") };
        auto name = LutTrim(src.substr(at + 7, lp - at - 7));
        auto ret = LutTrim(src.substr(rp + 1, lb - rp - 1));
        if (ret.starts_with("->")) ret = LutTrim(ret.substr(2));
        if (ret.empty()) throw CompileError { cat(path, ":", lineof(at), ": error: lut fn ", name, " needs a written result type") };
        int depth = 0;
        size_t end = lb;
        for (; end < src.size(); end++) if (src[end] == '{') depth++; else if (src[end] == '}' && !--depth) break;
        vector<LutParam> ps;
        int bits = 0;
        auto plist = src.substr(lp + 1, rp - lp - 1);
        for (size_t s = 0; s <= plist.size();) {
            auto c = plist.find(',', s);
            auto one = LutTrim(plist.substr(s, c == string::npos ? string::npos : c - s));
            s = c == string::npos ? plist.size() + 1 : c + 1;
            if (one.empty()) continue;
            auto sp = one.find_first_of(" :");
            LutParam p { LutTrim(one.substr(0, sp)), sp == string::npos ? "" : LutTrim(one.substr(one.find_first_not_of(" :", sp))), 0 };
            p.bits = LutBits(p.type);
            if (!p.bits) throw CompileError { cat(path, ":", lineof(at), ": error: lut fn ", name, ": parameter ", p.name, " has type ", p.type.empty() ? "(none)" : p.type, "; a lut fn takes byte, i8, u8, i16, u16 or bool parameters") };
            bits += p.bits;
            ps.push_back(p);
        }
        if (ps.empty() || bits > 24) throw CompileError { cat(path, ":", lineof(at), ": error: lut fn ", name, " has ", bits, " bits of input; a lut fn takes 1 to 24") };
        uint64_t h = 1469598103934665603ull;
        for (auto i = at; i <= end && i < src.size(); i++) h = (h ^ (unsigned char)src[i]) * 1099511628211ull;
        auto hex = Hex8(cat(h));
        auto tb = std::min(bits, 12), tiles = 1 << (bits - tb), tsz = 1 << tb, words = std::max(tsz / 64, 1);
        string key, args, sig, widen;
        int sh = bits;
        for (auto &p : ps) {
            sh -= p.bits;
            key += cat(key.empty() ? "" : " | ", LutKey(p, sh));
            args += cat(args.empty() ? "" : ", ", p.name);
            sig += cat(sig.empty() ? "" : ", ", p.name, " ", p.type);
            widen += cat("let lut__", p.name, " int = ", p.type == "bool" ? cat("if ", p.name, " { 1 } else { 0 }") : p.type == "i8" ? cat(p.name, " as! u8") : p.type == "i16" ? cat(p.name, " as! u16") : p.name, ";\n\t");
        }
        auto n = name + "__lut";
        out.replace(at + shift, lp - at, cat("fn ", n));
        shift += n.size() + 3 - (lp - at);
        gen += cat("var ", n, "_t i32[>..];\nvar ", n, "_v ", ret, "[>..];\nvar ", n, "_s u64[>..];\nvar ", n, "_live = false;\nvar ", n, "_dirty = false;\n",
                   "fn ", n, "_path() byte[>..] { var p byte[>..] = []; if !env(\"HOME\", p) { p.append(\".\"); } format(p, \"/.goose\"); make_dir(p); format(p, \"/lut\"); make_dir(p); format(p, \"/", name, "-", hex, ".lut\"); p }\n",
                   "fn ", n, "_load() {\n\t", n, "_live = true;\n\tvar img byte[>..] = [];\n\tif read_file(", n, "_path(), img) {\n\t\tlet a, an = parse_uleb(img);\n\t\tlet b, bn = parse_uleb(img[an + a..]);\n\t\tlet t, tok = from_bytes<i32[>..]>(img[..an + a]);\n\t\tlet v, vok = from_bytes<", ret, "[>..]>(img[an + a..an + a + bn + b]);\n\t\tlet s, sok = from_bytes<u64[>..]>(img[an + a + bn + b..]);\n\t\tif tok && vok && sok && t.len == ", tiles, " { ", n, "_t.append(t); ", n, "_v.append(v); ", n, "_s.append(s); return; }\n\t}\n\t", n, "_t.resize(", tiles, ", -1);\n}\n",
                   "fn ", n, "_save() { if ", n, "_dirty { var img byte[>..] = []; to_bytes(", n, "_t, img); to_bytes(", n, "_v, img); to_bytes(", n, "_s, img); write_file(", n, "_path(), img); ", n, "_dirty = false; } }\n",
                   "fn ", name, "(", sig, ") ", ret, " {\n\tif !", n, "_live { ", n, "_load(); }\n\t", widen, "let lut__k = ", key, ";\n\tvar lut__b = ", n, "_t[lut__k >> ", tb, "];\n\tif lut__b < 0 { lut__b = (", n, "_v.len >> ", tb, ") as i32; ", n, "_t[lut__k >> ", tb, "] = lut__b; let lut__vl = ", n, "_v.len + ", tsz, "; let lut__sl = ", n, "_s.len + ", words, "; ", n, "_v.resize(lut__vl, default<", ret, ">()); ", n, "_s.resize(lut__sl, 0); }\n\tlet lut__j = ((lut__b as int) << ", tb, ") | (lut__k & ", tsz - 1, ");\n\tif (", n, "_s[lut__j >> 6] >> (lut__j & 63)) & 1 == 0 { ", n, "_v[lut__j] = ", n, "(", args, "); ", n, "_s[lut__j >> 6] |= 1 << (lut__j & 63); ", n, "_dirty = true; }\n\t", n, "_v[lut__j]\n}\n");
        saves += cat(n, "_save(); ");
        auto spv = bits >= 10 && bits <= 20 ? LutSpirv(src, name, ps, ret) : string();
        if (!spv.empty()) {
            auto N = 1 << bits, cnt = (int)std::count(spv.begin(), spv.end(), ',') + 1;
            if (!gpudecl) gen += "extern fn gs_gpu_fill(spv const byte[:], out byte[>..]&, n int, cpu_ns int) bool;\n", gpudecl = true;
            gen += cat("let ", n, "_spv byte[", cnt, "] = [", spv, "];\n");
            auto conv = ret == "bool" ? string("lut__x != 0") : ret == "uint" || ret == "u64" ? string("lut__x") : cat("lut__x as! ", ret);
            string pargs;
            int psh = bits;
            for (auto &p : ps) {
                psh -= p.bits;
                auto raw = cat("((lut__e >> ", psh, ") & ", (1 << p.bits) - 1, ")");
                pargs += cat(pargs.empty() ? "" : ", ", p.type == "bool" ? cat(raw, " != 0") : cat(raw, " as! ", p.type));
            }
            gen += cat("var ", n, "_probe ", ret, "[>..];\n");
            auto fill = cat("\t", n, "_probe.resize(64, default<", ret, ">());\n\tlet lut__p0 = clock_ns();\n\tfor q in 64 { let lut__e = q * ", N / 64, "; ", n, "_probe[q] = ", n, "(", pargs, "); }\n\tvar lut__g byte[>..] = [];\n\tif gs_gpu_fill(", n, "_spv, lut__g, ", N, ", (clock_ns() - lut__p0) * ", N / 64, ") {\n\t\tfor q in ", tiles, " { ", n, "_t.push(q as i32); }\n\t\t", n, "_v.resize(", N, ", default<", ret, ">());\n\t\t", n, "_s.resize(", tiles * words, ", 0);\n\t\tfor e in ", N, " {\n\t\t\tif lut__g[", N * 8, " + e * 4] == 0 {\n\t\t\t\tvar lut__x uint = 0;\n\t\t\t\tfor q in 8 { let lut__gb uint = lut__g[e * 8 + q]; lut__x |= lut__gb << (q * 8); }\n\t\t\t\t", n, "_v[e] = ", conv, ";\n\t\t\t\t", n, "_s[e >> 6] |= 1 << (e & 63);\n\t\t\t}\n\t\t}\n\t\t", n, "_dirty = true;\n\t\treturn;\n\t}\n");
            auto at2 = gen.rfind(cat("\t", n, "_t.resize(", tiles, ", -1);\n}"));
            gen.insert(at2, fill);
        }
        pos = end;
    }
    if (gen.empty()) return src;
    if (root) {
        auto m = out.find("\nfn main(");
        if (out.starts_with("fn main(")) m = 0; else if (m != string::npos) m++;
        if (m != string::npos) { out.replace(m, 8, "fn main__lut("); gen += cat("fn main() { main__lut(); ", saves, "}\n"); }
    }
    return cat(out, "\nimport os;\n", gen);
}
}
