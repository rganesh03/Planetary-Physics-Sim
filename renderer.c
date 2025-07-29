#include <SDL2/SDL.h>
#include "Simulation.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PLANET_RADIUS 3

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

int init_renderer() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("Orbital Simulation",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP);
    if (!window) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        return 0;
    }

    return 1;
}

void render_simulation(const Simulation* sim) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black background
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white planets

    for (int i = 0; i < sim->planet_count; i++) {
        Planet* p = &sim->planets[i];

        // Convert simulation coordinates to screen space
        int screen_x = (int)(p->x + WINDOW_WIDTH / 2);
        int screen_y = (int)(p->y + WINDOW_HEIGHT / 2);

        p->trail[p->trail_index] = (SDL_Point){ screen_x, screen_y };
        p->trail_index = (p->trail_index + 1) % TRAIL_LENGTH;

        if(p->trail_count < TRAIL_LENGTH) {
            p->trail_count++;
        }

        SDL_Point ordered_trail[TRAIL_LENGTH];
        for (int j = 0; j < p->trail_count; j++) {
            int idx = (p->trail_index + j) % TRAIL_LENGTH;
            ordered_trail[j] = p->trail[idx];
        }

        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255); // light gray
        SDL_RenderDrawLines(renderer, ordered_trail, p->trail_count);

        SDL_Rect planet_rect = {
            screen_x - PLANET_RADIUS,
            screen_y - PLANET_RADIUS,
            PLANET_RADIUS * 2,
            PLANET_RADIUS * 2
        };

        SDL_RenderFillRect(renderer, &planet_rect);
    }

    SDL_RenderPresent(renderer);
}

void cleanup_renderer() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}