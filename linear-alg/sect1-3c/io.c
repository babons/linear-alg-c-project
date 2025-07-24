#include <stdio.h>
#include "ops.h"
#include "io.h"

void readvector(struct vector *v) {
	float x, y, z;
	int c;
	x = y = z = 0;

	scanf("%f %f %f", &x, &y, &z);
	v->x = x;
	v->y = y;
	v->z = z;

	while ((c = getchar()) != '\n' && c != EOF);
}

void printvector(struct vector v) {
	printf("[%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
}
