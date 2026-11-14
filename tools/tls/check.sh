#!/usr/bin/env bash
set -uo pipefail
D="$(cd "$(dirname "$0")" && pwd)" R="$(cd "$(dirname "$0")/../.." && pwd)" W=$(mktemp -d); PIDS=(); fail=0; n=0
cleanup() { for p in "${PIDS[@]}"; do kill "$p" 2>/dev/null; done; rm -rf "$W"; }; trap cleanup EXIT
HC_LIB="$R/hc/lib" "$R/build/hc" build "$D/client.amni" -o "$W/client" || exit 1
cd "$W"; o() { openssl "$@" >/dev/null 2>&1; }
o req -x509 -newkey ec -pkeyopt ec_paramgen_curve:P-256 -nodes -keyout ca.key -out ca.pem -days 30 -subj /CN=HeliumTestCA -addext basicConstraints=critical,CA:TRUE -addext keyUsage=critical,keyCertSign
o req -x509 -newkey ec -pkeyopt ec_paramgen_curve:P-256 -nodes -keyout ca2.key -out ca2.pem -days 30 -subj /CN=OtherCA -addext basicConstraints=critical,CA:TRUE -addext keyUsage=critical,keyCertSign
mk() { local name=$1 alg=$2 ca=$3 san=$4; o genpkey $alg -out $name.key; o req -new -key $name.key -out $name.csr -subj /CN=$name; printf "subjectAltName=$san\nextendedKeyUsage=serverAuth\nbasicConstraints=CA:FALSE\n" >$name.ext; o x509 -req -in $name.csr -CA $ca.pem -CAkey $ca.key -CAcreateserial -out $name.pem -days 7 -extfile $name.ext; }
mk rsa "-algorithm RSA -pkeyopt rsa_keygen_bits:2048" ca DNS:localhost; mk p256 "-algorithm EC -pkeyopt ec_paramgen_curve:P-256" ca DNS:localhost; mk p384 "-algorithm EC -pkeyopt ec_paramgen_curve:P-384" ca DNS:localhost
mk ed "-algorithm ED25519" ca DNS:localhost; mk other "-algorithm EC -pkeyopt ec_paramgen_curve:P-256" ca DNS:other.example; mk untrusted "-algorithm EC -pkeyopt ec_paramgen_curve:P-256" ca2 DNS:localhost
head -c 1500000 /dev/urandom >big.bin; echo hello >small.txt; BIG=$(sha256sum big.bin | cut -d' ' -f1); SMALL=$(sha256sum small.txt | cut -d' ' -f1)
port=$((20000 + RANDOM % 20000))
run() {
	local name=$1 expect=$2 path=$3 cert=$4; shift 4; local extra=(); [ "${1:-}" = "--pin" ] && { extra=("$2"); shift 2; }; port=$((port + 1)); n=$((n + 1))
	openssl s_server -accept 127.0.0.1:$port -cert $cert.pem -key $cert.key -WWW -quiet "$@" </dev/null >/dev/null 2>&1 & local sp=$!; PIDS+=($sp)
	for i in $(seq 70); do (exec 3<>/dev/tcp/127.0.0.1/$port) 2>/dev/null && break; sleep 0.1; done
	local out; out=$(timeout 40 "$W/client" localhost $port ca.pem "$path" 0 "${extra[@]}" 2>&1 | tail -1); kill $sp 2>/dev/null; wait $sp 2>/dev/null
	if [[ "$out" == *$expect* ]]; then printf 'ok    %-34s %s\n' "$name" "${out:0:110}"; else printf 'FAIL  %-34s %s\n' "$name" "${out:0:160}"; fail=1; fi
}
for s in TLS_CHACHA20_POLY1305_SHA256 TLS_AES_128_GCM_SHA256 TLS_AES_256_GCM_SHA384; do run "suite $s" "sha=$BIG" /big.bin p256 -ciphersuites $s; done
run "group X25519" "group=0x0 hrr=0" /small.txt p256 -groups X25519
run "group P-256" "sha=$SMALL" /small.txt p256 -groups P-256
run "group P-384 (HelloRetryRequest)" "group=0x18 hrr=1" /small.txt p256 -groups P-384
run "cert RSA-2048 (rsa_pss_rsae)" "sha=$SMALL" /small.txt rsa
run "cert ECDSA P-384" "sha=$SMALL" /small.txt p384
run "cert Ed25519" "sha=$SMALL" /small.txt ed
run "server asks for client cert" "sha=$SMALL" /small.txt p256 -verify 1
run "big download AES-128" "sha=$BIG" /big.bin rsa -ciphersuites TLS_AES_128_GCM_SHA256
run "wrong host rejected" "FAIL verify=2" /small.txt other
run "untrusted CA rejected" "FAIL verify=1" /small.txt untrusted
PIN=$(openssl x509 -in untrusted.pem -pubkey -noout | openssl pkey -pubin -outform DER | sha256sum | cut -d' ' -f1)
run "untrusted CA accepted when pinned" "sha=$SMALL" /small.txt untrusted --pin $PIN
for s in ECDHE-ECDSA-CHACHA20-POLY1305 ECDHE-ECDSA-AES128-GCM-SHA256 ECDHE-ECDSA-AES256-GCM-SHA384; do run "TLS 1.2 $s" "sha=$BIG" /big.bin p256 -tls1_2 -cipher $s; done
for s in ECDHE-RSA-CHACHA20-POLY1305 ECDHE-RSA-AES128-GCM-SHA256 ECDHE-RSA-AES256-GCM-SHA384; do run "TLS 1.2 $s" "sha=$SMALL" /small.txt rsa -tls1_2 -cipher $s; done
run "TLS 1.2 group P-384, ECDSA P-384 cert" "sha=$SMALL" /small.txt p384 -tls1_2 -groups P-384
run "TLS 1.2 group P-256" "sha=$SMALL" /small.txt p256 -tls1_2 -groups P-256
run "TLS 1.2 without extended master secret" "sha=$SMALL" /small.txt p256 -tls1_2 -no_ems
run "TLS 1.2 server asks for client cert" "sha=$SMALL" /small.txt rsa -tls1_2 -verify 1
run "TLS 1.2 wrong host rejected" "FAIL verify=2" /small.txt other -tls1_2
run "TLS 1.2 RSA-PKCS1 key exchange signature" "sha=$SMALL" /small.txt rsa -tls1_2 -sigalgs RSA+SHA256
run "TLS 1.1-only server refused" "FAIL" /small.txt p256 -tls1_1
echo "tls: $n cases, $([ $fail = 0 ] && echo ok || echo FAILED)"; exit $fail
