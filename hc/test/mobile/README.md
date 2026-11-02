# mobile: touch, packaging, scalability

Mobile support for any Helium game: multi-touch finger events in `gfx` (SDL3 finger events,
pixels), a gesture recognizer `gfx.touch` (tap, double tap, long press, pan, pinch, rotate,
swipe), a generic Android packager `tools/mobile/android.sh` that turns a Helium program into
an APK (hc C path, SDL3, no per-game Java), and `s3d` scalability presets (low, medium, high,
epic) with render-scale.

## Pre-registered bars (committed before the first run; never loosened)

* **M1 gestures.** 600 synthetic touch traces (100 each of tap, double tap, long press, pan,
  pinch, rotate) with positional jitter up to 2 px per sample and timing jitter up to 8 ms,
  labels written by the generator: at least **99 %** recognized as their label and no trace
  reported as two different gestures; pinch scale within **1 %** of the true ratio, rotation
  within **1 degree**, pan translation within **1 px**. Swipe: 100 fast pans in random
  directions report the right one of four directions every time.
* **M2 Android.** `tools/mobile/android.sh` builds a debug APK from the sample
  `hc/apps/mobile/mobile.amni` (a HUD panel with a button over a small `s3d` scene); on the
  Android emulator (host GPU) it installs and starts; `adb screencap` shows the panel's centre
  pixel equal to its colour within 3/255; `adb shell input tap` on the button makes the app log
  both `finger down` (the gfx finger-event path) and `tapped play` (HUD hit test) within 5 s.
* **M3 scalability.** On the reference scene at 1280x720 (RX 9060 XT), mean frame time over 60
  frames: low <= **40 %** of epic, and low < medium < high <= epic. Every preset's image is
  finite and not blank (standard deviation of luminance > 0.02).

### M1 interpretation (written before the first run)

The recognizer can only see the samples it is given, so "true" pan translation, pinch ratio
and rotation are computed by the test from the generator's first and last emitted (jittered)
samples, not from the noise-free intent. Pans in the 600-trace set ease in and out (slow at
release); swipes are a separate set of fast, accelerating strokes. A trace counts as
recognized when the set of base gestures it produced (TAP, DOUBLE_TAP, LONG_PRESS, PAN, PINCH,
ROTATE, SWIPE; updates and ends fold into their base) is exactly its label.

## Results (2026-11-02)

| Bar | Result |
| --- | --- |
| M1 | **PASS**: 600 / 600 recognized, none doubled; pinch 2.4e-7 relative, rotation 2.7e-5 deg, pan 0 px; swipes 100 / 100 |
| M2 | **PASS**: APK built in 28 s, panel centre 26 140 153 (exact), tap logged `finger down` and `tapped play` |
| M3 | **PASS**: low 0.70, medium 1.03, high 1.49, epic 22.6 ms/frame; low = 3.1 % of epic; all images non-blank |

Honest notes:

* M1's first run failed (546 / 600): a pending single tap fired on the second tap's release frame,
  so double taps came out as two taps. Fixed in the recognizer. The accuracy figures are tiny
  because, per the interpretation above, truth is taken from the same first and last samples
  the recognizer sees; they show the bookkeeping is exact, not that noise is filtered.
* M2's first runs failed on two real problems: Helium's C runtime buffered `print` output
  (64 KB) so nothing reached logcat (now flushed per line on Android), and the emulator recreates
  the activity once right after boot (a system theme overlay change), which SDL answers by
  quitting. The harness now waits 20 s after boot and relaunches up to twice if the process
  ended before `ready`; on the passing run no relaunch was needed. Apps can still be closed by
  that system event on real phones; SDL's activity does not survive recreation.
* M3's epic cost is dominated by GI (probe tracing) plus 4096 shadows; the ordering and the 40 %
  bar would also hold without GI, but that was not measured.
* `android_test.sh` needs the emulator and is run by hand, not by `ci.sh`.

## Using it

`tools/mobile/android.sh game.amni --name "My Game" --id com.example.game [--assets dir]
[--abis arm64-v8a,x86_64] [--release keystore.properties] [--portrait] [--c extra.c]` builds a
debug APK (or a signed release APK and AAB). Assets are copied to the app's files directory on
first launch; read them from `$HELIUM_ASSETS`, write saves under `$HELIUM_DATA`. `print` goes to
logcat (tag `helium`). Touch: `gfx::fingers()`, `EVENT_FINGER_DOWN/MOTION/UP`, and
`touch::frame(t, fingers)` + `touch::take(out)` for gestures. Quality: `scal::init(w, h, level)`.
iOS packaging is not covered yet (Waystone's `ios-helium` scripts are the model).
