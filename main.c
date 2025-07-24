#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "planet.h"
#include "physics.h"

#define GRID_WIDTH 80
#define GRID_HEIGHT 24
#define DT 0.01f
#define NUM_PLANETS 2


Planet planets[NUM_PLANETS] = {
    {.x = 40.0f, .y = 15.0f, .vx = 0.0f, .vy = 0.0f, .mass = 5000.0f }, //Central planet
    {.x = 20.0f, .y = 15.0f, .vx = 0.0f, .vy = 1.5f, .mass = 50.0f } //Orbiting planet
};


int main() {
    while (1) {
        system("cls"); //clear screen

        //reset forces
        float fx[NUM_PLANETS] = {0};
        float fy[NUM_PLANETS] = {0};

        //COmpute forces
        for(int i = 0; i < NUM_PLANETS; ++i) {
            for(int j = 0; j < NUM_PLANETS; ++j) {
                if(i == j) continue;

                float fx_ij = 0, fy_ij = 0;
                compute_force(&planets[i], &planets[j], &fx_ij, &fy_ij);
                fx[i] += fx_ij;
                fy[i] += fy_ij;
            }
        }
        
        //update positions
        for(int i = 0; i < NUM_PLANETS; ++i) {
            update_planet(&planets[i], fx[i], fy[i], DT);
        }

        //Render planets on grid
        char grid[GRID_HEIGHT][GRID_WIDTH];
        memset(grid, ' ', sizeof(grid));

        for(int i = 0; i < NUM_PLANETS; ++i) {
            int x = (int) (planets[i].x);
            int y = (int) (planets[i].y);

            if(x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
                grid[y][x] = (i == 0) ? 'O' : '*';
            }
        }

        //Print grid
        for(int y = 0; y < GRID_HEIGHT; ++y) {
            for(int x = 0; x < GRID_WIDTH; ++x) {
                putchar(grid[y][x]);
            }
            putchar('\n');
        }
    }

    Sleep(50);
    
}
