import os,random,subprocess,sys,tempfile,concurrent.futures as cf,pathlib
R=pathlib.Path(__file__).resolve().parents[2];HC=sys.argv[1];N=int(sys.argv[2]) if len(sys.argv)>2 else 500;S0=int(sys.argv[3]) if len(sys.argv)>3 else 1
T=['u8','i8','u16','i16','u32','i32','int','uint'];B={'u8':8,'i8':8,'u16':16,'i16':16,'u32':32,'i32':32,'int':64,'uint':64};OPS=['+=','+=','-=','^=','|=','&=']
def leaf(r,t,arrs,od,fe):
    k=r.random()
    if fe and k<0.5: return f'(v as! {t})'
    if k<0.62:
        n,_=r.choice(arrs);o=r.choice([0,0,0,1,2,-1,3,5,od,od+1,od-1,8,17]);return f'({n}[x + {o}] as! {t})' if o>=0 else f'({n}[x - {-o}] as! {t})'
    if k<0.74: return f'(u as! {t})'
    if k<0.78 and not fe: return f'(x as! {t})'
    return f'({r.randint(0,(1<<min(B[t],12))-1)} as {t})'
def ex(r,t,d,arrs,od,fe=False):
    if d<=0 or r.random()<0.22: return leaf(r,t,arrs,od,fe)
    k=r.random();e=lambda t2:ex(r,t2,d-1,arrs,od,fe)
    if k<0.12: return f'({e(t)} << {r.randint(0,B[t]-1)})'
    if k<0.28: return f'({e(t)} >> {r.randint(0,B[t]-1)})'
    if k<0.4: return f'({e(r.choice(T))} as! {t})'
    if k<0.48: return f'({e(t)} * {r.choice([2,4,8,3,5,16,7])})'
    return f'({e(t)} {r.choice(["+","+","-","*","&","|","^"])} {e(t)})'
def prog(seed):
    r=random.Random(seed);ks=[];N=r.choice([64,100,257,1000,4099])
    L=['xs_next(x uint) uint:\n\tv ~= x\n\tv ^= v << 13\n\tv ^= v >> 7\n\tv ^= v << 17\n\tv']
    for k in range(r.randint(3,7)):
        td,ta,tb=r.choice(T),r.choice(T),r.choice(T);od=r.choice([0,0,1,2,-1,4]);arrs=[('a',ta),('b',tb),('d',td)];tw=r.random()<0.2;mode=r.choice(['st','st','red','fe','last','glob','sl','sl','gat','gat']);ta='u8' if mode=='gat' and r.random()<0.8 else ta;arrs[0]=('a',ta);ks.append((td,ta,tb,tw and mode in('st','last')))
        L.append(f'k{k}(d {td}[>..]&, a {ta}[>..]&, b {tb}[>..]&, u int, lo int, hi int) int:')
        if mode=='fe':
            L+=[f'\tt ~= {r.randint(-1000,1000)}','\tfor v a:',f'\t\tt {r.choice(OPS)} {ex(r,"int",r.randint(0,3),arrs[:2],0,True).replace("[x ","[0 ")}','\tt'];continue
        if mode=='red':
            L+=[f'\tt ~= {r.randint(-1000,1000)}','\tfor x lo..hi:',f'\t\tt {r.choice(OPS)} ({ex(r,r.choice(T),r.randint(1,3),arrs,od)} as! int)']+([f'\t\td[x + {od+2}] = {ex(r,td,2,arrs,od)}'] if r.random()<0.3 else [])+['\tt'];continue
        if mode=='gat':
            g=r.choice([2,4,8,8,3]);o=r.choice([0,0,1,5,-1]);ix=f'x + {o} + k' if o>=0 else f'x - {-o} + k'
            L+=['\tt ~= 0','\tfor x lo..hi:',f'\t\tv uint ~= {r.randint(0,3)}',f'\t\tfor k {g}: v |= (a[{ix}] as{r.choice(["","","!"])} uint) << (8 * k)',f'\t\tt = t * 31 + (v as! int)']+([f'\t\td[x + {od+1}] = {ex(r,td,1,arrs,od)}'] if r.random()<0.3 else [])+['\tt'];continue
        if mode=='sl':
            sl=[('sa',ta),('sb',tb),('sd',td)];oa,ob,od2=(r.choice([0,0,1,2,3,5,8]) for _ in range(3))
            L+=['\tt ~= 0',f'\tsa := a[{oa}..hi + 8]',f'\tsb := b[{ob}..hi + 8]',f'\tsd := d[{od2}..hi + 8]','\tfor x lo..hi:',f'\t\tsd[x + {od+1}] = {ex(r,td,r.randint(1,4),sl,od)}']+([f'\t\tt += ({ex(r,r.choice(T),2,sl,od)} as! int)'] if r.random()<0.3 else [])+['\tt'];continue
        if mode=='glob':
            L+=['\tt ~= 0','\tfor x lo..hi:',f'\t\tG_{td}[x + {od+1}] = {ex(r,td,r.randint(1,3),arrs+[("G_"+td,td)],od)}','\tt'];continue
        ix=(lambda o:f'y * 16 + x + {o}' if o>=0 else f'y * 16 + x - {-o}') if tw else (lambda o:f'x + {o}' if o>=0 else f'x - {-o}');ind='\t\t\t' if tw else '\t\t';fx=lambda s:s.replace('[x ','[y * 16 + x ') if tw else s
        L+=['\tt ~= 0']+(['\tfor y 1..4:','\t\tfor x lo..hi:'] if tw else ['\tfor x lo..hi:'])+[f'{ind}d[{ix(od)}] = {fx(ex(r,td,r.randint(1,4),arrs,od))}']
        if r.random()<0.25: L.append(f'{ind}b[{ix(r.choice([0,1,3]))}] = {fx(ex(r,tb,r.randint(1,3),arrs,od))}')
        if mode=='last': L.append(f'{ind}t = {fx(ex(r,"int",2,arrs,od))}')
        L.append('\tt')
    for t in T: L+=[f'hs_{t}(v {t}[>..]&) int:\n\th ~= 0\n\tfor q v: h = h * 31 + q as! int\n\th',f'hg_{t}(v {t}[>..<]&) int:\n\th ~= 0\n\tfor q v: h = h * 31 + q as! int\n\th']
    L+=[f'var G_{t} {t}[>..<]' for t in T]+['main():',f'\tr uint ~= {seed * 2654435761 % (1<<40) + 1}']+[f'\tG_{t}.resize({N}, 0)' for t in T]
    for t in T:
        for j in range(2): L+=[f'\t{t}{j} {t}[>..] ~= []',f'\tfor i {N}:\n\t\tr = xs_next(r)\n\t\t{t}{j}.push(r as! {t})']
    for k,(td,ta,tb,tw) in enumerate(ks):
        for c in range(r.randint(2,5)):
            mx=N-24-(64 if tw else 0);lo=r.choice([3,4,5,9,17]) if r.random()>0.03 else r.randint(0,2);hi=r.choice([lo,lo+1,lo+7,lo+15,lo+16,lo+17,lo+33,mx,mx-1,mx-r.randint(0,40)])
            hi=max(lo,N+r.randint(0,40) if r.random()<0.012 else hi);dn=f'{td}0';an=f'{ta}{r.randint(0,1)}';bn=f'{tb}{r.randint(0,1)}'
            an=dn if r.random()<0.3 and ta==td else an;bn=dn if r.random()<0.2 and tb==td else bn;bn=an if r.random()<0.15 and tb==ta else bn
            L+=[f'\trr := k{k}({dn}, {an}, {bn}, {r.randint(-300,70000)}, {lo}, {hi})',f'\tprint(rr, " ", hs_{td}({dn}), " ", hs_{tb}({tb}0), " ", hs_{tb}({tb}1), " ", hg_{td}(G_{td}))']
    return '\n'.join(L)+'\n'
def one(seed):
    with tempfile.TemporaryDirectory() as w:
        (pathlib.Path(w)/'p.he').write_text(prog(seed));env=dict(os.environ,HC_LIB=str(R/'hc'/'lib'));out=[]
        for tag,e in (('s',dict(env,HC_NOVEC='1')),('v',env)):
            c=subprocess.run([HC,'p.he','p'+tag,'--native'],cwd=w,env=e,capture_output=True,timeout=60)
            if c.returncode: return seed,'compile',(c.stdout+c.stderr).decode(errors='replace')[:200]
            try: x=subprocess.run(['./p'+tag],cwd=w,capture_output=True,timeout=30);out.append((x.returncode,x.stdout))
            except subprocess.TimeoutExpired: out.append(('timeout',b''))
        return seed,('ok' if out[0]==out[1] else 'MISMATCH'),''
if __name__=='__main__':
    bad=0
    with cf.ThreadPoolExecutor(max(1,(os.cpu_count() or 2)//2)) as pool:
        for seed,st,msg in pool.map(one,range(S0,S0+N)):
            if st!='ok': bad+=1;print(seed,st,msg)
    print(f'{N-bad}/{N} programs match with and without HC_NOVEC');sys.exit(1 if bad else 0)
