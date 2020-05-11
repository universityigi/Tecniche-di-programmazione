#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    printf ("Programma per calcolare la radice quadrata con il metodo di Newton\n");
    float x;
    printf ("Inserire il valore: ");
    scanf ("%f", &x);
    
    if (x < 0.0) {
        printf ("Il valore non può essere negativo!\n");
        return -1;
        }
    
    
    int n = 10;
    float radice = x;
    for (int i=0; i < n; ++i) {
        radice = (radice + x/radice)/2.0f;
        }
        
    printf ("La radice di %.2f è: %.2f\n", x, radice);
    
    }
