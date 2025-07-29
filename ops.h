#ifndef VECTOROPS
#define VECTOROPS

struct vector {
        double x;
        double y;
        double z;
};

struct matrix3x3 {
	struct vector cols[3];
};

struct vector *makevector(float x, float y, float z);

struct matrix3x3 *makematrix(struct vector a, struct vector b, struct vector c);

struct vector vectoradd(struct vector a, struct vector b);

struct vector scalarmult(struct vector a, float m);

struct vector matvecmult(struct matrix3x3 m, struct vector s);

double dotproduct(struct vector a, struct vector b);

void performops(int n);

#endif
