#include <stdio.h>
#include "ops.h"
#include "io.h"
#define MAXENTRIES 128

struct matrix3x3 *matrixthistory[MAXENTRIES]
struct vector *history[MAXENTRIES];
int matrix_histp = 0;
int histp = 0;

struct matrix3x3 *makematrix(struct vector i, struct vector j, struct vector k) {
	struct matrix3x3 *r = alloc(sizeof(struct matrix3x3));
	if (r != NULL) {
		r->cols[0] = i;
		r->cols[1] = j;
		r->cols[2] = k;
		matrixhistory[matrix_histp++] = r;
		return r;
	} else {
		printf("oops: max matrices or buffer full\n");
		return NULL;
	}
}

struct vector *makevector(float x, float y, float z) {
	struct vector *r = alloc(sizeof(struct vector));
        if (r != NULL) {
		r->x = x;
		r->y = y;
		r->z = z;
		history[histp++] = r;
		return r;
	} else {
		printf("oops: max vectors or buffer full\n");
		return NULL;
	}
}

struct vector vectoradd(struct vector a, struct vector b) {
        struct vector r;

        r.x = (a.x + b.x);
        r.y = (a.y + b.y);
        r.z = (a.z + b.z);

        return r;
}

struct vector scalarmult(struct vector a, float m) {
        struct vector r;

        r.x = (a.x * m);
        r.y = (a.y * m);
        r.z = (a.z * m);

        return r;
}

double dotproduct(struct vector a, struct vector b) {
        double prod =
                (a.x * b.x) +
                (a.y * b.y) +
                (a.z * b.z);
        return prod;
}

void performops(int n) {
	
}
