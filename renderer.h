#ifndef RENDERER_H
#define RENDERER_H

#include "Simulation.h"

int init_renderer();
void render_simulation(const Simulation* sim);
void cleanup_renderer();

#endif