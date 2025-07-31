#ifndef IO
#define IO

/* chatgpt inspired some of this design -- i have learned a lot */

void waitforuser();
void readmatrix(struct matrix *m);
void readvector(struct vector *v);
int recordint();
void printvector(struct vector v);
void printmatrix(struct matrix m);

#endif
