#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void scambia (int *a, int *b);

int main () {
	
	printf ("Programma che scambia i contenuti di due dati\n");
	
	int i,j;
	
	printf ("Inserire il primo valore: ");
	scanf ("%d", &i);
	printf ("Inserire il secondo valore: ");
	scanf ("%d", &j);
	
	printf ("I valori prima dello scambio sono: i=%d e j=%d\n", i, j);
	
	scambia (&i,&j);
	
	printf ("I valori dopo dello scambio sono: i=%d e j=%d\n", i, j);
	
	return 0;
	}
	
void scambia (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	}
