#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
	printf ("Programma che risolve un'equazione di primo grado\n");
	
	float a, b, x;
	
	printf ("Inserire il valore di a: ");
	scanf ("%f", &a);
	printf ("Inserire il valore di b: ");
	scanf ("%f", &b);
	
	if (a==0) {
		printf ("l'equazione non è risolvibile!\n");
		return 0;
		}
	if (b==0) {
		printf ("L'incognita è uguale a 0!\n");
		return 0;
		}
		
	x = -b/a;
	
	printf ("La soluzione è: %f\n", x);		
		
	return 0;	
		
	}
