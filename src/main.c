/**
 * # C Balls.
 * src/main.c 
 */
#include <stddef.h>
#include <stdint.h>
#include <raylib.h>

#include "../include/app.h"

/** Entry point for the C ball simulation. */
int main(void) {
	struct App app;
	app_initialize(&app);

	app_run(&app);

	app_free(&app);	

	return 0;
}
