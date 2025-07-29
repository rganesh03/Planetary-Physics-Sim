#include <SDL2/SDL.h>

#ifndef PLANET_H
#define PLANET_H

#define TRAIL_LENGTH 80

typedef struct 
{
    int id;
    double x, y;
    double vx, vy;
    double mass;

    SDL_Point trail[TRAIL_LENGTH];  //trail position
    int trail_index;                // next position
    int trail_count;                // valid points in the trail
} Planet;


#endif