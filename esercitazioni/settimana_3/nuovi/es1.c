#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
	
	printf ("Programma che calcola la radice quadrata secondo il metodo di Newton!\n");
	
	float x;
	int i;
	
	printf ("Inserire l'argomento della radice: ");
	scanf ("%f", &x);
	printf ("Inserire il numero di iterazioni: ");
	scanf ("%d", &i);
	
	float radice = x;
	for (int n=0; n <=i ; ++n) {
		
		radice = (radice+x/radice)/2.0f;
		
		}
	printf ("La radice quadrata è: %f\n", radice);
	return 0;
	}
