import {spawn} from 'child_process';import fs from 'fs';import os from 'os';import path from 'path';
const [dir,mod]=process.argv.slice(2),port=+(process.env.PORT||8977),dbg=+(process.env.CDP||9377),hw=process.env.HW==='1',ud=fs.mkdtempSync(path.join(os.tmpdir(),'hgpu-'));
const sleep=t=>new Promise(r=>setTimeout(r,t)),srv=spawn('python3',['-m','http.server',String(port),'--bind','127.0.0.1'],{cwd:dir,stdio:'ignore'});
const flags=hw?['--enable-unsafe-webgpu','--enable-features=Vulkan,WebGPUService','--use-vulkan=native','--ignore-gpu-blocklist','--use-angle=vulkan']:['--use-angle=swiftshader','--enable-unsafe-swiftshader','--enable-unsafe-webgpu','--enable-features=Vulkan','--use-webgpu-adapter=swiftshader'];
const env=hw?{...process.env,HOME:ud,TMPDIR:ud,VK_DRIVER_FILES:'/usr/share/vulkan/icd.d/radeon_icd.json',MESA_VK_DEVICE_SELECT:'1002:7590',MESA_VK_DEVICE_SELECT_FORCE_DEFAULT_DEVICE:'1'}:{...process.env,HOME:ud,TMPDIR:ud};
const ch=spawn('google-chrome-stable',['--headless=new','--no-sandbox',...flags,'--remote-debugging-port='+dbg,'--user-data-dir='+ud,'about:blank'],{stdio:process.env.V?'inherit':'ignore',env});
let out;
try{
  let tgt;for(let i=0;i<80&&!tgt;i++){await sleep(250);try{tgt=(await(await fetch(`http://127.0.0.1:${dbg}/json`)).json()).find(t=>t.type==='page');}catch{}}
  const ws=new WebSocket(tgt.webSocketDebuggerUrl);await new Promise(r=>ws.onopen=r);let id=0;const pend={};ws.onmessage=m=>{const d=JSON.parse(m.data);if(d.id&&pend[d.id]){pend[d.id](d);delete pend[d.id];}};
  const cmd=(method,params={})=>new Promise(r=>{const i=++id;pend[i]=r;ws.send(JSON.stringify({id:i,method,params}));});
  await cmd('Page.enable');await cmd('Page.navigate',{url:`http://127.0.0.1:${port}/`});await sleep(800);
  const r=await cmd('Runtime.evaluate',{expression:`(async()=>{try{const m=await import('/${mod}?'+Date.now());const a=await navigator.gpu?.requestAdapter({powerPreference:'high-performance'});const info=a?.info||{};const res=await m.default();res.adapter=(info.vendor||'')+' '+(info.architecture||'')+' '+(info.description||'');return JSON.stringify(res);}catch(e){return JSON.stringify({err:String(e.stack||e)});}})()`,awaitPromise:true,returnByValue:true,timeout:600000});
  out=r.result?.result?.value||JSON.stringify({err:JSON.stringify(r.result||r)});
}finally{ch.kill();srv.kill();setTimeout(()=>fs.rmSync(ud,{recursive:true,force:true}),500);}
process.stdout.write(out+'\n');
