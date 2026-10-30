import json, subprocess, sys
from pathlib import Path
TEXT = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness."
MAZE = ["S.#.......", ".##.####.#", "....#....#", "#.#.#.##.#", "..#...#..#", ".####.#.##", "......#...", ".######.#.", "........#E"]
JSONDOC = '{"order": 1042, "items": [{"name": "bolt", "price": 0.25, "qty": 120}, {"name": "nut", "price": 0.1, "qty": 300}, {"name": "gear", "price": 12.5, "qty": 4}, {"name": "spring", "price": 1.75, "qty": 16}]}'
T = []
def t(id, cat, prompt, ref): T.append({"id": id, "cat": cat, "prompt": prompt, "ref": ref})
t("fizzbuzz", "basic", "Print the numbers from 1 to 30, one per line, but print Fizz for multiples of 3, Buzz for multiples of 5, and FizzBuzz for multiples of both.",
"for i in range(1,31): print('FizzBuzz' if i%15==0 else 'Fizz' if i%3==0 else 'Buzz' if i%5==0 else i)")
t("sum_primes", "math", "Print the sum of all prime numbers below 100000.",
"n=100000;s=bytearray([1])*n;s[0]=s[1]=0\nfor i in range(2,int(n**.5)+1):\n  if s[i]: s[i*i::i]=bytearray(len(s[i*i::i]))\nprint(sum(i for i in range(n) if s[i]))")
t("count_primes", "speed", "Print how many prime numbers are below 20000000 (twenty million).",
"n=20000000;s=bytearray([1])*n;s[0]=s[1]=0\nfor i in range(2,int(n**.5)+1):\n  if s[i]: s[i*i::i]=bytearray(len(s[i*i::i]))\nprint(sum(s))")
t("collatz", "speed", "For every starting number from 1 to 999999, count the steps of the Collatz sequence (n -> n/2 if even, 3n+1 if odd) until it reaches 1. Print the starting number with the most steps and its step count, separated by one space.",
"best=(0,0)\ncache={1:0}\ndef steps(n):\n  path=[]\n  while n not in cache: path.append(n); n = n//2 if n%2==0 else 3*n+1\n  c=cache[n]\n  for p in reversed(path): c+=1; cache[p]=c\n  return c\nfor i in range(1,1000000):\n  c=steps(i)\n  if c>best[1]: best=(i,c)\nprint(best[0],best[1])")
t("fib90", "basic", "Print the 90th Fibonacci number, where F(1) = 1 and F(2) = 1.",
"a,b=1,1\nfor _ in range(88): a,b=b,a+b\nprint(b)")
t("gcd_lcm", "basic", "Print gcd(1071, 462) and lcm(21, 6) on one line separated by one space, then gcd(123456789, 987654321) on the next line.",
"import math;print(math.gcd(1071,462),21*6//math.gcd(21,6));print(math.gcd(123456789,987654321))")
t("reverse_words", "strings", "Print the words of the sentence 'the quick brown fox jumps over the lazy dog' in reverse order, separated by single spaces.",
"print(' '.join(reversed('the quick brown fox jumps over the lazy dog'.split())))")
t("word_freq", "strings", f"Take this text: \"{TEXT}\". Lowercase it, treat every character that is not a letter as a separator, and count the words. Print the 5 most frequent words, one per line as `word count`, sorted by count descending and then alphabetically.",
f"import re,collections\nc=collections.Counter(re.findall('[a-z]+',{TEXT!r}.lower()))\nfor w,n in sorted(c.items(),key=lambda x:(-x[1],x[0]))[:5]: print(w,n)")
t("double_palindromes", "math", "Print the sum of all numbers below 1000000 that are palindromes in both base 10 and base 2 (without leading zeros).",
"print(sum(i for i in range(1,1000000) if str(i)==str(i)[::-1] and bin(i)[2:]==bin(i)[2:][::-1]))")
t("matmul", "speed", "Let A and B be 300x300 integer matrices with A[i][j] = (i*j) % 7 and B[i][j] = (i+j) % 5 for 0-based i and j. Compute C = A*B and print the sum of all entries of C.",
"n=300;A=[[(i*j)%7 for j in range(n)] for i in range(n)];B=[[(i+j)%5 for j in range(n)] for i in range(n)]\nrs=[sum(A[i][k] for i in range(n)) for k in range(n)];cs=[sum(B[k][j] for j in range(n)) for k in range(n)]\nprint(sum(rs[k]*cs[k] for k in range(n)))")
t("rle", "strings", "Run-length encode the string 'aaabccddddde' as each character followed by its run length (for example 'aab' becomes 'a2b1') and print the result.",
"import itertools;print(''.join(k+str(len(list(g))) for k,g in itertools.groupby('aaabccddddde')))")
t("rot13", "strings", "Apply ROT13 to 'Hello, World! The year is 2026.' (letters only, keep case, leave other characters) and print the result.",
"import codecs;print(codecs.encode('Hello, World! The year is 2026.','rot13'))")
t("brackets", "strings", "For each of these strings, print YES if its brackets ()[]{} are balanced and NO otherwise, one per line in order: '([]{})', '([)]', '((()', '{[()()]}', '', '}{'.",
"def ok(s):\n  st=[];m={')':'(',']':'[','}':'{'}\n  for c in s:\n    if c in '([{': st.append(c)\n    elif c in m:\n      if not st or st.pop()!=m[c]: return False\n  return not st\nfor s in ['([]{})','([)]','((()','{[()()]}','','}{']: print('YES' if ok(s) else 'NO')")
t("roman", "strings", "Print the Roman numerals for 1994, 2024, 3999 and 4, one per line.",
"def r(n):\n  v=[(1000,'M'),(900,'CM'),(500,'D'),(400,'CD'),(100,'C'),(90,'XC'),(50,'L'),(40,'XL'),(10,'X'),(9,'IX'),(5,'V'),(4,'IV'),(1,'I')];o=''\n  for a,s in v:\n    while n>=a: o+=s;n-=a\n  return o\nfor n in [1994,2024,3999,4]: print(r(n))")
t("lcs", "dp", "Print the length of the longest common subsequence of 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA' and 'GTCGTTCGGAATGCCGTTGCTCTGTAAA'.",
"a='ACCGGTCGAGTGCGCGGAAGCCGGCCGAA';b='GTCGTTCGGAATGCCGTTGCTCTGTAAA'\nd=[[0]*(len(b)+1) for _ in range(len(a)+1)]\nfor i in range(len(a)):\n  for j in range(len(b)): d[i+1][j+1]=d[i][j]+1 if a[i]==b[j] else max(d[i][j+1],d[i+1][j])\nprint(d[-1][-1])")
t("edit_distance", "dp", "Print the Levenshtein edit distance between 'kitten' and 'sitting', then on the next line between 'intention' and 'execution'.",
"def ed(a,b):\n  d=list(range(len(b)+1))\n  for i in range(1,len(a)+1):\n    p=d[:];d[0]=i\n    for j in range(1,len(b)+1): d[j]=min(p[j]+1,d[j-1]+1,p[j-1]+(a[i-1]!=b[j-1]))\n  return d[-1]\nprint(ed('kitten','sitting'));print(ed('intention','execution'))")
t("knapsack", "dp", "0/1 knapsack: items have weights [12, 7, 11, 8, 9, 6, 15, 4, 10, 13] and values [24, 13, 23, 15, 16, 12, 30, 7, 19, 25]. With capacity 50, print the maximum total value.",
"w=[12,7,11,8,9,6,15,4,10,13];v=[24,13,23,15,16,12,30,7,19,25];d=[0]*51\nfor i in range(10):\n  for c in range(50,w[i]-1,-1): d[c]=max(d[c],d[c-w[i]]+v[i])\nprint(d[50])")
t("coin_ways", "dp", "Print the number of different ways to make 200 pence from coins of 1, 2, 5, 10, 20, 50, 100 and 200 pence (order does not matter).",
"d=[1]+[0]*200\nfor c in [1,2,5,10,20,50,100,200]:\n  for x in range(c,201): d[x]+=d[x-c]\nprint(d[200])")
t("nqueens", "search", "Print the number of ways to place 10 non-attacking queens on a 10x10 chessboard.",
"def s(r,c,d1,d2,n):\n  if r==n: return 1\n  t=0\n  for x in range(n):\n    if not(c>>x&1 or d1>>(r+x)&1 or d2>>(r-x+n)&1): t+=s(r+1,c|1<<x,d1|1<<(r+x),d2|1<<(r-x+n),n)\n  return t\nprint(s(0,0,0,0,10))")
t("maze_bfs", "search", "This grid has rows " + ", ".join(f"'{r}'" for r in MAZE) + " ('#' is a wall, moves are up, down, left, right). Print the minimum number of moves from S to E, or -1 if E cannot be reached.",
f"from collections import deque\nm={MAZE!r};H=len(m);W=len(m[0])\nfor y in range(H):\n  for x in range(W):\n    if m[y][x]=='S': s=(y,x)\n    if m[y][x]=='E': e=(y,x)\nq=deque([(s,0)]);seen={{s}};r=-1\nwhile q:\n  (y,x),d=q.popleft()\n  if (y,x)==e: r=d;break\n  for dy,dx in((1,0),(-1,0),(0,1),(0,-1)):\n    ny,nx=y+dy,x+dx\n    if 0<=ny<H and 0<=nx<W and m[ny][nx]!='#' and (ny,nx) not in seen: seen.add((ny,nx));q.append(((ny,nx),d+1))\nprint(r)")
t("dijkstra", "search", "Directed weighted graph on nodes 0..6 with edges (from, to, weight): (0,1,7) (0,2,9) (0,5,14) (1,2,10) (1,3,15) (2,3,11) (2,5,2) (3,4,6) (4,5,9) (5,4,3) (4,6,1) (3,6,20). Print the shortest distance from node 0 to each node 0..6 on one line separated by spaces.",
"import heapq\nE=[(0,1,7),(0,2,9),(0,5,14),(1,2,10),(1,3,15),(2,3,11),(2,5,2),(3,4,6),(4,5,9),(5,4,3),(4,6,1),(3,6,20)];g={i:[] for i in range(7)}\nfor a,b,w in E: g[a].append((b,w))\nd=[10**9]*7;d[0]=0;q=[(0,0)]\nwhile q:\n  c,u=heapq.heappop(q)\n  if c>d[u]: continue\n  for v,w in g[u]:\n    if c+w<d[v]: d[v]=c+w;heapq.heappush(q,(d[v],v))\nprint(*d)")
t("toposort", "search", "Tasks 0..7 with dependencies (a must come before b): 5->2, 5->0, 4->0, 4->1, 2->3, 3->1, 7->6, 6->3. Print a topological order on one line separated by spaces, always choosing the smallest available task number next.",
"import heapq\nE=[(5,2),(5,0),(4,0),(4,1),(2,3),(3,1),(7,6),(6,3)];ind=[0]*8;g={i:[] for i in range(8)}\nfor a,b in E: g[a].append(b);ind[b]+=1\nq=[i for i in range(8) if ind[i]==0];heapq.heapify(q);o=[]\nwhile q:\n  u=heapq.heappop(q);o.append(u)\n  for v in g[u]:\n    ind[v]-=1\n    if ind[v]==0: heapq.heappush(q,v)\nprint(*o)")
t("sort_records", "strings", "Given the records 'mia,34', 'leo,27', 'ava,34', 'zoe,19', 'eli,27', 'ian,41' (name,age), print them one per line in the same 'name,age' form, sorted by age descending and then by name ascending.",
"r=[x.split(',') for x in ['mia,34','leo,27','ava,34','zoe,19','eli,27','ian,41']]\nfor n,a in sorted(r,key=lambda x:(-int(x[1]),x[0])): print(f'{n},{a}')")
t("anagrams", "strings", "Group these words into anagram groups: listen, silent, enlist, google, gooegl, cat, act, tac, dog. Print each group on its own line with its words sorted alphabetically and separated by spaces; order the lines by their first word.",
"import collections\ng=collections.defaultdict(list)\nfor w in 'listen silent enlist google gooegl cat act tac dog'.split(): g[''.join(sorted(w))].append(w)\nfor l in sorted(sorted(v) for v in g.values()): print(' '.join(l))")
t("life", "sim", "Conway's Game of Life on an 8x8 grid that does not wrap (cells outside are dead). Start with live cells at (row, col) (0,1), (1,2), (2,0), (2,1), (2,2). After 4 generations print the grid as 8 lines of '#' (live) and '.' (dead).",
"g=[[0]*8 for _ in range(8)]\nfor r,c in [(0,1),(1,2),(2,0),(2,1),(2,2)]: g[r][c]=1\nfor _ in range(4):\n  n=[[0]*8 for _ in range(8)]\n  for r in range(8):\n    for c in range(8):\n      k=sum(g[r+dr][c+dc] for dr in(-1,0,1) for dc in(-1,0,1) if (dr or dc) and 0<=r+dr<8 and 0<=c+dc<8)\n      n[r][c]=1 if k==3 or (g[r][c] and k==2) else 0\n  g=n\nfor r in g: print(''.join('#' if x else '.' for x in r))")
t("mandelbrot_count", "speed", "Sample a 600x600 grid of points c = x + yi where x = -2.0 + 3.0*i/600 and y = -1.5 + 3.0*j/600 for i, j in 0..599. Iterate z = z*z + c from z = 0 up to 200 times; a point is in the set if |z| never exceeds 2. Print how many points are in the set.",
"n=0\nfor i in range(600):\n  x=-2.0+3.0*i/600\n  for j in range(600):\n    y=-1.5+3.0*j/600;zr=zi=0.0;k=0\n    while k<200 and zr*zr+zi*zi<=4.0: zr,zi=zr*zr-zi*zi+x,2*zr*zi+y;k+=1\n    if k==200 and zr*zr+zi*zi<=4.0: n+=1\nprint(n)")
t("lcg", "basic", "Use the generator s = (1103515245*s + 12345) mod 2147483648 starting from s = 42. Generate 1000000 values (apply the formula, then use the new s). Print how many of them are below 1073741824, then on the next line the last value.",
"s=42;c=0\nfor _ in range(1000000):\n  s=(1103515245*s+12345)%2147483648\n  if s<1073741824: c+=1\nprint(c);print(s)")
t("factorial_digits", "math", "Print the sum of the decimal digits of 100! (100 factorial).",
"import math;print(sum(map(int,str(math.factorial(100)))))")
t("number_words", "strings", "Print 1234567, 90210, 13 and 1000000 in English words, one per line, all lowercase, with a hyphen in compounds from 21 to 99 (like forty-two), no 'and' and no commas.",
"O='zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen'.split();T='_ _ twenty thirty forty fifty sixty seventy eighty ninety'.split()\ndef h(n):\n  o=[]\n  if n>=100: o.append(O[n//100]+' hundred');n%=100\n  if n>=20: o.append(T[n//10]+('-'+O[n%10] if n%10 else ''))\n  elif n: o.append(O[n])\n  return ' '.join(o)\ndef w(n):\n  o=[]\n  for v,nm in((1000000,' million'),(1000,' thousand'),(1,'')):\n    if n>=v: o.append(h(n//v)+nm);n%=v\n  return ' '.join(o)\nfor n in [1234567,90210,13,1000000]: print(w(n))")
t("expr_eval", "parsing", "Write an evaluator for integer expressions with + - * and parentheses (normal precedence, left to right), and print the value of each of these on its own line: '(1+2)*3-4*(5-6)', '2*(3+4)*(5-1)', '100-2*3*4+(7-10)*2'.",
"for e in ['(1+2)*3-4*(5-6)','2*(3+4)*(5-1)','100-2*3*4+(7-10)*2']: print(eval(e))")
t("json_total", "parsing", f"Parse this JSON document: {JSONDOC}. Print the sum of price*qty over all items with exactly 2 digits after the decimal point.",
f"import json;d=json.loads({JSONDOC!r});print(f\"{{sum(i['price']*i['qty'] for i in d['items']):.2f}}\")")
t("distinct_trigrams", "strings", "Print how many distinct substrings of length 3 the string 'abracadabraabracadabra' has.",
"s='abracadabraabracadabra';print(len({s[i:i+3] for i in range(len(s)-2)}))")
t("pascal", "basic", "Print the first 10 rows of Pascal's triangle, one row per line, numbers separated by single spaces.",
"r=[1]\nfor _ in range(10): print(*r); r=[1]+[r[i]+r[i+1] for i in range(len(r)-1)]+[1]")
t("spiral", "basic", "Fill a 5x5 matrix with 1..25 row by row, then print its elements in clockwise spiral order starting at the top-left, on one line separated by spaces.",
"m=[[r*5+c+1 for c in range(5)] for r in range(5)];o=[]\nwhile m: o+=m.pop(0); m=[list(x) for x in zip(*m)][::-1]\nprint(*o)")
t("factorize", "math", "Print the prime factors of 600851475143 in increasing order separated by spaces (with repetition).",
"n=600851475143;f=[];d=2\nwhile d*d<=n:\n  while n%d==0: f.append(d);n//=d\n  d+=1\nif n>1: f.append(n)\nprint(*f)")
t("leap_years", "basic", "Print how many leap years there are from 1900 to 2100 inclusive under the Gregorian rules.",
"print(sum(1 for y in range(1900,2101) if y%4==0 and (y%100!=0 or y%400==0)))")
t("weekday", "math", "Without using a date library, print the day of the week (for example Monday) of 2026-10-29, 2000-01-01 and 1969-07-20, one per line.",
"import datetime\nfor d in ['2026-10-29','2000-01-01','1969-07-20']: print(datetime.date.fromisoformat(d).strftime('%A'))")
t("histogram", "basic", "For the values 3, 7, 1, 5, 0, 4 print one line each in the form 'value: ' followed by that many '*' characters (for example '3: ***').",
"for v in [3,7,1,5,0,4]: print(f'{v}: '+'*'*v)")
t("digit_square_chains", "speed", "Repeatedly replace a number by the sum of the squares of its digits; every starting number ends in a loop at 1 or at 89. Print how many starting numbers below 10000000 (ten million) arrive at 89.",
"c=[0]*568\nfor i in range(1,568):\n  n=i\n  while n not in(1,89): n=sum(int(d)**2 for d in str(n))\n  c[i]=n\nfrom functools import lru_cache\ncnt=[0]*568;cnt[0]=1\nfor _ in range(7):\n  nc=[0]*568\n  for s in range(568):\n    if cnt[s]:\n      for d in range(10):\n        if s+d*d<568: nc[s+d*d]+=cnt[s]\n  cnt=nc\nprint(sum(cnt[s] for s in range(1,568) if c[s]==89))")
t("leibniz_pi", "float", "Approximate pi with the first 10000000 terms of the Leibniz series 4*(1 - 1/3 + 1/5 - 1/7 + ...) and print it with exactly 6 digits after the decimal point.",
"s=0.0\nfor k in range(10000000): s+=(-1.0)**k/(2*k+1)\nprint(f'{4*s:.6f}')")
t("mean_stdev", "float", "For the values 2, 4, 4, 4, 5, 5, 7, 9, 13, 21 print the mean and the population standard deviation, each with exactly 3 digits after the decimal point, on one line separated by one space.",
"import statistics as st;v=[2,4,4,4,5,5,7,9,13,21];print(f'{st.mean(v):.3f} {st.pstdev(v):.3f}')")
t("binary_strings", "search", "Print all binary strings of length 4 that have no two adjacent 1s, in increasing numeric order, one per line.",
"for i in range(16):\n  s=format(i,'04b')\n  if '11' not in s: print(s)")
t("caesar_crack", "strings", "The text 'Wkh vhfuhw phhwlqj lv dw qrrq' was made with a Caesar shift. Try all 26 shifts and print the decryption that contains the word 'secret'.",
"c='Wkh vhfuhw phhwlqj lv dw qrrq'\nfor k in range(26):\n  p=''.join(chr((ord(x)-(65 if x.isupper() else 97)-k)%26+(65 if x.isupper() else 97)) if x.isalpha() else x for x in c)\n  if 'secret' in p: print(p)")
if __name__ == "__main__":
    for x in T:
        r = subprocess.run([sys.executable, "-c", x["ref"]], capture_output=True, text=True, timeout=600)
        assert r.returncode == 0, (x["id"], r.stderr)
        x["expected"] = r.stdout
    json.dump(T, open(Path(__file__).parent / "tasks.json", "w"), indent=1)
    print(len(T), "tasks;", {c: sum(1 for x in T if x["cat"] == c) for c in sorted({x["cat"] for x in T})})
