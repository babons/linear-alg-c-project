#include <stdio.h>
#include "ops.h"
#include "io.h"

void waitforuser() {
	printf("\nhit enter to continue");
	while (getchar() != '\n');
}

void readmatrix(struct matrix *m) {
	for (int i = 0; i < 3; i++) {
		printf("Enter col %d (x y z): ", i+1);
		readvector(&m->cols[i]);
	}
}

void readmatrix2x2(struct matrix2x2 *m) {
	for (int i = 0; i < 2; i++) {
		printf("Enter col %d (x y): ", i+1);
		readvector2x2(&m->cols[i]);
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

void readvector2x2(struct vector2x2 *v) {
	float x, y;
	int c;
	x = y = 0;

	printf("Enter your vector: (i, j): ");
	scanf("%f %f", &x, &y);
	v->x = x;
	v->y = y;

	while ((c = getchar()) != '\n' && c != EOF);
}

int recordint() {
	int n;
	char c;
	printf("Please enter an integer: ");
	scanf("%d", &n);
	while ((c = getchar()) != '\n' && c != EOF);
	return n;
}

void printvector(struct vector v) {
	printf("[%.2f]\n[%.2f]\n[%.2f]\n", v.x, v.y, v.z);
}

void printmatrix(struct matrix m) {
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

void printoptions() {
		printf("\n1. Create vectors\n");
		printf("2. Create matrices\n");
		printf("3. Add vectors\n");
		printf("4. Multiply vector (scalar)\n");
		printf("5. Multiply matrix (scalar)\n");
		printf("6. Calculate dot product\n");
		printf("7. Matrix vector multiplication\n");
		printf("8. Matrix matrix multiplication\n");
		printf("9. Cross product calculation\n");
		printf("10. Determinant calculation\n");
		printf("11. Calculate the cofactor matrix\n");
		printf("12. Transpose matrix\n");
		printf("13. Inverse matrix calculation\n");
		printf("14. Eigenvalue calculation (2x2)\n");
		printf("94. Print vector history\n");
		printf("95. Print matrix history\n");
		printf("96. Delete last vector\n");
		printf("97. Delete last matrix\n");
		printf("98. Clear\n");
		printf("99. Exit\n\n");
}