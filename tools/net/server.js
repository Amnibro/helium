const http = require('http'), https = require('https'), fs = require('fs'), { WebSocketServer } = require('ws'), { Server } = require('socket.io')
const [port, cert, key, mode] = process.argv.slice(2)
const body = n => { const b = Buffer.alloc(n); for (let i = 0; i < n; i++) b[i] = (i * 31 + 7) & 255; return b }
const handler = (req, res) => {
  const m = req.url.match(/^\/(len|chunk|close|echo|status)\/(\d+)/)
  if (!m) return
  const n = +m[2]
  if (m[1] === 'len') { res.writeHead(200, { 'Content-Length': n, 'X-Test': 'yes' }); return res.end(req.method === 'HEAD' ? undefined : body(n)) }
  if (m[1] === 'chunk') { res.writeHead(200, { 'Content-Type': 'application/octet-stream' }); const b = body(n); let i = 0; const step = () => { if (i >= n) return res.end(); const k = Math.min(n - i, 1 + (i % 7777)); res.write(b.subarray(i, i + k)); i += k; setImmediate(step) }; return step() }
  if (m[1] === 'close') { res.useChunkedEncodingByDefault = false; res.shouldKeepAlive = false; res.writeHead(200, { Connection: 'close' }); res.end(body(n)); return }
  if (m[1] === 'status') { res.writeHead(n); return res.end() }
  const parts = []; req.on('data', d => parts.push(d)); req.on('end', () => { const b = Buffer.concat(parts); res.writeHead(200, { 'Content-Type': 'application/json' }); res.end(JSON.stringify({ method: req.method, len: b.length, auth: req.headers.authorization || '', body: b.toString() })) })
}
const srv = cert ? https.createServer({ cert: fs.readFileSync(cert), key: fs.readFileSync(key) }, handler) : http.createServer(handler)
const wss = new WebSocketServer({ noServer: true })
const io = new Server(srv, { pingInterval: 2000, pingTimeout: 2000, ...(mode === 'pollonly' ? { transports: ['polling'] } : {}) })
io.use((s, next) => s.handshake.auth.token === 't0k' ? next() : next(new Error('bad token')))
io.on('connection', s => {
  s.emit('welcome', { sid: s.id, text: 'héllo ✓' })
  s.on('echo', (...a) => s.emit('echoed', ...a))
  s.on('add', (a, b, cb) => cb(a + b, 'sum'))
  s.on('ask', () => s.emit('question', 'name?', ans => s.emit('thanks', ans)))
  s.on('bye', () => s.disconnect(true))
})
srv.on('upgrade', (req, sock, head) => { if (req.url.startsWith('/ws')) wss.handleUpgrade(req, sock, head, ws => wss.emit('connection', ws, req)) })
wss.on('connection', ws => ws.on('message', (d, bin) => {
  const t = d.toString()
  if (!bin && t === 'frag') { ws.send('frag', { fin: false }); ws.ping('p1'); ws.send('ment', { fin: false }); ws.send('ed', { fin: true }); return }
  if (!bin && t === 'close') return ws.close(4001, 'done')
  ws.send(d, { binary: bin })
}))
srv.listen(+port, '127.0.0.1', () => console.log('ready'))
