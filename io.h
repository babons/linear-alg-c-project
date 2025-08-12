#ifndef IO
#define IO

/* chatgpt inspired some of this design -- i have learned a lot */

void waitforuser();
void readmatrix(struct matrix *m);
void readmatrix2x2(struct matrix2x2 *m);
void readvector(struct vector *v);
void readvector2x2(struct vector2x2 *v);
int recordint();
void printvector(struct vector v);
void printmatrix(struct matrix m);
void printoptions();

#endif
