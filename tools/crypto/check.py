import sys, os, json, random, hashlib, hmac, subprocess, tempfile
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes
W, BIN = sys.argv[1], sys.argv[2]
only = sys.argv[3].split(',') if len(sys.argv) > 3 else None
rng = random.Random(7177)
K = {'SHA-1': 1, 'SHA-256': 2, 'SHA-384': 3, 'SHA-512': 4}
HL = {1: hashlib.sha1, 2: hashlib.sha256, 3: hashlib.sha384, 4: hashlib.sha512}
HC = {1: hashes.SHA1, 2: hashes.SHA256, 3: hashes.SHA384, 4: hashes.SHA512}
h = lambda b: b.hex() if b else '-'
cases = []
def add(group, line, check): cases.append((group, line, check))
def suite_hash():
    lens = list(range(0, 300)) + [rng.randrange(300, 5000) for _ in range(40)] + [1000000]
    for k in (1, 2, 3, 4):
        for n in lens:
            m = bytes(rng.randrange(256) for _ in range(n)) if n < 100000 else b'a' * n
            d = HL[k](m).hexdigest()
            add('sha', f'H {k} {h(m)}', lambda o, d=d: o == d)
            if n in (0, 1, 63, 64, 65, 127, 128, 129, 1000) or n > 2000 and n < 5000 and rng.random() < 0.2:
                add('sha-stream', f'HS {k} {h(m)} {rng.randrange(1, 200)}', lambda o, d=d: o == d)
    for k in (1, 2, 3, 4):
        for n in (0, 1, 55, 56, 64, 111, 112, 128, 300):
            m = bytes(rng.randrange(256) for _ in range(n + 40)); c = rng.randrange(0, n + 1)
            add('sha-fork', f'HF {k} {h(m)} {c}', lambda o, a=HL[k](m[:c]).hexdigest(), b=HL[k](m).hexdigest(): o == a + ' ' + b)
    for k in (2, 3, 4):
        for _ in range(60):
            key = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 300))); m = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 500)))
            add('hmac-openssl', f'M {k} {h(key)} {h(m)}', lambda o, d=hmac.new(key, m, HL[k]).hexdigest(): o == d)
def suite_hmac():
    for name, k in (('hmac_sha256_test', 2), ('hmac_sha384_test', 3), ('hmac_sha512_test', 4)):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            n = g['tagSize'] // 8
            for t in g['tests']:
                ok = t['result'] == 'valid'
                add('hmac-wycheproof', f"M {k} {t['key'] or '-'} {t['msg'] or '-'}", lambda o, tag=t['tag'], n=n, ok=ok: (o[:2 * n] == tag) == ok)
def suite_hkdf():
    for name, k in (('hkdf_sha256_test', 2), ('hkdf_sha384_test', 3)):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            for t in g['tests']:
                ok = t['result'] == 'valid'
                add('hkdf-wycheproof', f"K {k} {t['ikm'] or '-'} {t['salt'] or '-'} {t['info'] or '-'} {t['size']}", lambda o, okm=t['okm'], ok=ok: (o == okm) if ok else (o == 'ERR' or o != okm))
    for k in (2, 3, 4):
        for _ in range(30):
            ikm, salt, info = (bytes(rng.randrange(256) for _ in range(rng.randrange(0, 80))) for _ in range(3)); n = rng.randrange(1, 255 * HL[k]().digest_size // 4)
            exp = HKDF(HC[k](), n, salt or None, info).derive(ikm).hex()
            add('hkdf-openssl', f'K {k} {h(ikm)} {h(salt)} {h(info)} {n}', lambda o, e=exp: o == e)
from cryptography.hazmat.primitives.ciphers.aead import AESGCM, ChaCha20Poly1305
def suite_aead():
    for name, alg in (('aes_gcm_test', 1), ('chacha20_poly1305_test', 2), ('xchacha20_poly1305_test', 3)):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            for t in g['tests']:
                r = t['result']; full = (t['ct'] + t['tag']) or '-'
                if r == 'valid':
                    add('aead-wycheproof', f"A {alg} {t['key'] or '-'} {t['iv'] or '-'} {t['aad'] or '-'} {t['msg'] or '-'}", lambda o, e=t['ct'] + t['tag']: o == e)
                    add('aead-wycheproof', f"AO {alg} {t['key'] or '-'} {t['iv'] or '-'} {t['aad'] or '-'} {full}", lambda o, e=t['msg'] or '-': o == e)
                elif r == 'invalid':
                    add('aead-wycheproof', f"AO {alg} {t['key'] or '-'} {t['iv'] or '-'} {t['aad'] or '-'} {full}", lambda o: o == 'ERR')
    for _ in range(150):
        for alg in (1, 2):
            kl = rng.choice((16, 24, 32)) if alg == 1 else 32; key = bytes(rng.randrange(256) for _ in range(kl)); nl = rng.choice((12, 12, 12, 8, 16, 60)) if alg == 1 else 12
            n = bytes(rng.randrange(256) for _ in range(nl)); aad = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 70))); m = bytes(rng.randrange(256) for _ in range(rng.choice((0, 1, 15, 16, 17, 64, 255, 1000, rng.randrange(0, 4000)))))
            e = (AESGCM(key) if alg == 1 else ChaCha20Poly1305(key)).encrypt(n, m, aad or None)
            add('aead-openssl', f'A {alg} {h(key)} {h(n)} {h(aad)} {h(m)}', lambda o, e=e.hex(): o == e)
            add('aead-openssl', f'AO {alg} {h(key)} {h(n)} {h(aad)} {e.hex()}', lambda o, e=m.hex() or '-': o == e)
            bad = bytearray(e); bad[rng.randrange(len(bad))] ^= 1 << rng.randrange(8)
            add('aead-openssl', f'AO {alg} {h(key)} {h(n)} {h(aad)} {bytes(bad).hex()}', lambda o: o == 'ERR')
from cryptography.hazmat.primitives.asymmetric import ed25519 as ed, x25519 as xx
from cryptography.hazmat.primitives import serialization as ser
RAW = (ser.Encoding.Raw, ser.PublicFormat.Raw)
def suite_25519():
    for g in json.load(open(f'{W}/x25519_test.json'))['testGroups']:
        for t in g['tests']:
            add('x25519-wycheproof', f"X {t['private']} {t['public']}", lambda o, e=t['shared'], r=t['result']: (o == e) if r != 'invalid' else True)
    add('x25519-rfc7748', 'XI 0900000000000000000000000000000000000000000000000000000000000000 1', lambda o: o == '422c8e7a6227d7bca1350b3e2bb7279f7897b87bb6854b783c60e80311ae3079')
    add('x25519-rfc7748', 'XI 0900000000000000000000000000000000000000000000000000000000000000 1000', lambda o: o == '684cf59ba83309552800ef566f2f4d3c1c3887c49360e3875f2eb94d99532c51')
    for _ in range(100):
        a, b = bytes(rng.randrange(256) for _ in range(32)), bytes(rng.randrange(256) for _ in range(32))
        A = xx.X25519PrivateKey.from_private_bytes(a); B = xx.X25519PrivateKey.from_private_bytes(b)
        add('x25519-openssl', f'XB {a.hex()}', lambda o, e=A.public_key().public_bytes(*RAW).hex(): o == e)
        add('x25519-openssl', f'X {a.hex()} {B.public_key().public_bytes(*RAW).hex()}', lambda o, e=A.exchange(B.public_key()).hex(): o == e)
    for g in json.load(open(f'{W}/ed25519_test.json'))['testGroups']:
        pk = g['publicKey']['pk']
        for t in g['tests']:
            r = t['result']; so = 'SmallOrderPublicKey' in t['flags']
            add('ed25519-wycheproof', f"EV {pk} {t['msg'] or '-'} {t['sig'] or '-'}", lambda o, r=r, so=so: o == '0' if so else (o == '1' if r == 'valid' else o == '0' if r == 'invalid' else o in ('0', '1')))
    for _ in range(100):
        sd = bytes(rng.randrange(256) for _ in range(32)); m = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 300))); k = ed.Ed25519PrivateKey.from_private_bytes(sd)
        sig = k.sign(m); pk = k.public_key().public_bytes(*RAW)
        add('ed25519-openssl', f'EP {sd.hex()}', lambda o, e=pk.hex(): o == e)
        add('ed25519-openssl', f'ES {sd.hex()} {h(m)}', lambda o, e=sig.hex(): o == e)
        add('ed25519-openssl', f'EV {pk.hex()} {h(m)} {sig.hex()}', lambda o: o == '1')
        bad = bytearray(sig); bad[rng.randrange(64)] ^= 1 << rng.randrange(8)
        add('ed25519-openssl', f'EV {pk.hex()} {h(m)} {bytes(bad).hex()}', lambda o: o == '0')
from cryptography.hazmat.primitives.asymmetric import rsa, padding
def wy_ok(r, o): return o == '1' if r == 'valid' else o == '0' if r == 'invalid' else o in ('0', '1')
def suite_rsa():
    for name in ('rsa_signature_2048_sha256_test', 'rsa_signature_3072_sha256_test', 'rsa_signature_4096_sha512_test'):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            k = K[g['sha']]; pk = g.get('publicKey', {}); n = pk.get('modulus') or g['n']; e = pk.get('publicExponent') or g['e']
            for t in g['tests']: add('rsa-pkcs1-wycheproof', f"RV {k} {n} {e} {t['msg'] or '-'} {t['sig'] or '-'}", lambda o, r=t['result']: wy_ok(r, o))
    for name in ('rsa_pss_2048_sha256_mgf1_32_test', 'rsa_pss_4096_sha512_mgf1_64_test'):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            k = K[g['sha']]; mk = K[g['mgfSha']]; pk = g.get('publicKey', {}); n = pk.get('modulus') or g['n']; e = pk.get('publicExponent') or g['e']
            for t in g['tests']: add('rsa-pss-wycheproof', f"RP {k} {mk} {g['sLen']} {n} {e} {t['msg'] or '-'} {t['sig'] or '-'}", lambda o, r=t['result']: wy_ok(r, o))
    for bits in (2048, 3072, 4096):
        key = rsa.generate_private_key(public_exponent=65537, key_size=bits); nn = key.public_key().public_numbers(); n = '%x' % nn.n; n = ('0' * (len(n) % 2)) + n; e = '010001'
        for _ in range(12):
            k = rng.choice((1, 2, 3, 4)); m = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 200)))
            s1 = key.sign(m, padding.PKCS1v15(), HC[k]()); s2 = key.sign(m, padding.PSS(padding.MGF1(HC[k]()), HL[k]().digest_size), HC[k]())
            add('rsa-openssl', f'RV {k} {n} {e} {h(m)} {s1.hex()}', lambda o: o == '1'); add('rsa-openssl', f'RP {k} {k} {HL[k]().digest_size} {n} {e} {h(m)} {s2.hex()}', lambda o: o == '1')
            add('rsa-openssl', f'RV {k} {n} {e} {h(m + b"x")} {s1.hex()}', lambda o: o == '0'); add('rsa-openssl', f'RP {k} {k} {HL[k]().digest_size} {n} {e} {h(m + b"x")} {s2.hex()}', lambda o: o == '0')
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.asymmetric.utils import decode_dss_signature
CV = {1: (ec.SECP256R1(), 32), 2: (ec.SECP384R1(), 48)}
def suite_ecc():
    for name, cid in (('ecdsa_secp256r1_sha256_test', 1), ('ecdsa_secp384r1_sha384_test', 2)):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            pk = g['publicKey']['uncompressed']; k = K[g['sha']]
            for t in g['tests']: add('ecdsa-der-wycheproof', f"PVD {cid} {k} {pk} {t['msg'] or '-'} {t['sig'] or '-'}", lambda o, r=t['result']: wy_ok(r, o))
    for name, cid in (('ecdsa_secp256r1_sha256_p1363_test', 1), ('ecdsa_secp384r1_sha384_p1363_test', 2)):
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            pk = g['publicKey']['uncompressed']; k = K[g['sha']]
            for t in g['tests']: add('ecdsa-raw-wycheproof', f"PV {cid} {k} {pk} {t['msg'] or '-'} {t['sig'] or '-'}", lambda o, r=t['result']: wy_ok(r, o))
    for name, cid in (('ecdh_secp256r1_ecpoint_test', 1), ('ecdh_secp384r1_ecpoint_test', 2)):
        sz = CV[cid][1]
        for g in json.load(open(f'{W}/{name}.json'))['testGroups']:
            for t in g['tests']:
                d = int(t['private'], 16)
                if d.bit_length() > 8 * sz: continue
                r = t['result']
                add('ecdh-wycheproof', f"PD {cid} {d.to_bytes(sz, 'big').hex()} {t['public'] or '-'}", lambda o, r=r, e=t['shared']: o == e if r == 'valid' else o == 'ERR' if r == 'invalid' else o in (e, 'ERR'))
    add('ecdsa-rfc6979', 'PS 1 2 c9afa9d845ba75166b5c215767b1d6934e50c3db36e89b127b8a622b120f6721 73616d706c65', lambda o: o == 'efd48b2aacb6a8fd1140dd9cd45e81d69d2c877b56aaf991c34d0ea84eaf3716f7cb1c942d657c41d436c7a1b6e29f65f3e900dbb9aff4064dc4ab2f843acda8')
    for cid, (cv, sz) in CV.items():
        for _ in range(60):
            key = ec.generate_private_key(cv); d = key.private_numbers().private_value.to_bytes(sz, 'big'); pub = key.public_key().public_bytes(ser.Encoding.X962, ser.PublicFormat.UncompressedPoint)
            comp = key.public_key().public_bytes(ser.Encoding.X962, ser.PublicFormat.CompressedPoint); peer = ec.generate_private_key(cv)
            ppub = peer.public_key().public_bytes(ser.Encoding.X962, ser.PublicFormat.UncompressedPoint); pcomp = peer.public_key().public_bytes(ser.Encoding.X962, ser.PublicFormat.CompressedPoint)
            sh = key.exchange(ec.ECDH(), peer.public_key()).hex()
            add('ecc-openssl', f'PK {cid} {d.hex()}', lambda o, e=pub.hex(): o == e)
            add('ecc-openssl', f'PD {cid} {d.hex()} {ppub.hex()}', lambda o, e=sh: o == e)
            add('ecc-openssl', f'PD {cid} {d.hex()} {pcomp.hex()}', lambda o, e=sh: o == e)
            k = rng.choice((2, 3, 4)); m = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 200)))
            der = key.sign(m, ec.ECDSA(HC[k](), deterministic_signing=True)); r, s = decode_dss_signature(der); raw = (r.to_bytes(sz, 'big') + s.to_bytes(sz, 'big')).hex()
            add('ecc-openssl', f'PS {cid} {k} {d.hex()} {h(m)}', lambda o, e=raw: o == e)
            rnd = key.sign(m, ec.ECDSA(HC[k]())); 
            add('ecc-openssl', f'PVD {cid} {k} {pub.hex()} {h(m)} {rnd.hex()}', lambda o: o == '1')
            add('ecc-openssl', f'PVD {cid} {k} {comp.hex()} {h(m)} {rnd.hex()}', lambda o: o == '1')
            add('ecc-openssl', f'PVD {cid} {k} {pub.hex()} {h(m + b"!")} {rnd.hex()}', lambda o: o == '0')
        def gen_ok(o, cv=cv, sz=sz):
            d, p = o.split(); return ec.derive_private_key(int(d, 16), cv).public_key().public_bytes(ser.Encoding.X962, ser.PublicFormat.UncompressedPoint).hex() == p
        for _ in range(5): add('ecc-keygen', f'PG {cid}', gen_ok)
    add('random', 'RB 64', lambda o: len(o) == 257 and o[:128] != o[129:] and o[:128] != '0' * 128)
def suite_pbkdf2():
    for g in json.load(open(f'{W}/pbkdf2_hmacsha256_test.json'))['testGroups']:
        for t in g['tests']:
            if t['iterationCount'] > 100000: continue
            add('pbkdf2-wycheproof', f"KD 2 {t['password'] or '-'} {t['salt'] or '-'} {t['iterationCount']} {t['dkLen']}", lambda o, r=t['result'], e=t['dk']: wy_ok('valid', '1' if o == e else '0') if r == 'valid' else o != e)
    for k in (1, 2, 3, 4):
        for _ in range(8):
            pw, salt = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 150))), bytes(rng.randrange(256) for _ in range(rng.randrange(0, 40))); it = rng.choice((1, 2, 5, 1000, 4096)); n = rng.randrange(1, 100)
            add('pbkdf2-openssl', f'KD {k} {h(pw)} {h(salt)} {it} {n}', lambda o, e=hashlib.pbkdf2_hmac(HL[k]().name, pw, salt, it, n).hex(): o == e)
    add('pbkdf2-haven', f"KD 2 {b'correct horse'.hex()} {b'haven-e2e-wrapping-v3'.hex()} 600000 32", lambda o, e=hashlib.pbkdf2_hmac('sha256', b'correct horse', b'haven-e2e-wrapping-v3', 600000, 32).hex(): o == e)
SUITES = {'pbkdf2': suite_pbkdf2, 'ecc': suite_ecc, 'rsa': suite_rsa, '25519': suite_25519, 'aead': suite_aead, 'hash': suite_hash, 'hmac': suite_hmac, 'hkdf': suite_hkdf}
for n, f in SUITES.items():
    if not only or n in only: f()
with tempfile.NamedTemporaryFile('w', delete=False, suffix='.txt') as fh:
    fh.write('\n'.join(c[1] for c in cases) + '\n'); path = fh.name
out = subprocess.run([BIN, path], capture_output=True, text=True, timeout=3600).stdout.split('\n'); os.unlink(path)
stats = {}; bad = 0
for i, (g, line, chk) in enumerate(cases):
    o = out[i] if i < len(out) else '<missing>'
    s = stats.setdefault(g, [0, 0]); s[0] += 1
    if not chk(o):
        s[1] += 1; bad += 1
        if s[1] <= 3: print(f'FAIL {g}: {line[:120]} -> {o[:100]}')
for g, (n, b) in stats.items(): print(f'{g:18s} {n - b}/{n} pass')
print('crypto: ok' if bad == 0 else f'crypto: {bad} FAILED'); sys.exit(1 if bad else 0)
