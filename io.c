#include <stdio.h>
#include "ops.h"
#include "io.h"

void waitforuser() {
	printf("\nhit enter to continue");
	while (getchar() != '\n');
}

void readmatrix(struct matrix3x3 *m) {
	for (int i = 0; i < 3; i++) {
		printf("Enter col %d (x y z): ", i+1);
		readvector(&m->cols[i]);
	}
}

void readvector(struct vector *v) {
	float x, y, z;
	int c;
	x = y = z = 0;

	printf("Enter your vector: (i, j, k): ");
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
	while ((c = getchar()) != '\n' && c != EOF);
	return n;
}

void printvector(struct vector v) {
	printf("[%.2f]\n[%.2f]\n[%.2f]\n", v.x, v.y, v.z);
}

void printmatrix(struct matrix3x3 m) {
	printf("[%.2f ", m.cols[0].x);
	printf("%.2f ", m.cols[1].x);
	printf("%.2f]\n", m.cols[2].x);
	printf("[%.2f ", m.cols[0].y);
	printf("%.2f ", m.cols[1].y);
	printf("%.2f]\n", m.cols[2].y);
	printf("[%.2f ", m.cols[0].z);
	printf("%.2f ", m.cols[1].z);
	printf("%.2f]\n", m.cols[2].z);
}