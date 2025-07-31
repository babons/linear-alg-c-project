#include <stdio.h>
#include "ops.h"
#include "io.h"
#include "mem.h"
#define MAXENTRIES 128

struct matrix *matrixhistory[MAXENTRIES];
struct vector *history[MAXENTRIES];
int matrix_histp = 0;
int vector_histp = 0;

struct matrix *makematrix(struct vector i, struct vector j, struct vector k) {
	struct matrix *r = (struct matrix *) alloc(sizeof(struct matrix), ENTRY_MATRIX);
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

struct vector vscalarmult(struct vector a, float m) {
	struct vector r;

	r.x = (a.x * m);
	r.y = (a.y * m);
	r.z = (a.z * m);

	return r;
}

struct matrix mscalarmult(struct matrix a, float m) {
	struct matrix r;

	r.cols[0] = vscalarmult(a.cols[0], m);
	r.cols[1] = vscalarmult(a.cols[1], m);
	r.cols[2] = vscalarmult(a.cols[2], m);

	return r;
}

struct vector matvecmult(struct matrix m, struct vector s) {
	struct vector r;
	r.x = m.cols[0].x * s.x + m.cols[1].x * s.y + m.cols[2].x * s.z;
	r.y = m.cols[0].y * s.x + m.cols[1].y * s.y + m.cols[2].y * s.z;
	r.z = m.cols[0].z * s.x + m.cols[1].z * s.y + m.cols[2].z * s.z;

	return r;
}

struct matrix matrixmult(struct matrix a, struct matrix b) {
	struct matrix r;
	struct vector row0 = {a.cols[0].x, a.cols[1].x, a.cols[2].x};
	struct vector row1 = {a.cols[0].y, a.cols[1].y, a.cols[2].y};
	struct vector row2 = {a.cols[0].z, a.cols[1].z, a.cols[2].z};

	r.cols[0].x = dotproduct(row0, b.cols[0]);
	r.cols[1].x = dotproduct(row0, b.cols[1]);
	r.cols[2].x = dotproduct(row0, b.cols[2]);
	r.cols[0].y = dotproduct(row1, b.cols[0]);
	r.cols[1].y = dotproduct(row1, b.cols[1]);
	r.cols[2].y = dotproduct(row1, b.cols[2]);
	r.cols[0].z = dotproduct(row2, b.cols[0]);
	r.cols[1].z = dotproduct(row2, b.cols[1]);
	r.cols[2].z = dotproduct(row2, b.cols[2]);

	return r;
}

double dotproduct(struct vector a, struct vector b) {
	double prod =
			(a.x * b.x) +
			(a.y * b.y) +
			(a.z * b.z);
	return prod;
}

struct vector crossproduct(struct vector a, struct vector b) {
	struct vector r;
	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return r;
}

double calcmdeterminant(struct matrix m) {
	double r = dotproduct(m.cols[0], crossproduct(m.cols[1], m.cols[2]));
	return r;
}

void getotherelement(int i, int *one, int *two) {
	if (i == 0) {
		*one = 1;
		*two = 2;
	} else if (i == 1) {
		*one = 0;
		*two = 2;
	} else if (i == 2) {
		*one = 0;
		*two = 1;
	} else {
		return;
	}
}

float getelement(struct matrix m, int i, int j) {
	switch (i) {
		case 0: return m.cols[j].x; break;
		case 1: return m.cols[j].y; break;
		case 2: return m.cols[j].z; break;
	}
}

double calccofactor(struct matrix m, int i, int j) {
	float a, b, c, d; // elements outside of the selected row/col
	int row1, row2, col1, col2;
	getotherelement(j, &col1, &col2);
	getotherelement(i, &row1, &row2);
	a = getelement(m, row1, col1);
	b = getelement(m, row1, col2);
	c = getelement(m, row2, col1);
	d = getelement(m, row2, col2);

	return a*d - b*c;
}

struct matrix cofactormatrix(struct matrix m) {
	struct matrix cof;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float sign = (i + j) % 2 == 0 ? 1.0 : -1.0;
			float cofactor = sign * calccofactor(m, i, j);
			switch (i) {
				case 0: cof.cols[j].x = cofactor; break;
				case 1: cof.cols[j].y = cofactor; break;
				case 2: cof.cols[j].z = cofactor; break;
			}
		}
	}

	return cof;
}

struct matrix inversematrix(struct matrix m) {

}

void viewvectors() {
	if (vector_histp < 1) {
		printf("\noops: you need to have at least one vector!\n\n");
		return;
	}
	printf("\nYou have %d vectors: \n", vector_histp);
	for (int i = 0; i < vector_histp; i++) {
		printf("%d.\n", i);
		printvector(*history[i]);
	}
	printf("\n");
}

void viewmatrices() {
	if (matrix_histp < 1) {
		printf("\noops: missing matrices!!!\n\n");
		return;
	}
	printf("\nYou have %d matrices: \n", matrix_histp);
	for (int i = 0; i < matrix_histp; i++) {
		printf("%d.\n", i);
		printmatrix(*matrixhistory[i]);
	}
	printf("\n");
}

void performops(int n) {
	switch(n) {
		case 1: { // vector creation
			struct vector a;
			readvector(&a);
			struct vector *r = makevector(a.x, a.y, a.z);
			printvector(*r);
			waitforuser();
			break;
		}
		case 2: { // matrix creation 
			struct matrix m;
			readmatrix(&m);
			struct matrix *r = makematrix(m.cols[0], m.cols[1], m.cols[2]);
			printmatrix(*r);
			waitforuser();
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
			waitforuser();
			break;
		}
		case 4: { // vector scalar multiplication
			if (vector_histp < 1) {
				printf("oops; please enter something man\n");
				return;
            }

			int n = recordint();

			struct vector *a = history[vector_histp-1];
			struct vector res = vscalarmult(*a, n);

			struct vector *r = makevector(res.x, res.y, res.z);
			if (r == NULL) {
				printf("oops: no more space\n");
				return;
			}

			printvector(*r);
			waitforuser();
			break;
		}
		case 5: { // matrix scalar mult
			if (matrix_histp < 1) {
				printf("oops; please enter something man\n");
				return;
            }

			int n = recordint();

			struct matrix *a = matrixhistory[matrix_histp-1];
			struct matrix res = mscalarmult(*a, n);

			struct matrix *r = makematrix(res.cols[0], res.cols[1], res.cols[2]);
			if (r == NULL) {
				printf("oops: no more space\n");
				return;
			}

			printmatrix(*r);
			waitforuser();
			break;
		}
		case 6: { // calc dot product
			if (vector_histp < 2) {
                                printf("oops: you need two vectors\n");
                                return;
                        }
			struct vector *a = history[vector_histp - 2];
			struct vector *b = history[vector_histp - 1];
			float res = dotproduct(*a, *b);

			printf("Result: %f\n", res);
			waitforuser();
			break;
		}
		case 7: { // matrix vector mult
			if (vector_histp < 1 || matrix_histp < 1) {
				printf("oops: you are missing something\n");
				return;
			}
			struct matrix *m = matrixhistory[matrix_histp - 1];
			struct vector *v = history[vector_histp - 1];
			struct vector r = matvecmult(*m, *v);

			struct vector *res = makevector(r.x, r.y, r.z);
			printf("Result:\n"); printvector(r);
			waitforuser();
			break;
		}
		case 8: { // matrix matrix mult
			if (matrix_histp < 2) {
				printf("oops: you only have %d matrices\n", matrix_histp);
				return;
			}
			struct matrix r = matrixmult(
				*matrixhistory[matrix_histp - 2],
				*matrixhistory[matrix_histp - 1]
			);

			struct matrix *res = makematrix(r.cols[0], r.cols[1], r.cols[2]);
			printf("Result:\n"); printmatrix(r);
			waitforuser();
			break;
		}
		case 9: { // cross product
			if (vector_histp < 2 && matrix_histp < 1) {
				printf ("oops: not enough vectors or no matrix\n");
				return;
			}
			printf("Cross product: %.2f\n", crossproduct(*history[vector_histp - 2], *history[vector_histp - 1]));
			waitforuser();
			break;
		}
		case 10: { // 3d determinant
			if (matrix_histp < 1) {
				printf("oops: no matrices found\n");
				return;
			}
			printf("Determinant: %.2f\n", calcmdeterminant(*matrixhistory[matrix_histp - 1]));
			waitforuser();
			break;
		}
		case 11: {// cofactor calc
			if (matrix_histp < 1) {
				printf("oops: no matrices found\n");
			}
			struct matrix r = cofactormatrix(*matrixhistory[matrix_histp - 1]);
			struct matrix *res = makematrix(r.cols[0], r.cols[1], r.cols[2]);
			printf("Cofactor Matrix:\n");
			printmatrix(r);
			waitforuser();
			break;
		}
		case 94: {
			viewvectors();
			waitforuser();
			break;
		}
		case 95: {
			viewmatrices();
			waitforuser();
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
			waitforuser();
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
			waitforuser();
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
				printf("\ncleared\n");
			}
			waitforuser();
			break;
		}
	}
}

