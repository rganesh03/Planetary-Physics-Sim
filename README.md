Absolutely, Rishi — here’s a polished, recruiter-friendly `README.md` tailored to your orbital simulation project. It highlights your technical rigor, creative polish, and thoughtful architecture.

---

## Orbital Simulation — Real-Time Gravity Visualizer

A lightweight, real-time simulation of gravitational interactions between celestial bodies using Newtonian physics and SDL2 for rendering. Designed for experimentation, visualization, and educational insight into orbital mechanics.

---

### Features

- **N-body simulation** with customizable planet count, mass, position, and velocity  
-  **Trail rendering** for visualizing orbital paths (fixed-length circular buffer)  
-  **Physics engine** using Newton’s law of universal gravitation  
-  **SDL2-based renderer** with smooth motion and real-time updates  
-  **Overflow protection** and epsilon-based distance handling to prevent instability  

---

###  Build Instructions

#### Prerequisites:
- SDL2 development libraries installed
- GCC or Clang (MinGW recommended on Windows)

#### Compile:
```bash
gcc -o orbital_sim main.c renderer.c input.c simulation.c physics.c -lSDL2 -lm
```

#### Run:
```bash
./orbit_sim.exe
```

---

### Controls

- On launch: choose between default 3-body system or custom input
- Input mode: enter mass, position, and velocity for each planet
- Simulation auto-runs with real-time rendering

---

### Default Setup

```c
planets[0] = { mass = 10000, x = 0, y = 0, vx = 0, vy = 0 };      // Central body  
planets[1] = { mass = 0.3,   x = 100, y = 0, vx = 0, vy = 2 };    // Earth-like  
planets[2] = { mass = 0.0004,x = 105, y = 0, vx = 0, vy = 2.5 };  // Moon-like  
```

---

### 🧠 Architecture Overview

| Module       | Responsibility                          |
|--------------|------------------------------------------|
| `planet.h`   | Defines `Planet` struct and trail buffer |
| `input.c`    | Handles user input and planet creation   |
| `physics.c`  | Computes gravitational forces and updates|
| `simulation.c` | Manages simulation loop and state      |
| `renderer.c` | Renders planets and trails using SDL2    |

---

### Future Enhancements

-  Lagrange point visualizations  
-  Real-time energy and momentum tracking   
-  Unit tests for physics validation

---

### 👨‍💻 Author

**Rishi** — Computer Science @ VCU 2026  
Passionate aboutaerospace, machine learning, and embedded systems.  

