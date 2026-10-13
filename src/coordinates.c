/**
 * # C balls. 
 * src/coordinates.c
 */
#include "constants.h"
#include "balls.h"
#include "coordinates.h"

float clamp(float x, float min, float max) {
	if (x < min) return min;
	else if (x > max) return max;
	else return x;
}

void ball_clamp_position(struct Ball *ball) {
	ball->position.x = clamp(ball->position.x, 0, screen_width);
	ball->position.y = clamp(ball->position.y, 0, screen_height);

	return;
}
