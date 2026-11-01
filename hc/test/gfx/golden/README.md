# gfx goldens

`spheres.png`: the 5x5 metal (rows) x roughness (columns) sphere grid of
`gfx_smoke.amni`, 480x360 RGBA8, with multiscatter compensation on. Rendered
2026-11-01 at commit f06aa1b by `GFX_MAKE_GOLDEN=1 tools/hc/gfxtest.sh build/hcn`
on an AMD Radeon RX 9060 XT (RADV GFX1200), Mesa 26.2.4-arch1.1, SDL3 3.4.18,
headless, `MESA_VK_DEVICE_SELECT='1002:7590!'`; reviewed by eye before commit.

`tools/hc/gfxtest.sh` fails when this file is missing, and `gfx_smoke` fails when
the render's PSNR against it is 40 dB or less. Re-make it only for an intended
change to shading, and say why in the commit. Other GPUs and drivers are expected
to stay above 40 dB; that has not been checked yet (see hc/TODO.md, JK-M3).
