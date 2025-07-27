#include <stdio.h>
#include "ops.h"
#include "io.h"
#include "mem.h"
#define MAXENTRIES 128

struct matrix3x3 *matrixhistory[MAXENTRIES];
struct vector *history[MAXENTRIES];
int matrix_histp = 0;
int vector_histp = 0;

struct matrix3x3 *makematrix(struct vector i, struct vector j, struct vector k) {
	struct matrix3x3 *r = (struct matrix3x3 *) alloc(sizeof(struct matrix3x3), ENTRY_MATRIX);
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
	struct vector *r = (struct vector *) alloc(sizeof(struct vector), ENTRY_VECTOR);
        if (r != NULL) {
		r->x = x;
		r->y = y;
		r->z = z;
		history[vector_histp++] = r;
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
/*
void delete_last_vector() {
	if (get_last_type() == ENTRY_VECTOR && vector_histp > 0) {
		rmlast();
		history[--vector_histp] = NULL;
	} else {
		printf("oops: last is not a vector\n");
	}
}

void delete_last_matrix() {
	if (histp
}
*/
void performops(int n) {
	switch(n) {
		case 1: { // vector creation
			struct vector a;
			readvector(&a);
			struct vector *r = makevector(a.x, a.y, a.z);
			printvector(*r);
			break;
		}
		case 3: { // vector addition
			if (vector_histp < 2) {
				printf("oops: you need two vectors\n");
				return;
			}
			struct vector *a = history[vector_histp - 2];
			struct vector *b = history[vector_histp - 1];
			struct vector res = vectoradd(*a, *b);

			struct vector *r = makevector(res.x, res.y, res.z);
			if (r == NULL) {
				printf("oops: no more space\n");
				return;
			}

			printf("Result: (%f, %f, %f)\n", r->x, r->y, r->z);
			break;
		}
		case 4: { // scalar multiplication
			if (vector_histp < 1) {
				printf("oops; please enter something man\n");
				return;
                        }

			int n = recordint();

			struct vector *a = history[vector_histp-1];
			struct vector res = scalarmult(*a, n);

			struct vector *r = makevector(res.x, res.y, res.z);
			if (r == NULL) {
				printf("oops: no more space\n");
				return;
			}

			printf("Result: (%f, %f, %f)\n", r->x, r->y, r->z);
			break;
		}
		case 5: {
			if (vector_histp < 2) {
                                printf("oops: you need two vectors\n");
                                return;
                        }
                        struct vector *a = history[vector_histp - 2];
                        struct vector *b = history[vector_histp - 1];
                        float res = dotproduct(*a, *b);

                        printf("Result: %f\n", res);
                        break;
		}
		case 96: { // delete last vector (result and/or last input)
			if (get_last_type() == ENTRY_VECTOR) {
				rmlast();
				history[--vector_histp] = NULL;
				printf("bye bye: vector\n\n");
			} else {
				printf("oops: not a vector\n\n");
			}
			break;
		}
		case 97: { // delete last matrix (result and/or last input
			if (get_last_type() == ENTRY_MATRIX) {
				rmlast();
				matrixhistory[--matrix_histp] = NULL;
				printf("bye bye: matrix\n\n");
			} else {
				printf("oops: not a matrix\n\n");
			}
			break;
		}
		case 98: { // clear
			if (vector_histp == 0 && matrix_histp == 0) {
				printf("oops: empty already\n\n");
			} else {
				clear();
				for (int i = 0; i < vector_histp; i++) {
					history[i] = NULL;
				}
				for (int i = 0; i < matrix_histp; i++) {
					matrixhistory[i] = NULL;
				}
				vector_histp = 0;
				matrix_histp = 0;
				printf("\ncleared\n\n");
			}
			break;
		}
	}
}

