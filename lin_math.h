#ifndef MATH_H
#define MATH_H

struct vector vectoradd(struct vector a, struct vector b);

struct vector vscalarmult(struct vector a, float m);

struct matrix mscalarmult(struct matrix a, float m);

struct vector matvecmult(struct matrix m, struct vector s);

struct matrix matrixmult(struct matrix a, struct matrix b);

double dotproduct(struct vector a, struct vector b);

double magnitude(struct vector a);

double lengthofprojection(struct vector a, struct vectorb);

struct vector crossproduct(struct vector a, struct vector b);

double calcmdeterminant(struct matrix m);

double calccofactor(struct matrix m, int i, int j);

void getotherelement(int i, int *one, int *two);

float getelement(struct matrix m, int i, int j);

struct matrix cofactormatrix(struct matrix m);

struct matrix transposematrix(struct matrix m);

struct matrix inversematrix(struct matrix m);

#endif