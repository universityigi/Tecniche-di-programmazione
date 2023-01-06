#include <stdio.h>

int main() {
	int square;
	printf("Lato del quadrato = ");
	scanf("%d",&square);
	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++) {
			printf("*");
		}
	printf("\n");
	}
	return 0;
}
