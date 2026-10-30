// Runs a Helium --web build that uses hc/lib/net.he WebSockets under the real hc/web/web.js, with just enough of a
// browser faked for it, against an in-process WebSocket echo server (RFC 6455, text and binary, closes after "bye").
// Usage: node wstest.mjs app.wasm   Prints the program's output; exits 1 if it never prints a line starting "closed".
import fs from 'node:fs';
import net from 'node:net';
import crypto from 'node:crypto';
import { fileURLToPath } from 'node:url';
import path from 'node:path';
const here = path.dirname(fileURLToPath(import.meta.url));
const frame = (op, b) => { const n = b.length, h = n < 126 ? Buffer.from([0x80 | op, n]) : Buffer.from([0x80 | op, 126, n >> 8, n & 255]); return Buffer.concat([h, b]); };
const server = net.createServer(s => {
  let buf = Buffer.alloc(0), up = false;
  s.on('data', d => {
    buf = Buffer.concat([buf, d]);
    if (!up) {
      const e = buf.indexOf('\r\n\r\n'); if (e < 0) return;
      const key = /Sec-WebSocket-Key: *(.+)\r\n/i.exec(buf.subarray(0, e).toString())[1].trim();
      const acc = crypto.createHash('sha1').update(key + '258EAFA5-E914-47DA-95CA-C5AB0DC85B11').digest('base64');
      s.write(`HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: ${acc}\r\n\r\n`);
      up = true; buf = buf.subarray(e + 4);
    }
    for (;;) {
      if (buf.length < 2) return;
      const op = buf[0] & 15; let n = buf[1] & 127, o = 2;
      if (n === 126) { if (buf.length < 4) return; n = buf.readUInt16BE(2); o = 4; } else if (n === 127) { s.destroy(); return; }
      if (buf.length < o + 4 + n) return;
      const m = buf.subarray(o, o + 4), p = Buffer.from(buf.subarray(o + 4, o + 4 + n)); for (let i = 0; i < n; i++) p[i] ^= m[i & 3];
      buf = buf.subarray(o + 4 + n);
      if (op === 8) { s.end(frame(8, Buffer.alloc(0))); return; }
      if (op === 1 || op === 2) { s.write(frame(op, p)); if (op === 1 && p.toString() === 'bye') s.end(frame(8, Buffer.from([3, 232]))); }
    }
  });
  s.on('error', () => {});
});
await new Promise(r => server.listen(0, '127.0.0.1', r));
const port = server.address().port, wasm = path.resolve(process.argv[2]);
const lines = [], log = console.log;
console.log = (...a) => { const l = a.join(' '); lines.push(l); log(l); };
const stub = () => new Proxy(function () {}, { get: (t, k) => k === Symbol.toPrimitive ? () => '' : stub(), apply: () => stub() });
globalThis.document = { querySelector: () => null, body: stub(), documentElement: stub() };
globalThis.window = globalThis;
globalThis.location = { protocol: 'http:', host: `127.0.0.1:${port}`, hostname: '127.0.0.1', pathname: '/', search: '', hash: '', href: `http://127.0.0.1:${port}/`, origin: `http://127.0.0.1:${port}` };
globalThis.requestAnimationFrame = f => setTimeout(() => f(performance.now()), 16);
globalThis.cancelAnimationFrame = clearTimeout;
globalThis.fetch = async u => new Response(fs.readFileSync(u));
const { start } = await import(path.join(here, '../../../hc/web/web.js'));
await start({ wasm });
const t0 = Date.now();
while (!lines.some(l => l.startsWith('closed')) && Date.now() - t0 < 5000) await new Promise(r => setTimeout(r, 20));
server.close();
process.exit(lines.some(l => l.startsWith('closed')) ? 0 : 1);
