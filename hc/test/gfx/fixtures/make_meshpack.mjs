import { readFileSync, writeFileSync } from 'node:fs';
import { pathToFileURL } from 'node:url';
const [cmd, dir, file] = process.argv.slice(2);
if (!cmd || !dir || !file) { console.error('usage: node make_meshpack.mjs make|check <meshoptimizer package dir> <file>'); process.exit(2); }
const { MeshoptEncoder: E } = await import(pathToFileURL(dir + '/meshopt_encoder.js'));
const { MeshoptDecoder: D } = await import(pathToFileURL(dir + '/meshopt_decoder.mjs'));
await E.ready; await D.ready;
let seed = 7; const rnd = () => (seed = (seed * 1103515245 + 12345) >>> 0) / 4294967296;
const shuffle = a => { for (let i = a.length - 1; i > 0; i--) { const j = Math.floor(rnd() * (i + 1)); [a[i], a[j]] = [a[j], a[i]]; } return a; };
const grid = (w, h) => { const t = []; for (let y = 0; y < h; y++) for (let x = 0; x < w; x++) { const a = y * (w + 1) + x, b = a + 1, c = a + w + 1, d = c + 1; t.push([a, b, d], [a, d, c]); } return [t, (w + 1) * (h + 1)]; };
const scramble = ([t, nv]) => { const ids = shuffle([...Array(nv).keys()]); return shuffle(t.map(([a, b, c]) => { const r = Math.floor(rnd() * 3), q = [ids[a], ids[b], ids[c]]; return [q[r], q[(r + 1) % 3], q[(r + 2) % 3]]; })).flat(); };
const soup = (n, nv) => { const o = []; for (let i = 0; i < n; i++) { const a = Math.floor(rnd() * nv); let b = a, c = a; while (b === a) b = Math.floor(rnd() * nv); while (c === a || c === b) c = Math.floor(rnd() * nv); o.push(a, b, c); } return o; };
const u8 = (a, size) => { const b = new Uint8Array(a.length * size), v = new DataView(b.buffer); a.forEach((x, i) => size === 2 ? v.setUint16(i * 2, x, true) : v.setUint32(i * 4, x, true)); return b; };
const out = []; const u32 = x => { const b = new Uint8Array(4); new DataView(b.buffer).setUint32(0, x, true); out.push(b); }; const blob = b => { u32(b.length); out.push(b); };
const rec = (kind, count, size, flag, input, extra, ref) => { u32(kind); u32(count); u32(size); u32(flag); blob(input); blob(extra); blob(ref); };
const tri = (idx, ordered, grid) => { const size = idx.reduce((m, x) => Math.max(m, x), 0) > 65535 ? 4 : 2, ex = Uint32Array.from(idx); if (ordered) E.reorderMesh(ex, true, false); const ref = E.encodeIndexBuffer(u8([...ex], size), ex.length, size); rec(1, idx.length, size, ordered ? (grid ? 3 : 1) : 0, u8(idx, 4), u8([...ex], 4), ref); return [...ex]; };
const seq = (idx, size) => rec(2, idx.length, size, 0, u8(idx, 4), new Uint8Array(0), E.encodeIndexSequence(u8(idx, size), idx.length, size));
const attr = (count, stride, smooth) => { const b = new Uint8Array(count * stride), v = new DataView(b.buffer); for (let i = 0; i < count; i++) for (let k = 0; k < stride; k += 2) v.setUint16(i * stride + k, smooth ? (32768 + 9000 * Math.sin(i * 0.013 * (k + 1)) + 300 * Math.cos(i * 0.31)) & 65535 : Math.floor(rnd() * 65536), true); rec(0, count, stride, smooth ? 1 : 0, b, new Uint8Array(0), E.encodeVertexBufferLevel(b, count, stride, 2, 0)); };
if (cmd === 'make') {
  const g7 = tri(grid(7, 7)[0].flat(), false), g100 = tri(scramble(grid(100, 100)), true, true), g120 = tri(scramble(grid(120, 80)), true, true), sp = tri(soup(3000, 1000), true);
  tri([5, 9, 2], true); tri(scramble(grid(30, 30)).map(x => x + 70000), false); tri([], true); tri([0, 1, 2, 2, 1, 3, 2, 3, 4, 4, 3, 5, 0, 1, 2, 2, 1, 3, 9, 1, 2, 70001, 3, 9], false);
  for (const [s, size] of [[g7, 2], [g100, 2], [sp, 2], [[...Array(5000).keys()], 2], [soup(2000, 100000), 4], [[], 2]]) seq(s, size);
  for (const stride of [4, 8, 12, 16, 20, 32, 64, 128, 256]) for (const count of [0, 1, 15, 16, 17, 100, 255, 256, 257, 1000, 3000]) if (count * stride <= 32768 && (count > 0 || stride === 12)) for (const smooth of count * stride <= 4096 ? [true, false] : [true]) attr(count, stride, smooth);
  writeFileSync(file, Buffer.concat(out)); console.log('wrote', file, Buffer.concat(out).length, 'bytes');
} else {
  const b = readFileSync(file), dv = new DataView(b.buffer, b.byteOffset, b.length); let at = 0, n = 0, bad = 0;
  const rd = () => { const x = dv.getUint32(at, true); at += 4; return x; }, rb = () => { const l = rd(), s = new Uint8Array(b.subarray(at, at + l)); at += l; return s; };
  const tris = (u, size) => { const v = new DataView(u.buffer, u.byteOffset, u.length), o = []; for (let i = 0; i < u.length / size; i += 3) { const q = [0, 1, 2].map(k => size === 2 ? v.getUint16((i + k) * 2, true) : v.getUint32((i + k) * 4, true)), m = q.indexOf(Math.min(...q)); o.push(q[m], q[(m + 1) % 3], q[(m + 2) % 3]); } return o.join(); };
  while (at < b.length) { const kind = rd(), count = rd(), size = rd(), stream = rb(), want = rb(), got = new Uint8Array(count * size); n++;
    try { kind === 0 ? D.decodeVertexBuffer(got, count, size, stream) : kind === 1 ? D.decodeIndexBuffer(got, count, size, stream) : D.decodeIndexSequence(got, count, size, stream); } catch (e) { bad++; console.log('record', n, 'kind', kind, 'throws', e.message); continue; }
    const same = kind === 1 ? tris(got, size) === tris(want, size) : Buffer.compare(Buffer.from(got), Buffer.from(want)) === 0; if (!same) { bad++; console.log('record', n, 'kind', kind, 'differs'); } }
  console.log(bad ? 'reference decoder: FAILED ' + bad + ' of ' + n : 'reference decoder: ok ' + n + ' of ' + n); process.exit(bad ? 1 : 0);
}
