#include <stdio.h>
#include <math.h>

int main() {
int radius;
scanf("%d",&radius);
for (int y = -radius; y<=radius; y++) {
	for (int x = -radius; x<=radius; x++) {
		if (pow(y,2) <= pow(radius,2) - pow(x,2))
		{printf("*");}
		else
		{printf("-");}
		}
	printf("\n");
	}
}
