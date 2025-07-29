#include <stdio.h>
#include "ops.h"
#include "io.h"


int main() {
	int option = 0;
	int c;

	printf("Welcome to the matrix calculator\n");
	for (;;) {
		printf("Select one of the following:\n");
		printf("1. Create vectors\n");
		printf("2. Create matrices\n");
		printf("3. Add vectors\n");
		printf("4. Multiply vectors\n");
		printf("5. Calculate dot product\n");
		printf("6. Matrix vector multiplicaion\n");
		printf("96. Delete last vector\n");
		printf("97. Delete last matrix\n");
		printf("98. Clear\n");
		printf("99. Exit\n");

		scanf("%d", &option);
		if (option == 99) {
			printf("godspeed, soldier\n");
			return 0;
		}
		performops(option);

		while ((c = getchar()) != '\n' && c != EOF);


	}
	return 0;
}
