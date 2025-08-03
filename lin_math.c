#include <stdio.h>
#include <math.h>
#include "ops.h"

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

double dotproduct(struct vector a, struct vector b) {
	double prod =
			(a.x * b.x) +
			(a.y * b.y) +
			(a.z * b.z);
	return prod;
}

double magnitude(struct vector a) {
    double mag =
		sqrt(
        (a.x * a.x) +
        (a.y * a.y) +
        (a.z * a.z) 
		);
	return mag;
}

double lengthofprojection(struct vector a, struct vector b) {
	// projection of b onto a
	return dotproduct(a, b) / magnitude(a);
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

struct matrix transposematrix(struct matrix m) {
	struct matrix r;

	r.cols[0].x = m.cols[0].x;
	r.cols[0].y = m.cols[1].x;
	r.cols[0].z = m.cols[2].x;
	r.cols[1].x = m.cols[0].y;
	r.cols[1].y = m.cols[1].y;
	r.cols[1].z = m.cols[2].y;
	r.cols[2].x = m.cols[0].z;
	r.cols[2].y = m.cols[1].z;
	r.cols[2].z = m.cols[2].z;

	return r;
}

struct matrix inversematrix(struct matrix m) {
	struct matrix inverse;
	struct matrix adjugate = transposematrix(cofactormatrix(m));
	inverse = mscalarmult(adjugate, (1/calcmdeterminant(m)));

	return inverse;
}