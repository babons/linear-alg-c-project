#include <stdio.h>
#include "ops.h"
#include "io.h"


int main() {
	struct vector a = makevector(0.0, 0.0, 0.0);
	struct vector b = makevector(0.0, 0.0, 0.0);
	struct vector r = makevector(0.0, 0.0, 0.0);
	int option = 0;
	int c;
	float scal = 0;

	printf("Welcome to the matrix calculator\n");
	for (;;) {
		printf("Select one of the following:\n");
		printf("1. Create vectors\n");
		printf("2. Add vectors\n");
		printf("3. Multiply vectors\n");
		printf("4. Calculate dot product\n");
		printf("5. Exit\n");

		scanf("%d", &option);

		while ((c = getchar()) != '\n' && c != EOF);
		switch (option) {
			case 1:
				printf("Please enter vector a - x, y, z: ");
				readvector(&a);
				printf("Please enter vector b - x, y, z: ");
				readvector(&b);
				break;
			case 2:
				r = vectoradd(a, b);
				printf("Vector a + Vector b = ");
				printvector(r);
				printf("\n");
				break;
			case 3:
				printf("Please enter a number. This is applied to vector a only: ");
				scanf("%f", &scal);
				while ((c = getchar()) != '\n' && c != EOF);
				r = scalarmult(a, scal);
				printf("Vector a * %f = ", scal);
				printvector(r);
				break;
			case 4:
				printf("Dot product of vectors a and b is: %.2f\n", dotproduct(a, b));
				break;
			case 5:
				printf("You will be missed.\n");
				return 0;
		}
	}
	return 0;
}
