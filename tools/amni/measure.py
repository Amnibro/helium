import sys,re,glob,tiktoken
from tokenizers import Tokenizer
E=tiktoken.get_encoding('o200k_base');Q=Tokenizer.from_file(sys.argv[2]) if len(sys.argv)>2 else None
def strip(s):return '\n'.join(l for l in (re.sub(r'//.*','',x).rstrip() for x in s.split('\n')) if l.strip())
d=sys.argv[1];g=sorted(glob.glob(d+'/**/*.goose',recursive=True))
for name,f in [('o200k',lambda s:len(E.encode(s)))]+([('qwen',lambda s:len(Q.encode(s,add_special_tokens=False).ids))] if Q else []):
    a=sum(f(strip(open(x,errors='ignore').read())) for x in g);b=sum(f(strip(open(x[:-6]+'.amni',errors='ignore').read())) for x in g)
    print(f'{name}: goose {a} amni {b} saved {100*(a-b)/a:.1f}%')
