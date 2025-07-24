#ifndef VECTOROPS
#define VECTOROPS

struct vector {
	double x;
	double y;
	double z;
};

struct vector vectoradd(struct vector a, struct vector b);

struct vector scalarmult(struct vector a, double m);

double dotproduct(struct vector a, struct vector b);

#endif
