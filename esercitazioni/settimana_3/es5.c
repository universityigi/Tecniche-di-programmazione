#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    int i, valore;
    scanf ("%d", &valore);
    
    while (valore != 0) {
        for ( i = 0; i < valore; ++i) {
            printf ("*");
            }
        printf ("\n");
        scanf ("%d", &valore);
        }
    
    
    
    }
