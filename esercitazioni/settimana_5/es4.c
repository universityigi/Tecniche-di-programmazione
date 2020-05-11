#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int risolviEquazione(float *x1, float *x2, float a, float b, float c);

int main (int argc, int **argv) {
	
	printf ("Programma che risolve un'equazione di secondo grado!\n");
	
	float a, b, c;
	printf ("Inserire il valore di a: ");
	scanf ("%f", &a);
	printf ("Inserire il valore di b: ");
	scanf ("%f", &b);
	printf ("Inserire il valore di c: ");
	scanf ("%f", &c);
	
	int risultato;
	float x1, x2;
	
	risultato = risolviEquazione(&x1, &x2, a, b, c);
	
	if (risultato > 0) {
		printf ("Le soluzioni sono: %f e %f\n", x1, x2);
		}
	else if (risultato == 0) {
		printf ("Le soluzioni sono coincidenti e sono: %f e %f\n", x1, x2);
		}
	else {
		printf ("Non ci sono soluzioni reali\n");
	}
	return 0;
	}

int risolviEquazione(float *x1, float *x2, float a, float b, float c) {
	
	float delta = b*b - 4.0f * a * c;
	
	if (delta > 0) {
		*x1 = (b + sqrt(delta))/ (2.0f*a);
		*x2 = (b - sqrt(delta))/ (2.0f*a);
		return 1;
		}
	else if (delta < 0) {
		return -1;
		}
	else
	{
	*x1 = b / (2.0f*a);
	*x2 = *x1;
	return 0;	
	}
	
	
	}







