#include <stdio.h>

int main() {
int maxFib = 0;
int a = 0;
int b = 1;
int c = 0;
scanf("%d",&maxFib);
while (maxFib > c) {
	c = a+b;
	if (c <= maxFib)
		{printf("%d ",c);}
	a = b;
	b = c;
	}
printf("\n");
return 0;
}

