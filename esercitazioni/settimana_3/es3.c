#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    printf ("Programma per disegnare un cerchio pieno\n");
    int r, d, lato_a, lato_b;
    printf ("Inserire il raggio del cerchio: ");
    scanf ("%d", &r);
    d = pow(r,2);
    for (lato_a=r; lato_a >= -r; lato_a--){
        for (lato_b=r; lato_b >= -r; lato_b--) {
            if ( (pow(lato_a,2) + pow(lato_b,2)) <= d) {
                printf ("*");
                }
            else
                printf ("-");
            }
        printf ("\n");
        }
    
    
    
    
    }
