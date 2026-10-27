import os,random,subprocess,sys,tempfile,concurrent.futures as cf,pathlib
R=pathlib.Path(__file__).resolve().parents[2];HC=sys.argv[1];N=int(sys.argv[2]) if len(sys.argv)>2 else 200;S0=int(sys.argv[3]) if len(sys.argv)>3 else 1
F=[('a','int'),('b','i32'),('c','i32'),('d','byte'),('e','u16'),('f','f32'),('g','f64'),('h','int')]
def val(r,t,src):
    k=r.random()
    if k<0.4 and src: return f'({r.choice(src)} as! {t})' if t not in('f32','f64') else f'({r.choice(src)} as {t})'
    if t=='f32' or t=='f64': return f'({r.randint(-50,50)}.5 as {t})'
    return f'({r.randint(0,200)} as! {t})'
def prog(seed):
    r=random.Random(seed);L=['use std','struct S { '+', '.join(f'{n} {t}' for n,t in F)+' }','let K = S{'+', '.join(f'{r.randint(1,9)} as! {t}' if t not in('f32','f64') else f'{r.randint(1,9)}.25' for n,t in F)+'}','var GV = S{1, 2, 3, 4, 5, 6.0, 7.0, 8}','var GA int[>..] = []']
    L.append('h(s S&) int: (s.a + s.b + s.c + s.d + s.e + s.h) + (s.f * 4.0) as int + (s.g * 8.0) as int')
    for k in range(r.randint(2,5)):
        L.append(f'k{k}(p S&, q S&, xs S[>..]&, n int) int:');L.append('\tt ~= 0')
        body=[];src=['t','n','p.a','q.b','K.a','K.c','GV.h']
        for z in range(r.randint(4,14)):
            n,ty=r.choice(F);who=r.choice(['p','q','xs[0]','xs[1]','GV']);m=r.random()
            if m<0.45: body.append(f'{who}.{n} = {val(r,ty,src)}')
            elif m<0.75: body.append(f't += ({who}.{n} as! int)' if ty not in('f32','f64') else f't += ({who}.{n} * 2.0) as int')
            elif m<0.82: body.append(f't += h({who})')
            elif m<0.9: body.append(f't += K.{n} as! int' if ty not in('f32','f64') else f't += (K.{n} * 3.0) as int')
            else: body.append(f'GA.push(t)')
        if r.random()<0.6:
            L.append('\tfor i n:');L+=['\t\t'+b for b in body]
        else: L+=['\t'+b for b in body]
        L.append('\tt + h(p) + h(q)')
    L.append('main():');L.append('\tps S[>..] ~= []');L.append('\tfor i 3: ps.push(S{i, 2, 3, 4, 5, 6.0, 7.0, 8})')
    for k in range(5):
        a,b=r.choice([('ps[0]','ps[0]'),('ps[0]','ps[1]'),('ps[1]','ps[0]'),('ps[2]','ps[2]'),('GV','ps[0]'),('GV','GV')])
        L.append(f'\tprint(str(k{r.randint(0,0)}({a}, {b}, ps, {r.randint(0,5)}), " ", h(ps[0]), " ", h(ps[1]), " ", h(GV), " ", GA.len))'.replace('k0(',f'k{r.randint(0,len([l for l in L if l.startswith("k") and "(p S&" in l])-1)}('))
    return '\n'.join(L)+'\n'
def one(seed):
    with tempfile.TemporaryDirectory() as w:
        (pathlib.Path(w)/'p.he').write_text(prog(seed));env=dict(os.environ,HC_LIB=str(R/'hc'/'lib'));out=[]
        for tag,e,a in (('o',env,['--native']),('n',dict(env,HC_NOOPT='1'),['--native']),('c',env,[])):
            c=subprocess.run([HC,'p.he','p'+tag+('.c' if tag=='c' else '')]+a,cwd=w,env=e,capture_output=True,timeout=60)
            if c.returncode: return seed,'compile',(c.stdout+c.stderr).decode(errors='replace')[:300]
            if tag=='c':
                c=subprocess.run(['clang','-O1','-fwrapv','-w','-I',str(R/'hc'),'pc.c','-o','pc','-lm'],cwd=w,capture_output=True)
                if c.returncode: return seed,'cc',c.stderr.decode()[:200]
            x=subprocess.run(['./p'+tag],cwd=w,capture_output=True,timeout=30);out.append((x.returncode,x.stdout))
        return seed,('ok' if out[0]==out[1]==out[2] else 'MISMATCH'),'' if out[0]==out[1]==out[2] else f'opt={out[0][1][:80]} noopt={out[1][1][:80]} c={out[2][1][:80]}'
if __name__=='__main__':
    bad=0
    with cf.ThreadPoolExecutor(8) as pool:
        for seed,st,msg in pool.map(one,range(S0,S0+N)):
            if st!='ok': bad+=1;print(seed,st,msg)
    print(f'{N-bad}/{N} match')
