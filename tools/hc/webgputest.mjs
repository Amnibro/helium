import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import http from 'node:http';
import zlib from 'node:zlib';
import { spawn, spawnSync } from 'node:child_process';
const [hc] = process.argv.slice(2), R = path.resolve(path.dirname(new URL(import.meta.url).pathname), '../..'), T = fs.mkdtempSync(path.join(os.tmpdir(), 'webgputest-')), OUT = path.resolve(process.env.WEBGPU_OUT || path.join(R, 'build/webgputest')), MIN = +(process.env.WEBGPU_PSNR || 30);
if (!hc) { console.log('usage: node tools/hc/webgputest.mjs hc'); process.exit(2); }
const holo = process.env.WEBGPU_HOLO || path.join(os.homedir(), 'ai/amni-companion/web/models/holo.glb');
const scenes = [['scene', path.join(R, 'hc/test/gfx/fixtures/scene.glb'), [512, 384, 1.5, 1.6, 3.5, 0, 0.6, 0, 0.9, 0.5]], ['scene_gi', path.join(R, 'hc/test/gfx/fixtures/scene.glb'), [512, 384, 1.5, 1.6, 3.5, 0, 0.6, 0, 0.9, 0.5, 1]], ['holo', holo, [384, 512, 0, 1, 2.8, 0, 0.85, 0, 0.7, 0]], ['scene_e3', path.join(R, 'hc/test/gfx/fixtures/scene.glb'), [512, 384, 1.5, 1.6, 3.5, 0, 0.6, 0, 0.9, 0.5, 'e3']], ['holo_e3', holo, [384, 512, 0.3, 1.45, 1.1, 0, 1.4, 0, 0.5, 0, 'e3']]].filter(s => fs.existsSync(s[1]) || console.log(`webgputest: ${s[0]}: SKIPPED (no ${s[1]})`));
const chrome = process.env.CHROME || ['google-chrome-stable', 'google-chrome', 'chromium', 'chromium-browser'].find(c => spawnSync('sh', ['-c', `command -v ${c}`]).status === 0);
if (!chrome) { console.log('webgputest: SKIPPED (no Chrome; set CHROME)'); process.exit(0); }
fs.mkdirSync(OUT, { recursive: true });
const sh = (cmd, o = {}) => { const r = spawnSync(cmd[0], cmd.slice(1), { encoding: 'utf8', ...o }); return r.status === 0 ? r.stdout : (console.log(`webgputest: ${cmd.join(' ')} failed:\n${(r.stdout + r.stderr).trim().split('\n').filter(l => !/ W\d+ /.test(l)).slice(-7).join('\n')}`), null); };
const src = f => path.join(R, 'hc/test/webgpu', f + '.amni'), env = { ...process.env, HC_LIB: path.join(R, 'hc/lib') }, web = (f, o) => sh([hc, 'build', '--web', ...(process.env.WEBGPU_HCFLAGS || '').split(' ').filter(Boolean), src(f), '-o', path.join(T, o)], { env });
if (['scene_frame', 'compute_check'].some(f => sh([hc, 'build', src(f), '-o', path.join(T, f)], { env }) === null) || [['scene_frame', 'app'], ['window_frame', 'win'], ['compute_check', 'cc']].some(([f, o]) => web(f, o + '.wasm') === null)) process.exit(1);
const paeth = (a, b, c) => { const p = a + b - c, pa = Math.abs(p - a), pb = Math.abs(p - b), pc = Math.abs(p - c); return pa <= pb && pa <= pc ? a : pb <= pc ? b : c; };
const unpng = b => {
	let o = 8, w = 0, h = 0, ct = 6; const idat = [];
	while (o < b.length) { const n = b.readUInt32BE(o), t = b.toString('latin1', o + 4, o + 8), d = b.subarray(o + 8, o + 8 + n); if (t === 'IHDR') { w = d.readUInt32BE(0); h = d.readUInt32BE(4); ct = d[9]; } if (t === 'IDAT') idat.push(d); o += 12 + n; }
	const raw = zlib.inflateSync(Buffer.concat(idat)), c = { 0: 1, 2: 3, 4: 2, 6: 4 }[ct], st = w * c, px = Buffer.alloc(w * h * 4, 255); let prev = Buffer.alloc(st);
	for (let y = 0; y < h; y++) { const f = raw[y * (st + 1)], l = Buffer.from(raw.subarray(y * (st + 1) + 1, (y + 1) * (st + 1))); for (let i = 0; i < st; i++) { const a = i >= c ? l[i - c] : 0, u = prev[i], ul = i >= c ? prev[i - c] : 0; l[i] = l[i] + [0, a, u, (a + u) >> 1, paeth(a, u, ul)][f] & 255; } for (let x = 0; x < w; x++) for (let k = 0; k < 3; k++) px[(y * w + x) * 4 + k] = l[x * c + (c < 3 ? 0 : k)]; prev = l; }
	return { w, h, px };
};
const crcT = new Int32Array(256).map((_, n) => { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ c >>> 1 : c >>> 1; return c; });
const mkpng = (w, h, px) => { const ch = (t, d) => { const c = Buffer.alloc(12 + d.length); c.writeUInt32BE(d.length); c.write(t, 4, 'latin1'); d.copy(c, 8); let r = -1; for (let i = 4; i < 8 + d.length; i++) r = crcT[(r ^ c[i]) & 255] ^ r >>> 8; c.writeInt32BE(~r, 8 + d.length); return c; }, hd = Buffer.alloc(13), raw = Buffer.alloc((w * 4 + 1) * h); hd.writeUInt32BE(w); hd.writeUInt32BE(h, 4); hd[8] = 8; hd[9] = 6; for (let y = 0; y < h; y++) px.copy(raw, y * (w * 4 + 1) + 1, y * w * 4, (y + 1) * w * 4); return Buffer.concat([Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]), ch('IHDR', hd), ch('IDAT', zlib.deflateSync(raw)), ch('IEND', Buffer.alloc(0))]); };
const native = {};
native.compute = (sh([path.join(T, 'compute_check')]) || '').trim().split('\n').pop();
for (const [name, model, a] of scenes) { const o = sh([path.join(T, 'scene_frame'), model, path.join(OUT, name + '_native.png'), ...a.map(String)]); if (o === null) process.exit(1); native[name] = o.trim(); }
const page = async (scenes) => {
	while (location.protocol !== 'http:' || document.readyState !== 'complete') await new Promise(r => setTimeout(r, 50));
	const logs = [], tap = k => { const f = console[k]; console[k] = (...a) => { logs.push(a.join(' ')); f.apply(console, a); }; }; tap('log'); tap('error'); tap('warn');
	const { start } = await import(new URL('helium.js', location.href).href), out = {}, b64 = b => { let s = ''; for (let i = 0; i < b.length; i += 32768) s += String.fromCharCode(...b.subarray(i, i + 32768)); return btoa(s); };
	for (const [name, , a] of scenes) {
		const files = { ['/m/' + name + '.glb']: new Uint8Array(await (await fetch('m/' + name + '.glb')).arrayBuffer()) }, t0 = performance.now(), n0 = logs.length;
		const rt = await start({ wasm: 'app.wasm', files, args: ['scene_frame', '/m/' + name + '.glb', '/out/' + name + '.png', ...a.map(String)] });
		await rt.done; const p = rt.files.get('/out/' + name + '.png');
		out[name] = { png: p ? b64(p) : '', logs: logs.slice(n0), ms: performance.now() - t0, stats: rt.gpu(), jspi: !!WebAssembly.Suspending };
	}
	const cv = document.body.appendChild(document.createElement('canvas')), n0 = logs.length, t0 = performance.now(), ev = (t, k, o) => t.dispatchEvent(new k(o.type, { bubbles: true, ...o })); let shot = '';
	cv.dataset.helium = ''; cv.style.cssText = 'width:320px;height:240px;display:block';
	setTimeout(() => { const r = cv.getBoundingClientRect(), at = { clientX: r.left + 40, clientY: r.top + 30, pointerType: 'mouse', button: 0 }; ev(document.body, KeyboardEvent, { type: 'keydown', code: 'KeyW', key: 'w' }); ev(cv, PointerEvent, { type: 'pointermove', ...at }); ev(cv, PointerEvent, { type: 'pointerdown', buttons: 1, ...at }); ev(cv, PointerEvent, { type: 'pointerup', ...at }); ev(document.body, KeyboardEvent, { type: 'keyup', code: 'KeyW', key: 'w' }); }, 300);
	const rt = await start({ wasm: 'win.wasm', files: { '/m/scene.glb': new Uint8Array(await (await fetch('m/scene.glb')).arrayBuffer()) }, args: ['window_frame', '/m/scene.glb', '/out/window.png'], onsave: p => { if (p === '/out/window.png') shot = cv.toDataURL('image/png').split(',')[1]; } });
	await rt.done; const p = rt.files.get('/out/window.png');
	out.window = { png: p ? b64(p) : '', shot, logs: logs.slice(n0), ms: performance.now() - t0, stats: rt.gpu(), jspi: !!WebAssembly.Suspending };
	const n1 = logs.length, rc = await start({ wasm: 'cc.wasm' }); await rc.done; out.compute = { logs: logs.slice(n1), stats: rc.gpu() };
	return JSON.stringify(out);
};
fs.writeFileSync(path.join(T, 'index.html'), '<!doctype html><meta charset="utf-8"><title>webgputest</title>');
const srv = http.createServer((q, r) => { const u = decodeURIComponent(q.url.split('?')[0]), m = /^\/m\/(\w+)\.glb$/.exec(u), f = m ? scenes.find(s => s[0] === m[1])?.[1] : path.join(T, path.normalize(u).replace(/^\/+/, '')); if (!f || !fs.existsSync(f)) { r.writeHead(404); r.end(); return; } r.writeHead(200, { 'content-type': f.endsWith('.js') ? 'text/javascript' : f.endsWith('.wasm') ? 'application/wasm' : f.endsWith('.html') ? 'text/html' : 'application/octet-stream' }); fs.createReadStream(f).pipe(r); });
await new Promise(r => srv.listen(0, '127.0.0.1', r));
const url = `http://127.0.0.1:${srv.address().port}/index.html`, ca = ['--headless=new', '--remote-debugging-port=0', `--user-data-dir=${T}/prof`, '--enable-unsafe-webgpu', '--enable-features=Vulkan', '--use-angle=vulkan', '--no-first-run', '--no-default-browser-check', url];
const ch = spawn(chrome, ca, { stdio: 'ignore', env: { ...process.env, TMPDIR: '/tmp' } });
const done = c => { try { process.kill(ch.pid, 'SIGKILL'); } catch {} srv.close(); setTimeout(() => { fs.rmSync(T, { recursive: true, force: true }); process.exit(c); }, 300); };
try {
	let port = '';
	for (let k = 0; k < 140 && !port; k++) { await new Promise(r => setTimeout(r, 100)); try { port = fs.readFileSync(`${T}/prof/DevToolsActivePort`, 'utf8').split('\n')[0]; } catch {} }
	let tgt; for (let k = 0; k < 140 && !tgt; k++) { try { tgt = (await (await fetch(`http://127.0.0.1:${port}/json/list`)).json()).find(t => t.type === 'page' && t.url.endsWith('index.html')); } catch {} if (!tgt) await new Promise(r => setTimeout(r, 100)); }
	if (!tgt) throw new Error(`no page target on port ${port}`);
	const ws = new WebSocket(tgt.webSocketDebuggerUrl); await new Promise((r, j) => { ws.onopen = r; ws.onerror = j; });
	let res; for (let k = 0; k < 7 && (!res || /context/.test(res.error?.message)); k++) res = await new Promise(r => { ws.onmessage = m => { const d = JSON.parse(m.data); if (d.id === 1) r(d.result || d); }; ws.onclose = () => r({ closed: 1 }); ws.send(JSON.stringify({ id: 1, method: "Runtime.evaluate", params: { expression: `(${page})(${JSON.stringify(scenes)})`, awaitPromise: true, returnByValue: true } })); });
	ws.close();
	if (!res.result || res.result.type !== 'string') { console.log('webgputest: the page failed:', JSON.stringify(res.exceptionDetails || res).slice(0, 2000)); done(1); }
	else {
		const out = JSON.parse(res.result.value); let fail = 0;
		const cmp = (name, a, b, w, what) => {
			if (a.w !== b.w || a.h !== b.h) { console.log(`FAIL ${name}: ${what[0]} ${a.w}x${a.h}, ${what[1]} ${b.w}x${b.h}`); return fail++; }
			let se = 0, big = 0; const d = Buffer.alloc(a.px.length, 255);
			for (let i = 0; i < a.px.length; i += 4) { let m = 0; for (let k = 0; k < 3; k++) { const e = a.px[i + k] - b.px[i + k]; se += e * e; m = Math.max(m, Math.abs(e)); } big += m > 16; d[i] = d[i + 1] = d[i + 2] = Math.min(255, m * 8); }
			fs.writeFileSync(path.join(OUT, name + '_diff.png'), mkpng(a.w, a.h, d));
			const mse = se / (a.w * a.h * 3), psnr = mse ? 10 * Math.log10(255 * 255 / mse) : Infinity, ok = psnr > MIN && !w.stats?.errors;
			fail += !ok; console.log(`${ok ? 'ok  ' : 'FAIL'} ${name}: PSNR ${psnr.toFixed(2)} dB (need > ${MIN}), ${(100 * big / (a.w * a.h)).toFixed(2)} % of pixels off by more than 16, ${w.stats?.errors ?? '?'} WebGPU errors, ${w.ms.toFixed(0)} ms in the page, JSPI ${w.jspi}; ${what[0]} ${path.join(OUT, name + '_' + what[0] + '.png')} vs ${what[1]} ${path.join(OUT, name + '_' + what[1] + '.png')} (|diff| x8 in ${name}_diff.png)`);
		};
		const cw = out.compute.logs.filter(l => l.startsWith('compute_check:')).pop() || '', cok = /^compute_check: ok /.test(native.compute) && cw === native.compute.replace(/vulkan$/, 'webgpu') && !out.compute.stats?.errors; fail += !cok;
		console.log(`${cok ? 'ok  ' : 'FAIL'} compute: native "${native.compute}", web "${cw}"`);
		for (const [name] of [...scenes, ['window']]) {
			const w = out[name], logs = w.logs.filter(l => !/missing import/.test(l) || (fail++, true));
			if (native[name]) console.log(`webgputest: ${name}: native: ${native[name]}`); for (const l of logs) console.log(`webgputest: ${name}: web: ${l}`);
			if (!w.png && logs.some(l => /grew past its region/.test(l))) { console.log(`BLOCKED ${name}: the --web build ran out of room in a Helium array region before rendering (wasm32 regions; see hc/lib/gfx/README.md)`); continue; }
			if (!w.png) { console.log(`FAIL ${name}: the web run wrote no PNG`); fail++; continue; }
			const wp = Buffer.from(w.png, 'base64'); fs.writeFileSync(path.join(OUT, name + '_web.png'), wp);
			if (name !== 'window') { cmp(name, unpng(fs.readFileSync(path.join(OUT, name + '_native.png'))), unpng(wp), w, ['native', 'web']); continue; }
			const sp = Buffer.from(w.shot, 'base64'), m = /frames (\d+) injected Space at (-?\d+) page W at (-?\d+) clicks (\d+) mouse (\d+),(\d+)/.exec(logs.join('\n')) || []; fs.writeFileSync(path.join(OUT, 'window_canvas.png'), sp);
			const evok = +m[2] >= 0 && +m[3] >= 0 && +m[4] > 0 && +m[5] === 40 && +m[6] === 30; fail += !evok; console.log(`${evok ? 'ok  ' : 'FAIL'} window: ${m[1]} frames on requestAnimationFrame, gfx::inject_key seen at frame ${m[2]}, a page keydown at frame ${m[3]}, ${m[4]} click(s), mouse at ${m[5]},${m[6]} (want 40,30)`);
			if (!sp.length) { console.log('FAIL window: no canvas capture'); fail++; } else cmp('window', unpng(wp), unpng(sp), w, ['web', 'canvas']);
		}
		console.log(`webgputest: ${scenes.length} scenes, a window and a compute check, ${fail} failures on ${out.window?.stats?.gpu || 'no WebGPU'}`); done(fail ? 1 : 0);
	}
} catch (e) { console.log('webgputest: could not drive Chrome:', e.message); done(1); }
