#include "planet.h"

#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct {
    Planet* planets;
    int planet_count;
    double gravitational_constant;
    double time_step;
} Simulation;


#endif