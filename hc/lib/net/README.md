# net: game networking

* `net.udp` (udp.he): non-blocking IPv4 UDP sockets over libc.
* `net.link` (link.amni): a connection endpoint independent of the transport. Packets carry a
  16-bit sequence, the latest received sequence and 32 ack bits. Reliable messages are ordered and
  resent until a packet carrying them is acked (timeout from the measured round trip);
  unreliable messages are sent once. Duplicate packets are dropped.
* `net.snap` (snap.amni): snapshot replication. A store keeps the last 64 snapshots of up to
  `max_entities` entities with `fields` fixed-point (1/1024) values each. Snapshots are delta
  encoded against a baseline the receiver acked (changed-field masks, zigzag varints), with adds
  and removes. Clients interpolate between the two snapshots around a render time.
* `net.pred` (in snap.amni): the client input ring for prediction and server reconciliation.

## Pre-registered bars (committed before the first run; never loosened)

The test link simulator delays packets 100 ms +- 50 ms (uniform, so they reorder), drops 20 %,
duplicates 10 %. Ticks are 30 Hz.

* **L1 reliable channel.** 1000 reliable messages each way through the hostile link: every one
  delivered exactly once and in order on both sides, within 10 s of simulated time.
* **L2 delta snapshots.** 64 entities x 8 fields, 8 of them moving each tick, 300 ticks, hostile
  link, client acks snapshots. Every snapshot the client decodes equals the server's snapshot
  for that tick exactly. Mean delta snapshot size <= 20 % of the full snapshot size.
* **L3 interpolation.** Entities on straight lines at constant speed, render delay 4 ticks.
  With the link perfect: max |interpolated - true position at render time| <= 2/1024. With the
  hostile link: <= 2/1024 for every frame where a snapshot on each side of the render time has
  arrived, and that is >= 90 % of frames.
* **L4 prediction.** Client applies inputs at once and reconciles from the server's
  authoritative state plus the last input it processed. No server override: the predicted
  position equals the server's for the same input, exactly, every tick. With a wall the client
  does not know about (the server clamps x <= 5): the predicted position matches the server's
  within 1/1024 at most ceil(RTT / tick) + 3 ticks after the clamp first happens.
* **L5 real UDP.** Two endpoints on 127.0.0.1 exchange 200 reliable messages each way, all
  delivered in order.
* **Must-fail controls.** Resends switched off fails L1. Encoding against a baseline the client
  never acked, under loss, fails L2. Reconciliation switched off fails L4's wall case.

## Results (2026-11-02)

| check | measured | result |
| --- | --- | --- |
| L1 reliable channel | 2000/2000 exactly once, in order, by 705 ms | PASS |
| L2 delta snapshots | 238 decoded, 0 mismatches; delta 75 B vs full 1232 B (6.2 %) | PASS |
| L3 perfect link | 4648/4648 frames, max error 0.5/1024 | PASS |
| L3 hostile link, fixed 4-tick delay | 64 % of frames bracketed, max error 0.5/1024 | **FAIL** |
| L3b hostile link, adaptive delay (post-hoc) | 94.3 % bracketed, max error 0.5/1024 | PASS |
| L4 no override | 196 inputs, exact | PASS |
| L4 wall | clamp at input 50, RTT 218 ms, matched by input 60 | PASS |
| L5 real UDP | 200 and 200 in order | PASS |
| controls | resends off 238/2000; unacked baseline 230 mismatches; no reconcile diverges | fail as required |

L3 as registered fails and stays recorded. Its render delay (4 ticks, 133 ms) is shorter than
the link's worst latency (150 ms), so the snapshot after the render time often has not arrived;
the expected bracketed share is about 0.8 x P(latency <= 100..133 ms), roughly 0.55 to 0.67,
which matches the 64 % measured. L3b, added after seeing this and labelled post-hoc, uses
`net::render_time`: the 95th percentile of recent arrival offsets plus one tick. The test
prints L3 but gates on L3b.

The L2 control is a client that applies a delta onto its newest snapshot when the named base is
missing (what a naive client does); the real `decode` refuses such deltas instead. The first run
decoded nothing: a full 64-entity snapshot (1247 B) did not fit the 1200 B packet limit and sat
in the queue. The limit is now 1400 B and unreliable messages that can never fit are dropped.

## TLS 1.3 server and QUIC v1

* `crypto.x509` gains a certificate writer: a self-signed ECDSA P-256 certificate for one DNS
  name, and the PKCS#8 form of its private key (the same pair of files rcgen writes).
* `net.tls` gains the TLS 1.3 server side over TCP, and a mode in which the same handshake code
  hands its messages and traffic secrets to QUIC instead of writing TLS records.
* `net.quic` (quic.he): QUIC version 1 (RFC 9000, 9001, 9002), client and server. The
  connection is independent of the socket: datagrams go in and come out through calls, time is
  a parameter, so tests can run it over a simulated link. An endpoint layer drives connections
  over a real UDP socket.

### Pre-registered bars (committed before the first run; never loosened)

* **T1 certificate writer.** A certificate written for the name `amni-lan`: `x509_parse` reads
  it back (P-256 key, the DNS name, validity dates) and it verifies under its own key;
  `openssl x509` parses it and `openssl verify` with the certificate as its own trust anchor
  and `-verify_hostname amni-lan` says OK; `openssl pkey` reads the PKCS#8 key and its public
  key equals the certificate's; a PKCS#8 P-256 key written by `openssl genpkey` loads.
  Control: one flipped signature byte fails both our check and OpenSSL's.
* **T2 ECDSA signing.** The RFC 6979 A.2.5 P-256 / SHA-256 signatures for "sample" and "test"
  come out exact. 100 random messages: each signature verifies with our verifier, and 5 of
  them with `openssl dgst -verify`. Control: a flipped message bit fails verification.
* **T3 TLS 1.3 server over TCP.** Helium client against Helium server on 127.0.0.1, for each
  of the three TLS 1.3 cipher suites with X25519, with P-256, and through a HelloRetryRequest
  to P-384: the handshake completes, the ALPN name is agreed, 1 MiB each way arrives byte
  exact, the close alert is seen. `openssl s_client -tls1_3` with the certificate as trust
  anchor and `-verify_return_error` completes and gets its line echoed. `curl --cacert` gets a
  fixed body over HTTPS. Controls: a client pinned to another certificate refuses; a server
  whose key does not match its certificate is refused by the client; a client Finished with
  one flipped bit is refused by the server.
* **T4 TLS client unchanged.** The Helium client still completes TLS 1.3 and TLS 1.2 against
  `openssl s_server` and reads the page it serves.
* **Q1 RFC 9001 Appendix A.** A.1 keys (client and server key, IV and header key) exact; the
  A.2 client Initial and the A.3 server Initial come out byte exact from their unprotected
  forms and open back to their payloads; the A.5 ChaCha20-Poly1305 short-header packet is
  exact. Control: one flipped bit in the connection ID and the A.2 packet no longer opens.
* **Q2 encoding and junk.** The four RFC 9000 A.1 variable-length integers and every length
  boundary encode and decode exactly; every frame the code sends parses back to the same
  values. 200,000 random and mutated datagrams fed to a listening server and to an open
  connection: no crash, no hang, and a connection either ignores the datagram or closes with
  an error code.
* **Q3 handshake and echo, perfect link.** Client and server joined in memory, each TLS 1.3
  suite: the handshake completes, ALPN `amni-v1` is agreed, the client's pin (SHA-256 of the
  certificate) holds, the client's first datagram is at least 1200 bytes, the server sends at
  most three times what it has received until the client's address is validated, 1 MiB each
  way on one two-way stream arrives byte exact, the end of stream arrives both ways, a close
  code and reason reach the peer, and both ends finish closed. Controls: a wrong pin fails at
  the client with a certificate error; an ALPN the server does not offer fails with QUIC error
  0x178.
* **Q4 hostile link.** The link simulator above (100 ms +- 50 ms, 20 % dropped, 10 %
  duplicated) on simulated time, 200 seeds: the handshake completes and 250 KiB each way
  arrives byte exact within 90 s of simulated time, every seed. Control: loss detection and
  probe timeouts switched off does not complete.
* **Q5 flow control.** A strict receiver checks every stream frame against the limits it has
  advertised, in every test here. With a reader that stops reading, the sender stops exactly
  at the stream limit, and with four streams exactly at the connection limit, then resumes
  when the reader reads. Control: a sender that ignores the limits is closed with
  FLOW_CONTROL_ERROR (0x03).
* **Q7 streams.** 100 two-way and 100 one-way streams opened from each side at once, distinct
  data on each, all byte exact. Opening past the peer's stream limit waits for more credit; a
  peer that exceeds ours is closed with STREAM_LIMIT_ERROR (0x04). A reset stream and a
  stop-sending request reach the other side's reader and writer.
* **Q8 timers and keys.** With a 3 s idle timeout and silence both ends close at 3 s, within
  one probe timeout, without sending. With keep-alive on, the connection is still open after
  30 s. A key update forced from either side: data continues byte exact.
* **Q9 real UDP.** One server endpoint on 127.0.0.1 and 70 clients at once, each echoing
  80 KiB byte exact. A datagram with version 0x1a2a3a4a gets a Version Negotiation packet that
  lists version 1.
* **Q10 other implementations (opt-in step, `HELIUM_QUIC_INTEROP=1`).** `openssl s_client
  -quic -alpn amni-v1`, trusting only our certificate, against the Helium echo server: 80 KiB
  sent comes back byte exact. `curl --http3-only` (ngtcp2) against a Helium server offering
  `h3`: the handshake completes and the server receives curl's control stream (a one-way
  stream whose first byte is 0). Control: a server offering a different ALPN name is refused.
  The same tests against quinn, in both directions, live with the Arena server port.
* **Q11 speed.** On loopback UDP: median handshake of 20 at most 50 ms; 8 MiB one way at
  2 MiB/s or more; 70 clients each exchanging a 1 KiB frame both ways at 30 Hz for 10 s with
  the server using at most half of one core and no frame arriving more than 100 ms late.
* **Q12 nothing else moves.** The `net`, `net_sock` and `he` steps of `tools/hc/ci.sh` pass
  as before.
