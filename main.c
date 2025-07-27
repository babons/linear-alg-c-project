#include <stdio.h>
#include "ops.h"
#include "io.h"


int main() {
	int option = 0;
	int c;

	printf("Welcome to the matrix calculator\n");
	for (;;) {
		printf("Select one of the following:\n");
		// printf("1. Create vectors\n");
		printf("1. Add vectors\n");
		printf("2. Multiply vectors\n");
		printf("3. Calculate dot product\n");
		printf("4. Exit\n");

		scanf("%d", &option);
		performop(option);

		while ((c = getchar()) != '\n' && c != EOF);


	}
	return 0;
}
