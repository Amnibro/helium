import * as H from './hgpu.js';import K from './wgsl_basic.js';
export default async()=>{const d=await H.device();if(!d)return{err:'no webgpu'};const errs={};for(const n in K){const e=await H.check(d,K[n]);if(e.length)errs[n]=e;}if(Object.keys(errs).length)return{errs};
const count=1000,x=new Float32Array(count),y=new Float32Array(count),ix=new Int32Array(count);for(let i=0;i<count;i++){x[i]=(i%17)*0.25-2.0;y[i]=i*0.5;ix[i]=i*7-3000;}
const bx=H.buffer(d,x),by=H.buffer(d,y),bix=H.buffer(d,ix),bo=H.buffer(d,count),bc=H.buffer(d,count);
await H.run(d,K.saxpy,count,{count,a:1.5},{x:bx,y:by});const xs=[];for(let i=0;i<count;i++)xs.push(i%2===0);
const flags=[true,false],res={y:[...await H.read(d,by)].slice(0,count)},outs=new Float32Array(count),cnts=new Uint32Array(count);
for(const f of flags){const bo2=H.buffer(d,count),bc2=H.buffer(d,count);await H.run(d,K.mix3,count,{count,k:13,w:0.75,flag:f},{xs:bx,ix:bix,out:bo2,cnt:bc2});const o=await H.read(d,bo2),c=await H.read(d,bc2,Uint32Array);for(let i=0;i<count;i++)if((i%2===0)===f){outs[i]=o[i];cnts[i]=c[i];}}
res.out=[...outs];res.cnt=[...cnts];return res;};
