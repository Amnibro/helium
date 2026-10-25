import sys,os,re,shutil,subprocess,glob
from concurrent.futures import ThreadPoolExecutor
sys.path.insert(0,os.path.dirname(__file__));from goose2amni import convert
src,w=sys.argv[1],sys.argv[2];B=os.path.join(os.path.dirname(os.path.abspath(__file__)),'../../build/');shutil.rmtree(w,ignore_errors=True);shutil.copytree(src,w)
fs=sorted(f for f in glob.glob(w+'/**/*.goose',recursive=True) if not re.search(sys.argv[3] if len(sys.argv)>3 else r'$^',f))
for f in fs:open(f[:-6]+'.amni','w').write(convert(open(f,errors='ignore').read()))
N=lambda s:re.sub(r'\d+(\.\d+)? ?(ms|s|us|ns|µs)\b','T',s)
Q=re.compile(r'^(parsed ok|typechecked ok|bce:|bce-line|roundtrip ok).*\n?',re.M)
def run(exe,f):
    try:r=subprocess.run([B+exe,'run',os.path.basename(f)],cwd=os.path.dirname(f),capture_output=True,text=True,timeout=30,errors='replace');return r.returncode,Q.sub('',r.stdout)
    except subprocess.TimeoutExpired:return 'timeout',''
def one(f):
    g=run('goose',f);a=run('amni',f[:-6]+'.amni')
    return ('skip' if g[0]=='timeout' else 'ok' if g[0]==a[0] and N(g[1])==N(a[1]) else 'DIFF'),f,g[0],a[0]
with ThreadPoolExecutor(7) as ex:res=list(ex.map(one,fs))
from collections import Counter
print(Counter(r[0] for r in res))
for r in res:
    if r[0]=='DIFF':print(*r)
