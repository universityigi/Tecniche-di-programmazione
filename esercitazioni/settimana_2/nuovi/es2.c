#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
	printf ("Programma che calcola la media aritmetica di N numeri, fino all'inserimento dello 0!\n");
	
	float a, totale=0, conteggio=0, media=0;
	
	printf ("Inserire un valore per la media aritmetica (con 0 si ferma il conteggio): ");
	scanf ("%f", &a);
	
	if (a==0) {
		printf ("Numeri insufficenti, riprovare\n");
		return 0;
		}
	
	while (a != 0) {
		totale += a;
		conteggio++;
		printf ("Inserire un valore per la media aritmetica (con 0 si ferma il conteggio): ");
		scanf ("%f", &a);
		}
	
	media = totale/conteggio;
	printf ("La media è: %f\n", media);
	
	return 0;
	}
