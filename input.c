#include <stdio.h>
#include <stdlib.h>
#include "planet.h"
#include "simulation.h"

Simulation create_simulation_from_input() {

    int choice;
    printf("Do you want to use the default simulation? (0 for no, 1 for yes): ");
    scanf("%d", &choice);

    Planet *planets;
    int count;


    if(choice) {
        // Default 3-body setup
        count = 3;
        planets = malloc(sizeof(Planet) * count);

        planets[0] = (Planet){ .id = 0, .mass = 10000, .x = 0, .y = 0, .vx = 0, .vy = 0, .trail_count = 0, .trail_index = 0};
        planets[1] = (Planet){ .id = 1, .mass = 0.3, .x = 100, .y = 0, .vx = 0, .vy = 2, .trail_count = 0, .trail_index = 0 };
        planets[2] = (Planet){ .id = 2, .mass = 0.0004, .x = 105, .y = 0, .vx = 0, .vy = 2.5, .trail_count = 0, .trail_index = 0 };

    } else {
        printf("Enter number of planets: ");
        scanf("%d", &count);

        planets = malloc(sizeof(Planet)*count);

        for(int i = 0; i < count; i++) {
            printf("Planet %d:\n", i);
            planets[i].id = i;

            printf("  Mass: ");
            scanf("%lf", &planets[i].mass);

            printf("  Position X: ");
            scanf("%lf", &planets[i].x);
            printf("  Position Y: ");
            scanf("%lf", &planets[i].y);

            printf("  Velocity X: ");
            scanf("%lf", &planets[i].vx);
            printf("  Velocity Y: ");
            scanf("%lf", &planets[i].vy);

            planets[i].trail_count = 0;
            planets[i].trail_index = 0;
        }
    }

        Simulation sim = {
        .planets = planets,
        .planet_count = count,
        .gravitational_constant = 0.1f, // default
        .time_step = 3600.0f             // default
    };

    return sim;

}