"""The language server, `goose lsp` (docs/design/language_server.md), driven
over its own protocol: a client of this runner's starts it on a pipe,
initializes, opens the fixtures in test/lsp/, waits for their diagnostics,
and asks what each fixture's `// lsp:` lines say to ask, comparing the
answers. Then it edits a document into an error and back, checking the
diagnostics follow, with the edits arriving in a burst so that one analysis
is cancelled by the next, and sees the server out."""
import json
import os
import re
import subprocess
import time
from pathlib import Path

import toolchain as tc

HERE = Path(__file__).resolve().parent


def uri_of(path):
    p = Path(path).resolve().as_posix()
    if re.match(r"^[A-Za-z]:/", p):
        p = p[0].lower() + "%3A" + p[2:]
    return "file:///" + p.lstrip("/")


class Client:
    def __init__(self, exe, cwd):
        self.p = subprocess.Popen([exe, "lsp"], cwd=cwd, stdin=subprocess.PIPE,
                                  stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        self.seq = 0
        self.pending = []    # Notifications read while waiting for a reply.

    def send(self, method, params=None, request=True):
        msg = {"jsonrpc": "2.0", "method": method}
        if params is not None:
            msg["params"] = params
        if request:
            self.seq += 1
            msg["id"] = self.seq
        body = json.dumps(msg).encode()
        try:
            self.p.stdin.write(b"Content-Length: %d\r\n\r\n" % len(body) + body)
            self.p.stdin.flush()
        except OSError:
            raise RuntimeError(f"the server is gone (exit {self.p.wait()}):\n"
                               f"{tc.decode(self.p.stderr.read())}")
        return self.seq if request else None

    def read(self):
        headers = {}
        while True:
            line = self.p.stdout.readline()
            if not line:
                raise RuntimeError(f"the server closed its output (exit {self.p.wait()}):\n"
                                   f"{tc.decode(self.p.stderr.read())}")
            line = line.strip()
            if not line:
                break
            name, value = line.decode().split(":", 1)
            headers[name.strip()] = value.strip()
        return json.loads(self.p.stdout.read(int(headers["Content-Length"])))

    def reply(self, rid, timeout=30):
        """The reply to request rid; the notifications before it wait in
        `pending`."""
        deadline = time.time() + timeout
        while time.time() < deadline:
            m = self.read()
            if m.get("id") == rid:
                if "error" in m:
                    raise RuntimeError(f"request {rid} failed: {m['error']}")
                return m.get("result")
            self.pending.append(m)
        raise RuntimeError(f"no reply to request {rid} in {timeout}s")

    def request(self, method, params):
        return self.reply(self.send(method, params))

    def notification(self, method, timeout=30):
        """The next notification of that method, pending or arriving."""
        for i, m in enumerate(self.pending):
            if m.get("method") == method:
                return self.pending.pop(i)["params"]
        deadline = time.time() + timeout
        while time.time() < deadline:
            m = self.read()
            if m.get("method") == method:
                return m["params"]
            self.pending.append(m)
        raise RuntimeError(f"no {method} in {timeout}s")

    def diagnostics_for(self, uri, accept=lambda diags: True, timeout=30):
        """The next diagnostics published for uri that `accept` takes:
        the ones of the text as it stands, after those of the versions a
        burst of changes went through."""
        deadline = time.time() + timeout
        last = None
        while time.time() < deadline:
            params = self.notification("textDocument/publishDiagnostics", timeout)
            if params["uri"].lower() != uri.lower():
                continue
            last = params["diagnostics"]
            if accept(last):
                return last
        raise RuntimeError(f"no accepted diagnostics for {uri} in {timeout}s; the last were\n"
                           f"{json.dumps(last, indent=1)[:2000]}")


def check_lsp_protocol(exe, base):
    """Raises RuntimeError on a failure."""
    base = Path(base).resolve()
    base.mkdir(parents=True, exist_ok=True)
    code, out, err = tc.run_capture([exe, "lsp", "--probe"])
    if code != 0 or not out.startswith("goose lsp 3."):
        raise RuntimeError(f"goose lsp --probe (exit {code}):\n{out}{err}")
    fixtures = HERE / "lsp"
    main = fixtures / "basics.goose"
    helper = fixtures / "helper.goose"
    text = main.read_text(encoding="utf-8")
    lines = text.splitlines()
    main_uri, helper_uri = uri_of(main), uri_of(helper)

    def position(spec):
        line, col = (int(x) for x in spec.split(":"))
        return {"line": line - 1, "character": col - 1}

    def fail(what, got):
        raise RuntimeError(f"lsp {what}:\n{json.dumps(got, indent=1)[:3000]}")

    client = Client(exe, fixtures)
    client.request("initialize", {"processId": None, "rootUri": uri_of(fixtures), "capabilities": {},
                                  "initializationOptions": {"entryFiles": [str(main)]}})
    client.send("initialized", {}, request=False)
    client.send("textDocument/didOpen", {"textDocument": {
        "uri": main_uri, "languageId": "goose", "version": 1, "text": text}}, request=False)
    diags = client.diagnostics_for(main_uri)
    if diags:
        fail("the fixture has diagnostics", diags)
    doc = {"textDocument": {"uri": main_uri}}
    for line in lines:
        m = re.match(r"// lsp: (\w+) (.*)$", line)
        if not m or line.startswith("// lsp: fixture"):
            continue
        kind, rest = m.groups()
        if kind == "hover":
            pos, want = rest.split(" ", 1)
            got = client.request("textDocument/hover", {**doc, "position": position(pos)})
            if not got or json.loads(want) not in got["contents"]["value"]:
                fail(f"hover {pos} lacks {want}", got)
        elif kind == "definition":
            pos, _, target = rest.split(" ", 2)
            got = client.request("textDocument/definition", {**doc, "position": position(pos)})
            if not got:
                fail(f"definition {pos}", got)
            if target.endswith(".goose"):
                if not got["uri"].lower().endswith(target):
                    fail(f"definition {pos} is not in {target}", got)
            else:
                want = position(target)
                if got["uri"].lower() != main_uri.lower() or got["range"]["start"] != want:
                    fail(f"definition {pos} is not at {target}", got)
        elif kind == "symbol":
            name, symkind = rest.split()
            kinds = {"function": 12, "struct": 23, "enum": 10, "constant": 14, "variable": 13}
            got = client.request("textDocument/documentSymbol", doc)
            if not any(s["name"] == name and s["kind"] == kinds[symkind] for s in got or []):
                fail(f"symbol {name} ({symkind})", got)
        elif kind == "signature":
            pos, want, active = re.match(r'(\S+) "(.*)" (\d+)$', rest).groups()
            got = client.request("textDocument/signatureHelp", {**doc, "position": position(pos)})
            if (not got or got["signatures"][got["activeSignature"]]["label"] != want or
                    got["activeParameter"] != int(active)):
                fail(f"signature {pos}", got)
        elif kind == "token":
            pos, want = rest.split()
            got = client.request("textDocument/semanticTokens/full", doc)
            legend = ["namespace", "type", "struct", "enum", "enumMember", "typeParameter",
                      "parameter", "variable", "property", "function", "method"]
            data = got["data"]
            tokens = {}
            line = char = 0
            for i in range(0, len(data), 5):
                dline, dchar, length, ttype, mods = data[i:i + 5]
                line += dline
                char = char + dchar if dline == 0 else dchar
                tokens[(line, char)] = legend[ttype]
            p = position(pos)
            if tokens.get((p["line"], p["character"])) != want:
                fail(f"token {pos} is not {want}", {"at": p, "got": tokens.get((p["line"], p["character"]))})
        else:
            raise RuntimeError(f"lsp: unknown query {kind} in {main.name}")
    got = client.request("workspace/symbol", {"query": "twi"})
    if not any(s["name"] == "twice" and s["location"]["uri"].lower() == helper_uri.lower() for s in got):
        fail("workspace symbol twice", got)

    # An edit into an error, and back, as a burst of changes: the server
    # drops the analysis a change interrupts, and the diagnostics that
    # stand are the last text's.
    broken = text.replace("let sum = add(p.x, p.y);", "let sum = add(p.x, p.y) + \"s\";")
    for version, body in ((2, broken), (3, text), (4, broken)):
        client.send("textDocument/didChange", {"textDocument": {"uri": main_uri, "version": version},
                                               "contentChanges": [{"text": body}]}, request=False)
    diags = client.diagnostics_for(main_uri, lambda d: len(d) > 0)
    if len(diags) != 1 or diags[0]["severity"] != 1 or diags[0]["range"]["start"]["line"] != 30:
        fail("diagnostics after an edit into an error", diags)
    client.send("textDocument/didChange", {"textDocument": {"uri": main_uri, "version": 5},
                                           "contentChanges": [{"text": text}]}, request=False)
    client.diagnostics_for(main_uri, lambda d: len(d) == 0)
    # The analysis stands again: a query answers as before.
    got = client.request("textDocument/hover", {**doc, "position": position("33:11")})
    if not got or "let sum: i64" not in got["contents"]["value"]:
        fail("hover after the edits", got)
    client.request("shutdown", None)
    client.send("exit", request=False)
    code = client.p.wait(timeout=30)
    if code != 0:
        raise RuntimeError(f"goose lsp exited with {code}:\n{tc.decode(client.p.stderr.read())}")
