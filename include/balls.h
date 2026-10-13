/**
 * # C balls : ball structure.
 * src/balls.h
 */
#ifndef CBALLS_BALLS_H
#define CBALLS_BALLS_H

#include <raylib.h>

/** # `Ball` entity. */
struct Ball {
	float radius;
	Color color;
	struct Vector2 position;
	struct Vector2 velocity;
	struct Vector2 acceleration; 
};

/** Move the `ball` using the `velocity` field. */
void ball_apply_velocity(struct Ball *ball);

/** Draw `ball` to the screen. */
void ball_draw(struct Ball *ball);

/** Check and apply collision. */
void ball_collision(struct Ball *ball);

#endif
