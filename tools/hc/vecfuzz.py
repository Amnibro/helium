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
def cond(r,d,bs):
    if d<=0 or r.random()<0.3:
        k=r.random()
        if k<0.25: return r.choice(bs) if r.random()<0.7 else '!'+r.choice(bs)
        v=lambda:r.choice(['p','q','c','h','lo',f'({r.randint(0,9)} as uint)','(x as! uint)'])
        return f'{v()} {r.choice(["<","<=",">",">=","==","!="])} {v()}'
    return f'({cond(r,d-1,bs)} {r.choice(["&&","||"])} {cond(r,d-1,bs)})'
def brk(r,od):
    bs=['f','g'];C=lambda:cond(r,r.randint(0,3),bs);L=['\tt ~= 0','\tc uint ~= 0','\th uint ~= 0','\tf ~= false','\tg ~= true','\tfor x lo..hi:',f'\t\tp := a[x + {r.choice([0,1,2,3])}] as! uint',f'\t\tq := b[x + {r.choice([0,1,2,od+2])}] as! uint','\t\tlo ~= p * q']
    for _ in range(r.randint(3,9)):
        k=r.randint(0,10);v=r.choice(['c','h'])
        L.append({0:lambda:f'\t\tif {C()} {{ {v}++ }}',1:lambda:f'\t\tif {C()} {{ {v}-- }}',2:lambda:f'\t\tt += if {C()} {{ 1 }} else {{ 0 }}',3:lambda:f'\t\t{v} = if {C()} {{ {v} + 1 }} else {{ {v} }}',4:lambda:f'\t\t{v} = if {C()} {{ {v} }} else {{ {v} - 1 }}',5:lambda:f'\t\t{r.choice(bs)} = {C()}',6:lambda:f'\t\tg = {C()} || (g && {C()})',7:lambda:f'\t\tif {C()} {{ f = true; {v} += 1 }}',8:lambda:'\t\th = mh(p, q + c)\n\t\tlo += c\n\t\tif lo < c { h++ }\n\t\tc = h',9:lambda:f'\t\tif {C()} {{ continue }}',10:lambda:f'\t\tc = if lo < c {{ h + 1 }} else {{ h }}'}[k]())
    return L+['\t\tt = t * 31 + (c as! int) + (h as! int) * 7 + (lo as! int) + (if f { 3 } else { 0 }) + (if g { 5 } else { 0 })','\tt']
def unk(r):
    k0=r.randint(0,4);N=k0+r.randint(1,9);nest=r.random()<0.3;ind='\t\t\t' if nest else '\t\t'
    st=[lambda:f'{ind}t += (a[k + {r.randint(0,5)}] as! int) * {r.randint(1,9)}',lambda:f'{ind}t ^= (k as! int) << {r.randint(0,7)}',lambda:f'{ind}if (b[k + {r.randint(0,3)}] as! int) & 1 == 0: t += k as! int',lambda:f'{ind}d[k + {r.randint(1,4)}] = (t as! int) as! {"{td}"}',lambda:f'{ind}t = t * 3 + (a[{{ k += 0; k }}] as! int)']
    body=[r.choice(st)() for _ in range(r.randint(1,5))];p=r.randint(0,len(body));body.insert(p,f'{ind}k += 1')
    if r.random()<0.4: body.insert(r.randint(p+1,len(body)),f'{ind}if t & 3 == 0: continue')
    L=['\tt ~= 0']+(['\tfor y 2:',f'\t\tk ~= {k0}',f'\t\twhile k < {N}:'] if nest else [f'\tk ~= {k0}',f'\twhile k < {N}:'])
    return L+[x.replace('\t\t','\t\t\t',1) if nest else x for x in []]+body+['\tt']
def whk(r,td):
    c=lambda:r.choice(['t & 7 != 3','t < 100000000','(t ^ (k as! int)) & 1 == 0','k != lo + 3','t >= 0','f','!f'])
    h=lambda d:c() if d<=0 or r.random()<0.4 else f'({h(d-1)} {r.choice(["&&","||"])} {h(d-1)})'
    b=r.choice(['k < hi','k < a.len - 8','k + 4 < b.len && k < hi'])
    L=['\tt ~= 0','\tf ~= false','\tk ~= lo',f'\twhile {b} && {h(2)}:','\t\tt += a[k] as! int',f'\t\tf = t & {r.choice([1,3,5])} == 0']
    if r.random()<0.5: L.append(f'\t\td[k + 1] = (t as! int) as! {td}')
    return L+['\t\tk += 1','\tt']
def slk(r,k):
    ft=r.choice(['f32','f64']);W=r.choice([4,8,8,12,16,20,32]);P=[f'P{i}' for i in range(r.randint(2,4))];sh=r.random()<0.3;rg=f'1..{W - 1}' if sh else f'{W}'
    ix=lambda:r.choice(['k','k','k','k','k + 1','k - 1']) if sh else 'k'
    def fe(dd):
        if dd<=0 or r.random()<0.3:
            q=r.random()
            if q<0.55: return f'{r.choice(P)}[{ix()}]'
            if q<0.75: return f'({r.choice(["1.5","0.25","-3.0","7.0","0.5"])} as {ft})'
            return r.choice(['s','(u as '+ft+')'])
        return f'({fe(dd-1)} {r.choice(["+","+","-","*","*","/"])} {fe(dd-1)})'
    L=[f'{"simd " if r.random()<0.7 else ""}k{k}(d {{td}}[>..]&, a {{ta}}[>..]&, b {{tb}}[>..]&, u int, lo int, hi int) int:']+[f'\t{q} {ft}[{W}] ~= [0.0; {W}]' for q in P]+['\tlv ~= 0.0 as '+ft,'\tt ~= 0']
    L+=[f'\tfor k {W}: {q}[k] = (k as {ft}) * ({r.choice(["0.5","1.25","-0.75"])} as {ft}) + (u as {ft}) * (0.001 as {ft})' for q in P]
    L+=['\tfor x lo..hi:',f'\t\ts := FA_{ft}[x]',f'\t\tfor k {rg}:']+[f'\t\t\t{r.choice(P)}[{"k" if r.random()<0.8 else ix()}] {r.choice(["=","+=","-=","*="])} {fe(r.randint(1,3))}' for _ in range(r.randint(1,4))]
    if r.random()<0.3: L.append(f'\t\t\tlv = {r.choice(P)}[k]')
    if r.random()<0.3: L.append(f'\t\td[x] = (({fe(1).replace("[k + 1]","[1]").replace("[k - 1]","[0]").replace("[k]","[0]")}) as! int) as! {{td}}')
    for q in P+['lv']: L+=[f'\tfor k {W}:' if q!='lv' else '\tif true:',f'\t\tz := str({q + "[k]" if q!="lv" else q})','\t\tfor c z: t = t * 31 + c as int']
    return L+['\tt']
def cmk(r,ta):
    op=lambda:r.choice(['<','<=','>','>=','==','!='])
    rhs=lambda:r.choice(['(u as! i8) as int','(u as! i16) as int','(u as! i32) as int','u','w','w','3','-2','100','40000','(b[x] as! int)',f'(a[x + {r.choice([0,1,2])}] as! int)'])
    if r.random()<0.3:
        ft=r.choice(['f32','f64']);fa=lambda:r.choice([f'FA_{ft}[x]',f'FB_{ft}[x + 1]',f'(FA_{ft}[x] / FB_{ft}[x + 2])',f'({r.choice(["0.5","4.0","-1.0","0.0"])} as {ft})',f'(FD_{ft}[x] * FA_{ft}[x])'])
        if r.random()<0.5: return ['\tfl ~= false','\tfor x lo..hi:',f'\t\tif {fa()} {op()} {fa()} {{ fl = true }}','\tif fl { 1 } else { 0 }']
        return ['\tt ~= 0','\tfor x lo..hi:',f'\t\tt += if {fa()} {op()} {fa()} {{ 1 }} else {{ 0 }}','\tt']
    if r.random()<0.35:
        W=r.choice([4,8,16,16]);return ['\tt ~= 0',f'\tth i32[{W}] ~= [0x7FFFFFFF; {W}]',f'\tfor q {W}: th[q] = ((q * {r.randint(1,9000)}) as! i32) - {r.randint(0,30000)}','\tfor x lo..hi:','\t\tv := (a[x] as! int) * '+str(r.choice([1,7,-3,1000])),'\t\tr2 := (v as! i32)','\t\tk ~= 0',f'\t\tfor e th: k {r.choice(["+=","-="])} if e {op()} r2 {{ 1 }} else {{ 0 }}','\t\tt = t * 7 + k','\tt']
    return ['\tt ~= '+str(r.randint(-50,50)),f'\tw := u ^ (u << {r.choice([15,31,33])})','\tfor x lo..hi:',f'\t\tt {r.choice(["+=","+=","-="])} if (a[x] as! int) {op()} {rhs()} {{ 1 }} else {{ 0 }}']+([f'\t\tt += if (b[x] as! int) {op()} {rhs()} {{ 1 }} else {{ 0 }}'] if r.random()<0.3 else [])+['\tt']
def prog(seed):
    r=random.Random(seed);ks=[];N=r.choice([64,100,257,1000,4099])
    L=['RONES uint := 0xFFFFFFFFFFFFFFFF']+[f'RT{n} uint[{n}] := ['+', '.join(str((i*0x9E3779B97F4A7C15>>7)&0xFFFFFFFFFFFF) for i in range(n))+']' for n in (16,64,256)]+['mh(a uint, b uint) uint:\n\tal := a & 0xffffffff; ah := a >> 32; bl := b & 0xffffffff; bh := b >> 32\n\tll := al * bl; lh := al * bh; hl := ah * bl; hh := ah * bh\n\tmid := (ll >> 32) + (lh & 0xffffffff) + (hl & 0xffffffff)\n\thh + (lh >> 32) + (hl >> 32) + (mid >> 32)','xs_next(x uint) uint:\n\tv ~= x\n\tv ^= v << 13\n\tv ^= v >> 7\n\tv ^= v << 17\n\tv']
    for k in range(r.randint(3,7)):
        td,ta,tb=r.choice(T),r.choice(T),r.choice(T);od=r.choice([0,0,1,2,-1,4]);arrs=[('a',ta),('b',tb),('d',td)];tw=r.random()<0.2;mode=r.choice(['st','st','red','fe','last','glob','sl','sl','gat','gat','flt','flt','flt','br','br','br','unr','unr','whl','whl','slt','slt','cmp','cmp','cmp','cmp','stf','stf','cry','cry','rot','rot','rs','rs','lx','lx','lmb','lmb','lmb','lmb2','lmb2','lmb2','lmb3','lmb3','lmb3','lmb3','lmb4','lmb4','lmb4','fib','fib','fib','callx','callx','callx','callx','rng','rng','rng','rng']);td,ta,tb=[r.choice(['int','uint']) for _ in range(3)] if mode in('lmb3','lmb4') else (td,ta,tb);arrs=[('a',ta),('b',tb),('d',td)];ta='u8' if mode=='gat' and r.random()<0.8 else ta;arrs[0]=('a',ta);ks.append((td,ta,tb,tw and mode in('st','last')))
        L.append(f'k{k}(d {td}[>..]&, a {ta}[>..]&, b {tb}[>..]&, u int, lo int, hi int) int:')
        if mode=='cmp': L+=cmk(r,ta);continue
        if mode=='rot':
            tt=r.choice(['u32','uint']);W=32 if tt=='u32' else 64;k=r.randint(1,W-1);op=r.choice(['|','^','+'])
            L+=[f'\tt ~= 0 as {tt}','\tfor x lo..hi:',f'\t\tv := (a[x + 1] as! {tt}) * (0x9E3779B9 as {tt}) + (u as! {tt})',(f'\t\tt = t + ((v << {k}) {op} (v >> {W - k}))' if r.random()<0.5 else f'\t\tt = t ^ ((v >> {W - k}) {op} (v << {k}))'),'\t(t as! int)'];continue
        if mode=='cry':
            L+=['\tt ~= 0 as uint','\th ~= 0 as uint','\tfor x lo..hi:','\t\tp := (a[x + 1] as! uint) * 0x9E3779B97F4A7C15','\t\tq := (b[x + 2] as! uint) ^ ((u as! uint) << 61)']
            for _ in range(r.randint(1,3)):
                v=r.choice(['p','q','t','(p >> 3)']);w=r.choice(['p','q','t','h']);cmpv=r.choice([v,w,w,'p','q'])
                op=r.choice(['<','<','>','<=']) ;L+=[f'\t\ts := {w} + {v}',f'\t\tif s {op} {cmpv} {{ h += {r.choice(["1","1","2"])} }}' if op!='>' else f'\t\tif {cmpv} > s {{ h += 1 }}',('\t\tt = s' if w=='t' and r.random()<0.5 else '\t\tt = t ^ s')]
            L+=['\t(t ^ (h << 7)) as! int'];continue
        if mode=='stf': o1,o2=r.choice([0,1,2]),r.choice([0,0,1,2]);L+=['	t ~= 0','	for x lo..hi:',f'		d[x + {o1}] = (a[x + 2] as! {td}) {r.choice(["+","^","-"])} (u as! {td})',f'		t += (d[x + {o2}] as! int)']+([f'		b[x] = (d[x + {o1}] as! {tb})'] if r.random()<0.4 else [])+['	t'];continue
        if mode=='lmb4':
            oa,od2=r.choice([0,0,1,2]),r.choice([0,0,1]);L+=['\tm := (u as! uint) * 0x9E3779B97F4A7C15 | 1','\tc ~= '+r.choice(['0 as uint','(u & 7) as! uint']),f'\taa := a[lo + {oa}..hi + {oa}]',f'\tdd := d[lo + {od2}..hi + {od2}]','\tassert(aa.len == dd.len)','\tfor x dd.len:','\t\tw := aa[x] as! uint','\t\tlo2 ~= w * m','\t\thi2 ~= mh(w, m)','\t\tlo2 += c','\t\tif lo2 < c { hi2 += 1 }']
            L+=(['\t\ty := (dd[x] as! uint) + lo2','\t\tif y < lo2 { hi2 += 1 }','\t\tdd[x] = y as! '+td] if r.random()<0.6 else ['\t\tdd[x] = lo2 as! '+td])+(['\t\tu ^= w as! int'] if r.random()<0.25 else [])+(['\t\tu += (w >> 3) as! int'] if r.random()<0.1 else [])+['\t\tc = hi2','\t((c * 1000003) as! int) ^ u'];continue
        if mode=='callx':
            g=r.choice(['rfa','rfb']);L+=['\tt ~= u','\tq ~= 1']
            body=r.choice([['\t\tt0 := u + x * 3','\t\tt1 := '+g+'(t0, 3)','\t\tt = t * 3 + t1 + t0'],['\t\tt0 := t ^ x','\t\tt2 := q + 7','\t\tt1 := '+g+'(t0 & 1023, 4)','\t\tq = t2 * 3 + t1','\t\tt += t0 - t2'],['\t\tt0 := x * 5','\t\tif (t0 & 3) == 1 { q += '+g+'(t0, 2) }','\t\tt = t + t0 * q'],['\t\ta0 := t + 1','\t\ta1 := q ^ x','\t\ta2 := a0 * a1','\t\tt1 := '+g+'(a1 & 511, 3)','\t\tt2 := '+g+'(a0 & 255, 2)','\t\tt = a0 + a1 * 3 + a2 + t1 * 7 + t2','\t\tq += a2 & 15']])
            L+=['\tfor x lo..min(hi, lo + 40):']+body+['\t(t ^ q * 31) & 0xFFFFFFFFFFFF'];continue
        if mode=='rng':
            M=r.choice([3,7,15,31,63,255]);K=r.choice([0,1,2,3]);K2=r.choice([0,0,1,2,4]);ub=M<<K;TL=r.choice([16,64,256]);K3=max(0,ub.bit_length()-TL.bit_length()+1);K3=max(0,K3-1) if r.random()<0.2 else K3
            C=r.choice([ub,ub,ub-1,ub+1,ub>>1,0,M]);cm=r.choice(['!=','!=','==']);ux=r.random()<0.2;ix=f'(s >> {K3}) & {TL-1}' if ux else f's >> {K3}'
            L+=['\tt ~= 0 as uint','\tc ~= 0',f'\ts ~= ((u as! uint) & {M}) << {K}','\tfor x lo..hi:','\t\tv := a[x + 1] as! uint']
            body=[f'\t\tc += if s {cm} {C} {{ 1 }} else {{ 0 }}',f'\t\tt = t ^ (v & ~(RONES << (s >> {K2})))',f'\t\tt = (t & ~(RONES << (s >> {K2}))) | (v << 3)',f'\t\tt += RT{TL}[{ix}]',f'\t\tif s {cm} {C} {{ c += 2 }}']
            r.shuffle(body);L+=body[:r.randint(2,5)]
            L+=[(f'\t\tif v & 3 == 0 {{ s = v }} else {{ s = ((v ^ t) & {M}) << {K} }}' if ux else r.choice([f'\t\ts = ((v ^ t) & {M}) << {K}',f'\t\ts = (((v >> 5) ^ t) & {M}) << {K}',f'\t\ts = (v & {M}) << {K}']))]
            L+=['\t(t ^ (c as! uint) * 31) as! int'];continue
        if mode=='fib':
            L+=['\tp0 ~= (u as! uint) | 1','\tp1 ~= 7 as uint','\tp2 ~= 3 as uint','\tfor x lo..hi:']
            L+=[r.choice(['\t\tt := p0 + p1 * 3','\t\tt := p1 ^ (p0 << 1)','\t\tt := p0 * 5 + (x as uint)','\t\tt := p0 - p2'])]+[r.choice(['\t\tp0 = p1','\t\tp0 = p1 + 1','\t\tp2 = p0','\t\tp0 = p2 ^ p1'])]+r.choice([['\t\tp1 = t'],['\t\tp2 = p1','\t\tp1 = t'],['\t\tp1 = t','\t\tp2 = t + p0']])
            L+=['\t((p0 ^ p1 * 3 ^ p2 * 7) >> 1) as! int'];continue
        if mode=='lmb3':
            sub=r.random()<0.5;ip=r.random()<0.3;nest=r.random()<0.25;oa,ob,od2=r.choice([0,0,1,2]),r.choice([0,0,1,2]),r.choice([0,0,1]);I='\t\t\t' if nest else '\t\t'
            sl=r.random()<0.6;L+=['\tc ~= '+r.choice(['0 as uint','0 as uint','(u & 1) as! uint','1 as uint','(u as! uint) * 3 + 2'])]
            hv=r.random()<0.5;H='h2' if hv else 'hi';L+=(['\th2 := max(lo, hi - ((a[0] as! int) & 3))'] if hv else [])
            if sl: L+=[f'\taa := a[lo + {oa}..{H} + {oa}]',f'\tbb := b[lo + {ob}..{H} + {ob}]',f'\tdd := d[lo + {od2}..{H} + {od2}]']+([r.choice(['\tassert(aa.len == dd.len && bb.len == dd.len)','\tassert(dd.len == aa.len && dd.len == bb.len)','\tassert(aa.len == dd.len)'])] if r.random()<0.9 else [])
            L+=(['\tfor z 2:'] if nest else [])+[I[:-1]+('for x dd.len:' if sl else f'for x lo..{H}:'),I+((f'p := dd[x] as! uint' if ip else f'p := aa[x] as! uint') if sl else (f'p := d[x + {od2}] as! uint' if ip else f'p := a[x + {oa}] as! uint')),I+'q := '+r.choice(([f'bb[x] as! uint']*2+[f'aa[x] as! uint']) if sl else ([f'b[x + {ob}] as! uint']*2+[f'a[x + {oa}] as! uint'])+['0xFFFFFFFFFFFFFFFF as uint','(u as! uint) << 3'])]
            if not sub: L+=[I+'xs := p + q',I+'ys := xs + c',I+'c = '+r.choice(['if xs < p || ys < xs { 1 } else { 0 }','if ys < xs || xs < q { 1 } else { 0 }','if xs < p || ys < c { 1 } else { 0 }','if xs < q || ys < xs { 1 } else { 0 }'])]
            else: L+=[I+'xs := p - q',I+'ys := xs - c',I+'c = '+r.choice(['if p < q || xs < c { 1 } else { 0 }','if xs < c || p < q { 1 } else { 0 }','if p < q || ys < c { 1 } else { 0 }'])]
            L+=[I+(f'dd[x] = ys as! {td}' if sl else f'd[x + {od2}] = ys as! {td}')]+([I+'if c != 0 { u += 1 }'] if r.random()<0.1 else [])+([I+(f'bb[x] = c as! {tb}' if sl else f'b[x + {ob}] = c as! {tb}')] if r.random()<0.12 else [])+([I+'u ^= ys as! int'] if r.random()<0.07 else [])
            L+=['\t((c * 1000003) as! int) ^ u'];continue
        if mode=='lmb2':
            sub=r.random()<0.5;L+=['\tt ~= 0 as uint','\tc ~= '+r.choice(['0 as uint','(u & 1) as! uint','(u as! uint) * 3 + 2']),'\tfor x lo..hi:',f'\t\tp := (a[x + 1] as! uint) * 0x9E3779B97F4A7C15 ^ (u as! uint)',f'\t\tq := '+r.choice(['(b[x] as! uint) << 7','0xFFFFFFFFFFFFFFFF as uint','(b[x + 2] as! uint) * 0xD1B54A32D192ED03','p ^ 1'])]
            if not sub: L+=['\t\txs := p + q','\t\tys := xs + c','\t\tc = '+r.choice(['if xs < p || ys < xs { 1 } else { 0 }','if ys < xs || xs < q { 1 } else { 0 }','if xs < p || ys < c { 1 } else { 0 }'])]
            else: L+=['\t\txs := p - q','\t\tys := xs - c','\t\tc = '+r.choice(['if p < q || xs < c { 1 } else { 0 }','if xs < c || p < q { 1 } else { 0 }','if p < q || ys < c { 1 } else { 0 }'])]
            L+=['\t\tt = t * 5 + ys']+(['\t\tt ^= xs'] if r.random()<0.15 else [])+(['\t\tif c != 0 { t += 3 }'] if r.random()<0.2 else [])
            L+=['\t((t ^ c) >> 1) as! int'];continue
        if mode=='lmb':
            K=r.randint(2,5);sub=r.random()<0.5;L+=['\tt ~= 0 as uint','\tfor x lo..hi:','\t\tc ~= '+r.choice(['false','false','(u & 1) == 1'])]
            for k in range(K):
                av=f'((a[x + {k}] as! uint) * 0x9E3779B97F4A7C15 ^ (u as! uint))';bv=r.choice([f'((b[x + {k}] as! uint) << {r.choice([0,1,13,63])})','(0 - (b[x] as! uint))','0xFFFFFFFFFFFFFFFF as uint','(t ^ 0xFFFFFFFFFFFFFFF0)'])
                L+=[f'\t\tp{k} := {av}',f'\t\tq{k} := {bv}']
                if not sub:
                    L+=[f'\t\tx{k} := p{k} + q{k}',f'\t\tc1{k} := '+r.choice([f'x{k} < p{k}',f'x{k} < q{k}',f'p{k} > x{k}',f'x{k} < p{k}']),f'\t\ty{k} := if c {{ x{k} + 1 }} else {{ x{k} }}']
                    zt=r.choice([f'y{k}',f'y{k}',f'y{k}',f'x{k}']);L+=[f'\t\tc = '+r.choice([f'c1{k} || (c && {zt} == 0)',f'(c && {zt} == 0) || c1{k}',f'c1{k} || ({zt} == 0 && c)'])]
                else:
                    L+=[f'\t\tx{k} := p{k} - q{k}',f'\t\tc1{k} := '+r.choice([f'p{k} < q{k}',f'q{k} > p{k}']),f'\t\ty{k} := if c {{ x{k} - 1 }} else {{ x{k} }}']
                    zt=r.choice([f'x{k}',f'x{k}',f'x{k}',f'y{k}']);L+=[f'\t\tc = '+r.choice([f'c1{k} || (c && {zt} == 0)',f'(c && {zt} == 0) || c1{k}'])]
                L+=[f'\t\tt = t * 3 + y{k}']+([f'\t\tt ^= x{k}'] if r.random()<0.15 else [])+(['\t\tt += if c { 7 } else { 0 }'] if r.random()<0.2 else [])
            L+=['\t\tif c { t ^= 0x5555 }','\t(t >> 1) as! int'];continue
        if mode=='lx':
            W=r.choice([8,16,32]);R=r.choice([2,3,5,7]);op=lambda:r.choice(['+','^','-','|','&','*'])
            src=lambda:r.choice(['zz[k]','yy[k]','zz[k]','(u as! TD)','(j as! TD)','(k as! TD)',f'yy[{r.randint(0,W-1)}]' if r.random()<0.15 else 'zz[k]'])
            L+=[f'\tzz TD[{W}] ~= [(0 as! TD); {W}]',f'\tyy TD[{W}] ~= [(0 as! TD); {W}]',f'\tfor k {W}:','\t\tzz[k] = a[k + 2] as! TD','\t\tyy[k] = (b[k] as! TD) ^ (u as! TD)',f'\tfor j {R}:',f'\t\tfor k {W}:']
            for _ in range(r.randint(1,4)):
                L+=[f'\t\t\t{r.choice(["zz","yy"])}[k] = {src()} {op()} {src()}']
            L+=['\tt ~= 0',f'\tfor k {W}: t = t * 31 + (zz[k] as! int) + (yy[k] as! int)','\tt'];L[:]=[x.replace('TD',td) for x in L];continue
        if mode=='rs':
            o1=r.choice([0,0,1]);op=lambda:r.choice(["+","^","-","|"]);L+=['	t ~= 0','	for x lo..hi:',f'		d[x + {o1}] = (a[x + 2] as! {td}) {op()} (u as! {td})']
            for _ in range(r.randint(1,3)):
                L+=[f'		d[x + {o1}] = d[x + {o1}] {op()} (b[x + 1] as! {td})']+([f'		t += (d[x + {o1}] as! int)'] if r.random()<0.3 else [])
            L+=['	t'];continue
        if mode=='slt': L.pop();L+=[x.replace('{td}',td).replace('{ta}',ta).replace('{tb}',tb) for x in slk(r,k)];continue
        if mode=='br': L+=brk(r,od);continue
        if mode=='whl': L+=whk(r,td);continue
        if mode=='unr': L+=[x.replace('{td}',td) for x in unk(r)];continue
        if mode=='fe':
            L+=[f'\tt ~= {r.randint(-1000,1000)}','\tfor v a:',f'\t\tt {r.choice(OPS)} {ex(r,"int",r.randint(0,3),arrs[:2],0,True).replace("[x ","[0 ")}','\tt'];continue
        if mode=='red':
            L+=[f'\tt ~= {r.randint(-1000,1000)}','\tfor x lo..hi:',f'\t\tt {r.choice(OPS)} ({ex(r,r.choice(T),r.randint(1,3),arrs,od)} as! int)']+([f'\t\td[x + {od+2}] = {ex(r,td,2,arrs,od)}'] if r.random()<0.3 else [])+['\tt'];continue
        if mode=='flt':
            ft=r.choice(['f32','f64']);fl=lambda o:f'x + {o}' if o>=0 else f'x - {-o}'
            def fe(dd):
                if dd<=0 or r.random()<0.25:
                    k=r.random()
                    if k<0.6: return f'F{r.choice("AAABD")}_{ft}[{fl(r.choice([0,0,1,2,-1,3,od]))}]'
                    if k<0.8: return f'({r.choice(["1.5","0.25","-3.0","7.0","0.0"])} as {ft})'
                    return f'(u as {ft})'
                return f'({fe(dd-1)} {r.choice(["+","+","-","*","*","/"])} {fe(dd-1)})'
            L+=['\tfor x lo..hi:',f'\t\tF{r.choice("DDDA")}_{ft}[{fl(od+1)}] = {fe(r.randint(1,4))}']+([f'\t\tFB_{ft}[{fl(od+2)}] = {fe(2)}'] if r.random()<0.2 else [])+['\t0'];continue
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
    L+=['recursive rfa(x int, d int) int:\n\tif d <= 0 { return x ^ 5 }\n\ta := x * 3 + d\n\tb := rfa(a & 4095, d - 1)\n\tc := rfa(b ^ x, d - 2)\n\ta + b * 7 - c + x','recursive rfb(x int, d int) int:\n\tif d <= 0 { return x + 11 }\n\tk := x ^ (d * 13)\n\tm := rfb(k & 2047, d - 1)\n\tif (m & 1) == 0 { return m + k }\n\tn := rfb(m & 1023, d - 2)\n\tk * 3 + n - m']
    for t in T: L+=[f'hs_{t}(v {t}[>..]&) int:\n\th ~= 0\n\tfor q v: h = h * 31 + q as! int\n\th',f'hg_{t}(v {t}[>..<]&) int:\n\th ~= 0\n\tfor q v: h = h * 31 + q as! int\n\th']
    L+=[f'var F{c}_{t} {t}[>..<]' for c in 'ABD' for t in ('f32','f64')]+[f'hf_{t}(v {t}[>..<]&) int:\n\th ~= 0\n\tfor q v:\n\t\ts := str(q)\n\t\tfor c s: h = h * 31 + c as int\n\th' for t in ('f32','f64')]
    L+=[f'var G_{t} {t}[>..<]' for t in T]+['main():',f'\tr uint ~= {seed * 2654435761 % (1<<40) + 1}']+[f'\tG_{t}.resize({N}, 0)' for t in T]+[f'\tfor i {N}:\n\t\tr = xs_next(r)\n\t\tF{c}_{t}.push(((r % 41) as {t}) * 0.375 - 3.0)' for c in 'ABD' for t in ('f32','f64')]
    for t in T:
        for j in range(2): L+=[f'\t{t}{j} {t}[>..] ~= []',f'\tfor i {N}:\n\t\tr = xs_next(r)\n\t\t{t}{j}.push(r as! {t})']
    for k,(td,ta,tb,tw) in enumerate(ks):
        for c in range(r.randint(2,5)):
            mx=N-24-(64 if tw else 0);lo=r.choice([3,4,5,9,17]) if r.random()>0.03 else r.randint(0,2);hi=r.choice([lo,lo+1,lo+7,lo+15,lo+16,lo+17,lo+33,mx,mx-1,mx-r.randint(0,40)])
            hi=max(lo,N+r.randint(0,40) if r.random()<0.012 else hi);dn=f'{td}0';an=f'{ta}{r.randint(0,1)}';bn=f'{tb}{r.randint(0,1)}'
            an=dn if r.random()<0.3 and ta==td else an;bn=dn if r.random()<0.2 and tb==td else bn;bn=an if r.random()<0.15 and tb==ta else bn
            L+=[f'\trr := k{k}({dn}, {an}, {bn}, {r.randint(-300,70000)}, {lo}, {hi})',f'\tprint(rr, " ", hs_{td}({dn}), " ", hs_{tb}({tb}0), " ", hs_{tb}({tb}1), " ", hg_{td}(G_{td}), " ", hf_f32(FD_f32), " ", hf_f64(FD_f64), " ", hf_f32(FB_f32), " ", hf_f64(FB_f64), " ", hf_f32(FA_f32), " ", hf_f64(FA_f64))']
    return '\n'.join(L)+'\n'
def one(seed):
    with tempfile.TemporaryDirectory() as w:
        (pathlib.Path(w)/'p.he').write_text(prog(seed));env=dict(os.environ,HC_LIB=str(R/'hc'/'lib'));out=[]
        for tag,e in (('s',dict(env,HC_NOVEC='1',HC_NOBR='1',HC_NOROT='1',HC_NOADC='1',HC_NOSEL='1',HC_NOMS='1',HC_NOFC='1',HC_NOLC='1',HC_NOMX='1',HC_NOSI='1',HC_NOCB='1',HC_NORW='1',HC_NO32='1',HC_NOZX='1',HC_NORL='1',HC_NOVMS='1',HC_NOVSO='1',HC_NOLX='1',HC_NOXB='1',HC_NOWB='1',HC_NOXS='1',HC_NOWE='1',HC_NOAC='1',HC_NOBF='1',HC_NOAE='1',HC_NOCF='1',HC_NOML='1',HC_NORC='1',HC_NOXC='1',HC_NOCI='1',HC_NOSC='1',HC_NORB='1',HC_NOBZ='1')),('v',env)):
            c=subprocess.run([HC,'p.he','p'+tag,'--native']+(['--v3'] if seed%2 else []),cwd=w,env=e,capture_output=True,timeout=60)
            if c.returncode: return seed,'compile',(c.stdout+c.stderr).decode(errors='replace')[:200]
            try: x=subprocess.run(['./p'+tag],cwd=w,capture_output=True,timeout=30);out.append((x.returncode,x.stdout))
            except subprocess.TimeoutExpired: out.append(('timeout',b''))
        return seed,('ok' if out[0]==out[1] else 'MISMATCH'),''
if __name__=='__main__':
    bad=0
    with cf.ThreadPoolExecutor(max(1,(os.cpu_count() or 2)//2)) as pool:
        for seed,st,msg in pool.map(one,range(S0,S0+N)):
            if st!='ok': bad+=1;print(seed,st,msg)
    print(f'{N-bad}/{N} programs match with and without the optional optimizations');sys.exit(1 if bad else 0)
