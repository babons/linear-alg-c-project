#include <stdio.h>

struct vector {
	double x;
	double y;
	double z;
};

struct vector vectoradd(struct vector a, struct vector b) {
	struct vector r;

	r.x = (a.x + b.x);
	r.y = (a.y + b.y);
	r.z = (a.z + b.z);

	return r;
}

struct vector scalarmult(struct vector a, double m) {
	struct vector r;

	r.x = (a.x * m);
	r.y = (a.y * m);
	r.z = (a.z * m);

	return r;
}

struct vector makevector(double x, double y, double z) {
	struct vector r;

	r.x = x;
	r.y = y;
	r.z = z;

	return r;
}

void printvector(struct vector p) {
	printf("\n[%.2f, %.2f, %.2f]\n", p.x, p.y, p.z);
}

int main() {
	struct vector a = makevector(1.0, 3.0, 5.0);
	struct vector b = makevector(-3.0, 2.0, 7.0);

	printvector(a);
	printf("and");
	printvector(b);
	printf("equals");
	struct vector sum = vectoradd(a, b);

	printvector(sum);

	struct vector mult = scalarmult(a, 2);
	printvector(a);
	printf("times\n2\n");
	printf("equals");
	printvector(mult);

	return 0;
}
