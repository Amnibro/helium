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
