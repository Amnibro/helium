// nbody: 5 bodies, symplectic Euler, dt 0.01. Prints energy before and after.
package main

import ("fmt"; "math"; "os"; "strconv")

func argN(d int64) int64 {
	if len(os.Args) > 1 {
		if v, err := strconv.ParseInt(os.Args[1], 10, 64); err == nil {
			return v
		}
	}
	return d
}

const NB = 5

var X, Y, Z, VX, VY, VZ, M [NB]float64

func initSys() {
	pi := 3.141592653589793; dpy := 365.24; s := 4 * pi * pi
	d := [NB][7]float64{
		{0, 0, 0, 0, 0, 0, 1},
		{4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04},
		{8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04},
		{1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05},
		{1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05}}
	for i := 0; i < NB; i++ {
		X[i], Y[i], Z[i] = d[i][0], d[i][1], d[i][2]
		VX[i], VY[i], VZ[i], M[i] = d[i][3]*dpy, d[i][4]*dpy, d[i][5]*dpy, d[i][6]*s
	}
	px, py, pz := 0.0, 0.0, 0.0
	for i := 0; i < NB; i++ { px += VX[i] * M[i]; py += VY[i] * M[i]; pz += VZ[i] * M[i] }
	VX[0], VY[0], VZ[0] = -px/s, -py/s, -pz/s
}

func energy() float64 {
	e := 0.0
	for i := 0; i < NB; i++ {
		e += 0.5 * M[i] * (VX[i]*VX[i] + VY[i]*VY[i] + VZ[i]*VZ[i])
		for j := i + 1; j < NB; j++ {
			dx, dy, dz := X[i]-X[j], Y[i]-Y[j], Z[i]-Z[j]
			e -= M[i] * M[j] / math.Sqrt(dx*dx+dy*dy+dz*dz)
		}
	}
	return e
}

func advance(dt float64) {
	for i := 0; i < NB; i++ {
		for j := i + 1; j < NB; j++ {
			dx, dy, dz := X[i]-X[j], Y[i]-Y[j], Z[i]-Z[j]
			d2 := dx*dx + dy*dy + dz*dz
			mag := dt / (d2 * math.Sqrt(d2))
			mj, mi := M[j]*mag, M[i]*mag
			VX[i] -= dx * mj; VY[i] -= dy * mj; VZ[i] -= dz * mj
			VX[j] += dx * mi; VY[j] += dy * mi; VZ[j] += dz * mi
		}
	}
	for i := 0; i < NB; i++ { X[i] += dt * VX[i]; Y[i] += dt * VY[i]; Z[i] += dt * VZ[i] }
}

func main() {
	n := argN(1000)
	initSys()
	fmt.Printf("%.9f\n", energy())
	for k := int64(0); k < n; k++ { advance(0.01) }
	fmt.Printf("%.9f\n", energy())
}
