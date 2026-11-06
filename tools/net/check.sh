#!/usr/bin/env bash
set -uo pipefail
D="$(cd "$(dirname "$0")" && pwd)" R="$(cd "$(dirname "$0")/../.." && pwd)" W=$(mktemp -d); PIDS=(); fail=0; n=0
NM="${HAVEN_NODE_MODULES:-$HOME/ai/Haven/node_modules}"
cleanup() { for p in "${PIDS[@]}"; do kill "$p" 2>/dev/null; done; rm -rf "$W"; }; trap cleanup EXIT
HC_LIB="$R/hc/lib" "$R/build/hc" build "$D/client.he" -o "$W/nc" || exit 1
cd "$W"; openssl req -x509 -newkey ec -pkeyopt ec_paramgen_curve:P-256 -nodes -keyout self.key -out self.pem -days 7 -subj /CN=localhost -addext subjectAltName=DNS:localhost >/dev/null 2>&1
PIN=$(openssl x509 -in self.pem -pubkey -noout | openssl pkey -pubin -outform DER | sha256sum | cut -d' ' -f1)
sha() { python3 -c "import hashlib,sys;n=int(sys.argv[1]);print(hashlib.sha256(bytes((i*31+7)&255 for i in range(n))).hexdigest())" "$1"; }
serve() { local port=$1; shift; NODE_PATH="$NM" node "$D/server.js" $port "$@" >"srv$port.log" 2>&1 & PIDS+=($!); for i in $(seq 70); do grep -q ready "srv$port.log" 2>/dev/null && return; sleep 0.1; done; echo "server on $port did not start"; exit 1; }
t() { local name=$1 want=$2; shift 2; n=$((n + 1)); local out; out=$(timeout 90 "$@" 2>&1 | tr '\n' ' '); if [[ "$out" == *"$want"* ]]; then printf 'ok    %-30s\n' "$name"; else printf 'FAIL  %-30s %s\n' "$name" "${out:0:300}"; fail=1; fi; }
P=$((20000 + RANDOM % 20000)); serve $P; serve $((P + 1)) self.pem self.key
for mode in plain tls; do
	[ $mode = plain ] && B=http://127.0.0.1:$P WB=ws://127.0.0.1:$P E=() || B=https://localhost:$((P + 1)) WB=wss://localhost:$((P + 1)) E=(env PIN=$PIN)
	for c in len/0 len/1 len/1000000 chunk/1 chunk/777777 close/12345; do k=${c#*/}; t "$mode GET $c" "status=200 len=$k sha=$(sha $k)" "${E[@]}" ./nc http GET $B/$c; done
	t "$mode GET status 204" "status=204 len=0" "${E[@]}" ./nc http GET $B/status/204
	t "$mode GET status 404" "status=404 len=0" "${E[@]}" ./nc http GET $B/status/404
	t "$mode HEAD" "status=200 len=0 sha=$(sha 0) x=yes" "${E[@]}" ./nc http HEAD $B/len/5000
	t "$mode POST json + bearer" '"len":15,"auth":"Bearer abc","body":"{\"hi\":\"thére\"}"' "${E[@]}" ./nc http POST $B/echo/0 '{"hi":"thére"}'
	t "$mode WebSocket suite" "ws ok echoes=16 fragments=ok close=4001 state=3" "${E[@]}" ./nc ws $WB/ws
	t "$mode Socket.IO suite" 'echoed [1,"two",{"three":[3,3.5,null,true]}] ack [42,"sum"] thanks ["helium"] alive after heartbeats: true sio ok end=3' "${E[@]}" ./nc sio $B t0k
	t "$mode Socket.IO refused" "bad token" "${E[@]}" ./nc sio $B nope
done
t "self-signed without pin refused" "ERR certificate rejected (1)" ./nc http GET https://localhost:$((P + 1))/len/1
t "untrusted reports SPKI pin" "pin=$PIN" ./nc http GET https://localhost:$((P + 1))/len/1
t "pin for another key refused" "ERR certificate rejected" env PIN=$(printf %064d 0) ./nc http GET https://localhost:$((P + 1))/len/1
t "connection refused" "ERR connect failed" ./nc http GET http://127.0.0.1:1/len/1
t "unknown host" "ERR cannot resolve host" ./nc http GET http://no-such-host.invalid/
echo "net: $n cases, $([ $fail = 0 ] && echo ok || echo FAILED)"; exit $fail
