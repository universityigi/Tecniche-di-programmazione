#include <stdio.h>
int main() {
int input = 10;
while (input != 0) {
	scanf("%d",&input);
	for (int i = 0; i<input; i++) {
		printf("*");
		}
	printf("\n");
	}
return 0;
}

