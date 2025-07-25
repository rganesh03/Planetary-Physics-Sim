#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <SDL2/SDL.h>

#include "renderer.h"
#include "input.h"
#include "physics.h"


int main() {
    Simulation sim = create_simulation_from_input();

    if (!init_renderer()) {
        fprintf(stderr, "Failed to initialize renderer\n");
        return 1;
    }
    
    SDL_Event event;
    int running = 1;

    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) running = 0;
        }

        update_planets(&sim);
        render_simulation(&sim);
        SDL_Delay(16); // ~60 FPS
    }

    cleanup_renderer();
    free(sim.planets);
    return 0;
}