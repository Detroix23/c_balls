/**
 * # C balls. 
 * src/coordinates.h
 */
#ifndef CBALLS_COORDINATES_H
#define CBALLS_COORDINATES_H

#include "constants.h"
#include "balls.h"

/** Returns a clamped value `x` between `min` and `max`. */
float clamp(float x, float min, float max);

/** Clamp `ball` in screen. */
void ball_clamp_position(struct Ball *ball);

#endif
