#!/usr/bin/env bash
set -uo pipefail
D="$(cd "$(dirname "$0")" && pwd)" R="$(cd "$(dirname "$0")/../.." && pwd)" W="${WYCHEPROOF:-$HOME/.cache/helium-wycheproof}" B=$(mktemp -d); trap 'rm -rf "$B"' EXIT; mkdir -p "$W"
for n in aes_gcm_test chacha20_poly1305_test xchacha20_poly1305_test x25519_test ed25519_test ecdsa_secp256r1_sha256_test ecdsa_secp384r1_sha384_test ecdsa_secp256r1_sha256_p1363_test ecdsa_secp384r1_sha384_p1363_test ecdh_secp256r1_ecpoint_test ecdh_secp384r1_ecpoint_test rsa_signature_2048_sha256_test rsa_signature_3072_sha256_test rsa_signature_4096_sha512_test rsa_pss_2048_sha256_mgf1_32_test rsa_pss_4096_sha512_mgf1_64_test hmac_sha256_test hmac_sha384_test hmac_sha512_test hkdf_sha256_test hkdf_sha384_test pbkdf2_hmacsha256_test; do [ -s "$W/$n.json" ] || curl -sfL --max-time 60 -o "$W/$n.json" "https://raw.githubusercontent.com/C2SP/wycheproof/main/testvectors_v1/$n.json" || { echo "cannot fetch $n"; exit 1; }; done
HC_LIB="$R/hc/lib" "$R/build/hc" build "$D/vec.amni" -o "$B/vec" || exit 1
python3 "$D/check.py" "$W" "$B/vec" "$@"
