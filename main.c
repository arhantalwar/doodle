#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include <math.h>

#define WIDTH	1920
#define HEIGHT	1080
#define OFFSET	(Vector2) { .x = WIDTH/2, .y = HEIGHT/2 }
#define TRAIL	2000

int main(int argc, char** argv) {

	SetTraceLogLevel(LOG_NONE);
	
	InitWindow(WIDTH, HEIGHT, "DOODLE");
	SetTargetFPS(60);

	float i = 0;

	float theta = 0.0f;
	float radius = 100;
	Vector2 arr[TRAIL];

	float theta2 = 0.0f;
	float radius2 = 100;
	Vector2 arr2[TRAIL];

	float theta3 = 0.0f;
	float radius3 = 100;
	Vector2 arr3[TRAIL];
		
	int trail_count = 0;

	while (!WindowShouldClose()) {
	    
		BeginDrawing();
		ClearBackground(BLACK);

		// DRAWING SPEED
		i += 0.05;

		// MODIFY HERE
		theta = radius * (sinf(i/2) + cosf(i/4));
		radius = 100 * sinf(i/4);
		
		Vector2 point1 = {.x=radius*cosf(theta*DEG2RAD),.y=radius*sinf(theta*DEG2RAD)};
		arr[trail_count] = (Vector2) { .x = point1.x + OFFSET.x, .y = point1.y + OFFSET.y };

		DrawLineStrip(arr, trail_count, BLUE);

		// MODIFY HERE
		theta2 = (radius2) * powf(sinf(1/(i * 2)), 2);
		radius2 = 200 * sinf(i/4);

		Vector2 point2 = {.x=radius2*cosf(theta2*DEG2RAD),.y=radius2*sinf(theta2*DEG2RAD)};
		/* point2 = Vector2Add(point2, point1); */
		arr2[trail_count] = (Vector2) { .x = point2.x + OFFSET.x, .y = point2.y + OFFSET.y };
		
		DrawLineStrip(arr2, trail_count, RED);

		// MODIFY HERE
		theta3 = (radius3) * exp2f(-0.342 * i);
		radius3 = 50 * sinf(i/4);

		Vector2 point3 = {.x=radius3*cosf(theta3*DEG2RAD),.y=radius3*sinf(theta3*DEG2RAD)};
		/* point3 = Vector2Add(point3, point2); */
		arr3[trail_count] = (Vector2) { .x = point3.x + OFFSET.x, .y = point3.y + OFFSET.y };
		
		DrawLineStrip(arr3, trail_count, RAYWHITE);

		if (trail_count > 4) {
			DrawLineEx(arr[trail_count],  arr [trail_count-4], 10, BLUE);
			DrawLineEx(arr2[trail_count], arr2[trail_count-4], 10, RED);
			DrawLineEx(arr3[trail_count], arr3[trail_count-4], 10, RAYWHITE);
		}

		trail_count < TRAIL ? trail_count++ : (trail_count = 0);
		
		// LAYOUT
		
		/* DrawCircleLines(point1.x + OFFSET.x, point1.y + OFFSET.y, radius, BLUE); */
		/* DrawCircleLines(point2.x + OFFSET.x, point2.y + OFFSET.y, radius2, RED); */
		/* DrawCircleLines(point3.x + OFFSET.x, point3.y + OFFSET.y, radius3, PURPLE); */

		/* DrawLineV((Vector2) {.x=0,.y = HEIGHT/2}, (Vector2) {.x=WIDTH,.y=HEIGHT/2}, BLUE); */
		/* DrawLineV((Vector2) {.x=WIDTH/2,.y = 0}, (Vector2) {.x=WIDTH/2,.y=HEIGHT}, BLUE); */

		EndDrawing();

	}

	return 0x00;

}
