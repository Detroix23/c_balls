/**
 * # C Balls.
 * src/app.c 
 */
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <raylib.h>

#include "../include/app.h"
#include "../include/resource_dir.h"	
#include "../include/constants.h"
#include "../include/balls.h"
#include "../include/coordinates.h"

void balls_draw(size_t ball_count, struct Ball balls[ball_count]) {
	for (size_t i = 0; i < ball_count; i++) {
		ball_draw(&balls[i]);	
	}
	return;
}

void balls_update(size_t ball_count, struct Ball balls[ball_count]) {
	for (size_t i = 0; i < ball_count; i++) {
		ball_apply_velocity(&balls[i]);
		ball_collision(&balls[i]);
		ball_clamp_position(&balls[i]);
	}
	return;
}

void app_initialize(struct App *app) {
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screen_width, screen_height, "Bouncing balls - Raylib.");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	app->background_color = BLACK;

	app->ball_count = 16;
	app->balls = malloc(app->ball_count * sizeof(struct Ball));
	app->balls[0] = (struct Ball) {
		.radius = 10.0,
		.color = RED,
		.position = (struct Vector2) {screen_width / 2.0, screen_height / 2.0},
		.velocity = (struct Vector2) {2.0, 1.0},
		.acceleration = (struct Vector2) {0.0, 0.0},
	};
	app->balls[1] = (struct Ball) {
		.radius = 10.0,
		.color = GREEN,
		.position = (struct Vector2) {screen_width / 1.5, screen_height / 1.5},
		.velocity = (struct Vector2) {1.0, -3.0},
		.acceleration = (struct Vector2) {0.0, 0.0},
	};
	
	return;
}

void app_update(struct App *app) {	
	balls_update(app->ball_count, app->balls);
	
	return;
}

void app_draw(struct App *app) {
		BeginDrawing();
		ClearBackground(app->background_color);
		
		// draw some text using the default font
		DrawText("Hello Raylib", 200,200,20,WHITE);
		// draw our texture to the screen

		balls_draw(app->ball_count, app->balls);
		
		EndDrawing();
		return;
}

void app_run(struct App *app) {
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
