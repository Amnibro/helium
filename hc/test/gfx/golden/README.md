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

`spheres_default.png`: the same grid, 480x360 RGBA8, with scene3d's shipped look
(sun shadows: 3 cascades at 2048^2; SSAO, 16 samples; bloom 0.6) instead of the
effects-off look of `spheres.png`. Added 2026-11-01 on auron/gfx-shadowfix because no
GPU check covered the default look (review item G1), and only after the shadow fix
(depth-layer targeting and normal offset, 509c26c and e4adf92) so the golden holds
correct shadows. Rendered at commit 3fcea0b by
`GFX_MAKE_GOLDEN=default tools/hc/gfxtest.sh build/hcn`, same GPU, driver and
settings as above; reviewed by eye before commit (sun-lit spheres, floor shadows
toward the camera-right, no slab-shaped shadows). `spheres.png` was not re-made: its
effects-off render is unchanged (53.53 dB), and with shadows on it scores 30.85 dB, so
re-enabling shadows there would have needed a new golden for no extra coverage.
Rules as for `spheres.png`: > 40 dB, required by `gfxtest.sh`, and the effects-off
image must score at most 40 dB against it (it scores 27.98 dB).
