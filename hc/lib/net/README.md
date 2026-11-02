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
