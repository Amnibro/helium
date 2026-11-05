import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { spawn, spawnSync } from 'node:child_process';
const [hc] = process.argv.slice(2), R = path.resolve(path.dirname(new URL(import.meta.url).pathname), '../..'), T = fs.mkdtempSync(path.join(os.tmpdir(), 'wgsltest-'));
if (!hc) { console.log('usage: node tools/hc/wgsltest.mjs hc'); process.exit(2); }
const files = ['hc/lib/gfx/shaders', 'hc/test/wgsl'].flatMap(d => fs.readdirSync(path.join(R, d)).filter(f => /\.(vert|frag|comp)$/.test(f)).map(f => [f.replace(/\.(\w+)$/, '_$1'), path.join(R, d, f), true]));
for (const [, st, src] of fs.readFileSync(path.join(R, 'hc/lib/ui.he'), 'utf8').matchAll(/embed_shader\("(vert|frag)", """([\s\S]*?)"""/g)) { const p = path.join(T, `ui.${st}`); fs.writeFileSync(p, src); files.push([`ui_${st}`, p, true]); }
files.push(['anim_skin_comp', path.join(R, 'hc/lib/anim/skin.comp'), false]);
const S = [], bad = [];
for (const [name, p, blob] of files) {
	const o = path.join(T, name + (blob ? '.blob' : '.wgsl')), r = spawnSync(hc, [blob ? '--blob' : '--wgsl', p, o], { encoding: 'utf8' });
	if (r.status !== 0) { bad.push(`${name}: hc failed: ${(r.stdout + r.stderr).trim()}`); continue; }
	const b = fs.readFileSync(o);
	if (!blob) { S.push({ name, stage: 2, wgsl: b.toString(), binds: null, inputs: [] }); continue; }
	const u16 = i => b.readUInt16LE(i), u32 = i => b.readUInt32LE(i), nin = b[7], nub = u16(30), nwb = u16(64), wo = u32(56), ws = u32(60);
	if (b.toString('latin1', 0, 4) !== 'GSHD' || u16(4) !== 2) { bad.push(`${name}: not a version 2 shader blob`); continue; }
	let q = 68 + 4 * nub; const inputs = [], binds = [];
	for (let k = 0; k < nin; k++, q += 2) inputs.push([b[q], b[q + 1]]);
	for (let k = 0; k < nwb; k++, q += 4) binds.push({ group: b[q], binding: b[q + 1], kind: b[q + 2], info: b[q + 3] });
	S.push({ name, stage: b[6], wgsl: b.toString('utf8', wo, wo + ws), binds, inputs });
}
const has = n => S.some(s => s.name === n), P = S.filter(s => s.stage === 1).map(s => { const f = s.name.replace(/_frag$/, ''); return [has(f + '_vert') ? f + '_vert' : ['depth_only', 'normals'].includes(f) ? 'surface_vert' : 'screen_vert', s.name]; });
const page = async (S, P) => {
	const ad = await navigator.gpu.requestAdapter(), dev = await ad.requestDevice(), M = {}, out = { mods: {}, pipes: {} }, by = Object.fromEntries(S.map(s => [s.name, s]));
	const FMT = { 1: 'rgba32float', 2: 'rgba16float', 3: 'r32float', 4: 'rgba8unorm', 32: 'rgba8uint', 33: 'r32uint', 6: 'rg32float', 7: 'rg16float', 9: 'r16float' }, DIM = ['2d', 'cube', '3d', '2d-array'];
	const VF = { 1: ['sint32', 4], 2: ['uint32', 4], 3: ['float32', 4], 4: ['sint32x2', 8], 5: ['uint32x2', 8], 6: ['float32x2', 8], 7: ['sint32x3', 12], 8: ['uint32x3', 12], 9: ['float32x3', 12], 10: ['sint32x4', 16], 11: ['uint32x4', 16], 12: ['float32x4', 16] };
	for (const s of S) { const m = dev.createShaderModule({ code: s.wgsl }); M[s.name] = m; out.mods[s.name] = (await m.getCompilationInfo()).messages.map(x => `${x.type} ${x.lineNum}:${x.linePos} ${x.message}`); }
	const ent = (b, st) => { const k = b.kind, e = { binding: b.binding, visibility: [GPUShaderStage.VERTEX, GPUShaderStage.FRAGMENT, GPUShaderStage.COMPUTE][st] }; if (k <= 3) e.buffer = { type: ['uniform', 'read-only-storage', 'storage'][k - 1] }; else if (k <= 6) e.texture = { sampleType: ['float', 'uint', 'depth'][k - 4], viewDimension: DIM[b.info] }; else if (k <= 8) e.sampler = { type: k === 7 ? 'filtering' : 'comparison' }; else e.storageTexture = { access: ['write-only', 'read-only', 'read-write'][k - 9], format: FMT[b.info] }; return e; };
	const lay = ss => { if (ss.some(s => !s.binds)) return 'auto'; const g = [[], [], [], []]; for (const s of ss) for (const b of s.binds) g[b.group].push(ent(b, s.stage)); const n = Math.max(0, ...ss.flatMap(s => s.binds.map(b => b.group + 1))); return dev.createPipelineLayout({ bindGroupLayouts: g.slice(0, n).map(entries => dev.createBindGroupLayout({ entries })) }); };
	const vb = s => { let off = 0; const attributes = [...s.inputs].sort((a, b) => a[0] - b[0]).map(([loc, ty]) => { const [format, n] = VF[ty]; const a = { shaderLocation: loc, offset: off, format }; off += n; return a; }); return attributes.length ? [{ arrayStride: off, attributes }] : []; };
	const tg = s => { const m = /struct cf_ps_out\n\{\n([\s\S]*?)\}/.exec(s.wgsl), t = []; for (const [, l, ty] of (m ? m[1] : '').matchAll(/@location\((\d+)\) \w+: (\w+(?:<\w+>)?)/g)) { const n = /^vec(\d)/.exec(ty), c = n ? +n[1] : 1, k = /i32/.test(ty) ? 'sint' : /u32/.test(ty) ? 'uint' : 'float'; t[+l] = { format: k === 'float' ? ['r16float', 'rg16float', 'rg16float', 'rgba16float'][c - 1] : `${['r', 'rg', 'rg', 'rgba'][c - 1]}32${k}` }; } return t; };
	const run = async (key, f) => { dev.pushErrorScope('validation'); try { f(); } catch (e) { out.pipes[key] = String(e); await dev.popErrorScope(); return; } const e = await dev.popErrorScope(); out.pipes[key] = e ? e.message : 'ok'; };
	for (const [v, f] of P) if (by[v] && by[f]) await run(`${v} + ${f}`, () => dev.createRenderPipeline({ layout: lay([by[v], by[f]]), vertex: { module: M[v], entryPoint: 'main', buffers: vb(by[v]) }, fragment: { module: M[f], entryPoint: 'main', targets: tg(by[f]) }, primitive: { topology: 'triangle-list' }, ...(tg(by[f]).length ? {} : { depthStencil: { format: 'depth32float', depthWriteEnabled: true, depthCompare: 'less' } }) }));
	for (const s of S.filter(s => s.stage === 2)) await run(s.name, () => dev.createComputePipeline({ layout: lay([s]), compute: { module: M[s.name], entryPoint: 'main' } }));
	const i = ad.info || {}; out.gpu = `${i.vendor} ${i.architecture} ${i.description}`.trim(); return JSON.stringify(out);
};
fs.writeFileSync(path.join(T, 'v.html'), '<!doctype html><title>wgsltest</title>');
const chrome = process.env.CHROME || ['google-chrome-stable', 'google-chrome', 'chromium', 'chromium-browser'].find(c => spawnSync('sh', ['-c', `command -v ${c}`]).status === 0);
if (!chrome) { console.log('wgsltest: SKIPPED (no Chrome; set CHROME)'); process.exit(0); }
const ch = spawn(chrome, ['--headless=new', '--remote-debugging-port=0', `--user-data-dir=${T}/prof`, '--enable-unsafe-webgpu', '--enable-features=Vulkan', '--use-angle=vulkan', '--no-first-run', '--no-default-browser-check', `file://${T}/v.html`], { stdio: 'ignore', env: { ...process.env, TMPDIR: '/tmp' } });
const done = c => { try { ch.kill('SIGKILL'); } catch {} setTimeout(() => { fs.rmSync(T, { recursive: true, force: true }); process.exit(c); }, 300); };
try {
	let port = '';
	for (let k = 0; k < 140 && !port; k++) { await new Promise(r => setTimeout(r, 100)); try { port = fs.readFileSync(`${T}/prof/DevToolsActivePort`, 'utf8').split('\n')[0]; } catch {} }
	let tgt; for (let k = 0; k < 140 && !tgt; k++) { try { tgt = (await (await fetch(`http://127.0.0.1:${port}/json/list`)).json()).find(t => t.type === 'page' && t.url.endsWith('v.html')); } catch {} if (!tgt) await new Promise(r => setTimeout(r, 100)); }
	if (!tgt) throw new Error(`no page target on port ${port}`);
	const ws = new WebSocket(tgt.webSocketDebuggerUrl); await new Promise((r, j) => { ws.onopen = r; ws.onerror = j; });
	const res = await new Promise(r => { ws.onmessage = m => { const d = JSON.parse(m.data); if (d.id === 1) r(d.result); }; ws.send(JSON.stringify({ id: 1, method: 'Runtime.evaluate', params: { expression: `(${page})(${JSON.stringify(S)}, ${JSON.stringify(P)})`, awaitPromise: true, returnByValue: true } })); });
	ws.close();
	if (!res.result || res.result.type !== 'string') { console.log('wgsltest: the page failed:', JSON.stringify(res.exceptionDetails || res).slice(0, 2000)); done(1); }
	else {
		const out = JSON.parse(res.result.value); let fail = bad.length, warn = 0;
		for (const b of bad) console.log('FAIL', b);
		for (const [n, ms] of Object.entries(out.mods)) { const e = ms.filter(m => m.startsWith('error')); fail += e.length > 0; warn += ms.length - e.length; console.log(e.length ? 'FAIL' : 'ok  ', 'module', n, ms.length ? '\n\t' + ms.join('\n\t') : ''); }
		for (const [n, m] of Object.entries(out.pipes)) { fail += m !== 'ok'; console.log(m === 'ok' ? 'ok  ' : 'FAIL', 'pipeline', n, m === 'ok' ? '' : '\n\t' + m); }
		console.log(`wgsltest: ${Object.keys(out.mods).length} modules, ${Object.keys(out.pipes).length} pipelines, ${fail} failures, ${warn} warnings on ${out.gpu}`); done(fail ? 1 : 0);
	}
} catch (e) { console.log('wgsltest: could not drive Chrome:', e.message); done(1); }
