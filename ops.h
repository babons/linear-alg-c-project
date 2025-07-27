#ifndef VECTOROPS
#define VECTOROPS

struct matrix3x3 {
	struct vector cols[3];
}

struct vector {
	double x;
	double y;
	double z;
};

struct vector makevector(float x, float y, float z);

struct vector vectoradd(struct vector a, struct vector b);

struct vector scalarmult(struct vector a, float m);

double dotproduct(struct vector a, struct vector b);

#endif
