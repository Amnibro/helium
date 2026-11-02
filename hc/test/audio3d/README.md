# audio 3D: spatial voices, reverb, limiter, voice stealing

Extensions to `hc/lib/audio.he`: `play3d`, `set_voice3d`, `set_listener`; inverse-distance rolloff
between min and max distance; equal-power panning from the listener-space azimuth; interaural
time difference (Woodworth, head radius 0.0875 m) by reading the far ear earlier in the source;
a head-shadow low-pass on the far ear; Doppler (c = 343 m/s); an occlusion low-pass and gain; a
Freeverb send bus; per-bus volumes; a peak limiter on the master that is exactly transparent
below its threshold; and stealing the least audible voice when every slot is busy.

## Pre-registered bars (committed before the first run; never loosened)

All offline at 48 kHz, mono sources, listener at the origin facing -z.

* **A1 rolloff.** A 440 Hz sine straight ahead at 1, 2, 4, 8 m (min distance 1, rolloff 1): RMS
  ratio to the 1 m RMS within **2 %** of 1/d.
* **A2 equal power.** Azimuths -90 to 90 deg in 15 deg steps at 2 m: L^2 + R^2 within **2 %**
  of its mean (ITD and head shadow off); left of the listener is louder left, right louder right.
* **A3 ITD.** Broadband noise at 90 deg right: the cross-correlation peak of L against R is at
  a lag of round(0.0875 / 343 x (pi/2 + 1) x 48000) = 32 samples **+-1** (L late); straight
  ahead the lag is **0**.
* **A4 Doppler.** A 1000 Hz sine 100 m ahead moving toward the listener at 34.3 m/s: measured
  frequency 1111.1 Hz **+-2**; moving away, 909.1 Hz **+-2**.
* **A5 occlusion.** Occlusion 1: a 4 kHz sine loses **>= 12 dB** more than a 200 Hz sine.
* **A6 reverb.** Unit impulse through the send with wet 0.3: energy 100 to 300 ms after it is
  >= -40 dB of the direct energy; with wet 0 it is < -90 dB. Measured RT60 rises with room size
  (0.5, 0.7, 0.9).
* **A7 limiter.** Eight full-scale 440 Hz voices in phase: no output sample reaches 0.999, and the
  output RMS is within 3 dB of a 0.99 full-scale sine. Control: limiter off (hard clip) has
  > 1000 samples at +-1.
* **A8 stealing.** 80 voices at random volumes into 64 slots: every voice still playing is at
  least as audible as every voice that was refused or stolen.
* **A9 compatibility.** `hc/test/audio_offline.he` output unchanged (hetest).

## Results (2026-11-02, first run)

| check | measured | result |
| --- | --- | --- |
| A1 rolloff | 0.0 % off 1/d | PASS |
| A2 equal power | 0.006 % spread, sides correct | PASS |
| A3 ITD | 32 samples at 90 deg, 0 ahead | PASS |
| A4 Doppler | 1111.111 Hz / 909.091 Hz | PASS |
| A5 occlusion | 4 kHz -29.9 dB vs 200 Hz -8.2 dB (21.8 dB apart) | PASS |
| A6 reverb | tail -17.4 dB, dry tail silent; RT60 0.48 / 0.82 / 2.01 s | PASS |
| A7 limiter | 0 samples >= 0.999, peak 0.983, RMS +0.34 dB; hard clip 44 240 at +-1 | PASS |
| A8 stealing | 64 playing, quietest 0.1961 >= loudest dropped 0.1954 | PASS |
| A9 compatibility | hetest 111 pass (audio_offline unchanged on C, native, debug) | PASS |
