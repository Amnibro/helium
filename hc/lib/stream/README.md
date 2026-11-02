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
