/**
 * # C Balls.
 * src/physics.c
 */
#include "../include/physics.h"
#include "../include/app.h"
#include "../include/balls.h"

void ball_apply_gravity(struct App *app, struct Ball *ball) {
  ball->acceleration.y += app->gravity_constant;
  
  return;
}

void ball_apply_velocity(struct App *app, struct Ball *ball) {
	ball->position.x += (ball->velocity.x * app->dt) + (0.5 * ball->acceleration.x * app->dt * app->dt);  
	ball->position.y += (ball->velocity.y * app->dt) + (0.5 * ball->acceleration.y * app->dt * app->dt);  

	return;
}

void ball_apply_acceleration(struct App *app, struct Ball *ball) {
	ball->velocity.x += ball->acceleration.x * app->dt;
	ball->velocity.y += ball->acceleration.y * app->dt;

	ball->acceleration.x = 0.0;
	ball->acceleration.y = 0.0;

	return;
}

void ball_boundaries(struct App *app, struct Ball *ball) {
	if (ball->position.x > app->window_size.x || ball->position.x < 0.0) {
		ball->velocity.x *= -1;
	}
	if (ball->position.y > app->window_size.y || ball->position.y < 0.0) {
		ball->velocity.y *= -1;
	}

	return;
}

