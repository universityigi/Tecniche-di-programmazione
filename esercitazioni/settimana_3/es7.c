#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    printf ("Programma che stampa l'intero set dei caratteri ASCII\n");
    
    int i;
    
    for ( i=0; i<128; ++i) {
        printf ("%c ; %d\n", i, i);
        } 
    printf ("\n");
    
    }
