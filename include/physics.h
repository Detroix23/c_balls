/**
 * # C Balls.
 * include/physics.h
 */
#include "./balls.h"
#include "./app.h"

/** Apply gravity to the velocity vector. */
void ball_apply_gravity(struct App *app, struct Ball *ball);

/** Move the `ball` using the `velocity` field. */
void ball_apply_velocity(struct App *app, struct Ball *ball);

/** Apply acceleration to velocity and nullify the acceleration vector. */
void ball_apply_acceleration(struct App *app, struct Ball *ball);

/** Check and apply collision. */
void ball_boundaries(struct App *app, struct Ball *ball);
