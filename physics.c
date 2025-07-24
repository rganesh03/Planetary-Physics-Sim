#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "planet.h"

#define G 0.1f

void compute_force(const Planet *a, const Planet *b, float *fx, float *fy) {
    float dx = b->x - a->x;
    float dy = b->y - a->y;
    float r = sqrtf(dx*dx + dy*dy);
    float F = G * a->mass * b->mass / (r*r);
    *fx = F * dx / r;
    *fy = F * dy / r;
}

void update_planet(Planet *p, float fx, float fy, float dt) {
    p->vx += (fx/p->mass)*dt;
    p->vy += (fy/p->mass)*dt;

    p->x += p->vx*dt;
    p->y += p->vy*dt;
}