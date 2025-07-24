#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <SDL2/SDL.h>
#include "planet.h"
#include "physics.h"

#define GRID_WIDTH 80
#define GRID_HEIGHT 24
#define DT 0.01f
#define NUM_PLANETS 2


Planet planets[NUM_PLANETS] = {
    {.x = 40.0f, .y = 15.0f, .vx = -1.5f, .vy = -1.5f, .mass = 5000.0f }, //Central planet
    {.x = 30.0f, .y = 15.0f, .vx = 1.5f, .vy = 1.5f, .mass = 500.0f } //Orbiting planet
};


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Gravity Sim",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    SDL_Event event;

    while (running) {
        // Handle quit event
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
        }

        // Reset forces
        float fx[NUM_PLANETS] = {0};
        float fy[NUM_PLANETS] = {0};

        for (int i = 0; i < NUM_PLANETS; ++i) {
            for (int j = 0; j < NUM_PLANETS; ++j) {
                if (i == j) continue;
                float fx_ij = 0, fy_ij = 0;
                compute_force(&planets[i], &planets[j], &fx_ij, &fy_ij);
                fx[i] += fx_ij;
                fy[i] += fy_ij;
            }
        }

        for (int i = 0; i < NUM_PLANETS; ++i) {
            update_planet(&planets[i], fx[i], fy[i], DT);
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw planets
        for (int i = 0; i < NUM_PLANETS; ++i) {
            int x = (int)(planets[i].x * 10); // scale up for visibility
            int y = (int)(planets[i].y * 25); // scale up for visibility

            SDL_SetRenderDrawColor(renderer, (i == 0) ? 255 : 0, 255, 255, 255);
            SDL_Rect rect = { x, y, 6, 6 };
            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}