#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	
	printf ("Programma che legge N valori di input e ne identifica il valore più basso!\n");
	
	float x, minimo = 0;
	
	printf ("Inserire il valore: ");
	scanf ("%f", &x);
	minimo = x;
	
	while (x != 0) {
		if (x < minimo && x != 0) {
			minimo = x;
			
			}
		printf ("Inserire il valore: ");
		scanf ("%f", &x);
		
		}
	printf ("Il valore minimo è: %f\n", minimo);
	
	return 0;
	}
