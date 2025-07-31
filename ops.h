#ifndef VECTOROPS
#define VECTOROPS

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

struct vector vectoradd(struct vector a, struct vector b);

struct vector vscalarmult(struct vector a, float m);

struct matrix mscalarmult(struct matrix a, float m);

struct vector matvecmult(struct matrix m, struct vector s);

struct matrix matrixmult(struct matrix a, struct matrix b);

double dotproduct(struct vector a, struct vector b);

struct vector crossproduct(struct vector a, struct vector b);

double calcmdeterminant(struct matrix m);

struct matrix inversematrix(struct matrix m);

void viewvectors();

void viewmatrices();

void performops(int n);

#endif
