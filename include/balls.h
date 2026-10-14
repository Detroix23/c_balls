/**
 * # C balls : ball structure.
 * src/balls.h
 */
#ifndef CBALLS_BALLS_H
#define CBALLS_BALLS_H

#include <raylib.h>

/** # `Ball` entity. */
struct Ball {
	double radius;
	double mass;
	Color color;
	struct Vector2 position;
	struct Vector2 velocity;
	struct Vector2 acceleration; 
};

/** Draw `ball` to the screen. */
void ball_draw(struct Ball *ball);

#endif
