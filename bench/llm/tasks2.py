import json, subprocess, sys
from pathlib import Path
SENT = "The quick brown fox jumps over the lazy dog while seven sleepy cats watch from the old wooden fence"
GRADES = "ana:91,78,85;ben:66,92,70;cara:88,95,79;dev:72,64,90;eli:95,98,93"
CSVTXT = "name,qty,price\\nbolt,120,0.25\\nnut,300,0.10\\ngear,4,12.50\\nspring,16,1.75\\nwasher,500,0.05"
STAFF = "ann,eng,120;bob,ops,85;cy,eng,135;dee,ops,85;eve,hr,90;fay,eng,120;gus,hr,70"
T = []
def t(id, cat, prompt, ref): T.append({"id": id, "cat": cat, "prompt": prompt, "ref": ref})
t("vowel_count", "strings", f"Count each vowel (a, e, i, o, u, case-insensitive) in the sentence '{SENT}'. Print one line `a:N e:N i:N o:N u:N`.",
f"s={SENT!r}.lower();print(' '.join(f'{{v}}:{{s.count(v)}}' for v in 'aeiou'))")
t("title_case", "strings", "Print 'the old man and the sea' with the first letter of every word capitalized.",
"print(' '.join(w[0].upper()+w[1:] for w in 'the old man and the sea'.split()))")
t("isbn_check", "parsing", "For each ISBN-10 in ['0306406152', '0306406153', '0131103628', '123456789X', '0201633612'] print the ISBN, a space, and VALID or INVALID. An ISBN-10 is valid when the sum of digit*(10-position) over positions 0..9 is divisible by 11, where a final X counts as 10.",
"for s in ['0306406152','0306406153','0131103628','123456789X','0201633612']:\n  v=sum((10 if c=='X' else int(c))*(10-i) for i,c in enumerate(s))\n  print(s,'VALID' if v%11==0 else 'INVALID')")
t("perfect_numbers", "math", "Print every perfect number below 10000 (a number equal to the sum of its proper divisors), one per line.",
"for n in range(2,10000):\n  if sum(d for d in range(1,n) if n%d==0)==n: print(n)")
t("armstrong", "math", "Print every 3-digit number that equals the sum of the cubes of its digits, separated by single spaces on one line.",
"print(' '.join(str(n) for n in range(100,1000) if n==sum(int(c)**3 for c in str(n))))")
t("base_convert", "basic", "For each of 255, 1000 and 4096 print one line with the number in base 2, base 8 and base 16 (lowercase digits), separated by single spaces.",
"for n in [255,1000,4096]: print(format(n,'b'),format(n,'o'),format(n,'x'))")
t("inversions", "search", "Count the inversions (pairs i < j with a[i] > a[j]) in the list [8, 4, 2, 1, 7, 3, 9, 5, 6, 0] and print the count.",
"a=[8,4,2,1,7,3,9,5,6,0];print(sum(1 for i in range(len(a)) for j in range(i+1,len(a)) if a[i]>a[j]))")
t("median", "float", "Print the median of [12, 3, 5, 7, 19, 1, 8, 4, 10, 2, 6] and then the median of [12, 3, 5, 7, 19, 1, 8, 4, 10, 2] on the next line, each with exactly 1 digit after the decimal point.",
"import statistics as s;print(f'{s.median([12,3,5,7,19,1,8,4,10,2,6]):.1f}');print(f'{s.median([12,3,5,7,19,1,8,4,10,2]):.1f}')")
t("grade_report", "parsing", f"Parse the string '{GRADES}' (students separated by ';', name and scores separated by ':', scores by ','). Print each student as `name average` with the average to exactly 1 decimal place, sorted by average descending.",
f"r=[(p.split(':')[0],sum(map(int,p.split(':')[1].split(',')))/3) for p in {GRADES!r}.split(';')]\nfor n,a in sorted(r,key=lambda x:-x[1]): print(f'{{n}} {{a:.1f}}')")
t("letter_histogram", "strings", f"Count the letters (case-insensitive) in '{SENT}'. Print every letter that occurs at least 3 times as `letter count`, one per line, in alphabetical order.",
f"import collections;c=collections.Counter(ch for ch in {SENT!r}.lower() if ch.isalpha())\nfor k in sorted(c):\n  if c[k]>=3: print(k,c[k])")
t("longest_word", "strings", f"Print the longest word in '{SENT}' (the first one if several tie) followed by a space and its length.",
f"w=max({SENT!r}.split(),key=len);print(w,len(w))")
t("transpose", "basic", "Let M be the 3x4 matrix with rows [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]. Print its transpose, one row per line with entries separated by single spaces.",
"M=[[1,2,3,4],[5,6,7,8],[9,10,11,12]]\nfor r in zip(*M): print(' '.join(map(str,r)))")
t("largest_prime_factor", "math", "Print the largest prime factor of 600851475143.",
"n=600851475143;f=2\nwhile f*f<=n:\n  if n%f==0: n//=f\n  else: f+=1\nprint(n)")
t("happy_numbers", "math", "A happy number reaches 1 when repeatedly replaced by the sum of the squares of its digits. Print the first 10 happy numbers separated by single spaces.",
"def h(n):\n  seen=set()\n  while n!=1 and n not in seen: seen.add(n); n=sum(int(c)**2 for c in str(n))\n  return n==1\nr=[];n=1\nwhile len(r)<10:\n  if h(n): r.append(n)\n  n+=1\nprint(' '.join(map(str,r)))")
t("triangle_path", "dp", "In the triangle with rows [3], [7, 4], [2, 4, 6], [8, 5, 9, 3], [1, 6, 2, 7, 4], a path goes from the top to the bottom, each step moving to one of the two adjacent numbers below. Print the maximum path sum.",
"t=[[3],[7,4],[2,4,6],[8,5,9,3],[1,6,2,7,4]]\nfor i in range(len(t)-2,-1,-1):\n  for j in range(len(t[i])): t[i][j]+=max(t[i+1][j],t[i+1][j+1])\nprint(t[0][0])")
t("stock_profit", "search", "Given daily prices [7, 1, 5, 3, 6, 4, 8, 2, 9, 1], print the maximum profit from buying on one day and selling on a later day.",
"p=[7,1,5,3,6,4,8,2,9,1];m=p[0];b=0\nfor x in p: b=max(b,x-m); m=min(m,x)\nprint(b)")
t("two_sum", "search", "In [11, 2, 15, 7, 3, 9, 4] find the first pair of indices i < j (in order of i, then j) whose values sum to 13 and print `i j`.",
"a=[11,2,15,7,3,9,4]\nprint(next(f'{i} {j}' for i in range(len(a)) for j in range(i+1,len(a)) if a[i]+a[j]==13))")
t("partition_diff", "dp", "Split [31, 7, 18, 4, 22, 13, 9, 26, 15] into two groups so that the difference of their sums is as small as possible. Print that smallest difference.",
"a=[31,7,18,4,22,13,9,26,15];s=sum(a);r={0}\nfor x in a: r|={y+x for y in r}\nprint(min(abs(s-2*y) for y in r))")
t("hanoi", "search", "Print the moves that solve the Tower of Hanoi with 3 disks from peg A to peg C using peg B, one per line as `A->C`, then a final line with the number of moves needed for 20 disks.",
"m=[]\ndef h(n,a,b,c):\n  if n: h(n-1,a,c,b); m.append(f'{a}->{c}'); h(n-1,b,a,c)\nh(3,'A','B','C');print('\\n'.join(m));print(2**20-1)")
t("queue_wait", "sim", "Customers arrive at times [0, 2, 3, 7, 8, 8, 12, 15] and need service times [4, 3, 2, 5, 1, 2, 3, 2]. One clerk serves them in arrival order. Print the average waiting time (time from arrival to start of service) with exactly 2 digits after the decimal point.",
"a=[0,2,3,7,8,8,12,15];s=[4,3,2,5,1,2,3,2];t=0;w=0\nfor x,y in zip(a,s):\n  t=max(t,x);w+=t-x;t+=y\nprint(f'{w/len(a):.2f}')")
t("date_diff", "math", "Print the number of days from 2024-01-15 to 2026-10-30 (Gregorian calendar).",
"import datetime as d;print((d.date(2026,10,30)-d.date(2024,1,15)).days)")
t("csv_total", "parsing", f"Parse this CSV text (lines separated by \\n, a header line first): '{CSVTXT}'. Print the total value (sum of qty*price) with exactly 2 digits after the decimal point, then on the next line the name of the item with the highest unit price.",
f"L={CSVTXT!r}.replace('\\\\n','\\n').split('\\n')[1:];r=[(x.split(',')[0],int(x.split(',')[1]),float(x.split(',')[2])) for x in L]\nprint(f'{{sum(q*p for _,q,p in r):.2f}}');print(max(r,key=lambda x:x[2])[0])")
t("palindrome_phrases", "strings", "From ['A man, a plan, a canal: Panama', 'Hello, World', 'Was it a car or a cat I saw?', 'No lemon, no melon', 'Helium is fast'] print, one per line, each phrase that reads the same backwards when only letters are kept and case is ignored.",
"for p in ['A man, a plan, a canal: Panama','Hello, World','Was it a car or a cat I saw?','No lemon, no melon','Helium is fast']:\n  s=[c.lower() for c in p if c.isalpha()]\n  if s==s[::-1]: print(p)")
t("twin_primes", "speed", "Print how many pairs of twin primes (p, p+2 both prime) exist with p + 2 below 5000000.",
"n=5000000;s=bytearray([1])*n;s[0]=s[1]=0\nfor i in range(2,int(n**.5)+1):\n  if s[i]: s[i*i::i]=bytearray(len(s[i*i::i]))\nprint(sum(1 for p in range(2,n-2) if s[p] and s[p+2]))")
t("monte_carlo_pi", "speed", "Use the generator s = (6364136223846793005*s + 1442695040888963407) mod 2^64 starting from s = 1. For each of 2000000 points take x = (next s >> 11) / 2^53 and then y the same way from the following value. Print 4 times the fraction of points with x*x + y*y < 1, with exactly 4 digits after the decimal point.",
"s=1;M=2**64;c=0\nfor _ in range(2000000):\n  s=(6364136223846793005*s+1442695040888963407)%M;x=(s>>11)/2**53\n  s=(6364136223846793005*s+1442695040888963407)%M;y=(s>>11)/2**53\n  c+=x*x+y*y<1\nprint(f'{4*c/2000000:.4f}')")
t("power_digit_sum", "math", "Print the sum of the decimal digits of 2 to the power 500.",
"print(sum(map(int,str(2**500))))")
t("spiral_diagonals", "math", "Numbers 1, 2, 3, ... are written in a clockwise spiral starting from the center of a 1001 by 1001 grid. Print the sum of the numbers on both diagonals.",
"s=1;n=1\nfor k in range(2,1001,2):\n  for _ in range(4): n+=k; s+=n\nprint(s)")
t("knight_moves", "search", "On a standard 8x8 chessboard print the minimum number of knight moves from a1 to h8, then on the next line from b1 to c3.",
"from collections import deque\ndef d(a,b):\n  s=(ord(a[0])-97,int(a[1])-1);g=(ord(b[0])-97,int(b[1])-1);q=deque([(s,0)]);seen={s}\n  while q:\n    (x,y),k=q.popleft()\n    if (x,y)==g: return k\n    for dx,dy in [(1,2),(2,1),(-1,2),(-2,1),(1,-2),(2,-1),(-1,-2),(-2,-1)]:\n      p=(x+dx,y+dy)\n      if 0<=p[0]<8 and 0<=p[1]<8 and p not in seen: seen.add(p); q.append((p,k+1))\nprint(d('a1','h8'));print(d('b1','c3'))")
t("nesting_depth", "parsing", "For each of ['(a(b)c)', '((()))()', '(()', 'x(y(z(w)))', ')('] print the string, a space, and its maximum parenthesis nesting depth if the parentheses are balanced or UNBALANCED otherwise.",
"for s in ['(a(b)c)','((()))()','(()','x(y(z(w)))',')(']:\n  d=m=0;ok=True\n  for c in s:\n    if c=='(': d+=1; m=max(m,d)\n    elif c==')':\n      d-=1\n      if d<0: ok=False\n  print(s, m if ok and d==0 else 'UNBALANCED')")
t("staff_sort", "parsing", f"Parse '{STAFF}' (records separated by ';', fields name,dept,salary). Print the records sorted by dept alphabetically, then salary descending, then name, one per line as `dept name salary`.",
f"r=[x.split(',') for x in {STAFF!r}.split(';')]\nfor n,d,s in sorted(r,key=lambda x:(x[1],-int(x[2]),x[0])): print(d,n,s)")
t("digit_factorials", "speed", "Print the sum of all numbers from 10 to 2540160 that equal the sum of the factorials of their digits.",
"import math;f=[math.factorial(i) for i in range(10)]\nprint(sum(n for n in range(10,2540161) if n==sum(f[int(c)] for c in str(n))))")
t("word_lengths", "strings", f"Count the words in '{SENT}' by length. Print one line per length that occurs, in increasing order, as `length count`.",
f"import collections;c=collections.Counter(len(w) for w in {SENT!r}.split())\nfor k in sorted(c): print(k,c[k])")
if __name__ == "__main__":
    for x in T:
        r = subprocess.run([sys.executable, "-c", x["ref"]], capture_output=True, text=True, timeout=600)
        assert r.returncode == 0, (x["id"], r.stderr)
        x["expected"] = r.stdout
    json.dump(T, open(Path(__file__).parent / "tasks2.json", "w"), indent=1)
    print(len(T), "tasks;", {c: sum(1 for x in T if x["cat"] == c) for c in sorted({x["cat"] for x in T})})
