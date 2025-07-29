#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "planet.h"
#include "simulation.h"


#define G 0.1f


void compute_force(const Planet *a, const Planet *b, float *fx, float *fy) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double r_sq = dx * dx + dy * dy + 1e-5; // epsilon to avoid div by zero
    double r = sqrt(r_sq);

    double F = G * a->mass * b->mass / r_sq;

    *fx = F * dx / r;
    *fy = F * dy / r;

    if (isnan(F) || isinf(F)) {
        printf("Force overflow between planet %d and %d\n", a->id, b->id);
        *fx = 0;
        *fy = 0;
        return;
    }
}

void update_planet(Planet *p, float fx, float fy, float dt) {
    p->vx += (fx/p->mass)*dt;
    p->vy += (fy/p->mass)*dt;

    p->x += p->vx*dt;
    p->y += p->vy*dt;
}

void update_planets(Simulation *sim) {

    int n = sim->planet_count;
    float dt = 0.1f;

    // Allocate force arrays
    float *fx = calloc(n, sizeof(float));
    float *fy = calloc(n, sizeof(float));

    // Compute net force on each planet
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            float dx, dy;
            compute_force(&sim->planets[i], &sim->planets[j], &dx, &dy);
            fx[i] += dx;
            fy[i] += dy;
        }
    }

    // Update each planet
    for (int i = 0; i < n; i++) {
        update_planet(&sim->planets[i], fx[i], fy[i], dt);
    }

    free(fx);
    free(fy);
}