
# 🌌 Newton Fractals Generator (C)

This project implements a visual fractal generator based on the **Newton-Raphson method** applied to complex polynomials. Each point in the complex plane is iterated to determine which root it converges to, creating **attraction basins** colored accordingly.

> **Author**: David Ruiz Cáceres  
> **Course**: Càlcul Numèric  
> **Project**: Pràctica 1  
> **Language**: C

---

## 📌 Description

Given a complex polynomial with **n roots**, the Newton-Raphson iteration is applied on a grid of complex values. Depending on which root a point converges to, a color is assigned, and the output is rendered using **gnuplot** to visualize the **fractal structure**.

---

## 🧩 File Overview

### 🔹 `nwtfr.c`
Contains the numerical routines:
- `avalp`: Evaluates the polynomial `p(z)` at a complex point.
- `avaldp`: Evaluates the derivative `p'(z)` at a complex point.
- `cnvnwt`: Applies Newton’s method and returns the index of the converging root.

### 🔹 `dibfr.c`
Main program that:
- Parses command-line arguments.
- Iterates through a 2D grid of complex values.
- Applies Newton iteration.
- Outputs colored data for each point based on convergence.

### 🔹 `nwtfr.h`
Header file declaring the three main routines.

### 🔹 `Makefile`
Simplifies compilation of the executable `dibfr`.

### 🔹 `Report.pdf`
Project report detailing the mathematical background, code structure, and usage.

---

## ⚙️ Compilation

You can compile manually:
```bash
gcc dibfr.c nwtfr.c -o dibfr -Wall -lm
```

Or using the provided Makefile:
```bash
make dibfr
```

---

## ▶️ Usage

```bash
./dibfr <n> <xmn> <xmx> <nx> <ymn> <ymx> <ny> <tolcnv> <maxit> > fractal.txt
```

- `n`: number of roots  
- `xmn`, `xmx`: x-axis range  
- `ymn`, `ymx`: y-axis range  
- `nx`, `ny`: resolution of the grid  
- `tolcnv`: convergence tolerance  
- `maxit`: max iterations  

Then, provide `n` lines via stdin:
```
<real> <imag> <R> <G> <B>
```
Each line corresponds to the coordinates of a root and its RGB color (0–1 range).

### 🧪 Example

```bash
./dibfr 3 -2 2 640 -2 2 480 1e-3 50 > fractal.txt
```

Followed by:
```
1 0 1 0 0
-0.5 0.8660254 0 1 0
-0.5 -0.8660254 0 0 1
```

---

## 📈 Visualizing with Gnuplot

```bash
gnuplot
gnuplot> unset key
gnuplot> plot 'fractal.txt' with rgbimage
```

This renders the Newton fractal based on convergence basins.

---

## 🧠 Mathematical Background

The Newton method on complex numbers iterates:
```
z_{n+1} = z_n - p(z_n)/p'(z_n)
```

When visualized over a grid, this reveals fractal boundaries between basins of attraction.

---

## 📄 License

This project is released for academic purposes.  
Feel free to adapt and visualize other polynomials.
