import os,random,subprocess,sys,tempfile,pathlib,concurrent.futures as cf
R=pathlib.Path(__file__).resolve().parents[2];os.environ.setdefault('HC_LIB',str(R/'hc'/'lib'));HC=sys.argv[1];N=int(sys.argv[2]) if len(sys.argv)>2 else 200;S0=int(sys.argv[3]) if len(sys.argv)>3 else 1
def expr(r,src,d=0):
    if d>2 or r.random()<0.3: return r.choice([f'{r.choice(src)}[l]',f'{r.choice(src)}[l]',f'{r.uniform(-2,2):.3f}'])
    a=expr(r,src,d+1);b=expr(r,src,d+1);o=r.random()
    if o<0.3: return f'({a} + {b})'
    if o<0.5: return f'({a} - {b})'
    if o<0.75: return f'({a} * {b} * 0.5)'
    if o<0.88: return f'({a} / ({b} * {b} + 1.0))'
    return f'sqrt({a} * {a} + {b} * {b} + 0.25)'
def gen(seed):
    r=random.Random(seed);bad=r.random()<0.3;st=r.random()<0.15;ints=r.random()<0.1
    P=[f'p{i}' for i in range(r.randint(1,6))];T=[f't{i}' for i in range(r.randint(0,7))];ready=list(P)
    L=['import std;','import os;','import math;','extern fn fbits(x real) uint = "hr_f64_bits";']
    if st: L.append('struct Q { u real[8], v real[8] }')
    L+=['simd fn run(n int) uint {','	var acc = 0.0;']
    if st: L.append('	var q = Q { .. };')
    if ints: L.append('	var z int[8] = [1, 2, 3, 4, 5, 6, 7, 8];')
    for x in P: L.append(f'	var {x} real[8] = [{", ".join(f"{r.uniform(-1,1):.4f}" for _ in range(8))}];')
    L.append('	for s in n {')
    for x in T: L.append(f'		var {x} real[8] = [0.0; 8];')
    for _ in range(r.randint(2,10)):
        k=r.random();allx=P+T
        if k<0.35 and len(allx)>1:
            s=r.choice(ready);d=r.choice([x for x in allx if x!=s]);p=list(range(8));r.shuffle(p);L.append(f'		{d} = [{", ".join(f"{s}[{i}]" for i in p)}];')
            if d not in ready: ready.append(d)
        elif k<0.85:
            outs=r.sample(allx,r.randint(1,min(3,len(allx))));body='; '.join(f'{o}[l] = {expr(r,ready)}' for o in outs);w=r.random()
            if bad and w<0.15: L.append(f'		if s % 2 == 0 {{ for l in 8 {{ {body}; }} }}')
            elif bad and w<0.3: L.append(f'		for t in 2 {{ for l in 8 {{ {body}; }} }}')
            else: L.append(f'		for l in 8 {{ {body}; }}')
            for o in outs:
                if o not in ready: ready.append(o)
        elif k<0.93: L.append(f'		acc += {r.choice(ready)}[{r.randint(0,7)}];')
        elif bad and k<0.96: L.append(f'		{r.choice(allx)}[{r.randint(0,7)}] = acc * 0.5;')
        elif bad and k<0.98: L.append(f'		for l in 8 {{ acc += {r.choice(ready)}[l]; }}')
        elif st: L.append(f'		for l in 8 {{ q.u[l] = q.v[l] * 0.5 + {r.choice(ready)}[l]; q.v[l] = q.u[l] - 0.25; }}')
        elif ints: L.append('		for l in 8 { z[l] = z[l] * 3 + 1; }')
        else: L.append(f'		acc = acc * 0.5 + {r.choice(ready)}[{r.randint(0,7)}];')
    if bad and T and r.random()<0.5: L.append(f'		acc += {r.choice(T)}[{r.randint(0,7)}];')
    L.append('	}')
    L.append('	var h uint = fbits(acc);')
    for x in P: L.append(f'	for l in 8 {{ h = h * 1000003 + fbits({x}[l]); }}')
    if st: L.append('	for l in 8 { h = h * 1000003 + fbits(q.u[l]) + fbits(q.v[l]); }')
    if ints: L.append('	for l in 8 { h = h * 1000003 + z[l] as! uint; }')
    L+=['	return h;','}','fn main() {','	let a = args();','	var n = 3;','	if a.len > 1 { let v, ok = parse_int(a[1]); if ok { n = v; } }','	var o byte[>..] = [];','	format(o, run(n), "\\n");','	print(o);','}']
    return '\n'.join(L)+'\n'
def one(seed):
    src=gen(seed);w=tempfile.mkdtemp(prefix='hf');open(os.path.join(w,'p.amni'),'w').write(src);env=dict(os.environ);res=[];bins=[]
    for tag,e,fl in (('a',env,['--v4']),('b',dict(env,HC_NOVH='1'),['--v4']),('c',env,['--v3'])):
        c=subprocess.run([HC,'p.amni','p'+tag,'--native']+fl,cwd=w,env=e,capture_output=True,timeout=120)
        if c.returncode: return seed,'build '+w,c.stderr.decode()[-300:],False
        bins.append(open(os.path.join(w,'p'+tag),'rb').read())
        x=subprocess.run(['./p'+tag,str(1+seed%9)],cwd=w,capture_output=True,timeout=60);res.append((x.returncode,x.stdout))
    ok=res[0]==res[1]==res[2];used=bins[0]!=bins[1]
    if ok: subprocess.run(['rm','-rf',w])
    return seed,'ok' if ok else 'DIFF '+w,'',used
bad=0;used=0
with cf.ThreadPoolExecutor(int(os.environ.get('HFJ','8'))) as ex:
    for seed,st,err,u in ex.map(one,range(S0,S0+N)):
        used+=u
        if st!='ok': bad+=1;print(seed,st,err)
print(f'{N-bad}/{N} programs match with and without register homes ({used} used homes)')
