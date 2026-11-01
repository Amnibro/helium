import json, os, re, subprocess, sys
HC = sys.argv[1]; D = os.path.abspath(sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(__file__), '../../hc/test/lsp'))
env = dict(os.environ); env.setdefault('HC_LIB', os.path.abspath(os.path.join(os.path.dirname(__file__), '../../hc/lib')))
p = subprocess.Popen([HC, 'lsp'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, env=env, cwd=D)
seq = [0]; fails = []; ok = [0]
def send(m, params, req=True):
    o = {'jsonrpc': '2.0', 'method': m, 'params': params}
    if req: seq[0] += 1; o['id'] = seq[0]
    b = json.dumps(o).encode(); p.stdin.write(b'Content-Length: %d\r\n\r\n' % len(b) + b); p.stdin.flush(); return seq[0]
def read():
    h = {}
    while True:
        l = p.stdout.readline()
        if not l: raise SystemExit('server exited')
        l = l.strip()
        if not l: break
        k, v = l.decode().split(':', 1); h[k.lower()] = v.strip()
    return json.loads(p.stdout.read(int(h['content-length'])))
def req(m, params):
    i = send(m, params)
    while True:
        r = read()
        if r.get('id') == i: return r.get('result')
def diags(uri):
    while True:
        r = read()
        if r.get('method') == 'textDocument/publishDiagnostics' and r['params']['uri'] == uri: return r['params']['diagnostics']
uri = lambda f: 'file://' + os.path.join(D, f)
def at(f, lc): l, c = map(int, lc.split(':')); return {'textDocument': {'uri': uri(f)}, 'position': {'line': l - 1, 'character': c - 1}}
def check(cond, what):
    if cond: ok[0] += 1
    else: fails.append(what)
req('initialize', {'capabilities': {}}); send('initialized', {}, False)
for f in sorted(os.listdir(D)):
    if not f.endswith('.he'): continue
    text = open(os.path.join(D, f)).read(); dirs = [l.split('# lsp: ', 1)[1] for l in text.split('\n') if l.startswith('# lsp: ')]
    if not dirs: continue
    send('textDocument/didOpen', {'textDocument': {'uri': uri(f), 'languageId': 'helium', 'version': 1, 'text': text}}, False); dg = diags(uri(f)); ver = 1
    for d in dirs:
        w = d.split(' '); k = w[0]; q = re.findall(r'"([^"]*)"', d); tag = f + ': ' + d
        if k == 'clean': check(dg == [], tag + ' got ' + json.dumps([x['message'] for x in dg]))
        elif k == 'error': check(any(x['range']['start']['line'] == int(w[1]) - 1 for x in dg), tag + ' got lines ' + str([x['range']['start']['line'] + 1 for x in dg]))
        elif k == 'hover': r = req('textDocument/hover', at(f, w[1])); v = r['contents']['value'] if r else ''; check(q[0] in v, tag + ' got ' + repr(v))
        elif k == 'def':
            r = req('textDocument/definition', at(f, w[1])); tf, tl, tc = w[3].split(':'); g = r and r['uri'] == uri(tf) and r['range']['start'] == {'line': int(tl) - 1, 'character': int(tc) - 1}
            check(g, tag + ' got ' + json.dumps(r))
        elif k == 'refs': r = req('textDocument/references', dict(at(f, w[1]), context={'includeDeclaration': True})); check(r is not None and len(r) == int(w[2]), tag + ' got ' + str(len(r or [])))
        elif k == 'rename': r = req('textDocument/rename', dict(at(f, w[1]), newName=w[2])); n = sum(len(v) for v in (r or {}).get('changes', {}).values()); check(n == int(w[3]), tag + ' got ' + str(n))
        elif k == 'sig': r = req('textDocument/signatureHelp', at(f, w[1])); check(r is not None and r['signatures'][0]['label'] == q[0] and r['activeParameter'] == int(w[-1]), tag + ' got ' + json.dumps(r))
        elif k == 'inlay': r = req('textDocument/inlayHint', {'textDocument': {'uri': uri(f)}, 'range': {'start': {'line': 0, 'character': 0}, 'end': {'line': 9999, 'character': 0}}}); check(any(h['position']['line'] == int(w[1]) - 1 and h['label'] == q[0] for h in r or []), tag + ' got ' + json.dumps(r))
        elif k == 'symbols': r = req('textDocument/documentSymbol', {'textDocument': {'uri': uri(f)}}); check(r is not None and len(r) == int(w[1]), tag + ' got ' + str(len(r or [])))
        elif k in ('complete', 'dotcomplete'):
            if k == 'dotcomplete':
                ls = text.split('\n'); ls[int(w[1].split(':')[0]) - 1] = q[0]; ver += 1
                send('textDocument/didChange', {'textDocument': {'uri': uri(f), 'version': ver}, 'contentChanges': [{'text': '\n'.join(ls)}]}, False); diags(uri(f))
            r = req('textDocument/completion', at(f, w[1])); names = [i['label'] for i in (r or {}).get('items', [])]
            check((w[-2] == 'has') == (w[-1] in names), tag + ' got ' + str(names[:12]))
            if k == 'dotcomplete':
                ver += 1; send('textDocument/didChange', {'textDocument': {'uri': uri(f), 'version': ver}, 'contentChanges': [{'text': text}]}, False); diags(uri(f))
        else: fails.append(tag + ': unknown directive')
    send('textDocument/didClose', {'textDocument': {'uri': uri(f)}}, False); diags(uri(f))
req('shutdown', None); send('exit', None, False); rc = p.wait(timeout=10)
for x in fails: print('FAIL', x)
print('lsptest: %d pass, %d fail' % (ok[0], len(fails) + (rc != 0))); sys.exit(1 if fails or rc else 0)
