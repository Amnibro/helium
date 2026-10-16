// Goose compiler — the language server's features (docs/design/
// language_server.md §6), each a request answered from a root's analysis:
// hover, go to definition, document and workspace symbols, semantic
// tokens and signature help. Every one takes the request's params and
// writes its result, or writes nothing and returns false for a null
// result.
#pragma once

namespace goose {

// Where a request is: the root and analysis answering for the file, the
// file's index, and the position as a byte offset in its text.
struct Located {
    Root *root = nullptr;
    Analysis *an = nullptr;
    FileIndex *fi = nullptr;
    size_t offset = 0;
};

inline bool Locate(Workspace &ws, const Json &params, Located &loc, bool position = true) {
    auto td = params.Get("textDocument");
    auto uri = JsonStr(td ? td->Get("uri") : nullptr);
    if (uri.empty()) return false;
    int fileidx;
    if (!ws.Locate(PathKey(PathOfUri(uri)), loc.root, loc.an, fileidx)) return false;
    loc.fi = &loc.an->files[(size_t)fileidx];
    if (position) {
        auto pos = params.Get("position");
        if (!pos) return false;
        loc.offset = loc.fi->text.OffsetOfPosition(JsonInt(pos->Get("line")), JsonInt(pos->Get("character")));
    }
    return true;
}

// --- rendering ---------------------------------------------------------------

inline string TypeText(const TypeExpr *t) {
    string s;
    if (t) t->Dump(s);
    else s = "?";
    return s;
}

inline string GenericsText(const vector<GenericParam> &gs) {
    if (gs.empty()) return {};
    string s = "<";
    for (size_t i = 0; i < gs.size(); i++) {
        if (i) s += ", ";
        s += gs[i].name;
        if (gs[i].bound) Append(s, ": ", TypeText(gs[i].bound));
    }
    return s + ">";
}

// A function's declaration as its header line, defaults elided.
inline string FnHeader(const SFunction *sf) {
    string s;
    if (sf->isexport) s += "export ";
    if (sf->isextern) s += "extern ";
    if (sf->checkfree && !sf->isnested) s += "checkfree ";
    if (sf->isinline) s += "inline ";
    if (sf->issimd) s += "simd ";
    if (sf->isrec) s += "recursive ";
    s += sf->isthread ? "thread_fn " : "fn ";
    Append(s, sf->qname, GenericsText(sf->generics), "(");
    for (size_t i = 0; i < sf->params.size(); i++) {
        auto &p = sf->params[i];
        if (i) s += ", ";
        if (p.isvar) s += "var ";
        s += p.name;
        if (p.type) Append(s, ": ", TypeText(p.type));
        if (p.defaultval) s += " = ...";
    }
    s += ")";
    if (sf->has_rets && !sf->rets.empty()) {
        s += " -> ";
        for (size_t i = 0; i < sf->rets.size(); i++) {
            if (i) s += ", ";
            s += TypeText(sf->rets[i]);
        }
    }
    return s;
}

// The specializations a function has, as `name(argument types)`, up to
// `most` of them.
inline string SpecsText(const SFunction *sf, size_t most) {
    string s;
    size_t n = 0;
    for (auto sp : sf->specs) {
        if (sp->isfunval) continue;
        if (n++ == most) {
            Append(s, "\n... ", sf->specs.size() - most, " more");
            break;
        }
        Append(s, s.empty() ? "" : "\n", sf->qname, "(");
        for (size_t i = 0; i < sp->argtypes.size(); i++) {
            if (i) s += ", ";
            s += TypeText(sp->argtypes[i]);
        }
        s += ")";
    }
    return s;
}

inline string VarDefHeader(const VarDef *vd) {
    string s = vd->isparam ? (vd->isvar ? "var " : "") : vd->isglobal ? (vd->isvar ? "var " : "let ")
                                                                       : (vd->isvar ? "var " : "let ");
    if (vd->isparam) s = cat("parameter ", s);
    Append(s, vd->name, ": ", TypeText(vd->type));
    return s;
}

// A documentation comment as Markdown: each line less its `//` and one
// space.
inline string DocText(string_view doc) {
    string s;
    for (size_t pos = 0; pos <= doc.size();) {
        auto end = doc.find('\n', pos);
        if (end == string_view::npos) end = doc.size();
        auto line = doc.substr(pos, end - pos);
        if (!line.empty() && line.back() == '\r') line.remove_suffix(1);
        auto first = line.find_first_not_of(" \t");
        if (first != string_view::npos) line.remove_prefix(first);
        if (line.substr(0, 2) == "//") line.remove_prefix(2);
        if (!line.empty() && line[0] == ' ') line.remove_prefix(1);
        if (!s.empty()) s += '\n';
        s += line;
        pos = end + 1;
    }
    return s;
}

// The enum a variant belongs to: the one whose variants hold it.
inline SEnum *EnumOfVariant(const Ast &ast, const SVariant *v) {
    for (auto en : ast.enums)
        if (v >= en->variants.data() && v < en->variants.data() + en->variants.size()) return en;
    return nullptr;
}

inline string VariantHeader(const SEnum *en, const SVariant *v) {
    auto s = cat(en ? string(en->qname) : string("?"), ".", v->name);
    if (v->has_payload) {
        s += " {";
        auto first = true;
        for (auto &f : v->fields) {
            if (f.ispad) continue;
            Append(s, first ? " " : ", ", f.name, ": ", TypeText(f.type));
            first = false;
        }
        s += " }";
    }
    return s;
}

// The field a member access names, by the object's type: a struct's, or a
// variant's payload's.
inline const Field *FieldOfDot(const Dot *d) {
    if (d->fieldidx < 0 || !d->obj) return nullptr;
    auto t = d->obj->exprtype;
    while (t && t->kind == TY_REF) t = t->ref->sub;
    if (!t) return nullptr;
    const vector<Field> *fields = nullptr;
    if (t->kind == TY_STRUCT) fields = &t->struc->st->fields;
    else if (t->kind == TY_VARIANT && t->var->variant) fields = &t->var->variant->fields;
    if (!fields || d->fieldidx >= (int)fields->size()) return nullptr;
    return &(*fields)[(size_t)d->fieldidx];
}

// The checked call whose callee the occurrence is: the innermost call
// starting there, in the first specialization that resolved it.
inline const Call *ResolvedCall(const Located &loc, const Occurrence &occ) {
    auto span = loc.fi->CallAt(occ.start);
    if (!span || span->call->callee != occ.node) return nullptr;
    auto c = loc.an->Find(span->call, [](const Node *n) {
        auto x = Is<Call>(n);
        return x && (x->spec || x->builtin >= 0 || !x->dispatch.empty() || x->fvbody);
    });
    return c ? Is<Call>(c) : nullptr;
}

inline const SFunction *CalleeOf(const Call *c) {
    if (!c) return nullptr;
    if (c->spec) return c->spec->sf;
    if (!c->dispatch.empty() && c->dispatch[0]) return c->dispatch[0]->sf;
    return nullptr;
}

// --- positions in results ---------------------------------------------------

inline void WritePosition(JsonOut &j, const TextIndex &t, size_t offset) {
    auto [line, character] = t.PositionOf(offset);
    j.BeginObject();
    j.Member("line", (int64_t)line);
    j.Member("character", (int64_t)character);
    j.EndObject();
}

inline void WriteRange(JsonOut &j, const TextIndex &t, size_t start, size_t end) {
    j.BeginObject();
    j.Key("start");
    WritePosition(j, t, start);
    j.Key("end");
    WritePosition(j, t, min(end, t.text.size()));
    j.EndObject();
}

inline void WriteLocation(JsonOut &j, const FileIndex &f, size_t start, size_t end) {
    j.BeginObject();
    j.Member("uri", f.uri);
    j.Key("range");
    WriteRange(j, f.text, start, end);
    j.EndObject();
}

// A declaration's name, as a place: the view the parser kept, else the
// declaration's own place.
struct Place {
    int fileidx = -1;
    size_t start = 0, len = 0;
    bool Known() const { return fileidx >= 0; }
};

inline Place PlaceOfLine(const Analysis &an, Line l, size_t len) {
    Place p;
    if (l.line <= 0 || l.fileidx < 0 || l.fileidx >= (int)an.files.size()) return p;
    auto off = an.files[(size_t)l.fileidx].text.OffsetOf(l.line, l.col);
    if (off < 0) return p;
    p.fileidx = l.fileidx;
    p.start = (size_t)off;
    p.len = len ? len : max<size_t>(an.files[(size_t)l.fileidx].text.NameLengthAt(p.start), 1);
    return p;
}

inline Place PlaceOfName(const Analysis &an, int fileidx, string_view name, Line fallback) {
    if (fileidx >= 0 && fileidx < (int)an.files.size()) {
        auto off = an.OffsetOfView(fileidx, name);
        if (off >= 0) return Place { fileidx, (size_t)off, name.size() };
    }
    return PlaceOfLine(an, fallback, 0);
}

inline Place PlaceOfFn(const Analysis &an, const SFunction *sf) {
    return PlaceOfName(an, sf->line.fileidx, sf->name, sf->line);
}
// A variable's declaration: its parameter, or the name in its `let` or
// `var`, else where the checker placed it (a loop's or an arm's binding).
inline Place PlaceOfVarDef(const Analysis &an, const VarDef *vd) {
    if (vd->isparam) return PlaceOfLine(an, vd->line, vd->name.size());
    if (auto decl = an.VarDeclOf(vd))
        for (auto &name : decl->names)
            if (name == vd->name) return PlaceOfName(an, decl->line.fileidx, name, decl->line);
    return PlaceOfLine(an, vd->line, 0);
}

inline void WritePlace(JsonOut &j, const Analysis &an, const Place &p) {
    auto &f = an.files[(size_t)p.fileidx];
    WriteLocation(j, f, p.start, p.start + p.len);
}

// --- hover ---------------------------------------------------------------------

struct HoverText {
    string header;      // Goose, in a code block.
    string doc;         // Markdown after it.
    string extra;       // More Goose, in a second code block.
};

inline HoverText HoverIdent(const Located &loc, const Occurrence &occ) {
    HoverText h;
    auto &an = *loc.an;
    auto &ast = *an.ast;
    auto id = Is<Ident>(occ.node);
    auto c = an.Find(occ.node, [](const Node *n) {
        auto x = Is<Ident>(n);
        return x && (x->vdef || x->fnref);
    });
    if (c) {
        auto ci = Is<Ident>(c);
        if (ci->vdef) {
            h.header = VarDefHeader(ci->vdef);
            if (auto vd = an.VarDeclOf(ci->vdef)) h.doc = DocText(vd->doc);
            auto types = an.TypesOf(occ.node, 4);
            if (types.size() > 1) {
                h.extra = "// in other instantiations:";
                for (auto t : types) Append(h.extra, "\n", ci->vdef->name, ": ", TypeText(t));
            }
        } else {
            h.header = FnHeader(ci->fnref);
            h.doc = DocText(ci->fnref->doc);
        }
        return h;
    }
    if (occ.callee) {
        auto call = ResolvedCall(loc, occ);
        if (auto sf = CalleeOf(call)) {
            h.header = FnHeader(sf);
            h.doc = DocText(sf->doc);
            h.extra = SpecsText(sf, 4);
            return h;
        }
        if (call && call->builtin >= 0) {
            auto &b = builtindefs[call->builtin];
            h.header = cat("builtin ", b.name, "(", b.minargs == b.maxargs ? to_string(b.minargs)
                                                  : cat(b.minargs, "..", b.maxargs), " arguments)");
            if (call->exprtype && call->exprtype->kind != TY_VOID)
                Append(h.header, " -> ", TypeText(call->exprtype));
            return h;
        }
        if (call && call->fvbody) {
            h.header = cat("function value ", id->name);
            return h;
        }
    }
    if (auto en = ast.LookupEnum(id->name, id->ns)) {
        h.header = cat("enum ", en->qname, GenericsText(en->generics));
        h.doc = DocText(en->doc);
        return h;
    }
    if (auto st = ast.LookupStruct(id->name, id->ns)) {
        h.header = cat("struct ", st->qname, GenericsText(st->generics));
        h.doc = DocText(st->doc);
        return h;
    }
    auto &fns = ast.LookupFunctions(id->name, id->ns);
    if (!fns.empty()) {
        for (auto sf : fns) Append(h.header, h.header.empty() ? "" : "\n", FnHeader(sf));
        h.doc = DocText(fns[0]->doc);
        return h;
    }
    if (auto b = LookupBuiltin(GlobalLeaf(id->name))) {
        h.header = cat("builtin ", b->name);
        return h;
    }
    h.header = string(id->name);
    h.doc = "Not checked: no instantiation reaches this code.";
    return h;
}

inline HoverText HoverDot(const Located &loc, const Occurrence &occ) {
    HoverText h;
    auto &an = *loc.an;
    auto &ast = *an.ast;
    auto d = Is<Dot>(occ.node);
    auto c = an.Find(occ.node, [](const Node *n) {
        auto x = Is<Dot>(n);
        return x && (x->fieldidx >= 0 || x->member >= 0 || x->variantconst);
    });
    if (c) {
        auto cd = Is<Dot>(c);
        if (cd->variantconst) {
            h.header = VariantHeader(EnumOfVariant(ast, cd->variantconst), cd->variantconst);
            h.doc = DocText(cd->variantconst->doc);
        } else if (cd->member >= 0) {
            h.header = cat("builtin .", builtindefs[cd->member].name);
            if (cd->exprtype && cd->exprtype->kind != TY_VOID) Append(h.header, ": ", TypeText(cd->exprtype));
        } else {
            auto f = FieldOfDot(cd);
            h.header = cat(f && f->isconst ? "let " : "", cd->name, ": ", TypeText(cd->exprtype));
            if (f) h.doc = DocText(f->doc);
        }
        return h;
    }
    if (occ.callee) {
        auto call = ResolvedCall(loc, occ);
        if (auto sf = CalleeOf(call)) {
            h.header = FnHeader(sf);
            h.doc = DocText(sf->doc);
            h.extra = SpecsText(sf, 4);
            return h;
        }
        if (call && call->builtin >= 0) {
            h.header = cat("builtin .", builtindefs[call->builtin].name);
            if (call->exprtype && call->exprtype->kind != TY_VOID)
                Append(h.header, " -> ", TypeText(call->exprtype));
            return h;
        }
    }
    auto &fns = ast.LookupFunctions(d->name, d->ns);
    if (occ.callee && !fns.empty()) {
        for (auto sf : fns) Append(h.header, h.header.empty() ? "" : "\n", FnHeader(sf));
        h.doc = DocText(fns[0]->doc);
        return h;
    }
    h.header = cat(".", d->name);
    h.doc = "Not checked: no instantiation reaches this code.";
    return h;
}

// A type name: its declaration, and the type as written where that
// says more (a generic's arguments).
inline HoverText HoverType(const Located &loc, const Occurrence &occ) {
    HoverText h;
    auto t = occ.type;
    auto written = TypeText(t);
    switch (t->kind) {
        case TY_STRUCT:
            h.header = cat("struct ", t->struc->st->qname, GenericsText(t->struc->st->generics));
            h.doc = DocText(t->struc->st->doc);
            if (!t->struc->st->generics.empty()) h.extra = written;
            break;
        case TY_ENUM:
            h.header = cat("enum ", t->enu->en->qname, GenericsText(t->enu->en->generics));
            h.doc = DocText(t->enu->en->doc);
            if (!t->enu->en->generics.empty()) h.extra = written;
            break;
        case TY_VARIANT:
            if (t->var->variant) {
                h.header = VariantHeader(EnumOfVariant(*loc.an->ast, t->var->variant), t->var->variant);
                h.doc = DocText(t->var->variant->doc);
            } else {
                h.header = written;
            }
            break;
        case TY_GENERIC:
            h.header = cat("type parameter ", written);
            break;
        default:
            h.header = written;
            break;
    }
    return h;
}

inline HoverText HoverOf(const Located &loc, const Occurrence &occ) {
    HoverText h;
    auto &an = *loc.an;
    switch (occ.kind) {
        case Occurrence::FN:
            h.header = FnHeader(occ.sf);
            h.doc = DocText(occ.sf->doc);
            h.extra = SpecsText(occ.sf, 4);
            break;
        case Occurrence::STRUCT:
            h.header = cat("struct ", occ.st->qname, GenericsText(occ.st->generics));
            h.doc = DocText(occ.st->doc);
            break;
        case Occurrence::ENUM:
            h.header = cat("enum ", occ.en->qname, GenericsText(occ.en->generics));
            h.doc = DocText(occ.en->doc);
            break;
        case Occurrence::ALIAS:
            h.header = cat("type ", occ.al->qname, " = ", TypeText(occ.al->type));
            h.doc = DocText(occ.al->doc);
            break;
        case Occurrence::GLOBAL: case Occurrence::LOCAL: {
            auto vd = Is<VarDecl>(occ.node);
            auto i = (size_t)occ.index;
            // A global is checked as written; a local in the body's clones.
            auto c = an.Find(occ.node, [i](const Node *n) {
                auto x = Is<VarDecl>(n);
                return x && x->defs.size() > i && x->defs[i] && x->defs[i]->type;
            });
            auto def = c ? Is<VarDecl>(c)->defs[i] : nullptr;
            h.header = cat(vd->isconst ? "const " : vd->isvar ? "var " : "let ", vd->names[i], ": ",
                           def ? TypeText(def->type) : vd->type ? TypeText(vd->type) : string("?"));
            h.doc = DocText(vd->doc);
            break;
        }
        case Occurrence::FIELD:
            h.header = cat(occ.field->isconst ? "let " : "", occ.field->name, ": ", TypeText(occ.field->type));
            h.doc = DocText(occ.field->doc);
            break;
        case Occurrence::VARIANT:
            h.header = VariantHeader(occ.en, occ.variant);
            h.doc = DocText(occ.variant->doc);
            break;
        case Occurrence::PARAM: {
            auto &p = *occ.param;
            h.header = cat("parameter ", p.isvar ? "var " : "", p.name);
            if (p.type) {
                Append(h.header, ": ", TypeText(p.type));
            } else {
                // Untyped: what the specializations gave it.
                auto idx = (size_t)(occ.param - occ.sf->params.data());
                set<string> seen;
                for (auto sp : occ.sf->specs) {
                    if (sp->isfunval || idx >= sp->argtypes.size()) continue;
                    auto s = TypeText(sp->argtypes[idx]);
                    if (seen.insert(s).second && seen.size() <= 4) Append(h.extra, h.extra.empty() ? "" : "\n", p.name, ": ", s);
                }
                if (seen.empty()) h.doc = "Not checked: no instantiation reaches this code.";
            }
            break;
        }
        case Occurrence::GENERIC:
            h.header = cat("type parameter ", occ.generic->name);
            if (occ.generic->bound) Append(h.header, ": ", TypeText(occ.generic->bound));
            break;
        case Occurrence::BINDER: {
            h.header = string(occ.name);
            TypeExpr *type = nullptr;
            if (auto fl = Is<ForLoop>(occ.node)) {
                auto c = an.Find(occ.node, [&](const Node *n) {
                    auto x = Is<ForLoop>(n);
                    return x && (occ.index ? x->idxdef : x->vdef);
                });
                if (c) type = occ.index ? Is<ForLoop>(c)->idxdef->type : Is<ForLoop>(c)->vdef->type;
                (void)fl;
            } else if (Is<MatchExpr>(occ.node)) {
                auto c = an.Find(occ.node, [&](const Node *n) {
                    auto x = Is<MatchExpr>(n);
                    return x && (size_t)occ.index < x->arms.size() && x->arms[(size_t)occ.index].binder;
                });
                if (c) type = Is<MatchExpr>(c)->arms[(size_t)occ.index].binder->type;
            }
            if (type) Append(h.header, ": ", TypeText(type));
            break;
        }
        case Occurrence::IDENT: return HoverIdent(loc, occ);
        case Occurrence::DOT:   return HoverDot(loc, occ);
        case Occurrence::TYPE:  return HoverType(loc, occ);
    }
    return h;
}

inline bool Hover(Workspace &ws, const Json &params, JsonOut &j) {
    Located loc;
    if (!Locate(ws, params, loc)) return false;
    auto occ = loc.fi->At(loc.offset);
    if (!occ) return false;
    auto h = HoverOf(loc, *occ);
    if (h.header.empty()) return false;
    auto value = cat("```goose\n", h.header, "\n```");
    if (!h.extra.empty()) Append(value, "\n```goose\n", h.extra, "\n```");
    if (!h.doc.empty()) Append(value, "\n\n", h.doc);
    j.BeginObject();
    j.Key("contents");
    j.BeginObject();
    j.Member("kind", "markdown");
    j.Member("value", value);
    j.EndObject();
    j.Key("range");
    WriteRange(j, loc.fi->text, occ->start, occ->start + occ->len);
    j.EndObject();
    return true;
}

// --- go to definition ------------------------------------------------------------

inline Place DefinitionOf(const Located &loc, const Occurrence &occ) {
    auto &an = *loc.an;
    auto &ast = *an.ast;
    switch (occ.kind) {
        case Occurrence::FN:      return PlaceOfFn(an, occ.sf);
        case Occurrence::STRUCT:  return PlaceOfName(an, occ.st->line.fileidx, occ.st->name, occ.st->line);
        case Occurrence::ENUM:    return PlaceOfName(an, occ.en->line.fileidx, occ.en->name, occ.en->line);
        case Occurrence::ALIAS:   return PlaceOfName(an, occ.al->line.fileidx, occ.al->name, occ.al->line);
        case Occurrence::FIELD:   return PlaceOfLine(an, occ.field->line, occ.field->name.size());
        case Occurrence::VARIANT: return PlaceOfLine(an, occ.variant->line, occ.variant->name.size());
        case Occurrence::PARAM:   return PlaceOfLine(an, occ.param->line, occ.param->name.size());
        case Occurrence::GENERIC: return PlaceOfLine(an, occ.generic->line, occ.generic->name.size());
        case Occurrence::GLOBAL: case Occurrence::LOCAL: case Occurrence::BINDER:
            return Place { loc.fi->fileidx, occ.start, occ.len };
        case Occurrence::IDENT: {
            auto id = Is<Ident>(occ.node);
            auto c = an.Find(occ.node, [](const Node *n) {
                auto x = Is<Ident>(n);
                return x && (x->vdef || x->fnref);
            });
            if (c) {
                auto ci = Is<Ident>(c);
                return ci->vdef ? PlaceOfVarDef(an, ci->vdef) : PlaceOfFn(an, ci->fnref);
            }
            if (occ.callee)
                if (auto sf = CalleeOf(ResolvedCall(loc, occ))) return PlaceOfFn(an, sf);
            if (auto en = ast.LookupEnum(id->name, id->ns))
                return PlaceOfName(an, en->line.fileidx, en->name, en->line);
            if (auto st = ast.LookupStruct(id->name, id->ns))
                return PlaceOfName(an, st->line.fileidx, st->name, st->line);
            auto &fns = ast.LookupFunctions(id->name, id->ns);
            if (!fns.empty()) return PlaceOfFn(an, fns[0]);
            return {};
        }
        case Occurrence::DOT: {
            auto d = Is<Dot>(occ.node);
            auto c = an.Find(occ.node, [](const Node *n) {
                auto x = Is<Dot>(n);
                return x && (x->fieldidx >= 0 || x->variantconst);
            });
            if (c) {
                auto cd = Is<Dot>(c);
                if (cd->variantconst) return PlaceOfLine(an, cd->variantconst->line, cd->variantconst->name.size());
                if (auto f = FieldOfDot(cd)) return PlaceOfLine(an, f->line, f->name.size());
            }
            if (occ.callee)
                if (auto sf = CalleeOf(ResolvedCall(loc, occ))) return PlaceOfFn(an, sf);
            auto &fns = ast.LookupFunctions(d->name, d->ns);
            if (occ.callee && !fns.empty()) return PlaceOfFn(an, fns[0]);
            return {};
        }
        case Occurrence::TYPE: {
            auto t = occ.type;
            switch (t->kind) {
                case TY_STRUCT:  return PlaceOfName(an, t->struc->st->line.fileidx, t->struc->st->name, t->struc->st->line);
                case TY_ENUM:    return PlaceOfName(an, t->enu->en->line.fileidx, t->enu->en->name, t->enu->en->line);
                case TY_VARIANT: return t->var->variant ? PlaceOfLine(an, t->var->variant->line, t->var->variant->name.size()) : Place {};
                default:         return {};
            }
        }
    }
    return {};
}

inline bool Definition(Workspace &ws, const Json &params, JsonOut &j) {
    Located loc;
    if (!Locate(ws, params, loc)) return false;
    auto &an = *loc.an;
    if (auto occ = loc.fi->At(loc.offset)) {
        auto p = DefinitionOf(loc, *occ);
        if (!p.Known()) return false;
        WritePlace(j, an, p);
        return true;
    }
    // On an import: the file it imports.
    for (auto &imp : an.ast->imports) {
        if (imp.line.fileidx != loc.fi->fileidx) continue;
        auto start = loc.fi->text.OffsetOf(imp.line.line, imp.line.col);
        auto end = imp.end.line > 0 ? loc.fi->text.OffsetOf(imp.end.line, imp.end.col) : start;
        if (start < 0 || (int64_t)loc.offset < start || (int64_t)loc.offset > end) continue;
        auto f = an.FileOf(PathKey(imp.path));
        j.BeginObject();
        j.Member("uri", f >= 0 ? an.files[(size_t)f].uri : UriOfPath(CanonicalPath(imp.path)));
        j.Key("range");
        j.Raw("{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":0,\"character\":0}}");
        j.EndObject();
        return true;
    }
    return false;
}

// --- symbols ------------------------------------------------------------------------

// LSP SymbolKind.
enum SymbolKind {
    SK_NAMESPACE = 3, SK_CLASS = 5, SK_FIELD = 8, SK_ENUM = 10, SK_FUNCTION = 12, SK_VARIABLE = 13,
    SK_CONSTANT = 14, SK_STRUCT = 23, SK_ENUMMEMBER = 22, SK_TYPEPARAMETER = 26
};

// The extent of a declaration node, from its anchor to its end.
inline pair<size_t, size_t> ExtentOf(const FileIndex &f, const Node *n) {
    auto start = f.text.OffsetOf(n->line.line, n->line.col);
    auto end = n->end.line > 0 ? f.text.OffsetOf(n->end.line, n->end.col) : start;
    if (start < 0) start = 0;
    if (end < start) end = start;
    return { (size_t)start, (size_t)end };
}

inline void WriteDocumentSymbol(JsonOut &j, const FileIndex &f, string_view name, int kind,
                                pair<size_t, size_t> extent, Place sel,
                                const function<void()> &children = {}) {
    j.BeginObject();
    j.Member("name", name);
    j.Member("kind", (int64_t)kind);
    j.Key("range");
    WriteRange(j, f.text, extent.first, extent.second);
    j.Key("selectionRange");
    if (sel.Known() && sel.fileidx == f.fileidx) WriteRange(j, f.text, sel.start, sel.start + sel.len);
    else WriteRange(j, f.text, extent.first, extent.first);
    if (children) {
        j.Key("children");
        j.BeginArray();
        children();
        j.EndArray();
    }
    j.EndObject();
}

// A function's symbol, with the functions declared in its body as children.
inline void WriteFnSymbol(JsonOut &j, const Analysis &an, const FileIndex &f, const FnDecl *fd) {
    auto sf = fd->sf;
    WriteDocumentSymbol(j, f, sf->name, SK_FUNCTION, ExtentOf(f, fd), PlaceOfFn(an, sf), [&] {
        function<void(const Node *)> nested = [&](const Node *n) {
            if (!n) return;
            if (auto inner = Is<FnDecl>(n)) {
                WriteFnSymbol(j, an, f, inner);
                return;
            }
            n->Children([&](Node *ch) { nested(ch); });
        };
        if (sf->body) nested(sf->body);
    });
}

inline bool DocumentSymbols(Workspace &ws, const Json &params, JsonOut &j) {
    Located loc;
    if (!Locate(ws, params, loc, false)) return false;
    auto &an = *loc.an;
    auto &f = *loc.fi;
    j.BeginArray();
    for (auto d : an.ast->topdecls) {
        if (d->line.fileidx != f.fileidx) continue;
        if (auto fd = Is<FnDecl>(d)) {
            WriteFnSymbol(j, an, f, fd);
        } else if (auto sd = Is<StructDecl>(d)) {
            auto st = sd->st;
            WriteDocumentSymbol(j, f, st->name, SK_STRUCT, ExtentOf(f, d),
                                PlaceOfName(an, st->line.fileidx, st->name, st->line), [&] {
                for (auto &fld : st->fields) {
                    if (fld.ispad) continue;
                    auto p = PlaceOfLine(an, fld.line, fld.name.size());
                    WriteDocumentSymbol(j, f, fld.name, SK_FIELD, { p.start, p.start + p.len }, p);
                }
            });
        } else if (auto ed = Is<EnumDecl>(d)) {
            auto en = ed->en;
            WriteDocumentSymbol(j, f, en->name, SK_ENUM, ExtentOf(f, d),
                                PlaceOfName(an, en->line.fileidx, en->name, en->line), [&] {
                for (auto &v : en->variants) {
                    auto p = PlaceOfLine(an, v.line, v.name.size());
                    WriteDocumentSymbol(j, f, v.name, SK_ENUMMEMBER, { p.start, p.start + p.len }, p);
                }
            });
        } else if (auto ad = Is<AliasDecl>(d)) {
            auto al = ad->al;
            WriteDocumentSymbol(j, f, al->name, SK_TYPEPARAMETER, ExtentOf(f, d),
                                PlaceOfName(an, al->line.fileidx, al->name, al->line));
        } else if (auto vd = Is<VarDecl>(d)) {
            for (auto &name : vd->names)
                WriteDocumentSymbol(j, f, name, vd->isvar ? SK_VARIABLE : SK_CONSTANT, ExtentOf(f, d),
                                    PlaceOfName(an, d->line.fileidx, name, d->line));
        }
    }
    j.EndArray();
    return true;
}

inline bool WorkspaceSymbols(Workspace &ws, const Json &params, JsonOut &j) {
    auto query = JsonStr(params.Get("query"));
    for (auto &c : query) c = (char)tolower((uint8_t)c);
    auto matches = [&](string_view name) {
        if (query.empty()) return true;
        string lower(name);
        for (auto &c : lower) c = (char)tolower((uint8_t)c);
        return lower.find(query) != string::npos;
    };
    set<pair<string, size_t>> seen;
    size_t count = 0;
    j.BeginArray();
    auto write = [&](const Analysis &an, string_view name, string_view ns, int kind, Place p) {
        if (!p.Known() || !matches(name) || count >= 1000) return;
        auto &f = an.files[(size_t)p.fileidx];
        if (!seen.insert({ f.uri, p.start }).second) return;
        count++;
        j.BeginObject();
        j.Member("name", name);
        j.Member("kind", (int64_t)kind);
        if (!ns.empty()) j.Member("containerName", ns);
        j.Key("location");
        WriteLocation(j, f, p.start, p.start + p.len);
        j.EndObject();
    };
    for (auto &r : ws.roots) {
        if (!r->analysis) continue;
        auto &an = *r->analysis;
        auto &ast = *an.ast;
        for (auto sf : ast.functions)
            if (!sf->isnested) write(an, sf->name, sf->ns, SK_FUNCTION, PlaceOfFn(an, sf));
        for (auto st : ast.structs)
            write(an, st->name, st->ns, SK_STRUCT, PlaceOfName(an, st->line.fileidx, st->name, st->line));
        for (auto en : ast.enums)
            write(an, en->name, en->ns, SK_ENUM, PlaceOfName(an, en->line.fileidx, en->name, en->line));
        for (auto al : ast.aliases)
            write(an, al->name, al->ns, SK_TYPEPARAMETER, PlaceOfName(an, al->line.fileidx, al->name, al->line));
        for (auto g : ast.globals)
            for (auto &name : g->names)
                write(an, name, g->ns, g->isvar ? SK_VARIABLE : SK_CONSTANT,
                      PlaceOfName(an, g->line.fileidx, name, g->line));
    }
    j.EndArray();
    return true;
}

// --- semantic tokens ------------------------------------------------------------------

// The legend the server declares: token types by index, modifiers by bit.
inline const char *const SEMANTIC_TYPES[] = {
    "namespace", "type", "struct", "enum", "enumMember", "typeParameter", "parameter", "variable",
    "property", "function", "method"
};
enum SemanticType {
    ST_NAMESPACE, ST_TYPE, ST_STRUCT, ST_ENUM, ST_ENUMMEMBER, ST_TYPEPARAMETER, ST_PARAMETER,
    ST_VARIABLE, ST_PROPERTY, ST_FUNCTION, ST_METHOD
};
inline const char *const SEMANTIC_MODIFIERS[] = { "declaration", "readonly", "defaultLibrary" };
enum SemanticModifier { SM_DECLARATION = 1, SM_READONLY = 2, SM_DEFAULTLIBRARY = 4 };

// The token an occurrence is, or -1 for none.
inline int SemanticTokenOf(const Located &loc, const Occurrence &occ, int &modifiers) {
    auto &an = *loc.an;
    auto &ast = *an.ast;
    modifiers = 0;
    auto readonly = [&](bool isvar) { return isvar ? 0 : SM_READONLY; };
    switch (occ.kind) {
        case Occurrence::FN:      modifiers = SM_DECLARATION; return ST_FUNCTION;
        case Occurrence::STRUCT:  modifiers = SM_DECLARATION; return ST_STRUCT;
        case Occurrence::ENUM:    modifiers = SM_DECLARATION; return ST_ENUM;
        case Occurrence::ALIAS:   modifiers = SM_DECLARATION; return ST_TYPE;
        case Occurrence::VARIANT: modifiers = SM_DECLARATION; return ST_ENUMMEMBER;
        case Occurrence::GENERIC: modifiers = SM_DECLARATION; return ST_TYPEPARAMETER;
        case Occurrence::FIELD:   modifiers = SM_DECLARATION | readonly(occ.isvar); return ST_PROPERTY;
        case Occurrence::PARAM:   modifiers = SM_DECLARATION | readonly(occ.isvar); return ST_PARAMETER;
        case Occurrence::GLOBAL: case Occurrence::LOCAL: case Occurrence::BINDER:
            modifiers = SM_DECLARATION | readonly(occ.isvar);
            return ST_VARIABLE;
        case Occurrence::TYPE:
            switch (occ.type->kind) {
                case TY_STRUCT:  return ST_STRUCT;
                case TY_ENUM:    return ST_ENUM;
                case TY_VARIANT: return ST_ENUMMEMBER;
                case TY_GENERIC: return ST_TYPEPARAMETER;
                default:         return -1;
            }
        case Occurrence::IDENT: {
            auto id = Is<Ident>(occ.node);
            auto c = an.Find(occ.node, [](const Node *n) {
                auto x = Is<Ident>(n);
                return x && (x->vdef || x->fnref);
            });
            if (c) {
                auto ci = Is<Ident>(c);
                if (ci->fnref) return ST_FUNCTION;
                modifiers = readonly(ci->vdef->isvar);
                return ci->vdef->isparam ? ST_PARAMETER : ST_VARIABLE;
            }
            if (occ.callee) {
                auto call = ResolvedCall(loc, occ);
                if (call && call->fvbody) return ST_VARIABLE;
                return ST_FUNCTION;
            }
            if (ast.LookupEnum(id->name, id->ns)) return ST_ENUM;
            if (ast.LookupStruct(id->name, id->ns)) return ST_STRUCT;
            return -1;
        }
        case Occurrence::DOT: {
            auto c = an.Find(occ.node, [](const Node *n) {
                auto x = Is<Dot>(n);
                return x && (x->fieldidx >= 0 || x->member >= 0 || x->variantconst);
            });
            if (c) {
                auto cd = Is<Dot>(c);
                if (cd->variantconst) return ST_ENUMMEMBER;
                if (cd->member >= 0) return occ.callee ? ST_METHOD : ST_PROPERTY;
                return ST_PROPERTY;
            }
            return occ.callee ? ST_METHOD : ST_PROPERTY;
        }
    }
    return -1;
}

inline bool SemanticTokens(Workspace &ws, const Json &params, JsonOut &j) {
    Located loc;
    if (!Locate(ws, params, loc, false)) return false;
    auto &f = *loc.fi;
    j.BeginObject();
    j.Key("data");
    j.BeginArray();
    int64_t lastline = 0, lastchar = 0;
    for (auto &occ : f.occs) {
        int modifiers;
        auto type = SemanticTokenOf(loc, occ, modifiers);
        if (type < 0) continue;
        auto [line, character] = f.text.PositionOf(occ.start);
        auto ltext = f.text.LineText(line);
        auto startbyte = occ.start - f.text.linestarts[(size_t)line];
        auto length = Utf16Col(ltext, startbyte + occ.len) - character;
        if (length <= 0) continue;
        j.Int(line - lastline);
        j.Int(line == lastline ? character - lastchar : character);
        j.Int(length);
        j.Int(type);
        j.Int(modifiers);
        lastline = line;
        lastchar = character;
    }
    j.EndArray();
    j.EndObject();
    return true;
}

// --- signature help --------------------------------------------------------------------

inline void WriteSignature(JsonOut &j, const SFunction *sf) {
    j.BeginObject();
    j.Member("label", FnHeader(sf));
    if (!sf->doc.empty()) {
        j.Key("documentation");
        j.BeginObject();
        j.Member("kind", "markdown");
        j.Member("value", DocText(sf->doc));
        j.EndObject();
    }
    j.Key("parameters");
    j.BeginArray();
    for (auto &p : sf->params) {
        j.BeginObject();
        auto label = string(p.name);
        if (p.type) Append(label, ": ", TypeText(p.type));
        j.Member("label", label);
        j.EndObject();
    }
    j.EndArray();
    j.EndObject();
}

inline bool SignatureHelp(Workspace &ws, const Json &params, JsonOut &j) {
    Located loc;
    if (!Locate(ws, params, loc)) return false;
    auto &an = *loc.an;
    auto &ast = *an.ast;
    auto &text = loc.fi->text.text;
    // The innermost call around the position whose arguments it is in.
    const CallSpan *span = nullptr;
    size_t paren = 0;
    for (auto &c : loc.fi->calls) {
        if (c.start > loc.offset) break;
        if (loc.offset > c.end) continue;
        auto p = text.find('(', c.start);
        if (p == string_view::npos || p >= loc.offset || p > c.end) continue;
        if (!span || c.start >= span->start) {
            span = &c;
            paren = p;
        }
    }
    if (!span) return false;
    // The active parameter: the commas at depth 0 before the position.
    auto active = 0;
    auto depth = 0;
    for (auto i = paren + 1; i < loc.offset && i < text.size(); i++) {
        auto c = text[i];
        if (c == '"') {
            for (i++; i < loc.offset && i < text.size() && text[i] != '"'; i++) if (text[i] == '\\') i++;
        } else if (c == '(' || c == '[' || c == '{') {
            depth++;
        } else if (c == ')' || c == ']' || c == '}') {
            depth--;
        } else if (c == ',' && depth == 0) {
            active++;
        }
    }
    string_view name, ns;
    auto ufcs = false;
    if (auto id = Is<Ident>(span->call->callee)) {
        name = id->name;
        ns = id->ns;
    } else if (auto d = Is<Dot>(span->call->callee)) {
        name = d->name;
        ns = d->ns;
        ufcs = true;
    } else {
        return false;
    }
    auto &fns = ast.LookupFunctions(name, ns);
    auto b = fns.empty() ? LookupBuiltin(GlobalLeaf(name)) : nullptr;
    if (fns.empty() && !b) return false;
    auto resolved = an.Find(span->call, [](const Node *n) {
        auto x = Is<Call>(n);
        return x && x->spec;
    });
    auto activesig = 0;
    if (resolved)
        for (size_t i = 0; i < fns.size(); i++)
            if (fns[i] == Is<Call>(resolved)->spec->sf) activesig = (int)i;
    j.BeginObject();
    j.Key("signatures");
    j.BeginArray();
    for (auto sf : fns) WriteSignature(j, sf);
    if (b) {
        j.BeginObject();
        j.Member("label", cat(b->name, "(", b->minargs == b->maxargs ? to_string(b->minargs)
                                             : cat(b->minargs, "..", b->maxargs), " arguments)"));
        j.Key("parameters");
        j.BeginArray();
        j.EndArray();
        j.EndObject();
    }
    j.EndArray();
    j.Member("activeSignature", (int64_t)activesig);
    j.Member("activeParameter", (int64_t)(active + (ufcs ? 1 : 0)));
    j.EndObject();
    return true;
}

}  // namespace goose
