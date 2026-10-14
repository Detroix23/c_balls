/**
 * # C balls : ball structure.
 * src/balls.c
 */
#include <raylib.h>
#include "../include/balls.h"

void ball_draw(struct Ball *ball) {
	DrawCircle(
		ball->position.x,
		ball->position.y,
		ball->radius,
		ball-> color
	);
	return;
}
