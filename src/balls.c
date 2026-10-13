/**
 * # C balls : ball structure.
 * src/balls.c
 */
#include <raylib.h>
#include "../include/constants.h"
#include "../include/balls.h"

void ball_apply_velocity(struct Ball *ball) {
	ball->position.x += ball->velocity.x;  
	ball->position.y += ball->velocity.y;  
	return;
}

void ball_draw(struct Ball *ball) {
	DrawCircle(
		ball->position.x,
		ball->position.y,
		ball->radius,
		ball-> color
	);
	return;
}

void ball_collision(struct Ball *ball) {
	if (ball->position.x > screen_width || ball->position.x < 0) {
		ball->velocity.x *= -1;
	}
	if (ball->position.y > screen_height || ball->position.y < 0) {
		ball->velocity.y *= -1;
	}

	return;
}

