#include <stdio.h>
#include <math.h>
int main() {
double square;
double x = 1;
printf("inserisci numero per l'approssimazione di radice: ");
scanf("%lf", &square);
for (int i=0; i<10;i++)
	{x = x - (pow(x,2)-square)/(x*2);}
printf("x uguale a %lf\n",x);
return 0;
}
