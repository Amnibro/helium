#pragma once
namespace goose {
struct LutParam { string name, type; int bits; };
struct GlslGen {
    struct Fail { string why; };
    struct E { string code, ty; bool ll = false; };
    struct Fn { vector<pair<string, string>> params; string ret; size_t body; };
    const string &src;
    vector<string> tk;
    map<string, Fn> fns;
    map<string, string> sigs;
    set<string> busy, done;
    string out, cur;
    vector<map<string, string>> scopes;
    size_t p = 0;
    GlslGen(const string &s) : src(s) {}
    [[noreturn]] void No(const string &w) { throw Fail { w }; }
    void Lex() {
        for (size_t i = 0; i < src.size();) {
            auto c = src[i];
            if (isspace((unsigned char)c)) { i++; continue; }
            if (c == '/' && i + 1 < src.size() && src[i + 1] == '/') { while (i < src.size() && src[i] != '\n') i++; continue; }
            if (c == '/' && i + 1 < src.size() && src[i + 1] == '*') { auto e = src.find("*/", i + 2); i = e == string::npos ? src.size() : e + 2; continue; }
            if (isalpha((unsigned char)c) || c == '_') { auto b = i; while (i < src.size() && (isalnum((unsigned char)src[i]) || src[i] == '_')) i++; tk.push_back(src.substr(b, i - b)); continue; }
            if (isdigit((unsigned char)c)) { auto b = i; while (i < src.size() && (isalnum((unsigned char)src[i]) || src[i] == '_')) i++; if (i + 1 < src.size() && src[i] == '.' && isdigit((unsigned char)src[i + 1])) No("float literal"); tk.push_back(src.substr(b, i - b)); continue; }
            if (c == '"') { i++; while (i < src.size() && src[i] != '"') i += src[i] == '\\' ? 2 : 1; i++; tk.push_back("\"str\""); continue; }
            if (c == '\'') { auto b = i++; while (i < src.size() && src[i] != '\'') i += src[i] == '\\' ? 2 : 1; i++; tk.push_back(src.substr(b, i - b)); continue; }
            static const char *ops[] = { "<<=", ">>=", "as!", "==", "!=", "<=", ">=", "&&", "||", "<<", ">>", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "++", "--", "..", "->", "::", ".=", ".==" };
            auto hit = false;
            for (auto o : ops) if (!src.compare(i, strlen(o), o)) { tk.push_back(o); i += strlen(o); hit = true; break; }
            if (!hit) tk.push_back(string(1, c)), i++;
        }
        for (size_t i = 0; i + 1 < tk.size(); i++) {
            if (tk[i] != "fn" || (i && (tk[i - 1] == "extern" || tk[i - 1] == "::"))) continue;
            auto name = tk[i + 1];
            size_t j = i + 2;
            if (j >= tk.size() || tk[j] != "(") continue;
            Fn f;
            j++;
            while (j < tk.size() && tk[j] != ")") {
                auto pn = tk[j++];
                if (j < tk.size() && tk[j] == ":") j++;
                string ty;
                while (j < tk.size() && tk[j] != "," && tk[j] != ")") ty += tk[j++];
                f.params.push_back({ pn, ty });
                if (j < tk.size() && tk[j] == ",") j++;
            }
            j++;
            if (j < tk.size() && tk[j] == "->") j++;
            while (j < tk.size() && tk[j] != "{" && tk[j] != "=" && tk[j] != ";") f.ret += tk[j++];
            if (j < tk.size() && tk[j] == "{") { f.body = j; if (!fns.count(name)) fns[name] = f; }
        }
    }
    static string Ty(const string &t) {
        static const map<string, string> m = { { "int", "int64_t" }, { "i64", "int64_t" }, { "uint", "uint64_t" }, { "u64", "uint64_t" }, { "i32", "int" }, { "u32", "uint" },
                                                { "i16", "i16" }, { "i8", "i8" }, { "u16", "u16" }, { "u8", "u8" }, { "byte", "u8" }, { "bool", "bool" } };
        auto it = m.find(t);
        return it == m.end() ? "" : it->second;
    }
    static string Store(const string &t) { return t == "i16" || t == "i8" ? "int" : t == "u16" || t == "u8" ? "uint" : t == "lit" ? "int64_t" : t; }
    static bool Signed(const string &t) { return t == "int64_t" || t == "int" || t == "i16" || t == "i8"; }
    static int Width(const string &t) { return t == "int64_t" || t == "uint64_t" || t == "lit" ? 64 : t == "int" || t == "uint" ? 32 : t == "i16" || t == "u16" ? 16 : t == "bool" ? 1 : 8; }
    static string Wrap(const string &code, const string &t) {
        return t == "i8" || t == "i16" ? cat("bitfieldExtract(", code, ", 0, ", Width(t), ")") : t == "u8" ? cat("((", code, ") & 0xFFu)") : t == "u16" ? cat("((", code, ") & 0xFFFFu)") : code;
    }
    static bool Widens(const string &from, const string &to) {
        if (from == to) return true;
        if (from == "bool" || to == "bool") return false;
        return Signed(from) == Signed(to) ? Width(from) < Width(to) : !Signed(from) && Signed(to) && Width(from) < Width(to);
    }
    string Lit(const string &l, const string &t) {
        auto v = l;
        v.erase(std::remove(v.begin(), v.end(), '_'), v.end());
        if (v.size() && v[0] == '\'') {
            if (v.size() == 3) v = cat((int)(unsigned char)v[1]);
            else if (v.size() == 4 && v[1] == '\\') v = cat(v[2] == 'n' ? 10 : v[2] == 't' ? 9 : v[2] == 'r' ? 13 : v[2] == '0' ? 0 : (int)(unsigned char)v[2]);
            else No("character literal");
        }
        auto s = Store(t);
        return s == "int64_t" ? cat("int64_t(", v, "l)") : s == "uint64_t" ? cat("uint64_t(", v, "ul)") : s == "uint" ? cat(v, "u") : s == "bool" ? (No("integer as bool"), string()) : cat("int(", v, ")");
    }
    E To(E e, const string &t) {
        if (e.ty == t) return e;
        if (e.ty == "lit") return { Lit(e.code, t), t };
        if (e.ll && t != "bool") return { cat(Store(t), "(", e.code, ")"), t };
        if (!Widens(e.ty, t)) No(cat("no implicit ", e.ty, " to ", t));
        return { cat(Store(t), "(", e.code, ")"), t };
    }
    string Unify(const E &a, const E &b) {
        if (a.ty == b.ty) return a.ty == "lit" ? "int64_t" : a.ty;
        if (a.ty == "lit" || (a.ll && !b.ll && b.ty != "bool")) return b.ty;
        if (b.ty == "lit" || (b.ll && !a.ll && a.ty != "bool")) return a.ty;
        if (Widens(a.ty, b.ty)) return b.ty;
        if (Widens(b.ty, a.ty)) return a.ty;
        No(cat("mixed ", a.ty, " and ", b.ty));
    }
    const string &T() { if (p >= tk.size()) No("end of file"); return tk[p]; }
    bool Is(const string &s) { return p < tk.size() && tk[p] == s; }
    void Eat(const string &s) { if (!Is(s)) No(cat("expected ", s, " near ", p < tk.size() ? tk[p] : "end")); p++; }
    string Local(const string &n) { for (auto i = scopes.size(); i--;) if (auto it = scopes[i].find(n); it != scopes[i].end()) return it->second; return ""; }
    string Def(const string &t) { return t == "bool" ? "false" : cat(Store(t), "(0)"); }
    string Guard() { return cat("if (++gs_n > 65536u) { gs_fail = 1u; return ", Def(cur), "; } "); }
    E Bin(const string &op, E a, E b) {
        if (op == "&&" || op == "||") { if (a.ty != "bool" || b.ty != "bool") No("&& on non-bool"); return { cat("(", a.code, " ", op, " ", b.code, ")"), "bool" }; }
        if (a.ty == "bool" || b.ty == "bool") {
            if ((op == "==" || op == "!=") && a.ty == b.ty) return { cat("(", a.code, " ", op, " ", b.code, ")"), "bool" };
            No("arithmetic on bool");
        }
        if (op == "<<" || op == ">>") {
            auto t = a.ty == "lit" ? "int64_t" : a.ty;
            auto x = To(a, t);
            auto k = b.ty == "lit" ? E { Lit(b.code, Store(t)), Store(t) } : E { cat(Store(t), "(", b.code, ")"), Store(t) };
            return { Wrap(cat("(", x.code, " ", op, " (", k.code, " & ", Lit(cat(Width(t) - 1), Store(t)), "))"), t), t };
        }
        auto t = Unify(a, b);
        a = To(a, t), b = To(b, t);
        if (op == "==" || op == "!=" || op == "<" || op == "<=" || op == ">" || op == ">=") return { cat("(", a.code, " ", op, " ", b.code, ")"), "bool" };
        if (op == "/" || op == "%") return { Wrap(cat(op == "/" ? "gs_div(" : "gs_mod(", a.code, ", ", b.code, ")"), t), t, (a.ll || a.ty == "lit") && (b.ll || b.ty == "lit") };
        auto ll = (a.ll || a.ty == "lit") && (b.ll || b.ty == "lit");
        return { Wrap(cat("(", a.code, " ", op, " ", b.code, ")"), t), t, ll };
    }
    static int Prec(const string &o) {
        return o == "*" || o == "/" || o == "%" ? 10 : o == "+" || o == "-" ? 9 : o == "<<" || o == ">>" ? 8 : o == "&" ? 7 : o == "^" ? 6 : o == "|" ? 5 :
               o == "<" || o == "<=" || o == ">" || o == ">=" ? 4 : o == "==" || o == "!=" ? 3 : o == "&&" ? 2 : o == "||" ? 1 : 0;
    }
    E Expr(int min = 1) {
        auto l = Unary();
        for (;;) {
            if (p >= tk.size()) return l;
            auto o = tk[p];
            auto pr = Prec(o);
            if (!pr || pr < min) return l;
            p++;
            auto r = Expr(pr + 1);
            l = Bin(o, l, r);
        }
    }
    E Unary() {
        if (Is("-")) { p++; auto e = Unary(); if (e.ty == "lit") return { cat("-", e.code), "lit" }; if (e.ty == "bool") No("- on bool"); return { Wrap(cat("(-", e.code, ")"), e.ty), e.ty }; }
        if (Is("!")) { p++; auto e = Unary(); if (e.ty != "bool") No("! on non-bool"); return { cat("(!", e.code, ")"), "bool" }; }
        if (Is("~")) { p++; auto e = Unary(); if (e.ty == "lit") e = To(e, "int64_t"); if (e.ty == "bool") No("~ on bool"); return { Wrap(cat("(~", e.code, ")"), e.ty), e.ty }; }
        return Postfix();
    }
    E Postfix() {
        auto e = Primary();
        while (Is("as")) {
            p++;
            if (Is("!")) p++;
            auto t = Ty(T());
            p++;
            if (t.empty() || t == "bool" || e.ty == "bool") No("cast");
            e = e.ty == "lit" ? E { Lit(e.code, t), t } : E { Wrap(cat(Store(t), "(", e.code, ")"), t), t };
        }
        return e;
    }
    E IfExpr() {
        Eat("if");
        auto c = Expr();
        if (c.ty != "bool") No("if on non-bool");
        Eat("{");
        auto a = Expr();
        Eat("}");
        Eat("else");
        E b;
        if (Is("if")) b = IfExpr(); else { Eat("{"); b = Expr(); Eat("}"); }
        string t;
        auto ll = (a.ll || a.ty == "lit") && (b.ll || b.ty == "lit");
        if (a.ty == "bool" || b.ty == "bool") { if (a.ty != b.ty) No("if branches"); t = "bool"; ll = false; } else { t = Unify(a, b); a = To(a, t); b = To(b, t); }
        return { cat("(", c.code, " ? ", a.code, " : ", b.code, ")"), t, ll };
    }
    E Primary() {
        auto t = T();
        if (t == "(") { p++; auto e = Expr(); Eat(")"); return e; }
        if (t == "if") return IfExpr();
        if (t == "true" || t == "false") { p++; return { t, "bool" }; }
        if (isdigit((unsigned char)t[0]) || t[0] == '\'') { p++; return { t, "lit" }; }
        if (!(isalpha((unsigned char)t[0]) || t[0] == '_')) No(cat("token ", t));
        p++;
        if (Is("(")) {
            p++;
            vector<E> args;
            while (!Is(")")) { args.push_back(Expr()); if (Is(",")) p++; }
            p++;
            if (t == "min" || t == "max" || t == "abs" || t == "clamp") {
                if (args.empty()) No("builtin args");
                auto ty = args[0].ty;
                for (auto &a : args) ty = Unify({ "", ty }, a);
                if (ty == "lit") ty = "int64_t";
                if (ty == "bool" || (t == "abs" && !Signed(ty))) No("builtin type");
                string c;
                for (auto &a : args) c += cat(c.empty() ? "" : ", ", To(a, ty).code);
                return { Wrap(cat(t, "(", c, ")"), ty), ty };
            }
            auto f = Func(t);
            auto &fd = fns[t];
            if (args.size() != fd.params.size()) No(cat("call to ", t, " with defaults"));
            string c;
            for (size_t i = 0; i < args.size(); i++) c += cat(i ? ", " : "", To(args[i], Ty(fd.params[i].second)).code);
            return { cat("h_", t, "(", c, ")"), Ty(fd.ret) };
        }
        auto ty = Local(t);
        if (ty.empty()) No(cat("name ", t));
        return { cat("l_", t), ty };
    }
    string Func(const string &name) {
        if (done.count(name)) return name;
        if (busy.count(name)) No(cat("recursion through ", name));
        auto it = fns.find(name);
        if (it == fns.end()) No(cat("function ", name));
        auto &f = it->second;
        auto rt = Ty(f.ret);
        if (rt.empty()) No(cat(name, " result type ", f.ret.empty() ? "(inferred)" : f.ret));
        busy.insert(name);
        auto sp = p;
        auto savescopes = scopes;
        auto savecur = cur;
        scopes = { {} };
        cur = rt;
        string sig;
        for (auto &[pn, pt] : f.params) {
            auto t = Ty(pt);
            if (t.empty()) No(cat(name, " parameter type ", pt));
            scopes.back()[pn] = t;
            sig += cat(sig.empty() ? "" : ", ", Store(t), " l_", pn);
        }
        p = f.body;
        string body;
        Block(body, true, 1);
        out += cat(Store(rt), " h_", name, "(", sig, ") {\n", body, "    return ", Def(rt), ";\n}\n");
        p = sp, scopes = savescopes, cur = savecur;
        busy.erase(name);
        done.insert(name);
        return name;
    }
    size_t AfterIf(size_t i) {
        auto skip = [&](size_t j) { int d = 0; for (; j < tk.size(); j++) { if (tk[j] == "{") d++; else if (tk[j] == "}" && !--d) return j + 1; } return j; };
        for (;;) {
            while (i < tk.size() && tk[i] != "{") i++;
            i = skip(i);
            if (i < tk.size() && tk[i] == "else") { i++; if (i < tk.size() && tk[i] == "if") continue; while (i < tk.size() && tk[i] != "{") i++; return skip(i); }
            return i;
        }
    }
    void Block(string &o, bool tail, int ind) {
        Eat("{");
        scopes.push_back({});
        while (!Is("}")) Stmt(o, tail, ind);
        p++;
        scopes.pop_back();
    }
    void Stmt(string &o, bool tail, int ind) {
        string pad(ind * 4, ' ');
        auto t = T();
        if (t == ";") { p++; return; }
        if (t == "let" || t == "var" || t == "const") {
            p++;
            auto n = T();
            p++;
            string ty;
            if (Is(":")) p++;
            if (!Is("=") && !Is(";")) { ty = Ty(T()); if (ty.empty()) No(cat("local type ", T())); p++; }
            if (!Is("=")) No("local without initializer");
            p++;
            auto e = Expr();
            Eat(";");
            if (ty.empty()) ty = e.ty == "lit" ? "int64_t" : e.ty;
            e = ty == "bool" ? (e.ty == "bool" ? e : (No("bool init"), e)) : To(e, ty);
            scopes.back()[n] = ty;
            o += cat(pad, Store(ty), " l_", n, " = ", e.code, ";\n");
            return;
        }
        if (t == "while") {
            p++;
            auto c = Expr();
            if (c.ty != "bool") No("while on non-bool");
            string b;
            Block(b, false, ind + 1);
            o += cat(pad, "while (", c.code, ") { ", Guard(), "\n", b, pad, "}\n");
            return;
        }
        if (t == "loop") {
            p++;
            string b;
            Block(b, false, ind + 1);
            o += cat(pad, "while (true) { ", Guard(), "\n", b, pad, "}\n");
            return;
        }
        if (t == "for") {
            p++;
            auto n = T();
            p++;
            if (Is(",") || Is(":")) No("for binding form");
            Eat("in");
            auto a = Expr();
            E lo { "0", "lit" }, hi = a;
            if (Is("..")) { p++; lo = a; hi = Expr(); }
            auto ty = Unify(lo, hi);
            if (ty == "lit") ty = "int64_t";
            if (ty == "bool") No("for over bool");
            lo = To(lo, ty), hi = To(hi, ty);
            scopes.push_back({ { n, ty } });
            string b;
            Block(b, false, ind + 1);
            scopes.pop_back();
            o += cat(pad, "for (", Store(ty), " l_", n, " = ", lo.code, ", l_", n, "_end = ", hi.code, "; l_", n, " < l_", n, "_end; l_", n, "++) { ", Guard(), "\n", b, pad, "}\n");
            return;
        }
        if (t == "if") {
            auto last = tail && AfterIf(p) < tk.size() && tk[AfterIf(p)] == "}";
            p++;
            auto c = Expr();
            if (c.ty != "bool") No("if on non-bool");
            string b;
            Block(b, last, ind + 1);
            o += cat(pad, "if (", c.code, ") {\n", b, pad, "}");
            while (Is("else")) {
                p++;
                if (Is("if")) {
                    p++;
                    auto c2 = Expr();
                    if (c2.ty != "bool") No("if on non-bool");
                    string b2;
                    Block(b2, last, ind + 1);
                    o += cat(" else if (", c2.code, ") {\n", b2, pad, "}");
                } else {
                    string b2;
                    Block(b2, last, ind + 1);
                    o += cat(" else {\n", b2, pad, "}");
                }
            }
            o += "\n";
            return;
        }
        if (t == "guard") {
            p++;
            auto c = Expr();
            if (c.ty != "bool") No("guard on non-bool");
            if (Is(";")) No("guard without else");
            Eat("else");
            string b;
            Block(b, false, ind + 1);
            o += cat(pad, "if (!", c.code, ") {\n", b, pad, "}\n");
            return;
        }
        if (t == "return") {
            p++;
            auto e = Expr();
            Eat(";");
            o += cat(pad, "return ", cur == "bool" ? (e.ty == "bool" ? e.code : (No("return type"), string())) : To(e, cur).code, ";\n");
            return;
        }
        if (t == "break" || t == "continue") { p++; if (!Is(";")) No("break with a value"); p++; o += cat(pad, t, ";\n"); return; }
        if (t == "{") { string b; Block(b, tail, ind + 1); o += cat(pad, "{\n", b, pad, "}\n"); return; }
        if (p + 1 < tk.size() && !Local(t).empty()) {
            auto &op = tk[p + 1];
            if (op == "++" || op == "--") {
                auto ty = Local(t);
                p += 2;
                Eat(";");
                o += cat(pad, "l_", t, " = ", Bin(op == "++" ? "+" : "-", { cat("l_", t), ty }, { "1", "lit" }).code, ";\n");
                return;
            }
            if (op == "=" || (op.size() >= 2 && op.back() == '=' && op != "==" && op != "!=" && op != "<=" && op != ">=")) {
                auto ty = Local(t);
                p += 2;
                auto e = Expr();
                Eat(";");
                auto v = op == "=" ? (ty == "bool" ? e : To(e, ty)) : Bin(op.substr(0, op.size() - 1), { cat("l_", t), ty }, e);
                if (op != "=" && v.ty != ty) v = To(v, ty);
                o += cat(pad, "l_", t, " = ", v.code, ";\n");
                return;
            }
        }
        auto e = Expr();
        if (Is("}") && tail) { o += cat(pad, "return ", cur == "bool" ? e.code : To(e, cur).code, ";\n"); return; }
        Eat(";");
        o += cat(pad, e.code, ";\n");
    }
};
inline string LutGlsl(const string &src, const string &name, const vector<LutParam> &ps, const string &ret, string &why) {
    GlslGen g(src);
    try {
        g.Lex();
        auto rt = GlslGen::Ty(ret);
        if (rt.empty()) throw GlslGen::Fail { cat("result type ", ret) };
        g.Func(name);
        string helpers;
        for (auto t : { "int64_t", "uint64_t", "int", "uint" }) {
            string s = t;
            auto sg = GlslGen::Signed(s);
            auto zero = cat(s, "(0)"), one = cat(s, "(1)");
            helpers += cat(s, " gs_div(", s, " a, ", s, " b) { if (b == ", zero, ") { gs_fail = 1u; return ", zero, "; } ", sg ? cat("if (b == -", one, " && a == (", s, "(1) << ", GlslGen::Width(s) - 1, ")) { gs_fail = 1u; return ", zero, "; } ") : "", "return a / b; }\n",
                           s, " gs_mod(", s, " a, ", s, " b) { if (b == ", zero, ") { gs_fail = 1u; return ", zero, "; } ", sg ? cat("if (b == -", one, ") return ", zero, "; ", s, " r = a - b * (a / b); return r < ", zero, " ? r + (b < ", zero, " ? -b : b) : r;") : "return a % b;", " }\n");
        }
        string decode, args;
        int sh = 0;
        for (auto &p : ps) sh += p.bits;
        for (auto &p : ps) {
            sh -= p.bits;
            auto raw = cat("((i >> ", sh, "u) & ", (1u << p.bits) - 1, "u)");
            auto t = GlslGen::Ty(p.type);
            decode += cat("    ", GlslGen::Store(t), " a_", p.name, " = ", t == "bool" ? cat(raw, " != 0u") : t == "i8" || t == "i16" ? cat("bitfieldExtract(int(", raw, "), 0, ", p.bits, ")") : GlslGen::Store(t) == "uint" ? raw : cat(GlslGen::Store(t), "(", raw, ")"), ";\n");
            args += cat(args.empty() ? "" : ", ", "a_", p.name);
        }
        auto res = rt == "bool" ? "(r ? int64_t(1) : int64_t(0))" : "int64_t(r)";
        return cat("#version 450\n#extension GL_EXT_shader_explicit_arithmetic_types_int64 : require\nlayout(local_size_x = 64) in;\n",
                   "layout(std430, binding = 0) buffer V { int64_t v[]; };\nlayout(std430, binding = 1) buffer F { uint f[]; };\n",
                   "layout(push_constant) uniform P { uint base; uint n; } pc;\nuint gs_fail;\nuint gs_n;\n", helpers, g.out,
                   "void main() {\n    uint i = gl_GlobalInvocationID.x + pc.base;\n    if (i >= pc.n) return;\n    gs_fail = 0u;\n    gs_n = 0u;\n", decode,
                   "    ", GlslGen::Store(rt), " r = h_", name, "(", args, ");\n    v[i] = ", res, ";\n    f[i] = gs_fail;\n}\n");
    } catch (GlslGen::Fail &f) {
        why = f.why;
        return "";
    }
}
}
