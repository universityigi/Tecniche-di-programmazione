#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
	
	printf ("Programma che genere una scacchiera MxN cn blocchi MxM!\n");
	
	int n, m;
	
	printf ("Inserire il valore di M: ");
	scanf ("%d", &m);
	printf ("Inserire il valore di N: ");
	scanf ("%d", &n);
	
	for (int r=0; r < m*n ; ++r) {
		for (int c=0; c < m*n ; ++c) {
			if ((r/m) % 2 == 0){
				if ((c/m) % 2 == 0) {
					printf ("*");
					}
				else {
					printf("_");
					}
				}
			else {
				if ((c/m) % 2 != 0) {
					printf ("*");
					}
				else {
					printf ("_");
					}
				}
			
			}
		
		printf ("\n");
		
		}
	
	}
