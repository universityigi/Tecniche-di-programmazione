#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    printf ("Programma che legge N valori e ne restituisce il minimo\n");
    
    int n, minimo;
    
    printf ("Inserire un valore intero: ");
    scanf ("%d", &n);
    minimo = n;
    
    while (n != 0) {
        
        printf ("Inserire un valore intero: ");
        scanf ("%d", &n);
        
        if (n < minimo && n != 0) {
            minimo = n;
            }
            
        
        
        }
        
    printf ("Il valore minimo è: %d\n", minimo);
    
    }
