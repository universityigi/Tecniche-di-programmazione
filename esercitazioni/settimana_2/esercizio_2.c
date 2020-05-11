#include <stdio.h>


int main () {
    float a=0, totale=0, numeri=0, media=0;
    printf ("Inserire il valore: ");
    scanf ("%f", &a);
    while (a!=0) {
        totale += a;
        numeri += 1;
        printf ("Inserire il valore: ");
        scanf ("%f", &a);
        }
    media= totale/numeri;
    printf("La media aritmetica dei valori inseriti è: %.2f\n", media);
    
    }
