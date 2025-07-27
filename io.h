#ifndef IO
#define IO

/* chatgpt inspired some of this design -- i have learned a lot */

void readmatrix(struct matrix3x3 *m);
void readvector(struct vector *v);
int recordint();
void printvector(struct vector v);

#endif
