#include "planet.h"

#ifndef PHYSICS_H
#define PHYSICS_H

void compute_force(const Planet *a, const Planet *b, float *fx, float *fy);

void update_planet(Planet *p, float fx, float fy, float dt);

#endif