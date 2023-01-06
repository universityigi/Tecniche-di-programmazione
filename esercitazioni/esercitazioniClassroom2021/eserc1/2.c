#include <stdio.h>

int main() {
	int c = 0;
	int input = 10;
	int sum = 0;
	while (input != 0) {
		printf("inserisci numero (0 per terminare): ");
		scanf("%d", &input);
		if (input != 0) {
			sum += input;
		}
		c++;
	}
	int media;
	media = sum / c;
	printf("l'ultimo numero era %d\n", media);
	return 0;
}

