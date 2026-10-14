/**
 * # C Balls.
 * src/app.c 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <raylib.h>

#include "../include/app.h"
#include "../include/resource_dir.h"	
#include "../include/constants.h"
#include "../include/balls.h"
#include "../include/coordinates.h"
#include "../include/physics.h"

void window_initialize(struct App *app) {
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(
		app->window_size.x,
		app->window_size.y,
		app->title
	);
	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	return;
}

void app_initialize(struct App *app) {
	app->window_size = (Vector2) {.x=screen_width, .y=screen_height};
	app->gravity_constant = gravity_constant * 0.1;
	app->title = "C balls (raylib).";
	app->background_color = BLACK;

	app->dt = 1.0;	
	app->enable_boundaries = true;
	app->enable_gravity = true;

	app->ball_count = 16;
	app->balls = malloc(app->ball_count * sizeof(struct Ball));
	app->balls[0] = (struct Ball) {
		.radius=10.0,
		.mass=2.0,
		.color=RED,
		.position=(struct Vector2) {app->window_size.x / 2.0, app->window_size.y / 2.0},
		.velocity=(struct Vector2) {2.0, 1.0},
		.acceleration=(struct Vector2) {0.0, 0.0},
	};
	app->balls[1] = (struct Ball) {
		.radius=10.0,
		.mass=2.0,
		.color=GREEN,
		.position=(struct Vector2) {app->window_size.x / 1.5, app->window_size.y / 1.5},
		.velocity=(struct Vector2) {1.0, -3.0},
		.acceleration=(struct Vector2) {0.0, 0.0},
	};
	
	window_initialize(app);
	return;
}

void balls_draw(struct App *app) {
	for (size_t i = 0; i < app->ball_count; i++) {
		ball_draw(&app->balls[i]);	
	}
	return;
}

void balls_update(struct App *app) {
	for (size_t i = 0; i < app->ball_count; i++) {
		if (app->enable_gravity) {
			ball_apply_gravity(app, &app->balls[i]);
		}

		ball_apply_acceleration(app, &app->balls[i]);
		ball_apply_velocity(app, &app->balls[i]);

		if (app->enable_boundaries) {
			ball_boundaries(app, &app->balls[i]);
			ball_clamp_position(app, &app->balls[i]);
		}
	}
	return;
}

void app_update(struct App *app) {	
	balls_update(app);
	return;
}

void app_draw(struct App *app) {
		BeginDrawing();
		ClearBackground(app->background_color);
		
		DrawText(app->title, 0, 0, 20, WHITE);

		balls_draw(app);
		
		EndDrawing();
		return;
}

void app_run(struct App *app) {
	printf(
		"\n## Start `App`.\n"
			"Paramters :\n"
			"- title=%s \n"
			"- enable_boundaries=%s \n"
			"- enable_gravity=%s \n"
			"- gravity_constant=%f \n",
			app->title,
			app->enable_boundaries ? "true" : "false",
			app->enable_gravity ? "true" : "false",
			app->gravity_constant
	);
	
	// Game loop.
  // Runs the loop until the user presses ESCAPE or presses the Close button on the window
	while (!WindowShouldClose()) {
		app_update(app);
		app_draw(app);
	}
	return;
}

void app_free(struct App *app) {
	free(app->balls);
	
	// destroy the window and cleanup the OpenGL context
	CloseWindow();

	return;
}
