import re,sys
W={'i64':'int','u64':'uint','u8':'byte','f64':'real'}
TOK=re.compile(r'"""[\s\S]*?"""|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|//[^\n]*|/\*[\s\S]*?\*/|[A-Za-z_]\w*|\d[\w.]*|->|::|\.\.|[ \t]+|.|\n',re.S)
def sig(x):return not(x.isspace() or x[:2] in('//','/*'))
def convert(s):
    t=TOK.findall(s);ren={v:v+'_' for v in W.values() if v in t};t=[ren.get(x,x) for x in t]
    out,st,prev=[],[],[];pend=None;decl=False
    for i,x in enumerate(t):
        if not sig(x):
            out.append('\t'*(len(x)//4)+' '*(len(x)%4) if x.strip(' ')=='' and (not out or out[-1]=='\n') else x);decl=decl and x!='\n';continue
        p1=prev[-1] if prev else '';drop=False;top=st[-1] if st else None
        if pend=='fnname':pend='fnparams' if x[:1].isalpha() else None
        if x=='{':st.append('decl' if pend=='decl' or top=='enum' and p1[:1].isalpha() else 'enum' if pend=='enum' else 'body');pend=None
        elif x=='(':st.append('params' if pend=='fnparams' else 'paren');pend=None if pend=='fnparams' else pend
        elif x=='[':st.append('br')
        elif x in'})]':pend='rets' if st and st.pop()=='params' else pend
        elif x=='struct':pend='decl'
        elif x=='enum':pend='enum'
        elif x=='fn' and top in(None,'decl','body','enum'):pend='fnname'
        elif x=='<' and pend=='fnparams':pend='fngen'
        elif x=='>' and pend=='fngen':pend='fnparams'
        elif x==':' and p1[:1].isalpha() and p1!='pad' and pend!='fngen':drop=top in('decl','params') or decl
        elif x=='->' and pend=='rets':drop=True
        if pend=='rets' and x in('{','=',';'):pend=None
        decl=x in('let','var') or decl and x not in('=',';')
        prev.append(x)
        if drop:
            if x=='->' and out and out[-1]==' ':out.pop()
            if i+1<len(t) and sig(t[i+1]):out.append(' ')
            continue
        out.append(W.get(x,x))
    return ''.join(out)
if __name__=='__main__':
    for f in sys.argv[1:]:open(f[:-6]+'.amni','w').write(convert(open(f).read()))
