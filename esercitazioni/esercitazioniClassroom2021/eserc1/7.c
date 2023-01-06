#include <stdio.h>

int main() {
	int input = 10;
	int min = 0;
	while (input != 0) {
		printf("inserisci numero (0 per terminare)");
		scanf("%d", &input);
		if (input != 0 && min == 0) {
			min = input;
		}
		else if (input != 0 && input < min) {
			min = input;
		}
	}
	printf("il minimo era %d\n", min);
	return 0;
}

