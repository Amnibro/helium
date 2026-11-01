import random,sys,os,subprocess,tempfile,pathlib
T={'int':(64,1),'uint':(64,0),'i32':(32,1),'u32':(32,0),'i16':(16,1),'u16':(16,0),'i8':(8,1),'u8':(8,0)}
DS=[1,2,3,4,5,6,7,9,10,11,12,13,16,25,31,60,64,97,100,125,127,128,255,256,641,1000,1024,4096,10007,65535,65536,1000000,2147483647,2147483648,4294967295,4294967296,4294967297,1099511627783,(1<<61)+1,(1<<62)-1,(1<<62),(1<<63)-25,(1<<63),(1<<64)-1,(1<<64)-2,(1<<63)+1]
r=random.Random(int(sys.argv[1]) if len(sys.argv)>1 else 7);DS=DS+[r.randrange(2,1<<r.choice([8,16,32,48,63])) for _ in range(24)];L=['use std'];M=['main():']
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
def ex(dd):
    if dd<=0 or r.random()<0.3: return r.choice(['i','(i - 37)','(bs[i & 63] as int)','(sb[i & 63] as int)','(i & 255)','(i >> 3)','(i % 13)','(-i)','y','j','(((i as uint) >> 58) as int)','(((i as uint) * 11400714819323198485 >> 1) as! int)','(((i as uint) * 15183679541453049859 >> 3) as! int)','((((i as uint) + 9) * 13787848793156543929 >> 1) as! int)','(((18446744073709551615 - (i as uint)) >> 1) as! int)',str(r.choice([0,5,-5,1000,-1000,77]))])
    o=r.choice(['+','-','*','&','|','^','%','/']);k=r.choice([3,7,10,64,97,1000,-7])
    return f'({ex(dd-1)} {o} {k})' if o in '*%/' else f'({ex(dd-1)} {o} {ex(dd-1)})'
NG=40;L.append('var bs byte[>..<]\nvar sb i8[>..<]')
for g in range(NG):
    KS=[2,3,7,10,64,97,100,1000,65536,1000003,1000000000039,(1<<40)+15,(1<<61)+1,(1<<62)-1,(1<<62)+3];k1,k2=r.choice(KS),r.choice(KS)
    L+=[f'g{g}(lo int, hi int) uint:','\th ~= 0 as uint; j ~= 0; y ~= 0',f'\tfor i lo..hi:',f'\t\ty = if i % {r.choice([2,3,5])} == 0 {{ y - {r.randint(1,90)} }} else {{ y + {r.randint(0,9)} }}',f'\t\tx := {ex(3)}',f'\t\th = h * 31 + ((x / {k1}) as! uint); h = h * 37 + ((x % {k2}) as! uint); j += {r.randint(1,3)}','\th']
for wi,(cc,kk) in enumerate([(cc,kk) for cc in (1,5,77,1000) for kk in (3,7,97,1000003)]):
    L+=[f'w{wi}(lo int, hi int) uint:','\th ~= 0 as uint',f'\tfor i lo..hi:',f'\t\tx := (((18446744073709551615 - (i as uint)) >> 1) as! int) + {cc}',f'\t\th = h * 31 + ((x / {kk}) as! uint); h = h * 37 + ((x % {kk}) as! uint)','\th'];M.append(f'\tprint(str("w{wi} ", w{wi}(0, 2100), " ", w{wi}(-5, 5)))')
M.insert(1,'\tfor q 64:\n\t\tbs.push((q * 37 + 11) as! byte)\n\t\tsb.push((q * 41 - 120) as! i8)')
for g in range(NG): M.append(f'\tprint(str("g{g} ", g{g}(0, 500), " ", g{g}(-60, 90), " ", g{g}(7, 8)))')
R=pathlib.Path(__file__).resolve().parents[2];HC=sys.argv[2];env=dict(os.environ,HC_LIB=str(R/'hc'/'lib'))
with tempfile.TemporaryDirectory() as w:
    (pathlib.Path(w)/'d.he').write_text('\n'.join(L+M)+'\n');o=[]
    for a in (['d.he','n','--native'],['d.he','d.c']): subprocess.run([HC]+a,cwd=w,env=env,check=True)
    subprocess.run(['clang','-O1','-fwrapv','-w','-I',str(R/'hc'),'d.c','-o','c','-lm'],cwd=w,check=True)
    for x in ('./n','./c'): o.append(subprocess.run([x],cwd=w,capture_output=True).stdout)
    print(f'{len(fs)} type/divisor pairs, {NG} sign-mixed kernels, native and C', 'match' if o[0]==o[1] else 'DIFFER');sys.exit(0 if o[0]==o[1] else 1)
