import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { Worker, isMainThread, workerData } from 'node:worker_threads';
const N = Number, te = new TextEncoder(), td = new TextDecoder();
const boot = isMainThread ? null : workerData;
const file = isMainThread ? process.argv[2] : boot.file;
const mod = isMainThread ? await WebAssembly.compile(fs.readFileSync(file)) : boot.mod;
const meta = new Uint8Array(WebAssembly.Module.customSections(mod, 'he.mem')[0] || new ArrayBuffer(5));
const pages0 = meta[0] | meta[1] << 8 | meta[2] << 16 | meta[3] << 24, shared = meta[4] === 1;
const mem = isMainThread ? new WebAssembly.Memory({ initial: pages0, maximum: 65536, shared }) : boot.mem;
const ctl = isMainThread ? new SharedArrayBuffer(8 * 8 + 16 * 8192) : boot.ctl;
const C32 = new Int32Array(ctl), C64 = new BigInt64Array(ctl);
let u8, dv, i32;
const sync = () => { if (u8?.buffer !== mem.buffer) { u8 = new Uint8Array(mem.buffer); dv = new DataView(mem.buffer); i32 = shared ? new Int32Array(mem.buffer) : null; } };
const lock = () => { while (Atomics.compareExchange(C32, 0, 0, 1) !== 0) Atomics.wait(C32, 0, 1, 1); };
const unlock = () => { Atomics.store(C32, 0, 0); Atomics.notify(C32, 0, 1); };
const FL = 8, FCAP = 8192;
const mmap = len => {
  len = Math.ceil(len / 65536) * 65536; lock();
  try {
    const n = N(C64[2]);
    for (let k = 0; k < n; k++) { const a = N(C64[FL + 2 * k]), l = N(C64[FL + 2 * k + 1]); if (l >= len) { if (l === len) { C64[FL + 2 * k] = C64[FL + 2 * (n - 1)]; C64[FL + 2 * k + 1] = C64[FL + 2 * (n - 1) + 1]; C64[2] = BigInt(n - 1); } else { C64[FL + 2 * k] = BigInt(a + len); C64[FL + 2 * k + 1] = BigInt(l - len); } sync(); u8.fill(0, a, a + len); return a; } }
    const old = mem.grow(len / 65536); sync(); return old * 65536;
  } catch { return -12; } finally { unlock(); }
};
const munmap = (a, len) => { a = N(a); len = Math.ceil(N(len) / 65536) * 65536; if (a % 65536 || len <= 0) return; lock(); const n = N(C64[2]); if (n < FCAP) { C64[FL + 2 * n] = BigInt(a); C64[FL + 2 * n + 1] = BigInt(len); C64[2] = BigInt(n + 1); } unlock(); };
const fds = new Map([[0, { fd: 0 }], [1, { fd: 1 }], [2, { fd: 2 }]]); let nfd = 3;
const fdh = a => fds.get(N(a));
const cstr = a => { a = N(a); let e = a; while (u8[e]) e++; return td.decode(u8.subarray(a, e)); };
const wrap = f => { try { return f(); } catch (e) { if (e && e.helium_exit !== undefined) throw e; const n = e && e.code && os.constants.errno[e.code]; return BigInt(-(n || 5)); } };
const oflags = f => { const K = fs.constants; let r = (f & 3) === 1 ? K.O_WRONLY : (f & 3) === 2 ? K.O_RDWR : K.O_RDONLY; if (f & 0x40) r |= K.O_CREAT; if (f & 0x80) r |= K.O_EXCL; if (f & 0x200) r |= K.O_TRUNC; if (f & 0x400) r |= K.O_APPEND; return r; };
const wstat = (st, p) => { sync(); u8.fill(0, p, p + 144); dv.setBigUint64(p + 8, BigInt(st.ino), true); dv.setBigUint64(p + 16, BigInt(st.nlink), true); dv.setUint32(p + 24, st.mode, true); dv.setBigInt64(p + 48, BigInt(st.size), true); dv.setBigInt64(p + 88, BigInt(Math.floor(st.mtimeMs / 1000)), true); dv.setBigInt64(p + 96, BigInt(Math.floor(st.mtimeMs % 1000 * 1e6)), true); };
const exitAll = code => { Atomics.store(C32, 2, code + 1); Atomics.notify(C32, 3); throw { helium_exit: code }; };
const checkExit = () => { const e = Atomics.load(C32, 2); if (e) throw { helium_exit: e - 1 }; };
const futex = (a, op, v, ts) => {
  a = N(a); if (!shared) return 0n; sync(); const w = (op & 127) === 0;
  if (!w) return BigInt(Atomics.notify(i32, a >> 2, N(v)));
  let ms = ts ? N(dv.getBigInt64(N(ts), true)) * 1000 + N(dv.getBigInt64(N(ts) + 8, true)) / 1e6 : Infinity;
  const end = performance.now() + ms;
  for (;;) { checkExit(); const r = Atomics.wait(i32, a >> 2, N(BigInt.asIntN(32, v)), Math.min(50, Math.max(0, end - performance.now()))); if (r !== 'timed-out') return r === 'ok' ? 0n : -11n; if (performance.now() >= end) return -110n; }
};
const pool = [];
const clone = (sp, ctid, tls) => {
  let w = pool.find(p => Atomics.compareExchange(p.st, 0, 0, 2) === 0);
  if (!w) { const st = new Int32Array(new SharedArrayBuffer(32)); st[0] = 2; w = { st, t: new BigInt64Array(st.buffer) }; w.worker = new Worker(new URL(import.meta.url), { workerData: { file, mod, mem, ctl, st: st.buffer } }); w.worker.unref(); pool.push(w); }
  w.t[1] = sp; w.t[2] = ctid; w.t[3] = tls; Atomics.store(w.st, 0, 1); Atomics.notify(w.st, 0); return 1000n + BigInt(pool.indexOf(w));
};
const TR = process.env.HE_TRACE;
const sys = (n, a, b, c, d, e, f) => {
  n = N(n); sync(); if (TR) fs.writeSync(2, `sys ${n} ${N(a)} ${N(b)} ${N(c)} ${N(d)}${isMainThread ? '' : ' [w]'}\n`); if (shared) checkExit();
  switch (n) {
    case 0: { const h = fdh(a); if (!h || h.dir) return -9n; return wrap(() => BigInt(fs.readSync(h.fd, u8, N(b), N(c), null))); }
    case 1: { const h = fdh(a); if (!h || h.dir) return -9n; return wrap(() => BigInt(fs.writeSync(h.fd, u8.subarray(N(b), N(b) + N(c))))); }
    case 2: { const p = cstr(a), fl = N(b); return wrap(() => { if (fl & 0x10000) { const ents = fs.readdirSync(p, { withFileTypes: true }); const k = nfd++; fds.set(k, { dir: true, ents: [{ name: '.', t: 4 }, { name: '..', t: 4 }, ...ents.map(x => ({ name: x.name, t: x.isDirectory() ? 4 : x.isSymbolicLink() ? 10 : 8 }))], i: 0 }); return BigInt(k); } const k = nfd++; fds.set(k, { fd: fs.openSync(p, oflags(fl), N(c)) }); return BigInt(k); }); }
    case 3: { const h = fdh(a); if (!h) return -9n; fds.delete(N(a)); if (h.fd !== undefined && h.fd > 2) fs.closeSync(h.fd); return 0n; }
    case 4: return wrap(() => { wstat(fs.statSync(cstr(a)), N(b)); return 0n; });
    case 5: { const h = fdh(a); if (!h) return -9n; return wrap(() => { if (h.dir) { u8.fill(0, N(b), N(b) + 144); dv.setUint32(N(b) + 24, 0o40755, true); } else wstat(fs.fstatSync(h.fd), N(b)); return 0n; }); }
    case 9: return BigInt(mmap(N(b)));
    case 11: munmap(a, b); return 0n;
    case 10: case 13: case 131: case 14: return 0n;
    case 28: { if (N(c) === 4) u8.fill(0, N(a), N(a) + N(b)); return 0n; }
    case 35: { const ms = N(dv.getBigInt64(N(a), true)) * 1000 + N(dv.getBigInt64(N(a) + 8, true)) / 1e6; Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, ms); return 0n; }
    case 39: return BigInt(process.pid);
    case 56: return clone(b, d, e);
    case 82: return wrap(() => { fs.renameSync(cstr(a), cstr(b)); return 0n; });
    case 83: return wrap(() => { fs.mkdirSync(cstr(a), { mode: N(b) }); return 0n; });
    case 84: return wrap(() => { fs.rmdirSync(cstr(a)); return 0n; });
    case 87: return wrap(() => { fs.unlinkSync(cstr(a)); return 0n; });
    case 90: return wrap(() => { fs.chmodSync(cstr(a), N(b)); return 0n; });
    case 89: { const p = cstr(a); const t = te.encode(p === '/proc/self/exe' ? path.resolve(file) : fs.readlinkSync(p)); const k = Math.min(t.length, N(c)); u8.set(t.subarray(0, k), N(b)); return BigInt(k); }
    case 202: return futex(a, N(b), c, d);
    case 204: { const k = Math.min(os.availableParallelism(), 64); u8.fill(0, N(c), N(c) + 8); for (let i = 0; i < k; i++) u8[N(c) + (i >> 3)] |= 1 << (i & 7); return 8n; }
    case 217: { const h = fdh(a); if (!h || !h.dir) return -9n; let o = N(b); const lim = o + N(c); while (h.i < h.ents.length) { const x = h.ents[h.i], nb = te.encode(x.name), rl = (19 + nb.length + 1 + 7) & ~7; if (o + rl > lim) break; u8.fill(0, o, o + rl); dv.setBigUint64(o, BigInt(h.i + 1), true); dv.setBigInt64(o + 8, BigInt(h.i + 1), true); dv.setUint16(o + 16, rl, true); u8[o + 18] = x.t; u8.set(nb, o + 19); o += rl; h.i++; } return BigInt(o - N(b)); }
    case 228: { const t = N(a) === 0 ? Date.now() * 1e6 : (performance.timeOrigin + performance.now()) * 1e6; const p = N(b); dv.setBigInt64(p, BigInt(Math.floor(t / 1e9)), true); dv.setBigInt64(p + 8, BigInt(Math.floor(t % 1e9)), true); return 0n; }
    case 318: { const k = N(b); const tmp = new Uint8Array(k); crypto.getRandomValues(tmp); u8.set(tmp, N(a)); return b; }
    case 60: throw { helium_thread_exit: N(a) };
    case 231: exitAll(N(a));
    default: return -38n;
  }
};
const instance = await WebAssembly.instantiate(mod, { env: new Proxy({ sys, memory: mem }, { get: (t, k) => t[k] || (() => { fs.writeSync(2, `helium runtime error: ${String(k)} is not available on this host\n`); exitAll(1); }) }) });
const X = instance.exports;
const run = f => { try { f(); return 0; } catch (e) { if (e instanceof RangeError && /call stack/.test(e.message)) { try { X.he_sovf(); } catch (e2) { e = e2; } } if (e && e.helium_exit !== undefined) return e.helium_exit; if (e && e.helium_thread_exit !== undefined) return 0; fs.writeSync(2, 'wasm trap: ' + (e && e.stack || e) + '\n'); if (shared) { Atomics.store(C32, 2, 135); } return 134; } };
if (isMainThread) {
  const argv = process.argv.slice(2), envs = Object.entries(process.env).map(([k, v]) => k + '=' + v);
  const strs = [...argv, ...envs].map(x => te.encode(x + '\0'));
  const hdr = 8 * (argv.length + envs.length + 3), tot = hdr + strs.reduce((k, b) => k + b.length, 0);
  const base = mmap(tot); sync();
  let q = base + hdr, w = base; const put = v => { dv.setBigInt64(w, BigInt(v), true); w += 8; };
  put(argv.length); strs.forEach((b, i) => { if (i === argv.length) put(0); u8.set(b, q); put(q); q += b.length; }); if (!envs.length) put(0); put(0);
  const code = run(() => X.he_start(BigInt(base)));
  process.exit(code);
} else {
  const st = new Int32Array(boot.st), t = new BigInt64Array(boot.st);
  for (;;) {
    while (Atomics.load(st, 0) !== 1) Atomics.wait(st, 0, Atomics.load(st, 0));
    const ctid = N(t[2]); const code = run(() => X.he_thread(t[1], t[3]));
    sync(); if (code !== 0 && !Atomics.load(C32, 2)) Atomics.store(C32, 2, code + 1);
    Atomics.store(i32, ctid >> 2, 0); Atomics.notify(i32, ctid >> 2);
    Atomics.store(st, 0, 0);
  }
}
