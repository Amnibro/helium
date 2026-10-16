// Goose compiler — a language server's analysis of one program
// (docs/design/language_server.md §4): the Ast a check of a root left,
// the diagnostics it gave, and the indexes the features read: every
// occurrence of a name in each file, every call's extent, and each source
// node's clones, which carry the types and resolutions the checker made
// per specialization (Node::origin).
#pragma once

namespace goose {

// A name as a file has it: a use, or a declaration of something.
struct Occurrence {
    enum Kind {
        IDENT, DOT, TYPE,                           // Uses: a name, a member, a type name.
        FN, STRUCT, ENUM, ALIAS, GLOBAL, LOCAL,     // Declarations.
        FIELD, VARIANT, PARAM, GENERIC, BINDER      // Parts of declarations, and the bindings of loops, arms and blocks.
    };
    Kind kind = IDENT;
    size_t start = 0, len = 0;      // In the file's text.
    string_view name;
    const Node *node = nullptr;     // IDENT, DOT: the source node. GLOBAL, LOCAL: the VarDecl.
                                    // BINDER: the ForLoop, MatchExpr or FunVal.
    TypeExpr *type = nullptr;       // TYPE
    SFunction *sf = nullptr;        // FN, PARAM
    SStruct *st = nullptr;          // STRUCT, FIELD of a struct
    SEnum *en = nullptr;            // ENUM, VARIANT, FIELD of a variant
    SAlias *al = nullptr;           // ALIAS
    const Field *field = nullptr;   // FIELD
    const SVariant *variant = nullptr;      // VARIANT, FIELD of a variant
    const Param *param = nullptr;   // PARAM
    const GenericParam *generic = nullptr;  // GENERIC
    int index = 0;                  // GLOBAL, LOCAL: which name. BINDER: 0 the loop
                                    // variable, 1 its index; a match arm's number; a
                                    // block parameter's number.
    bool callee = false;            // IDENT, DOT: a call's callee.
    bool isvar = false;             // A declaration that can be assigned.
};

// A call's extent, for the signature help at a position inside it.
struct CallSpan {
    size_t start = 0, end = 0;
    const Call *call = nullptr;
};

struct FileIndex {
    int fileidx = 0;
    string uri;
    TextIndex text;
    vector<Occurrence> occs;        // By start, one per start.
    vector<CallSpan> calls;         // By start.

    // The occurrence covering an offset.
    const Occurrence *At(size_t offset) const {
        auto it = upper_bound(occs.begin(), occs.end(), offset,
                              [](size_t o, const Occurrence &x) { return o < x.start; });
        if (it == occs.begin()) return nullptr;
        --it;
        return offset < it->start + it->len ? &*it : nullptr;
    }
    // The innermost call whose extent holds an offset.
    const CallSpan *CallAt(size_t offset) const {
        const CallSpan *found = nullptr;
        for (auto &c : calls) {
            if (c.start > offset) break;
            if (offset <= c.end && (!found || c.start >= found->start)) found = &c;
        }
        return found;
    }
};

struct Analysis {
    unique_ptr<Ast> ast;
    bool parsed = false;            // Past resolution: the indexes stand on a whole program.
    bool checked = false;           // Checked, optimized and bounds-check analyzed without error.
    vector<Diagnostic> diags;       // Warnings as they came, then the error's.
    map<string, int> fileof;        // PathKey -> index in ast->sources.
    vector<FileIndex> files;        // Per source.
    unordered_map<const Node *, vector<Node *>> clones;   // Source node -> its clones.

    int FileOf(const string &key) const {
        auto it = fileof.find(key);
        return it == fileof.end() ? -1 : it->second;
    }

    // The first clone of n (or n itself) that `pred` accepts: where the
    // checker's annotations are.
    template<typename F> const Node *Find(const Node *n, F pred) const {
        if (pred(n)) return n;
        if (auto it = clones.find(n); it != clones.end())
            for (auto c : it->second) if (pred(c)) return c;
        return nullptr;
    }

    // The value type of a source node in the first specialization that
    // gave it one, and all of them, distinct, up to `most`.
    TypeExpr *TypeOf(const Node *n) const {
        auto c = Find(n, [](const Node *x) { return x->exprtype != nullptr; });
        return c ? c->exprtype : nullptr;
    }
    vector<TypeExpr *> TypesOf(const Node *n, size_t most) const {
        vector<TypeExpr *> types;
        set<string> seen;
        auto add = [&](const Node *x) {
            if (!x->exprtype || types.size() >= most) return;
            string s;
            x->exprtype->Dump(s);
            if (seen.insert(s).second) types.push_back(x->exprtype);
        };
        add(n);
        if (auto it = clones.find(n); it != clones.end()) for (auto c : it->second) add(c);
        return types;
    }

    // The declaration (as the source has it) of a variable the checker
    // made: a global's, or a local's found in the body it is in.
    const VarDecl *VarDeclOf(const VarDef *vd) const {
        for (auto g : ast->globals)
            for (auto d : g->defs) if (d == vd) return g;
        const VarDecl *found = nullptr;
        function<void(Node *)> walk = [&](Node *n) {
            if (!n || found) return;
            if (auto v = Is<VarDecl>(n))
                for (auto d : v->defs) if (d == vd) { found = (const VarDecl *)v->Origin(); return; }
            if (auto c = Is<Call>(n)) if (c->fvbody) walk(c->fvbody);
            n->Children(walk);
        };
        for (auto sp : ast->fnspecs) if (sp->body && !found) walk(sp->body);
        return found;
    }

    // The byte offset of a name the parser kept as a view into the file's
    // text, -1 for one it interned.
    int64_t OffsetOfView(int fileidx, string_view name) const {
        auto &src = *ast->sources[(size_t)fileidx].second;
        if (name.data() < src.data() || name.data() + name.size() > src.data() + src.size()) return -1;
        return name.data() - src.data();
    }

    // The files: their texts, line starts and URIs, which publishing the
    // diagnostics needs before anything else is indexed.
    void IndexFiles() {
        auto &a = *ast;
        files.resize(a.sources.size());
        for (size_t i = 0; i < a.sources.size(); i++) {
            auto &f = files[i];
            f.fileidx = (int)i;
            f.uri = UriOfPath(CanonicalPath(a.sources[i].first));
            f.text.Index(*a.sources[i].second);
            fileof[PathKey(a.sources[i].first)] = (int)i;
        }
    }

    // The rest of the indexes, from the Ast as the check left it.
    void Build() {
        auto &a = *ast;
        if (files.size() != a.sources.size()) IndexFiles();
        auto add = [&](Occurrence o, int fileidx, int64_t start) {
            if (start < 0 || fileidx < 0 || fileidx >= (int)files.size() || !o.len) return;
            o.start = (size_t)start;
            files[(size_t)fileidx].occs.push_back(o);
        };
        auto view = [&](Occurrence o, int fileidx, string_view name) {
            o.name = name;
            o.len = name.size();
            add(o, fileidx, OffsetOfView(fileidx, name));
        };
        auto at = [&](Occurrence o, Line l, string_view name) {
            if (l.line <= 0 || l.fileidx < 0 || l.fileidx >= (int)files.size()) return;
            o.name = name;
            o.len = name.size();
            add(o, l.fileidx, files[(size_t)l.fileidx].text.OffsetOf(l.line, l.col));
        };
        auto decl = [&](Occurrence::Kind k) { Occurrence o; o.kind = k; return o; };
        // Declarations and their parts.
        auto generics = [&](const vector<GenericParam> &gs) {
            for (auto &g : gs) {
                auto o = decl(Occurrence::GENERIC);
                o.generic = &g;
                at(o, g.line, g.name);
            }
        };
        auto fields = [&](const vector<Field> &fs, SStruct *st, SEnum *en, const SVariant *v) {
            for (auto &f : fs) {
                if (f.ispad) continue;
                auto o = decl(Occurrence::FIELD);
                o.field = &f;
                o.st = st;
                o.en = en;
                o.variant = v;
                o.isvar = !f.isconst;
                at(o, f.line, f.name);
            }
        };
        for (auto sf : a.functions) {
            auto o = decl(Occurrence::FN);
            o.sf = sf;
            view(o, sf->line.fileidx, sf->name);
            generics(sf->generics);
            for (auto &p : sf->params) {
                auto po = decl(Occurrence::PARAM);
                po.sf = sf;
                po.param = &p;
                po.isvar = p.isvar;
                at(po, p.line, p.name);
            }
        }
        for (auto st : a.structs) {
            auto o = decl(Occurrence::STRUCT);
            o.st = st;
            view(o, st->line.fileidx, st->name);
            generics(st->generics);
            fields(st->fields, st, nullptr, nullptr);
        }
        for (auto en : a.enums) {
            auto o = decl(Occurrence::ENUM);
            o.en = en;
            view(o, en->line.fileidx, en->name);
            generics(en->generics);
            for (auto &v : en->variants) {
                auto vo = decl(Occurrence::VARIANT);
                vo.en = en;
                vo.variant = &v;
                at(vo, v.line, v.name);
                fields(v.fields, nullptr, en, &v);
            }
        }
        for (auto al : a.aliases) {
            auto o = decl(Occurrence::ALIAS);
            o.al = al;
            view(o, al->line.fileidx, al->name);
        }
        for (auto g : a.globals) {
            for (size_t i = 0; i < g->names.size(); i++) {
                auto o = decl(Occurrence::GLOBAL);
                o.node = g;
                o.index = (int)i;
                o.isvar = g->isvar;
                view(o, g->line.fileidx, g->names[i]);
            }
        }
        // Type names, as written: the parser's type expressions, which the
        // resolver rewrote in place, keep the use's place; the checker's
        // copies share it and are left out, as is a place that does not
        // spell the type's name (a declaration's own type at its keyword).
        for (auto t : a.alltypes) {
            if (t->line.line <= 0 || t->line.fileidx < 0 || t->line.fileidx >= (int)files.size()) continue;
            string_view leaf;
            switch (t->kind) {
                case TY_STRUCT:  leaf = t->struc->st->name; break;
                case TY_ENUM:    leaf = t->enu->en->name; break;
                case TY_GENERIC: leaf = t->named->name; break;
                case TY_VARIANT: leaf = t->var->name; break;
                default: continue;
            }
            auto &f = files[(size_t)t->line.fileidx];
            auto start = f.text.OffsetOf(t->line.line, t->line.col);
            if (start < 0) continue;
            // A variant type is anchored at its `.`; the name follows.
            if (t->kind == TY_VARIANT && (size_t)start < f.text.text.size() && f.text.text[(size_t)start] == '.') start++;
            auto len = f.text.NameLengthAt((size_t)start);
            if (!len) continue;
            auto written = f.text.text.substr((size_t)start, len);
            auto lastleaf = written.substr(written.rfind("::") == string_view::npos ? 0 : written.rfind("::") + 2);
            if (lastleaf != leaf) continue;
            Occurrence o;
            o.kind = Occurrence::TYPE;
            o.type = t;
            o.name = written;
            o.len = len;
            add(o, t->line.fileidx, start);
        }
        // Uses inside bodies and initializers, and the bindings declared there.
        function<void(Node *, bool)> visit = [&](Node *n, bool callee) {
            if (!n) return;
            auto fileidx = n->line.fileidx;
            if (auto id = Is<Ident>(n)) {
                Occurrence o;
                o.kind = Occurrence::IDENT;
                o.node = n;
                o.callee = callee;
                at(o, n->line, id->name);
            } else if (auto d = Is<Dot>(n)) {
                Occurrence o;
                o.kind = Occurrence::DOT;
                o.node = n;
                o.callee = callee;
                o.name = d->name;
                o.len = d->name.size();
                if (n->end.line > 0 && n->end.fileidx == fileidx) {
                    auto end = files[(size_t)fileidx].text.OffsetOf(n->end.line, n->end.col);
                    if (end >= (int64_t)o.len) add(o, fileidx, end - (int64_t)o.len);
                }
            } else if (auto vd = Is<VarDecl>(n)) {
                if (!vd->isglobal && !vd->results)
                    for (size_t i = 0; i < vd->names.size(); i++) {
                        auto o = decl(Occurrence::LOCAL);
                        o.node = n;
                        o.index = (int)i;
                        o.isvar = vd->isvar;
                        view(o, fileidx, vd->names[i]);
                    }
            } else if (auto fl = Is<ForLoop>(n)) {
                auto o = decl(Occurrence::BINDER);
                o.node = n;
                o.isvar = fl->byref;
                view(o, fileidx, fl->var);
                if (!fl->idxvar.empty()) {
                    o.index = 1;
                    view(o, fileidx, fl->idxvar);
                }
            } else if (auto m = Is<MatchExpr>(n)) {
                for (size_t i = 0; i < m->arms.size(); i++) {
                    if (m->arms[i].pat.binder.empty()) continue;
                    auto o = decl(Occurrence::BINDER);
                    o.node = n;
                    o.index = (int)i;
                    o.isvar = m->arms[i].pat.byref;
                    view(o, fileidx, m->arms[i].pat.binder);
                }
            } else if (auto fv = Is<FunVal>(n)) {
                for (size_t i = 0; i < fv->params.size(); i++) {
                    auto o = decl(Occurrence::BINDER);
                    o.node = n;
                    o.index = (int)i;
                    o.isvar = fv->params[i].isvar;
                    at(o, fv->params[i].line, fv->params[i].name);
                }
            }
            if (auto c = Is<Call>(n)) {
                if (n->line.line > 0 && n->end.line > 0 && fileidx >= 0 && fileidx < (int)files.size()) {
                    auto &f = files[(size_t)fileidx];
                    auto start = f.text.OffsetOf(n->line.line, n->line.col);
                    auto end = f.text.OffsetOf(n->end.line, n->end.col);
                    if (start >= 0 && end >= start) f.calls.push_back({ (size_t)start, (size_t)end, c });
                }
                visit(c->callee, true);
                for (auto arg : c->args) visit(arg, false);
                if (c->trailing) visit(c->trailing, false);
                return;
            }
            n->Children([&](Node *ch) { visit(ch, false); });
        };
        for (auto sf : a.functions) {
            if (sf->body) visit(sf->body, false);
            for (auto &p : sf->params) if (p.defaultval) visit(p.defaultval, false);
        }
        for (auto st : a.structs)
            for (auto &f : st->fields) if (f.defaultval) visit(f.defaultval, false);
        for (auto en : a.enums)
            for (auto &v : en->variants)
                for (auto &f : v.fields) if (f.defaultval) visit(f.defaultval, false);
        for (auto g : a.globals) {
            for (auto init : g->inits) visit(init, false);
        }
        for (auto &f : files) {
            stable_sort(f.occs.begin(), f.occs.end(),
                        [](const Occurrence &x, const Occurrence &y) { return x.start < y.start; });
            f.occs.erase(unique(f.occs.begin(), f.occs.end(),
                                [](const Occurrence &x, const Occurrence &y) { return x.start == y.start; }),
                         f.occs.end());
            stable_sort(f.calls.begin(), f.calls.end(),
                        [](const CallSpan &x, const CallSpan &y) { return x.start < y.start; });
        }
        // The clones: every specialization's body, the bodies of the
        // function values its calls checked, and the defaults they made.
        function<void(Node *)> mark = [&](Node *n) {
            if (!n) return;
            if (n->origin) clones[n->origin].push_back(n);
            if (auto c = Is<Call>(n)) {
                if (c->fvbody) mark(c->fvbody);
                if (c->defaultinit) mark(c->defaultinit);
            }
            n->Children(mark);
        };
        for (auto sp : a.fnspecs) if (sp->body) mark(sp->body);
        for (auto g : a.globals) for (auto init : g->inits) mark(init);
    }
};

}  // namespace goose
