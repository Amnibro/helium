import random,sys,os,subprocess,tempfile,pathlib
T={'int':(64,1),'uint':(64,0),'i32':(32,1),'u32':(32,0),'i16':(16,1),'u16':(16,0),'i8':(8,1),'u8':(8,0)}
DS=[1,2,3,4,5,6,7,9,10,11,12,13,16,25,31,60,64,97,100,125,127,128,255,256,641,1000,1024,4096,10007,65535,65536,1000000,2147483647,2147483648,4294967295,4294967296,4294967297,1099511627783,(1<<61)+1,(1<<62)-1,(1<<62),(1<<63)-25,(1<<63),(1<<64)-1,(1<<64)-2,(1<<63)+1]
r=random.Random(int(sys.argv[1]) if len(sys.argv)>1 else 7);L=['use std'];M=['main():']
def ok(t,d):
    b,s=T[t];return (-(1<<(b-1))<=d<(1<<(b-1))) if s else (0<d<(1<<b))
def lit(t,d): return f'({d} as! {t})' if d>=0 else f'(({d}) as! {t})'
fs=[]
for t in T:
    ds=[d for d in DS+[-x for x in DS] if ok(t,d) and d not in (0,-1)]
    for i,d in enumerate(ds):
        L.append(f'q_{t}_{i}(n {t}) {t}: n / {lit(t,d)}');L.append(f'm_{t}_{i}(n {t}) {t}: n % {lit(t,d)}');fs.append((t,i))
b=[0,1,2,3,5,7,63,64,65,99,100,127,128,129,255,256,1000,999999,1000000,2147483647,2147483648,4294967295,4294967296,(1<<62)-1,(1<<63)-1,(1<<63),(1<<63)+1,(1<<64)-1,(1<<64)-2]+[r.getrandbits(64) for _ in range(30)]+[r.getrandbits(r.randint(1,40)) for _ in range(30)]
vals=sorted(set(b+[((1<<64)-x)%(1<<64) for x in b]))
M.append('\tvs uint[>..] ~= []')
for v in vals: M.append(f'\tvs.push({v})')
M.append('\th ~= 0 as uint')
for t,i in fs: M.append(f'\tfor v vs: x := v as! {t}; h = h * 31 + (q_{t}_{i}(x) as! uint); h = h * 37 + (m_{t}_{i}(x) as! uint)\n\tprint(str("{t} {i} ", h))')
R=pathlib.Path(__file__).resolve().parents[2];HC=sys.argv[2];env=dict(os.environ,HC_LIB=str(R/'hc'/'lib'))
with tempfile.TemporaryDirectory() as w:
    (pathlib.Path(w)/'d.he').write_text('\n'.join(L+M)+'\n');o=[]
    for a in (['d.he','n','--native'],['d.he','d.c']): subprocess.run([HC]+a,cwd=w,env=env,check=True)
    subprocess.run(['clang','-O1','-fwrapv','-w','-I',str(R/'hc'),'d.c','-o','c','-lm'],cwd=w,check=True)
    for x in ('./n','./c'): o.append(subprocess.run([x],cwd=w,capture_output=True).stdout)
    print(f'{len(fs)} type/divisor pairs, native and C', 'match' if o[0]==o[1] else 'DIFFER');sys.exit(0 if o[0]==o[1] else 1)
