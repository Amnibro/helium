# Ogg Vorbis decoder

`hc/lib/codec_vorbis.amni` (built from `codec_vorbis.gold`) decodes Ogg Vorbis files to
interleaved f32 samples in Vorbis channel order, clamped to -1..1:

```
var pcm f32[>..] = [];
let ch, rate, ok = codec_vorbis::decode(bytes[..], pcm);
if !ok { print(codec_vorbis::error()); }
let snd = audio::create_sound(pcm[..], rate, ch);
```

It covers Vorbis I with floor type 1 (floor 0 is refused with a clear error; no encoder has
written it since 2002), residue types 0, 1 and 2, channel coupling, multiple submaps and any
channel count up to 255. The frame count follows the stream's granule positions the way
libvorbisfile does, start and end trimming included. `codec_vorbis::imdct_into(x, out)` exposes
the inverse MDCT (an N/4-point complex FFT).

## Bars (`vorbis_check.amni`, run by ci.sh)

* **V1 matches libvorbisfile.** Eight clips made with ffmpeg's libvorbis encoder (mono 8 kHz,
  stereo 44.1 and 48 kHz at q -1, 3 and 9, 5.1, silence, a 99-frame clip shorter than one block,
  clicks that force short blocks): same channels, rate and frame count as `ov_read_float`, every
  sample within **1e-4** (measured: under 5e-7). References are libvorbisfile's float output,
  clamped, in `fixtures/*.f32`.
* **V2 fast IMDCT.** n = 64, 512, 4096 against the cosine-sum definition, within 1e-5 of the
  largest value.
* **V3 damaged files.** Halved, cut to 40 bytes, first byte changed, middle byte flipped, every
  97th byte flipped, empty: never crashes, and any accepted result has sane channels and samples.
* **V4 speed.** One second of 48 kHz stereo decodes at least **200x** faster than realtime.
