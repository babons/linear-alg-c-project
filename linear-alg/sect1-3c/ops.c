#include <stdio.h>
#include "ops.h"

struct vector makevector(float x, float y, float z) {
        struct vector r;

        r.x = x;
        r.y = y;
        r.z = z;

        return r;
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
