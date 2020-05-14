#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    
    int* num = (int*)malloc(sizeof(int));
    int* minimo = (int*)malloc(sizeof(int));
    
    printf ("Inserire un numero (il programma termina con 0): ");
    scanf ("%d", num);
    
    *minimo = *num;
    
    while (*num != 0) {
        printf ("Inserire un numero (il programma termina con 0): ");
        scanf ("%d", num);
        if (*num < *minimo && *num > 0) {
            *minimo = *num;
            }
        }
    printf ("Il numero minimo inserito è: %d\n", *minimo);
    free (num);
    free (minimo);
    }
