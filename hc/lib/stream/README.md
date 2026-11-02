# stream: world-partition streaming

The world is a grid of cells, each with an asset file. `stream::update(x, z)` each frame
requests the cells within `load_r` of the viewer, nearest first, from loader threads; drops
cells beyond `unload_r` (> `load_r`, hysteresis); evicts the farthest cells outside `inner_r`
when resident bytes pass `budget`; and copies finished bytes in, at most `frame_bytes` per frame.
Loader threads read files and send the bytes back in 8 KB chunks (threads share nothing).
Requests carry a generation so bytes for a cell dropped mid-load are discarded.

## Pre-registered bars (committed before the first run; never loosened)

24 x 24 cells of 25 m, each with a file of 8 to 64 KB of random bytes. load_r 100 m, unload_r
125 m, inner_r 50 m, budget 2 MB, 2 loader threads. 60 frames per second in real time.

* **S1 coverage.** The viewer flies a figure-eight at 30 m/s for 10 s. After 1 s of warm-up, in
  every frame every cell within inner_r is loaded.
* **S2 main-thread cost.** `update` p99 <= 1.0 ms and max <= 4 ms over the flight.
* **S3 memory.** Resident bytes <= 2 MB in every frame.
* **S4 contents.** Every cell loaded during the flight matches its file byte for byte.
* **S5 hysteresis.** The viewer oscillates +-10 m (period 1 s) across a load-radius boundary
  for 5 s after settling: no cell is loaded more than once.
* **Must-fail controls.** Loading synchronously on the main thread fails S2. unload_r = load_r
  fails S5.

## Results (2026-11-02)

| check | measured | result |
| --- | --- | --- |
| S1 coverage | 0 misses over 540 frames | PASS |
| S2 main-thread cost | p99 0.25 ms, max 0.52 ms | PASS |
| S3 memory | peak 2 097 102 B (budget 2 097 152) | PASS |
| S4 contents | 111 loads, 0 byte errors | PASS |
| S5 hysteresis, 2 MB budget | 0 reloads, control also 0 | vacuous |
| S5b hysteresis, 4 MB budget (post-hoc) | 1 load; control without hysteresis 5 | PASS |
| S2 control on tmpfs | sync p99 0.09 ms, max 0.71 ms | **does not fail** |
| S2 control, 4 ms storage latency (post-hoc) | sync p99 8.2 ms, max 204 ms; threaded p99 0.16 ms | fails as required |

Two of the registered controls could not discriminate in this setup, and that stays recorded:

* The test files sit on tmpfs, so synchronous reads take microseconds and the sync control
  passes S2. With `io_delay_ms = 4` (emulated per-file storage latency, added post-hoc) the
  threaded loader still passes S2 and the synchronous one fails it badly.
* At the registered 2 MB budget the cells near the load radius never load (the budget is full of
  nearer cells), so the oscillation loads nothing with or without hysteresis. S5b, post-hoc,
  repeats it with a 4 MB budget.

First-run fixes: S1 missed 7 inner cells because far cells held the budget and blocked nearer
loads; a nearer request now evicts a loaded cell more than one cell farther away. The first S4
count was a test bug (`read_file` appends; the buffer was not cleared).
