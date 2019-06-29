#include <stdio.h>

int main()
{
    float a, b, x;
    printf("Inserisci il primo numero: ");
    scanf("%f", &a);
    printf("Inserisci un secondo numero: ");
    scanf("%f", &b);
    x = -b/a;
    printf("Il risultato dell'equazione in questione è: %f", x);
    return 0;
}
