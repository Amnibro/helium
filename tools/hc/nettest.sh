#!/bin/bash
# Two-process socket tests: the relay server and two clients from tools/hc/net (the minigolf netcode spike on
# hc/lib/net.he; both clients must reach the same SIMHASH and swap one UDP datagram), and the echo and chat samples
# as separate server and client processes, each built natively and through C; then the web build: ws_client.he under
# hc/web/web.js talking to a WebSocket echo server (wstest.mjs, needs node). Usage: nettest.sh <hc>
HC=${1:?usage: nettest.sh <hc>}; R=$(cd "$(dirname "$0")/../.." && pwd); L=${HC_LIB:-$R/hc/lib}; W=$(mktemp -d); p=0; f=0
trap 'kill $(jobs -p) 2>/dev/null; rm -rf "$W"' EXIT
build() { # src out mode
	case $3 in
		native) HC_LIB=$L "$HC" "$1" "$2" --native ;;
		c) HC_LIB=$L "$HC" "$1" "$2.c" && ${CC:-clang} -O1 -fwrapv -w -I"$L/.." "$2.c" -o "$2" -lm ;;
	esac
}
ok() { p=$((p+1)); }
bad() { f=$((f+1)); echo "FAIL $1"; [ -n "${2:-}" ] && sed 's/^/  /' "$2" | head -20; }
# a free-looking port per run so parallel runs and TIME_WAIT leftovers don't collide
port() { echo $(( 20000 + (RANDOM % 20000) )); }
for m in native c; do
	d=$W/$m; mkdir -p "$d"
	for s in tools/hc/net/relay_server.he tools/hc/net/relay_client.he samples/32_net_chat.he samples/33_net_echo.he; do
		n=$(basename "$s" .he); build "$R/$s" "$d/$n" $m 2>"$d/$n.err" || { bad "build $n ($m)" "$d/$n.err"; continue 2; }
	done
	P=$(port); "$d/relay_server" $P > "$d/server.log" 2>&1 & S=$!; sleep 0.3
	timeout 20 "$d/relay_client" $P alice 0 > "$d/alice.log" 2>&1 & A=$!
	timeout 20 "$d/relay_client" $P bob 1 > "$d/bob.log" 2>&1 & B=$!
	wait $A; ra=$?; wait $B; rb=$?; timeout 5 tail --pid=$S -f /dev/null; kill $S 2>/dev/null
	want="SIMHASH 7232135907065437725"
	if [ $ra = 0 ] && [ $rb = 0 ] && grep -q "alice: $want" "$d/alice.log" && grep -q "bob: $want" "$d/bob.log" && grep -q "UDP ok" "$d/alice.log" && grep -q "UDP ok" "$d/bob.log" && grep -q "2 relayed messages" "$d/server.log"; then ok; else bad "relay ($m)" <(cat "$d/server.log" "$d/alice.log" "$d/bob.log"); fi
	P=$(port); "$d/33_net_echo" server $P > "$d/echo.log" 2>&1 & S=$!; sleep 0.3
	if timeout 10 "$d/33_net_echo" client 127.0.0.1:$P "two processes" > "$d/echoc.log" 2>&1 && grep -q "^tcp echo: two processes$" "$d/echoc.log" && grep -q "^udp echo: two processes (from the server's port)$" "$d/echoc.log"; then ok; else bad "echo ($m)" "$d/echoc.log"; fi
	kill $S 2>/dev/null
	P=$(port); "$d/32_net_chat" server $P > "$d/chat.log" 2>&1 & S=$!; sleep 0.3
	if timeout 10 "$d/32_net_chat" client localhost:$P cy one two > "$d/chatc.log" 2>&1 && printf '[cy] * cy joined\n[cy] cy: one\n[cy] cy: two\n' | cmp -s - "$d/chatc.log"; then ok; else bad "chat ($m)" "$d/chatc.log"; fi
	kill $S 2>/dev/null
done
if command -v node >/dev/null; then
	if HC_LIB=$L "$HC" "$R/tools/hc/net/ws_client.he" "$W/ws.wasm" --web > "$W/ws.err" 2>&1 && timeout 20 node "$R/tools/hc/net/wstest.mjs" "$W/ws.wasm" > "$W/ws.log" 2>&1 && cmp -s "$W/ws.log" "$R/tools/hc/net/ws_client.out"; then ok; else bad "websocket (web)" <(cat "$W/ws.err" "$W/ws.log"); fi
fi
echo "nettest: $p pass, $f fail"; [ $f = 0 ]
