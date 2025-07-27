#include <stdio.h>
#include "ops.h"
#include "io.h"

void readmatrix(struct matrix3x3 *m) {
	for (int i = 0; i < 3; i++) {
		struct vector col;
		printf("Enter col %d (x y z): ", i+1);
		readvector(&m->cols[i]);
	}
}

void readvector(struct vector *v) {
	float x, y, z;
	int c;
	x = y = z = 0;

	printf("Enter your vector: (i, j, k)");
	scanf("%f %f %f", &x, &y, &z);
	v->x = x;
	v->y = y;
	v->z = z;

	while ((c = getchar()) != '\n' && c != EOF);
}

int recordint() {
	int n;
	printf("Please enter an integer: ");
	scanf("%d", &n);
	return n;
}

void printvector(struct vector v) {
	printf("[%.2f, %.2f, %.2f]\n", v.x, v.y, v.z);
}
