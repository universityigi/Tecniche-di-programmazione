#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
	
	printf ("Programma che calcola il valore minimo inserito (con lo 0 termina il programma)\n");
	
	int *num = (int*)malloc(sizeof(int));
	int *minimo = (int*)malloc(sizeof(int));
	
	printf ("Inserire un valore: ");
	scanf ("%d", num);
	
	*minimo = *num;
	
	while (*num != 0) {
		if (*num<*minimo && *num > 0) {
			*minimo = *num;
			}
		printf ("Inserire un valore: ");
		scanf ("%d", num);
		}
	printf ("Il numero minimo inserito è: %d\n", *minimo);	
	
	free(num);
	free(minimo);
	
	}
