/**
 * # C Balls.
 * include/app.h 
 */
#ifndef CBALLS_APP_H
#define CBALLS_APP_H

#include <raylib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "./balls.h"

/**
 * # Main `App` global state.
 */
struct App {
  char *title;
	Color background_color;
  Vector2 window_size;
  double gravity_constant;

  double dt;
  bool enable_boundaries;
  bool enable_gravity;

	size_t ball_count;
	struct Ball *balls;
};

/** Initialize the window and `app`'s fields. */
void app_initialize(struct App *app);

/** Updates all `balls`. */
void balls_update(struct App *app);

/** Updates all app fields and components. */
void app_update(struct App *app);	

/** Draws all `balls`. */
void balls_draw(struct App *app);

/** Draws all components. */
void app_draw(struct App *app);

/**
 * Start the simulation loop, calling `app_update` and `app_draw`?
 */
void app_run(struct App *app);

/**
 * Free the heap stored field of `app`.
 * Do not destroy `app` itself.
 */
void app_free(struct App *app);

#endif
