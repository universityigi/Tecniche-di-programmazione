#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    printf ("Programma che genera una scacchiera N*MxN*M con blocchi M*M\n");
    
    int n, m, lato_a, lato_b;
    
    printf ("Inserire la dimensione della scacchiera: ");
    scanf ("%d", &n);
    printf ("Inserire la dimensione dei blocchi: ");
    scanf ("%d", &m);
    
    for (lato_a=0; lato_a < n*m; lato_a++) {
        for (lato_b=0; lato_b < n*m; lato_b++) {
            if ((lato_a / m) % 2 == 0) {
                if ((lato_b / m) % 2 == 0) {
                    printf ("*");
                    }
                else {
                    printf ("-");
                    }
                }
            else {
                if ((lato_b / m) % 2 != 0) {
                    printf ("*");
                }
                else {
                    printf ("-");
                    }
                }
            }
        printf ("\n");
        }
    
    }
