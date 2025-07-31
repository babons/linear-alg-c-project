#include <stdio.h>
#include "ops.h"
#include "io.h"


int main() {
	int option = 0;
	int c;

	printf("Welcome to the matrix calculator\n");
	for (;;) {
		printf("Enter '999' to view options\nInput: ");

		scanf("%d", &option);
		if (option == 99) {
			printf("godspeed, soldier\n");
			return 0;
		} else if (option == 999) {
			printoptions();
		}
		while ((c = getchar()) != '\n' && c != EOF);
		performops(option);


	}
	return 0;
}
