#include <stdio.h>

int main() {
	int square = 0;
	printf("Lato del quadrato = ");
	scanf("%d",&square);
	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++) {
			if (i == 0 || i == square - 1)
				{printf("*");}
			else if (j == 0 || j == square - 1)
				{printf("*");}
			else
				{printf(" ");}
		}
	printf("\n");
	}
}
