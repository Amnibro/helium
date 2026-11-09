function sdlgpu(R) {
  const N = Number, td = new TextDecoder(), te = new TextEncoder(), O = new Map(), u8 = R.u8, dv = R.dv, RING = 1 << 20, files = R.files;
  let nid = 1, dev = null, info = null, err = '', spage = 0, tring = 0, raf = 0, clip = '', textOn = false, focusW = null, inside = false, gx = 0, gy = 0, gb = 0, uev = 0x8000, nfail = 0;
  const evq = [], ring = [], waits = [], bgc = new Map(), sm = {}, bp = {};
  const nh = o => { const i = nid++; O.set(i, o); return BigInt(i); }, g = h => O.get(N(h)), del = h => { O.delete(N(h)); bgc.clear(); };
  const r32 = (p, o) => dv().getUint32(N(p) + o, true), s32 = (p, o) => dv().getInt32(N(p) + o, true), rf = (p, o) => dv().getFloat32(N(p) + o, true), r64 = (p, o) => N(dv().getBigUint64(N(p) + o, true));
  const w32 = (p, o, v) => dv().setInt32(N(p) + o, v, true), wf = (p, o, v) => dv().setFloat32(N(p) + o, v, true), w64 = (p, o, v) => dv().setBigUint64(N(p) + o, BigInt(v), true);
  const cs = p => { p = N(p); if (!p) return ''; const m = u8(); let e = p; while (m[e]) e++; return td.decode(m.subarray(p, e)); };
  const page = () => spage || (spage = R.mmap(65536));
  const cstr = (k, s, cap = 1024) => { const b = te.encode(s).subarray(0, cap - 1), p = page() + k; u8().set(b, p); u8()[p + b.length] = 0; return BigInt(p); };
  const fail = (m, r = 0n) => { err = m; return r; };
  const al = (n, a) => Math.ceil(n / a) * a;
  const F = {}; '2 r8unorm 1,3 rg8unorm 2,4 rgba8unorm 4,8 rgb10a2unorm 4,12 bgra8unorm 4,21 r8snorm 1,22 rg8snorm 2,23 rgba8snorm 4,27 r16float 2,28 rg16float 4,29 rgba16float 8,30 r32float 4,31 rg32float 8,32 rgba32float 16,33 rg11b10ufloat 4,34 r8uint 1,35 rg8uint 2,36 rgba8uint 4,37 r16uint 2,38 rg16uint 4,39 rgba16uint 8,40 r32uint 4,41 rg32uint 8,42 rgba32uint 16,43 r8sint 1,44 rg8sint 2,45 rgba8sint 4,46 r16sint 2,47 rg16sint 4,48 rgba16sint 8,49 r32sint 4,50 rg32sint 8,51 rgba32sint 16,52 rgba8unorm-srgb 4,53 bgra8unorm-srgb 4,58 depth16unorm 2,59 depth24plus 4,60 depth32float 4,61 depth24plus-stencil8 4,62 depth32float-stencil8 8'.split(',').forEach(s => { const [k, f, b] = s.split(' '); F[k] = [f, +b]; });
  const VF = [, 'sint32', 'sint32x2', 'sint32x3', 'sint32x4', 'uint32', 'uint32x2', 'uint32x3', 'uint32x4', 'float32', 'float32x2', 'float32x3', 'float32x4', 'sint8x2', 'sint8x4', 'uint8x2', 'uint8x4', 'snorm8x2', 'snorm8x4', 'unorm8x2', 'unorm8x4', 'sint16x2', 'sint16x4', 'uint16x2', 'uint16x4', 'snorm16x2', 'snorm16x4', 'unorm16x2', 'unorm16x4', 'float16x2', 'float16x4'];
  const CMP = [, 'never', 'less', 'equal', 'less-equal', 'greater', 'not-equal', 'greater-equal', 'always'], BF = [, 'zero', 'one', 'src', 'one-minus-src', 'dst', 'one-minus-dst', 'src-alpha', 'one-minus-src-alpha', 'dst-alpha', 'one-minus-dst-alpha', 'constant', 'one-minus-constant', 'src-alpha-saturated'], BO = [, 'add', 'subtract', 'reverse-subtract', 'min', 'max'];
  const dead = []; let live = 0;
  const TOPO = ['triangle-list', 'triangle-strip', 'line-list', 'line-strip', 'point-list'], DIM = ['2d', 'cube', '3d', '2d-array', 'cube-array'], SFMT = { 1: 'rgba32float', 2: 'rgba16float', 3: 'r32float', 4: 'rgba8unorm', 6: 'rg32float', 7: 'rg16float', 9: 'r16float', 32: 'rgba8uint', 33: 'r32uint' };
  const MS = n => n > 0 ? 4 : 1;
  const SC = ',,,,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,1,2,3,4,5,6,7,8,9,0,Return,Escape,Backspace,Tab,Space,-,=,[,],\\,#,;,\',`,{,.,/,CapsLock,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,PrintScreen,ScrollLock,Pause,Insert,Home,PageUp,Delete,End,PageDown,Right,Left,Down,Up,Numlock,Keypad /,Keypad *,Keypad -,Keypad +,Keypad Enter,Keypad 1,Keypad 2,Keypad 3,Keypad 4,Keypad 5,Keypad 6,Keypad 7,Keypad 8,Keypad 9,Keypad 0,Keypad .,NonUSBackslash,Application,Power,Keypad =,F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24'.split(',').map(s => s === '{' ? ',' : s);
  const SCX = { 224: 'Left Ctrl', 225: 'Left Shift', 226: 'Left Alt', 227: 'Left GUI', 228: 'Right Ctrl', 229: 'Right Shift', 230: 'Right Alt', 231: 'Right GUI' }; Object.entries(SCX).forEach(([k, v]) => SC[k] = v);
  const CODE = { Enter: 40, Escape: 41, Backspace: 42, Tab: 43, Space: 44, Minus: 45, Equal: 46, BracketLeft: 47, BracketRight: 48, Backslash: 49, Semicolon: 51, Quote: 52, Backquote: 53, Comma: 54, Period: 55, Slash: 56, CapsLock: 57, PrintScreen: 70, ScrollLock: 71, Pause: 72, Insert: 73, Home: 74, PageUp: 75, Delete: 76, End: 77, PageDown: 78, ArrowRight: 79, ArrowLeft: 80, ArrowDown: 81, ArrowUp: 82, NumLock: 83, NumpadDivide: 84, NumpadMultiply: 85, NumpadSubtract: 86, NumpadAdd: 87, NumpadEnter: 88, NumpadDecimal: 99, IntlBackslash: 100, ContextMenu: 101, NumpadEqual: 103, ControlLeft: 224, ShiftLeft: 225, AltLeft: 226, MetaLeft: 227, ControlRight: 228, ShiftRight: 229, AltRight: 230, MetaRight: 231 };
  const scOf = c => CODE[c] ?? (/^Key[A-Z]$/.test(c) ? c.charCodeAt(3) - 61 : /^Digit\d$/.test(c) ? (+c[5] + 9) % 10 + 30 : /^Numpad\d$/.test(c) ? (+c[6] + 9) % 10 + 89 : /^F\d+$/.test(c) ? (+c.slice(1) <= 12 ? 57 + +c.slice(1) : 91 + +c.slice(1)) : 0);
  const keyOf = sc => ({ 40: 13, 41: 27, 42: 8, 43: 9, 44: 32, 76: 127 })[sc] ?? (SC[sc]?.length === 1 ? SC[sc].toLowerCase().charCodeAt(0) : (sc | 0x40000000) >>> 0);
  const crcT = new Uint32Array(256).map((_, n) => { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1; return c >>> 0; });
  const png = (w, h, px) => {
    const rl = w * 4 + 1, raw = new Uint8Array(rl * h), nb = Math.max(1, Math.ceil(raw.length / 65535)), z = new Uint8Array(2 + raw.length + 5 * nb + 4); let o = 2, a = 1, b = 0;
    for (let y = 0; y < h; y++) raw.set(px.subarray(y * w * 4, (y + 1) * w * 4), y * rl + 1);
    z[0] = 0x78; z[1] = 1; for (let i = 0; i < nb; i++) { const s = raw.subarray(i * 65535, (i + 1) * 65535), n = s.length; z.set([i === nb - 1 ? 1 : 0, n & 255, n >> 8, ~n & 255, ~n >> 8 & 255], o); z.set(s, o + 5); o += 5 + n; }
    for (let i = 0; i < raw.length; i++) { a = (a + raw[i]) % 65521; b = (b + a) % 65521; } new DataView(z.buffer).setUint32(o, (b << 16 | a) >>> 0);
    const ch = (t, d) => { const c = new Uint8Array(12 + d.length), q = new DataView(c.buffer); q.setUint32(0, d.length); c.set(te.encode(t), 4); c.set(d, 8); let r = ~0; for (let i = 4; i < 8 + d.length; i++) r = crcT[(r ^ c[i]) & 255] ^ (r >>> 8); q.setUint32(8 + d.length, ~r >>> 0); return c; };
    const hd = new Uint8Array(13), q = new DataView(hd.buffer); q.setUint32(0, w); q.setUint32(4, h); hd.set([8, 6, 0, 0, 0], 8);
    const parts = [new Uint8Array([137, 80, 78, 71, 13, 10, 26, 10]), ch('IHDR', hd), ch('IDAT', z), ch('IEND', new Uint8Array(0))], out = new Uint8Array(parts.reduce((k, p) => k + p.length, 0)); let k = 0; for (const p of parts) { out.set(p, k); k += p.length; } return out;
  };
  const view = (t, dim, mip = 0, nm = t.mips, lay = 0, nl = dim === '2d-array' || dim === 'cube-array' ? t.layers : dim === 'cube' ? 6 : 1) => { const k = `${dim} ${mip} ${nm} ${lay} ${nl}`; let v = t.views.get(k); if (!v) t.views.set(k, v = t.g.createView({ dimension: dim, baseMipLevel: mip, mipLevelCount: nm, baseArrayLayer: dim === '3d' ? 0 : lay, arrayLayerCount: dim === '3d' ? 1 : nl, aspect: t.f.startsWith('depth') ? 'depth-only' : 'all' })); return v; };
  const att = (t, mip, lay) => t.d3 ? view(t, '3d', mip, 1) : view(t, '2d', mip, 1, lay, 1);
  const chunk = () => ring.pop() || { g: dev.createBuffer({ size: RING, usage: GPUBufferUsage.UNIFORM | GPUBufferUsage.COPY_DST }), cpu: new Uint8Array(RING), id: nid++, used: 0 };
  const cmd = () => ({ enc: dev.createCommandEncoder(), ub: [], cur: null, off: 0, push: [[], [], []], st: [], downs: [] });
  const stage = (c, n) => { const b = dev.createBuffer({ size: al(Math.max(n, 4), 4), usage: GPUBufferUsage.COPY_SRC | GPUBufferUsage.COPY_DST, mappedAtCreation: true }); c.st.push(b); return [b, new Uint8Array(b.getMappedRange())]; };
  const submit = c => {
    if (!dev || !c) return Promise.resolve();
    for (const k of c.ub) dev.queue.writeBuffer(k.g, 0, k.cpu, 0, al(k.used, 4));
    dev.queue.submit([c.enc.finish()]); ring.push(...c.ub); for (const b of c.st) b.destroy(); if (--live <= 0) { live = 0; for (const b of dead.splice(0)) b.destroy(); }
    for (const d of c.downs) d.p = d.buf.mapAsync(GPUMapMode.READ).then(() => { d.ok = 1; }, e => { d.ok = 2; err = String(e); });
    const p = Promise.all([dev.queue.onSubmittedWorkDone(), ...c.downs.map(d => d.p)]); waits.push(p); p.then(() => waits.splice(waits.indexOf(p), 1)); return p;
  };
  const blob = (p, n) => {
    const b = u8().slice(N(p), N(p) + N(n)), q = new DataView(b.buffer), u16 = i => q.getUint16(i, true), u32 = i => q.getUint32(i, true);
    if (td.decode(b.subarray(0, 4)) !== 'GSHD' || u16(4) !== 2) return null;
    const s = { stage: b[6], n: [20, 22, 24, 26, 28, 30].map(u16), wgsl: td.decode(b.subarray(u32(56), u32(56) + u32(60))), usz: [], binds: [], dims: {} }; let o = 68;
    for (let k = 0; k < s.n[5]; k++, o += 4) s.usz.push(u32(o));
    o += 2 * b[7]; for (let k = u16(64); k > 0; k--, o += 4) s.binds.push({ group: b[o], binding: b[o + 1], kind: b[o + 2], info: b[o + 3] });
    for (const [, gr, bi, d] of s.wgsl.matchAll(/@group\((\d+)\)\s*@binding\((\d+)\)\s*var\s*\w+\s*:\s*texture_storage_(2d_array|2d|3d)/g)) s.dims[gr + ' ' + bi] = d.replace('_', '-');
    s.nofilt = new Set([...s.wgsl.matchAll(/@group\((\d+)\)\s*@binding\((\d+)\)\s*var\s+(\w+)\s*:\s*texture_(?:2d|2d_array|3d|cube|cube_array)<f32>/g)].filter(([, , , v]) => !new RegExp(`\\b${v}\\s*,\\s*(${[...s.wgsl.matchAll(/(\w+)\s*:\s*sampler\b/g)].map(x => x[1]).join('|') || '\\B\\b'})\\b`).test(s.wgsl)).map(([, gr, bi]) => gr + ' ' + bi));
    return s;
  };
  const role = (b, sh, comp) => {
    const x = b.binding >> 1, [nsmp, nstro, nstrw] = sh.n;
    if (b.kind === 1) return ['u', b.info];
    if (comp && b.group === 1) return b.kind >= 9 ? ['rwt', x] : ['rwb', x - nstrw];
    return b.kind >= 4 && b.kind <= 8 ? ['smp', x] : b.kind >= 9 ? ['stx', x - nsmp] : ['sbuf', x - nsmp - nstro];
  };
  const layout = shs => {
    const G = [], vis = [GPUShaderStage.VERTEX, GPUShaderStage.FRAGMENT, GPUShaderStage.COMPUTE], comp = shs[0].stage === 2;
    for (const sh of shs) for (const b of sh.binds) {
      const k = b.kind, e = { binding: b.binding, visibility: vis[sh.stage] }, [src, slot] = role(b, sh, comp);
      if (k <= 3) e.buffer = { type: ['uniform', 'read-only-storage', 'storage'][k - 1], hasDynamicOffset: k === 1 }; else if (k <= 6) e.texture = { sampleType: k === 4 && sh.nofilt?.has(b.group + ' ' + b.binding) ? 'unfilterable-float' : ['float', 'uint', 'depth'][k - 4], viewDimension: DIM[b.info] }; else if (k <= 8) e.sampler = { type: k === 7 ? 'filtering' : 'comparison' }; else e.storageTexture = { access: ['write-only', 'read-only', 'read-write'][k - 9], format: SFMT[b.info], viewDimension: sh.dims[b.group + ' ' + b.binding] || '2d' };
      (G[b.group] ||= { ents: [], es: [] }).ents.push({ ...b, st: sh.stage, src, slot, size: k === 1 ? sh.usz[b.info] : 0, dim: e.texture?.viewDimension || e.storageTexture?.viewDimension }); G[b.group].es.push(e);
    }
    const n = G.length, gs = []; for (let i = 0; i < n; i++) { const x = G[i] || { ents: [], es: [] }; x.ents.sort((a, b) => a.binding - b.binding); x.es.sort((a, b) => a.binding - b.binding); x.lay = dev.createBindGroupLayout({ entries: x.es }); x.id = nid++; gs.push(x); }
    return { gs, pl: dev.createPipelineLayout({ bindGroupLayouts: gs.map(x => x.lay) }) };
  };
  const bind = pa => {
    const pl = pa.pipe; if (!pl) return false;
    for (let i = 0; i < pl.gs.length; i++) {
      const G = pl.gs[i], ents = [], dyn = []; let key = G.id + '', ok = true;
      for (const b of G.ents) {
        const S = pa.st[b.st], c = pa.c; let r;
        if (b.src === 'u') { const u = c.push[b.st][b.slot]; if (!u) { ok = false; break; } r = { buffer: u.k.g, offset: 0, size: b.size }; dyn.push(u.off); key += ' u' + u.k.id; }
        else if (b.src === 'smp') { const s = S.smp[b.slot]; if (!s) { ok = false; break; } r = b.kind <= 6 ? view(s.t, b.dim) : s.s.g; key += ' ' + s.t.id + ':' + s.s.id; }
        else if (b.src === 'stx' || b.src === 'rwt') { const t = S[b.src][b.slot]; if (!t) { ok = false; break; } r = t.v ? t.v(b.dim) : view(t, b.dim, 0, 1); key += ' t' + t.id; }
        else { const s = S[b.src][b.slot]; if (!s) { ok = false; break; } r = { buffer: s.g }; key += ' b' + s.id; }
        ents.push({ binding: b.binding, resource: r });
      }
      if (!ok) return !!fail('a draw or dispatch reads a resource that is not bound', 0);
      let bg = bgc.get(key); if (!bg) bgc.set(key, bg = dev.createBindGroup({ layout: G.lay, entries: ents }));
      if (pa.bk[i] !== key || dyn.length) { pa.e.setBindGroup(i, bg, dyn); pa.bk[i] = key; }
    }
    return true;
  };
  const tex = (u, f, ty, w, h, l, m, s) => {
    const [fmt, bs] = F[f] || [], ms = MS(s), us = (u & 1 ? GPUTextureUsage.TEXTURE_BINDING : 0) | (u & 6 ? GPUTextureUsage.RENDER_ATTACHMENT : 0) | (u & 120 ? GPUTextureUsage.STORAGE_BINDING : 0) | (ms > 1 ? 0 : GPUTextureUsage.COPY_SRC | GPUTextureUsage.COPY_DST);
    if (!fmt) return fail(`texture format ${f} has no WebGPU match`);
    return nh({ g: dev.createTexture({ size: [w, h, ty === 3 ? 6 : l], dimension: ty === 2 ? '3d' : '2d', format: fmt, mipLevelCount: m, sampleCount: ms, usage: us }), f: fmt, bs, w, h, layers: ty === 2 ? 1 : ty === 3 ? 6 : l, depth: ty === 2 ? l : 1, mips: m, d3: ty === 2, views: new Map(), id: nid++ });
  };
  const blitter = f => bp[f] || (bp[f] = (() => { const m = dev.createShaderModule({ code: 'struct V { @builtin(position) p: vec4f, @location(0) uv: vec2f }\n@group(0) @binding(0) var t: texture_2d<f32>;\n@group(0) @binding(1) var s: sampler;\n@group(0) @binding(2) var<uniform> r: vec4f;\n@vertex fn vs(@builtin(vertex_index) i: u32) -> V { let q = vec2f(f32(i & 1u) * 2.0, f32(i >> 1u) * 2.0); return V(vec4f(q.x * 2.0 - 1.0, 1.0 - q.y * 2.0, 0.0, 1.0), mix(r.xy, r.zw, q)); }\n@fragment fn fs(v: V) -> @location(0) vec4f { return textureSampleLevel(t, s, v.uv, 0.0); }' }); return dev.createRenderPipeline({ layout: 'auto', vertex: { module: m, entryPoint: 'vs' }, fragment: { module: m, entryPoint: 'fs', targets: [{ format: f }] }, primitive: { topology: 'triangle-list' } }); })());
  const blit = (c, s, smip, slay, sx, sy, sw, sh, d, dmip, dlay, dx, dy, dw, dh, lin, flip, load, clr) => {
    const p = blitter(d.f), mw = Math.max(1, s.w >> smip), mh = Math.max(1, s.h >> smip), r = [sx / mw, sy / mh, (sx + sw) / mw, (sy + sh) / mh], ub = dev.createBuffer({ size: 16, usage: GPUBufferUsage.UNIFORM, mappedAtCreation: true });
    if (flip & 1) [r[0], r[2]] = [r[2], r[0]]; if (flip & 2) [r[1], r[3]] = [r[3], r[1]];
    new Float32Array(ub.getMappedRange()).set(r); ub.unmap(); c.st.push(ub);
    const smp = sm[lin] || (sm[lin] = dev.createSampler({ minFilter: lin ? 'linear' : 'nearest', magFilter: lin ? 'linear' : 'nearest' })), dw0 = Math.max(1, d.w >> dmip), dh0 = Math.max(1, d.h >> dmip);
    const e = c.enc.beginRenderPass({ colorAttachments: [{ view: att(d, dmip, dlay), loadOp: load === 1 || load === 2 && !dx && !dy && dw === dw0 && dh === dh0 ? 'clear' : 'load', clearValue: clr, storeOp: 'store' }] });
    e.setPipeline(p); e.setBindGroup(0, dev.createBindGroup({ layout: p.getBindGroupLayout(0), entries: [{ binding: 0, resource: view(s, '2d', smip, 1, slay, 1) }, { binding: 1, resource: smp }, { binding: 2, resource: { buffer: ub } }] })); e.setViewport(dx, dy, dw, dh, 0, 1); e.draw(3); e.end();
  };
  const win = h => g(h)?.cv ? g(h) : null;
  const ev = (t, wid = 1) => { const b = new Uint8Array(128), q = new DataView(b.buffer); q.setUint32(0, t, true); q.setBigUint64(8, BigInt(Math.round(performance.now() * 1e6)), true); q.setUint32(16, wid, true); evq.push(b); return q; };
  const fit = W => {
    const cv = W.cv, d = W.f & 8192 ? devicePixelRatio || 1 : 1, cw = cv.clientWidth || W.w, ch = cv.clientHeight || W.h, pw = Math.max(1, Math.round(cw * d)), ph = Math.max(1, Math.round(ch * d));
    if (cw !== W.w || ch !== W.h) { W.w = cw; W.h = ch; const q = ev(518); q.setInt32(20, cw, true); q.setInt32(24, ch, true); }
    if (pw !== cv.width || ph !== cv.height) { cv.width = pw; cv.height = ph; const q = ev(519); q.setInt32(20, pw, true); q.setInt32(24, ph, true); }
  };
  const listen = W => {
    const cv = W.cv, at = e => { const r = cv.getBoundingClientRect(); return [e.clientX - r.left, e.clientY - r.top]; }, mine = e => e.target === cv || e.target === document.body || e.target === document.documentElement;
    const L = [[cv, 'pointermove', e => { const [x, y] = at(e); gx = e.clientX; gy = e.clientY; if (e.pointerType === 'touch') { const q = ev(1794); finger(q, e, x, y); return; } const q = ev(1024); q.setUint32(24, e.buttons, true); q.setFloat32(28, x, true); q.setFloat32(32, y, true); q.setFloat32(36, e.movementX, true); q.setFloat32(40, e.movementY, true); }],
      [cv, 'pointerdown', e => { cv.focus?.(); const [x, y] = at(e); if (e.pointerType === 'touch') { finger(ev(1792), e, x, y); return; } gb |= 1 << e.button; const q = ev(1025); q.setUint8(24, [1, 2, 3, 4, 5][e.button] || 1); q.setUint8(25, 1); q.setUint8(26, e.detail || 1); q.setFloat32(28, x, true); q.setFloat32(32, y, true); }],
      [cv, 'pointerup', e => { const [x, y] = at(e); if (e.pointerType === 'touch') { finger(ev(1793), e, x, y); return; } gb &= ~(1 << e.button); const q = ev(1026); q.setUint8(24, [1, 2, 3, 4, 5][e.button] || 1); q.setUint8(26, e.detail || 1); q.setFloat32(28, x, true); q.setFloat32(32, y, true); }],
      [cv, 'pointercancel', e => { if (e.pointerType === 'touch') finger(ev(1795), e, ...at(e)); }],
      [cv, 'wheel', e => { e.preventDefault(); const k = e.deltaMode ? 1 : 0.01, [x, y] = at(e), q = ev(1027); q.setFloat32(24, -e.deltaX * k, true); q.setFloat32(28, -e.deltaY * k, true); q.setFloat32(36, x, true); q.setFloat32(40, y, true); }],
      [cv, 'pointerenter', () => { inside = true; ev(524); }], [cv, 'pointerleave', () => { inside = false; ev(525); }], [cv, 'contextmenu', e => e.preventDefault()],
      [window, 'focus', () => ev(526)], [window, 'blur', () => ev(527)], [document, 'paste', e => { clip = e.clipboardData?.getData('text') ?? clip; }],
      [window, 'keydown', e => { if (!mine(e)) return; const sc = scOf(e.code); if (sc) { e.preventDefault(); key(768, sc, e); } if (textOn && e.key.length === 1 && !e.ctrlKey && !e.metaKey) { const p = page() + 8192 + (tring++ & 31) * 256, b = te.encode(e.key).subarray(0, 255); u8().set(b, p); u8()[p + b.length] = 0; ev(771).setBigUint64(24, BigInt(p), true); } }],
      [window, 'keyup', e => { if (!mine(e)) return; const sc = scOf(e.code); if (sc) { e.preventDefault(); key(769, sc, e); } }]];
    if (R.input !== false) for (const [t, k, f] of L) t.addEventListener(k, f, { passive: k !== 'wheel' && k !== 'keydown' && k !== 'keyup' && k !== 'contextmenu' });
    W.off = () => { for (const [t, k, f] of L) t.removeEventListener(k, f); };
  };
  const key = (t, sc, e) => { const q = ev(t); q.setUint32(24, sc, true); q.setUint32(28, keyOf(sc), true); q.setUint16(32, (e.shiftKey ? 1 : 0) | (e.ctrlKey ? 0x40 : 0) | (e.altKey ? 0x100 : 0) | (e.metaKey ? 0x400 : 0), true); q.setUint8(36, t === 768 ? 1 : 0); q.setUint8(37, e.repeat ? 1 : 0); };
  const finger = (q, e, x, y) => { const W = focusW; q.setBigUint64(16, 1n, true); q.setBigUint64(24, BigInt(e.pointerId), true); q.setFloat32(32, x / (W?.w || 1), true); q.setFloat32(36, y / (W?.h || 1), true); q.setFloat32(48, e.pressure, true); q.setUint32(52, 1, true); };
  const nextFrame = () => new Promise(r => requestAnimationFrame(r));
  const env = {
    SDL_InitSubSystem: () => 1, SDL_QuitSubSystem: () => {}, SDL_SetHint: () => 1, SDL_ResetHint: () => 1, SDL_GetError: () => cstr(0, err), SDL_free: () => {},
    SDL_CreateGPUDevice: () => dev ? nh({ dev }) : fail('no WebGPU device: ' + (err || (navigator.gpu ? 'no adapter' : 'this browser has no WebGPU'))),
    SDL_GetGPUShaderFormats: () => 64, SDL_GetGPUDeviceDriver: () => cstr(1024, 'webgpu'), SDL_DestroyGPUDevice: h => del(h),
    SDL_GPUTextureSupportsFormat: (d, f, t, u) => F[f] && (!(u & 120) || /^(rgba8(unorm|snorm|uint|sint)|(rgba16|rgba32|r32|rg32)(float|uint|sint))$/.test(F[f][0])) && (!(u & 4) || F[f][0].startsWith('depth')) ? 1 : 0,
    SDL_GPUTextureFormatTexelBlockSize: f => F[f]?.[1] || 0,
    SDL_CreateGPUTexture: (d, p) => tex(r32(p, 8), s32(p, 4), s32(p, 0), r32(p, 12), r32(p, 16), r32(p, 20), r32(p, 24), s32(p, 28)),
    SDL_ReleaseGPUTexture: (d, h) => { const t = g(h); if (t && !t.sw) { dead.push(t.g); del(h); } },
    SDL_CreateGPUSampler: (d, p) => { const fl = ['nearest', 'linear'], A = ['repeat', 'mirror-repeat', 'clamp-to-edge'], mi = s32(p, 0), ma = s32(p, 4), mm = s32(p, 8), an = u8()[N(p) + 44] && mi && ma && mm ? Math.min(16, Math.max(1, Math.floor(rf(p, 28)))) : 1; return nh({ g: dev.createSampler({ minFilter: fl[mi], magFilter: fl[ma], mipmapFilter: fl[mm], addressModeU: A[s32(p, 12)], addressModeV: A[s32(p, 16)], addressModeW: A[s32(p, 20)], lodMinClamp: rf(p, 36), lodMaxClamp: rf(p, 40), compare: u8()[N(p) + 45] ? CMP[s32(p, 32)] : undefined, maxAnisotropy: an }), id: nid++ }); },
    SDL_ReleaseGPUSampler: (d, h) => del(h),
    SDL_CreateGPUBuffer: (d, p) => { const u = r32(p, 0), B = GPUBufferUsage; return nh({ g: dev.createBuffer({ size: al(r32(p, 4), 4), usage: (u & 1 ? B.VERTEX : 0) | (u & 2 ? B.INDEX : 0) | (u & 4 ? B.INDIRECT : 0) | (u & 56 ? B.STORAGE : 0) | B.COPY_SRC | B.COPY_DST }), id: nid++ }); },
    SDL_ReleaseGPUBuffer: (d, h) => { const t = g(h); if (t) dead.push(t.g); del(h); },
    SDL_CreateGPUTransferBuffer: (d, p) => { const n = r32(p, 4), a = R.mmap(n); return a < 0 ? fail('out of memory for a transfer buffer') : nh({ up: r32(p, 0) === 0, n, ptr: a, downs: [] }); },
    SDL_ReleaseGPUTransferBuffer: (d, h) => { const t = g(h); if (!t) return; R.munmap(t.ptr, t.n); for (const x of t.downs) x.buf.destroy(); O.delete(N(h)); },
    SDL_MapGPUTransferBuffer: (d, h) => { const t = g(h); if (!t) return 0n; t.downs = t.downs.filter(x => { if (x.ok !== 1) return true; const m = new Uint8Array(x.buf.getMappedRange()), o = u8(); for (let r = 0; r < x.rows; r++) o.set(m.subarray(r * x.ar, r * x.ar + x.row), t.ptr + x.off + r * x.prow); x.buf.unmap(); x.buf.destroy(); return false; }); return BigInt(t.ptr); },
    SDL_UnmapGPUTransferBuffer: () => {},
    SDL_AcquireGPUCommandBuffer: () => { if (!dev) return fail('gfx: no device'); live++; return nh(cmd()); },
    SDL_SubmitGPUCommandBuffer: c => { submit(g(c)); O.delete(N(c)); return 1; },
    SDL_SubmitGPUCommandBufferAndAcquireFence: c => { const f = { done: false }; f.p = submit(g(c)).then(() => { f.done = true; }); O.delete(N(c)); return nh(f); },
    SDL_CancelGPUCommandBuffer: c => { const C = g(c); if (C) { for (const b of C.st) b.destroy(); ring.push(...C.ub); live = Math.max(0, live - 1); } O.delete(N(c)); return 1; },
    SDL_WaitForGPUFences: (d, all, p, n) => { const fs = []; for (let i = 0; i < n; i++) { const f = g(r64(p, 8 * i)); if (f && !f.done) fs.push(f.p); } return fs.length && R.canWait() ? (all ? Promise.all(fs) : Promise.race(fs)).then(() => 1) : 1; },
    SDL_ReleaseGPUFence: (d, f) => { O.delete(N(f)); }, SDL_WaitForGPUIdle: () => R.canWait() && dev ? Promise.all([dev.queue.onSubmittedWorkDone(), ...waits]).then(() => 1) : 1,
    SDL_BeginGPUCopyPass: c => nh({ c: g(c) }), SDL_EndGPUCopyPass: p => { O.delete(N(p)); },
    SDL_UploadToGPUBuffer: (cp, s, d) => { const c = g(cp).c, t = g(r64(s, 0)), b = g(r64(d, 0)), n = r32(d, 12), [sb, m] = stage(c, n); m.set(u8().subarray(t.ptr + r32(s, 8), t.ptr + r32(s, 8) + n)); sb.unmap(); c.enc.copyBufferToBuffer(sb, 0, b.g, r32(d, 8), al(n, 4)); },
    SDL_DownloadFromGPUBuffer: (cp, s, d) => { const c = g(cp).c, b = g(r64(s, 0)), t = g(r64(d, 0)), n = r32(s, 12), rb = dev.createBuffer({ size: al(n, 4), usage: GPUBufferUsage.MAP_READ | GPUBufferUsage.COPY_DST }); c.enc.copyBufferToBuffer(b.g, r32(s, 8), rb, 0, al(n, 4)); const x = { buf: rb, off: r32(d, 8), row: n, ar: 0, rows: 1, prow: 0 }; t.downs.push(x); c.downs.push(x); },
    SDL_UploadToGPUTexture: (cp, s, d) => { const c = g(cp).c, t = g(r64(s, 0)), x = g(r64(d, 0)), w = r32(d, 28), h = r32(d, 32), dp = r32(d, 36), row = w * x.bs, ar = al(row, 256), prow = (r32(s, 12) || w) * x.bs, rows = h * dp, src = t.ptr + r32(s, 8), [sb, m] = stage(c, ar * rows), o = u8(); for (let r = 0; r < rows; r++) m.set(o.subarray(src + r * prow, src + r * prow + row), r * ar); sb.unmap(); c.enc.copyBufferToTexture({ buffer: sb, bytesPerRow: ar, rowsPerImage: h }, { texture: x.g, mipLevel: r32(d, 8), origin: [r32(d, 16), r32(d, 20), x.d3 ? r32(d, 24) : r32(d, 12)] }, [w, h, dp]); },
    SDL_DownloadFromGPUTexture: (cp, s, d) => { const c = g(cp).c, x = g(r64(s, 0)), t = g(r64(d, 0)), w = r32(s, 28), h = r32(s, 32), dp = r32(s, 36), row = w * x.bs, ar = al(row, 256), rb = dev.createBuffer({ size: ar * h * dp, usage: GPUBufferUsage.MAP_READ | GPUBufferUsage.COPY_DST }); c.enc.copyTextureToBuffer({ texture: x.g, mipLevel: r32(s, 8), origin: [r32(s, 16), r32(s, 20), x.d3 ? r32(s, 24) : r32(s, 12)] }, { buffer: rb, bytesPerRow: ar, rowsPerImage: h }, [w, h, dp]); const q = { buf: rb, off: r32(d, 8), row, ar, rows: h * dp, prow: (r32(d, 12) || w) * x.bs }; t.downs.push(q); c.downs.push(q); },
    SDL_CreateGPUShader: (d, p) => { if (r32(p, 24) !== 64) return fail('gfx on the web takes WGSL shaders (format 64)'); const s = blob(r64(p, 8), r64(p, 0)); if (!s) return fail('not a version 2 shader blob'); if (!s.wgsl) return fail('this shader has no WGSL (hc --wgsl on it names the reason)'); s.mod = dev.createShaderModule({ code: s.wgsl }); return nh(s); },
    SDL_ReleaseGPUShader: (d, h) => { O.delete(N(h)); },
    SDL_CreateGPUGraphicsPipeline: (d, p) => {
      const vs = g(r64(p, 0)), fs = g(r64(p, 8)), bufs = [], tg = [], L = layout([vs, fs]), m = u8(), q = N(p);
      for (let i = 0; i < r32(p, 24); i++) { const b = r64(p, 16) + 16 * i; bufs[r32(b, 0)] = { arrayStride: r32(b, 4), stepMode: s32(b, 8) ? 'instance' : 'vertex', attributes: [] }; }
      for (let i = 0; i < r32(p, 40); i++) { const a = r64(p, 32) + 16 * i; bufs[r32(a, 4)]?.attributes.push({ shaderLocation: r32(a, 0), format: VF[s32(a, 8)], offset: r32(a, 12) }); }
      for (let i = 0; i < r32(p, 144); i++) { const c = r64(p, 136) + 36 * i, eb = m[c + 29]; tg.push({ format: F[s32(c, 0)][0], writeMask: m[c + 30] ? m[c + 28] : 15, blend: eb ? { color: { srcFactor: BF[s32(c, 4)], dstFactor: BF[s32(c, 8)], operation: BO[s32(c, 12)] }, alpha: { srcFactor: BF[s32(c, 16)], dstFactor: BF[s32(c, 20)], operation: BO[s32(c, 24)] } } : undefined }); }
      for (let i = 0; i < bufs.length; i++) bufs[i] ||= null;
      const prim = s32(p, 48), ds = m[q + 152] ? { format: F[s32(p, 148)][0], depthWriteEnabled: !!m[q + 131], depthCompare: m[q + 130] ? CMP[s32(p, 92)] : 'always', depthBias: m[q + 76] ? Math.round(rf(p, 64)) : 0, depthBiasSlopeScale: m[q + 76] ? rf(p, 72) : 0, depthBiasClamp: m[q + 76] ? rf(p, 68) : 0 } : undefined;
      return nh({ g: dev.createRenderPipeline({ layout: L.pl, vertex: { module: vs.mod, entryPoint: 'main', buffers: bufs }, fragment: { module: fs.mod, entryPoint: 'main', targets: tg }, primitive: { topology: TOPO[prim], cullMode: ['none', 'front', 'back'][s32(p, 56)], frontFace: s32(p, 60) ? 'cw' : 'ccw', stripIndexFormat: prim === 1 || prim === 3 ? 'uint32' : undefined }, depthStencil: ds, multisample: { count: MS(s32(p, 80)), alphaToCoverageEnabled: !!m[q + 89] && MS(s32(p, 80)) > 1 } }), gs: L.gs });
    },
    SDL_ReleaseGPUGraphicsPipeline: (d, h) => del(h),
    SDL_CreateGPUComputePipeline: (d, p) => { if (r32(p, 24) !== 64) return fail('gfx on the web takes WGSL shaders (format 64)'); const s = blob(r64(p, 8), r64(p, 0)); if (!s || !s.wgsl) return fail('a compute shader with no WGSL'); const L = layout([s]); return nh({ g: dev.createComputePipeline({ layout: L.pl, compute: { module: dev.createShaderModule({ code: s.wgsl }), entryPoint: 'main' } }), gs: L.gs }); },
    SDL_ReleaseGPUComputePipeline: (d, h) => del(h),
    SDL_BeginGPURenderPass: (c, ct, n, dt) => {
      const C = g(c), ca = []; let w = 0, h = 0, ds;
      for (let i = 0; i < n; i++) { const p = N(ct) + 64 * i, t = g(r64(p, 0)), mip = r32(p, 8), lay = r32(p, 12), ld = s32(p, 32), so = s32(p, 36), rt = r64(p, 40); w = Math.max(1, t.w >> mip); h = Math.max(1, t.h >> mip); ca.push({ view: att(t, mip, lay), depthSlice: t.d3 ? lay : undefined, loadOp: ld === 0 ? 'load' : 'clear', clearValue: [rf(p, 16), rf(p, 20), rf(p, 24), rf(p, 28)], storeOp: so === 1 || so === 2 ? 'discard' : 'store', resolveTarget: rt ? att(g(rt), r32(p, 48), r32(p, 52)) : undefined }); }
      if (dt) { const p = N(dt), t = g(r64(p, 0)), m = u8(), mip = m[p + 30]; w = Math.max(1, t.w >> mip); h = Math.max(1, t.h >> mip); ds = { view: att(t, mip, m[p + 31]), depthClearValue: rf(p, 8), depthLoadOp: s32(p, 12) === 0 ? 'load' : 'clear', depthStoreOp: s32(p, 16) === 1 ? 'discard' : 'store', ...(t.f.includes('stencil') ? { stencilLoadOp: s32(p, 20) === 0 ? 'load' : 'clear', stencilStoreOp: s32(p, 24) === 1 ? 'discard' : 'store', stencilClearValue: m[p + 29] } : {}) }; }
      return nh({ c: C, e: C.enc.beginRenderPass({ colorAttachments: ca, depthStencilAttachment: ds }), w, h, bk: [], st: [0, 1, 2].map(() => ({ smp: [], stx: [], sbuf: [], rwt: [], rwb: [] })) });
    },
    SDL_EndGPURenderPass: p => { g(p)?.e.end(); O.delete(N(p)); },
    SDL_BeginGPUComputePass: (c, tp, nt, bp, nb) => { const C = g(c), S = { smp: [], stx: [], sbuf: [], rwt: [], rwb: [] }; for (let i = 0; i < nt; i++) { const q = N(tp) + 24 * i, t = g(r64(q, 0)), mip = r32(q, 8), lay = r32(q, 12); S.rwt[i] = { id: `${t.id}.${mip}.${lay}`, v: dim => view(t, dim, mip, 1, dim === '2d' ? lay : 0) }; } for (let i = 0; i < nb; i++) S.rwb[i] = g(r64(bp, 16 * i)); return nh({ c: C, e: C.enc.beginComputePass(), bk: [], st: [S, S, S] }); },
    SDL_EndGPUComputePass: p => { g(p)?.e.end(); O.delete(N(p)); },
    SDL_BindGPUGraphicsPipeline: (p, h) => { const pa = g(p); pa.pipe = g(h); pa.e.setPipeline(pa.pipe.g); pa.bk = []; },
    SDL_BindGPUComputePipeline: (p, h) => { const pa = g(p); pa.pipe = g(h); pa.e.setPipeline(pa.pipe.g); pa.bk = []; },
    SDL_SetGPUViewport: (p, v) => { const pa = g(p); pa.e.setViewport(rf(v, 0), rf(v, 4), rf(v, 8), rf(v, 12), rf(v, 16), rf(v, 20)); },
    SDL_SetGPUScissor: (p, r) => { const pa = g(p), x = Math.min(Math.max(s32(r, 0), 0), pa.w), y = Math.min(Math.max(s32(r, 4), 0), pa.h); pa.e.setScissorRect(x, y, Math.max(0, Math.min(s32(r, 8) + Math.min(s32(r, 0), 0), pa.w - x)), Math.max(0, Math.min(s32(r, 12) + Math.min(s32(r, 4), 0), pa.h - y))); },
    SDL_BindGPUVertexBuffers: (p, s, b, n) => { const pa = g(p); for (let i = 0; i < n; i++) pa.e.setVertexBuffer(s + i, g(r64(b, 16 * i)).g, r32(b, 16 * i + 8)); },
    SDL_BindGPUIndexBuffer: (p, b, sz) => { g(p).e.setIndexBuffer(g(r64(b, 0)).g, sz ? 'uint32' : 'uint16', r32(b, 8)); },
    SDL_BindGPUVertexSamplers: (p, s, b, n) => bset(p, 0, 'smp', s, b, n), SDL_BindGPUFragmentSamplers: (p, s, b, n) => bset(p, 1, 'smp', s, b, n), SDL_BindGPUComputeSamplers: (p, s, b, n) => bset(p, 2, 'smp', s, b, n),
    SDL_BindGPUVertexStorageTextures: (p, s, b, n) => bset(p, 0, 'stx', s, b, n), SDL_BindGPUFragmentStorageTextures: (p, s, b, n) => bset(p, 1, 'stx', s, b, n), SDL_BindGPUComputeStorageTextures: (p, s, b, n) => bset(p, 2, 'stx', s, b, n),
    SDL_BindGPUVertexStorageBuffers: (p, s, b, n) => bset(p, 0, 'sbuf', s, b, n), SDL_BindGPUFragmentStorageBuffers: (p, s, b, n) => bset(p, 1, 'sbuf', s, b, n), SDL_BindGPUComputeStorageBuffers: (p, s, b, n) => bset(p, 2, 'sbuf', s, b, n),
    SDL_DrawGPUPrimitives: (p, nv, ni, fv, fi) => { const pa = g(p); if (bind(pa)) pa.e.draw(nv, ni, fv, fi); },
    SDL_DrawGPUIndexedPrimitives: (p, nx, ni, fx, vo, fi) => { const pa = g(p); if (bind(pa)) pa.e.drawIndexed(nx, ni, fx, vo, fi); },
    SDL_DispatchGPUCompute: (p, x, y, z) => { const pa = g(p); if (bind(pa)) pa.e.dispatchWorkgroups(x, y, z); },
    SDL_PushGPUVertexUniformData: (c, s, p, n) => upush(c, 0, s, p, n), SDL_PushGPUFragmentUniformData: (c, s, p, n) => upush(c, 1, s, p, n), SDL_PushGPUComputeUniformData: (c, s, p, n) => upush(c, 2, s, p, n),
    SDL_BlitGPUTexture: (c, b) => { const s = g(r64(b, 0)), d = g(r64(b, 32)); blit(g(c), s, r32(b, 8), r32(b, 12), r32(b, 16), r32(b, 20), r32(b, 24), r32(b, 28), d, r32(b, 40), r32(b, 44), r32(b, 48), r32(b, 52), r32(b, 56), r32(b, 60), s32(b, 88) === 1, s32(b, 84), s32(b, 64), [rf(b, 68), rf(b, 72), rf(b, 76), rf(b, 80)]); },
    SDL_GenerateMipmapsForGPUTexture: (c, h) => { const t = g(h), C = g(c); if (!t || t.d3 || t.f.includes('int') || t.f.startsWith('depth')) return; for (let l = 0; l < t.layers; l++) for (let m = 1; m < t.mips; m++) { const w = Math.max(1, t.w >> m), hh = Math.max(1, t.h >> m); blit(C, t, m - 1, l, 0, 0, Math.max(1, t.w >> m - 1), Math.max(1, t.h >> m - 1), t, m, l, 0, 0, w, hh, true, 0, 2, [0, 0, 0, 0]); } },
    SDL_CreateWindow: (t, w, h, f) => { f = N(f); const own = !R.canvas(), cv = R.canvas() || document.body.appendChild(Object.assign(document.createElement('canvas'), { style: `width:${w}px;height:${h}px;display:block` })); cv.tabIndex = cv.tabIndex < 0 ? 0 : cv.tabIndex; if (f & 8) cv.hidden = true; if (cs(t)) document.title = cs(t); const W = { cv, f, w: 0, h: 0, own }; focusW = W; listen(W); fit(W); evq.length = 0; return nh(W); },
    SDL_DestroyWindow: h => { const W = win(h); if (!W) return; W.off(); if (W.own) W.cv.remove(); if (focusW === W) focusW = null; O.delete(N(h)); },
    SDL_ClaimWindowForGPUDevice: (d, h) => { const W = win(h); if (!W || !dev) return fail('no canvas or no device', 0); W.ctx = W.cv.getContext('webgpu'); W.fmt = navigator.gpu.getPreferredCanvasFormat(); W.ctx.configure({ device: dev, format: W.fmt, alphaMode: 'opaque' }); W.tex = { sw: 1, views: new Map(), mips: 1, layers: 1, f: W.fmt, bs: 4, id: nid++ }; W.th = nh(W.tex); return 1; },
    SDL_ReleaseWindowFromGPUDevice: (d, h) => { win(h)?.ctx?.unconfigure(); },
    SDL_WindowSupportsGPUPresentMode: (d, w, m) => m === 0 ? 1 : 0, SDL_SetGPUSwapchainParameters: (d, w, c, m) => m === 0 && c === 0 ? 1 : 0,
    SDL_WaitAndAcquireGPUSwapchainTexture: (c, h, tp, wp, hp) => { const W = win(h), go = () => { fit(W); const T = W.tex; T.g = W.ctx.getCurrentTexture(); T.views.clear(); T.w = W.cv.width; T.h = W.cv.height; w64(tp, 0, W.th); w32(wp, 0, T.w); w32(hp, 0, T.h); return 1; }; if (!W?.ctx) return 0; return raf || !R.canWait() ? go() : nextFrame().then(go); },
    SDL_GetWindowSize: (h, a, b) => { const W = win(h); if (!W) return 0; w32(a, 0, W.w); w32(b, 0, W.h); return 1; },
    SDL_GetWindowSizeInPixels: (h, a, b) => { const W = win(h); if (!W) return 0; w32(a, 0, W.cv.width); w32(b, 0, W.cv.height); return 1; },
    SDL_GetWindowSafeArea: (h, r) => { const W = win(h); if (!W) return 0; w32(r, 0, 0); w32(r, 4, 0); w32(r, 8, W.w); w32(r, 12, W.h); return 1; },
    SDL_GetWindowPosition: (h, a, b) => { const W = win(h); if (!W) return 0; const r = W.cv.getBoundingClientRect(); w32(a, 0, Math.round(r.left)); w32(b, 0, Math.round(r.top)); return 1; },
    SDL_GetWindowFlags: h => { const W = win(h); return W ? BigInt(W.f & 8192 | (W.cv.hidden ? 8 : 0) | (document.hasFocus() ? 512 : 0) | (inside ? 1024 : 0)) : 0n; },
    SDL_GetWindowID: h => win(h) ? 1 : 0, SDL_SetWindowTitle: (h, t) => { document.title = cs(t); return 1; },
    SDL_SetWindowFullscreen: (h, on) => { const W = win(h); if (!W) return 0; (on ? W.cv.requestFullscreen?.() : document.fullscreenElement && document.exitFullscreen())?.catch?.(() => {}); return 1; },
    SDL_GetMouseFocus: () => inside && focusW ? BigInt([...O].find(([, v]) => v === focusW)?.[0] || 0) : 0n, SDL_GetCurrentVideoDriver: () => cstr(2048, 'browser'),
    SDL_GetGlobalMouseState: (x, y) => { wf(x, 0, gx); wf(y, 0, gy); return (gb & 1 ? 1 : 0) | (gb & 4 ? 2 : 0) | (gb & 2 ? 4 : 0); },
    SDL_ShowCursor: () => { if (focusW) focusW.cv.style.cursor = ''; return 1; }, SDL_HideCursor: () => { if (focusW) focusW.cv.style.cursor = 'none'; return 1; },
    SDL_SetWindowRelativeMouseMode: (h, on) => { const W = win(h); if (!W) return 0; try { on ? W.cv.requestPointerLock()?.catch?.(() => {}) : document.pointerLockElement && document.exitPointerLock(); } catch {} return 1; },
    SDL_FlushEvent: t => { for (let i = evq.length - 1; i >= 0; i--) if (new DataView(evq[i].buffer).getUint32(0, true) === t) evq.splice(i, 1); },
    SDL_PollEvent: p => { if (focusW) fit(focusW); const b = evq.shift(); if (!b) return 0; u8().set(b, N(p)); return 1; },
    SDL_PushEvent: p => { evq.push(u8().slice(N(p), N(p) + 128)); return 1; }, SDL_RegisterEvents: n => { const k = uev; uev += n; return k; },
    SDL_OpenGamepad: () => 0n, SDL_GetTicksNS: () => BigInt(Math.round(performance.now() * 1e6)),
    SDL_StartTextInput: () => { textOn = true; return 1; }, SDL_StopTextInput: () => { textOn = false; return 1; },
    SDL_StepUTF8: (pp, np) => { const p = r64(pp, 0), m = u8(), b = m[p]; if (!b) return 0; const n = b < 0x80 ? 1 : b < 0xe0 ? 2 : b < 0xf0 ? 3 : 4, cp = td.decode(m.subarray(p, p + n)).codePointAt(0) || 0xfffd; w64(pp, 0, p + n); return cp; },
    SDL_GetScancodeFromName: p => { const s = cs(p).toLowerCase(), i = SC.findIndex(x => x && x.toLowerCase() === s); return i < 0 ? 0 : i; },
    SDL_GetScancodeName: sc => cstr(3072, SC[sc] || ''), SDL_GetKeyFromScancode: sc => keyOf(sc),
    SDL_GetClipboardText: () => cstr(16384, clip, 49152), SDL_SetClipboardText: t => { clip = cs(t); navigator.clipboard?.writeText(clip).catch(() => {}); return 1; },
    SDL_CreateSurfaceFrom: (w, h, f, px, pitch) => nh({ w, h, f, px: N(px), pitch }),
    SDL_SavePNG: (s, p) => { const S = g(s); if (!S || (S.f !== 376840196 && S.f !== 372645892)) return fail('SDL_SavePNG on the web: an RGBA8 or BGRA8 surface', 0); const px = new Uint8Array(S.w * S.h * 4), m = u8(); for (let y = 0; y < S.h; y++) px.set(m.subarray(S.px + y * S.pitch, S.px + y * S.pitch + S.w * 4), y * S.w * 4); if (S.f === 372645892) for (let i = 0; i < px.length; i += 4) [px[i], px[i + 2]] = [px[i + 2], px[i]]; files.set(cs(p), png(S.w, S.h, px)); R.saved?.(cs(p)); return 1; },
    SDL_LoadPNG: () => fail('SDL_LoadPNG: load images on the web with codec_png'), SDL_LoadBMP: () => fail('SDL_LoadBMP is not available on the web'), SDL_ConvertSurface: () => 0n, SDL_DestroySurface: s => { O.delete(N(s)); }
  };
  return {
    env,
    waiting: ['SDL_WaitForGPUFences', 'SDL_WaitForGPUIdle', 'SDL_WaitAndAcquireGPUSwapchainTexture'],
    init: async () => { try { const ad = await navigator.gpu?.requestAdapter({ powerPreference: 'high-performance' }); if (!ad) return; const L = {}; for (const k in ad.limits) if (typeof ad.limits[k] === 'number') L[k] = ad.limits[k]; dev = await ad.requestDevice({ requiredFeatures: ['float32-filterable', 'float32-blendable', 'rg11b10ufloat-renderable', 'depth32float-stencil8'].filter(f => ad.features.has(f)), requiredLimits: L }); info = ad.info; dev.onuncapturederror = e => { nfail++; if (nfail <= 7) console.error('webgpu:', e.error.message); }; } catch (e) { err = String(e && e.message || e); } },
    raf: on => { raf = on; }, close: () => { for (const o of O.values()) o?.off?.(); dev?.destroy(); dev = null; }, stats: () => ({ errors: nfail, gpu: info ? `${info.vendor} ${info.architecture} ${info.description}`.trim() : '' }), idle: () => dev ? dev.queue.onSubmittedWorkDone() : Promise.resolve()
  };
  function bset(p, st, k, s, b, n) { const S = g(p).st[st]; for (let i = 0; i < n; i++) S[k][s + i] = k === 'smp' ? { t: g(r64(b, 16 * i)), s: g(r64(b, 16 * i + 8)) } : g(r64(b, 8 * i)); }
  function upush(c, st, slot, p, n) { const C = g(c); if (!C.cur || C.off + n > RING) { C.cur = chunk(); C.cur.used = 0; C.ub.push(C.cur); C.off = 0; } C.cur.cpu.set(u8().subarray(N(p), N(p) + n), C.off); C.push[st][slot] = { k: C.cur, off: C.off }; C.cur.used = C.off + n; C.off = al(C.off + n, 256); }
}
