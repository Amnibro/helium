# physics kit: character mover and ragdoll

Two layers on top of `physics` (the Box3D-style world in `physics.he`).

| Module | Import | What it does |
|---|---|---|
| `mover.amni` | `import physics.mover;` | Capsule character controller: walk, slide along walls, climb steps, refuse steep slopes, jump, land. Uses `collide_mover`, `solve_planes`, `cast_mover` and a sphere-cast ground probe. No body of its own. |
| `ragdoll.amni` | `import physics.ragdoll;` | Turns an `anim` skeleton and model pose into capsule bodies joined by limited spherical joints, hands animation velocity over, reads the bodies back into a `Pose`, and can drive the joints toward a target pose (powered ragdoll). |

Both are written in Gold (`*.gold` next to each `.amni`).

## Mover

```
var m = mover::new(float3 { 0.0, 0.0, 0.0 }, mover::settings());
mover::step(world, m, wish, jump, 1.0 / 60.0);
```

`wish` is the wanted horizontal direction with length 0 to 1, and `m.pos` is the feet point. The capsule floats `step_height` above the feet. A ground probe holds that gap, so a ledge lower than `step_height` is stepped onto and a taller one blocks like a wall. While standing, any surface steeper than `max_slope` is treated as a vertical wall, so it can't be walked up. In the air the real normal is used, so the character slides down it.

## Ragdoll

```
var rd = ragdoll::build(world, sk, model, at, ragdoll::settings(), radii);
ragdoll::start(rd, prev_model, model, at, at, dt);
physics::step(world, dt, 4);
ragdoll::read(rd, sk, at, pose);
ragdoll::drive(rd, sk, target_pose, 7.0);
```

Every joint gets a body. A joint with children gets a capsule toward the mean of its children; a leaf gets a sphere past its end. Each joint has a spherical joint to its parent's body. Joint frames are set so the relative rotation is identity at the skeleton's rest pose, and their Z axis runs along the bone, so the cone limits swing away from the rest direction and the twist limits turn about the bone.

Thin bodies between heavy ones (a neck between chest and head, a hand on a forearm) let joint limits give way on impact, so `build` multiplies every body's inertia by `inertia_scale` (3) and then raises any body lighter or easier to spin than a neighbor to that neighbor's mass and inertia divided by `mass_ratio` (3).

## Bars (set before running, each with a control that must fail)

| Bar | Pass | Control |
|---|---|---|
| C1 flat walk | grounded after 12 steps, feet within 0.01 of the floor, final speed within 2% of `max_speed` | a mover whose filter sees nothing falls below -1 |
| C2 wall | stops within 0.03 of touching the wall, never inside it | a wall the filter skips is walked through |
| C3 slide | along a 45° wall, speed along it at least 0.6 × `max_speed`, never more than 0.01 inside | none (C2's control covers it) |
| C4 step | 0.3 step climbed, feet within 0.01 of its top | 0.5 step blocks |
| C5 slope | 30° ramp walked up, feet within 0.05 of the surface | 60° ramp is not climbed above 0.45; with `max_slope` 1.5 it is |
| C6 jump | apex within 5% of v²/2g, grounded again, back on the floor | none |
| C7 fall | a 37 m drop never ends below the floor and lands grounded | none |
| C8 speed | 77 movers stepping among 100 boxes, under 50 µs per mover step | none |
| R1 build | one body per joint, one joint per non-root joint; at the rest pose every swing and twist is under 1e-4 | none |
| R2 round trip | read straight back from a posed build, local rotations within 1e-3 rad, root within 1e-4 m | the same read compared with the rest pose differs by more than 0.1 rad |
| R3 settle | dropped ragdoll ends above the floor, all speeds under 0.1 m/s, no NaN | none |
| R4 limits | in each of seven falls (upright to upside down), no joint passes its cone or twist limit by more than 0.1 rad | with limits off, every fall has a joint past by more than 0.3 rad |
| R5 hand-over | `start` from two poses moving 3 m/s gives a mean body velocity within 1% of 3 m/s | none |
| R6 powered | with `drive` at 7 Hz the mean pose error after each of the seven falls stays under 0.2 rad | strength 0 gives more than 0.3 rad in every fall |
| R7 speed | 17 ragdolls in one world, average world step under 7 ms | none |

Run with `hc build hc/test/physics/mover_test.amni` and `hc/test/physics/ragdoll_test.amni` (CI step `physkit`).

R4 and R6 started as one fall (tilt 0.5). After the first run they were widened to seven falls, since a single fall hid the worst case (an upright landing folded the neck 0.55 rad past its cone).

## Results (Linux x86-64, `hcn`)

| Bar | Result | Control |
|---|---|---|
| C1 | grounded, max \|y\| 0.000, speed 4.70 | falls to -44.3 |
| C2 | stops at x 2.595 (limit 2.6), never past | walks to 13.7 |
| C3 | 4.75 m/s along the wall, never closer than 0.305 | |
| C4 | climbs to y 0.300 | 0.5 step stops it at x 1.73 |
| C5 | 30° walked to y 3.29 on the surface | 60° peaks at 0.41; with `max_slope` 1.5 reaches 1.66 |
| C6 | apex 1.423 (expected 1.380, +3.1%) | |
| C7 | lowest y 0.000, grounded | |
| C8 | 2.1 µs per mover step | |
| R1 | 17 bodies, 16 joints, swing and twist 0.0 | |
| R2 | 7e-4 rad, root 0.0 | 0.7 rad from the rest pose |
| R3 | all speeds 0.0, all above the floor | |
| R4 | worst 0.071 rad over seven falls | worst-case fall still 1.48 rad |
| R5 | 3.00 m/s | |
| R6 | worst 0.050 rad over seven falls | 0.44 rad |
| R7 | 0.66 ms per step | |

## First-run notes

- C2 sat 0.005 inside the wall: the plane solver allows a little contact slop. The capsule now carries a `skin` of 0.01 so that slop stays outside the real radius.
- C5 crept up a 60° ramp while airborne: the plane solver could hand back an upward move from a steep slope. In the air the solved move may no longer rise more than was asked.
- C7 dipped 0.2 below the floor on landing: the ground snap was rate-limited even when arriving from the air. Landing now takes the full rise at once.
- C4 and C6 first failed on test setup (the step box was too short and the jump fired before the first ground contact); the bars did not change.
- R4 first failed at 0.63, then 0.47 after mass balancing. Two causes: the spherical joint in `physics_engine.he` computed its swing and twist axes once per step, so they went stale across substeps (now refreshed every substep; the other physics tests give identical output); and thin, light bodies with little inertia between heavy ones. Inertia scaling and balancing fixed the second. Joint friction was tried and dropped: it made the ragdoll stiff without fixing the worst fall.
