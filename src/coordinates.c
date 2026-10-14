/**
 * # C balls. 
 * src/coordinates.c
 */
#include "../include/constants.h"
#include "../include/app.h"
#include "../include/balls.h"
#include "../include/coordinates.h"

float clamp(float x, float min, float max) {
	if (x < min) return min;
	else if (x > max) return max;
	else return x;
}

void ball_clamp_position(struct App *app, struct Ball *ball) {
	ball->position.x = clamp(ball->position.x, 0, app->window_size.x);
	ball->position.y = clamp(ball->position.y, 0, app->window_size.y);

	return;
}
