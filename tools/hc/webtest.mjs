import fs from 'node:fs';
const mod = await WebAssembly.compile(fs.readFileSync(process.argv[2]));
const meta = new Uint8Array(WebAssembly.Module.customSections(mod, 'he.mem')[0]), pages = meta[0] | meta[1] << 8 | meta[2] << 16 | meta[3] << 24;
const mem = new WebAssembly.Memory({ initial: pages, maximum: 65536 }), td = new TextDecoder(), te = new TextEncoder(), u8 = () => new Uint8Array(mem.buffer);
let X;
const sys = (n, a, b, c) => { n = Number(n); if (n === 1) { process.stdout.write(td.decode(u8().subarray(Number(b), Number(b) + Number(c)))); return c; } if (n === 9) return BigInt(mem.grow(Math.ceil(Number(b) / 65536)) * 65536); if (n === 231 || n === 60) throw { exit: Number(a) }; return 0n; };
const env = { sys, memory: mem, he_log: (p, n) => console.log('log:', td.decode(u8().subarray(p, p + n))), he_now: () => 1.5, he_user_agent: r => { const b = te.encode('hc-test'), p = X.he_grow(r, b.length); u8().set(b, p); } };
X = (await WebAssembly.instantiate(mod, { env })).exports;
X.he_start(0n); X.he_event(3, 1); X.he_event(4, 2); console.log('frame', X.he_frame(21.5));
