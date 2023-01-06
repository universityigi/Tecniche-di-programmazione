#include <stdio.h>
#include <math.h>

int main() {
	int input = 0;
	int decimale = 0;
	int c = 0;
	while(input == 0 || input == 1) {
		scanf("%d",&input);
		if (input == 1){
			decimale += pow(2,c);
		}
	c++;
	}
	printf("il numro è %d",decimale);
	return 0;

}
