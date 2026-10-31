package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

const solarMass = 4 * math.Pi * math.Pi
const dpy = 365.24

type Body struct{ x, y, z, vx, vy, vz, mass float64 }

func body(x, y, z, vx, vy, vz, m float64) Body {
	return Body{x, y, z, vx * dpy, vy * dpy, vz * dpy, m * solarMass}
}

func offset(b *[5]Body) {
	var px, py, pz float64
	for i := range b {
		px += b[i].vx * b[i].mass
		py += b[i].vy * b[i].mass
		pz += b[i].vz * b[i].mass
	}
	b[0].vx = -px / solarMass
	b[0].vy = -py / solarMass
	b[0].vz = -pz / solarMass
}
func energy(b *[5]Body) float64 {
	e := 0.0
	for i := 0; i < 5; i++ {
		e += 0.5 * b[i].mass * (b[i].vx*b[i].vx + b[i].vy*b[i].vy + b[i].vz*b[i].vz)
		for j := i + 1; j < 5; j++ {
			dx, dy, dz := b[i].x-b[j].x, b[i].y-b[j].y, b[i].z-b[j].z
			e -= b[i].mass * b[j].mass / math.Sqrt(dx*dx+dy*dy+dz*dz)
		}
	}
	return e
}
func advance(b *[5]Body, dt float64) {
	for i := 0; i < 5; i++ {
		for j := i + 1; j < 5; j++ {
			dx, dy, dz := b[i].x-b[j].x, b[i].y-b[j].y, b[i].z-b[j].z
			d2 := dx*dx + dy*dy + dz*dz
			mag := dt / (d2 * math.Sqrt(d2))
			mi, mj := b[i].mass*mag, b[j].mass*mag
			b[i].vx -= dx * mj
			b[i].vy -= dy * mj
			b[i].vz -= dz * mj
			b[j].vx += dx * mi
			b[j].vy += dy * mi
			b[j].vz += dz * mi
		}
	}
	for i := range b {
		b[i].x += dt * b[i].vx
		b[i].y += dt * b[i].vy
		b[i].z += dt * b[i].vz
	}
}
func main() {
	n := 1000
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}
	b := [5]Body{
		body(0, 0, 0, 0, 0, 0, 1),
		body(4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04),
		body(8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04),
		body(1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05),
		body(1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05),
	}
	offset(&b)
	fmt.Printf("%.9f\n", energy(&b))
	for i := 0; i < n; i++ {
		advance(&b, 0.01)
	}
	fmt.Printf("%.9f\n", energy(&b))
}
