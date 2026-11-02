# nav: navigation mesh

`nav::add` triangles, `nav::build()`, then `nav::path(a, b, out)`. Recast-style: triangles are
voxelized into a heightfield (`cs` cell size, `ch` cell height); a span top is walkable when its
triangle's slope is at most `slope_deg` and it has `height` of clearance; neighbours connect
when their surfaces differ by at most `step`; cells closer than `radius` to a border are eroded
(2-3 chamfer distance). Cells merge into convex rectangles (at most `rect_max` cells a side);
shared edges become portals. Queries run A* over portal midpoints, then the simple stupid funnel
algorithm (Mononen 2010) over the chosen portal chain.

## Pre-registered bars (committed before the first run; never loosened)

Agent radius 0.3, height 1.8, step 0.35, slope 45 deg, cs 0.1, ch 0.05. "Reference" is the
exact shortest path among obstacles inflated into squares by the radius (visibility graph over
the inflated corners, Dijkstra). Clearance is measured from the path to the original boxes.

* **N1 one box.** 20 x 20 m ground, 2 x 2 x 1 m box in the middle, start and goal on opposite
  sides. Bar: path found, length within 3 % of the reference, clearance >= radius - cs.
* **N2 slopes and ledges.** Goal on top of a 1 m platform: no path from the ground. Add a 20 deg
  ramp: path found and it ends within 0.05 m of the platform top. A 60 deg ramp instead: no path.
* **N3 stairs.** Rise 0.2 m per step up to the platform: path found. Rise 0.5 m: no path.
* **N4 two layers.** A 2.5 m high deck over the ground with 20 deg ramps at both ends. A point
  under the deck locates to the ground (|y| < 0.05), a point on it to the deck (|y - 2.5| < 0.05);
  a path under the deck is within 3 % of straight; a path from under to on top is found and ends
  on the deck.
* **N5 random fields.** 20 fields of 1.0 to 1.2 m boxes on a 2.5 m grid (40 % occupancy), 10
  random start/goal pairs each in free space. Bar: every path found; length between 0.97 x and
  1.04 x the reference; clearance >= radius - cs everywhere.
* **Must-fail controls.** The straight segment from start to goal fails N1's clearance; a mesh
  built with radius 0 fails the clearance bar of N1 and N5.

Reported, no bar: build time and mean query time on the largest N5 field.
