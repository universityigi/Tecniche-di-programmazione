#include <stdio.h>

int main() {
    printf("Funzione che calcola il valore della x in un espressione di primo grado dati i valori di a e b\n");
    float a,b,x;
    printf("Inserire il valore di a: ");
    scanf("%f", &a);
    printf("Inserire il valore di b: ");
    scanf("%f", &b);
    x=-(b/a);
    printf("Il valore di x è: %.2f\n", x);
        
    }
