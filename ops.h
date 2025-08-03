#ifndef OPS_H
#define OPS_H

struct vector {
        double x;
        double y;
        double z;
};

struct matrix {
	struct vector cols[3];
};

struct vector *makevector(float x, float y, float z);

struct matrix *makematrix(struct vector a, struct vector b, struct vector c);

void viewvectors();

void viewmatrices();

void performops(int n);

#endif
