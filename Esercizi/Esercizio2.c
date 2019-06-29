#include <stdio.h>

int main()
{
    float a, somma=0, risultato;
    int n=0;
    printf("Inserisci un valore: ");
    scanf("%f", &a);
    while(a!=0)
        {
        somma+=a;
        n++;
        printf("%d",n);
        printf("Inserisci un valore: ");
        scanf("%f", &a);
        }

    risultato=somma/n;
    printf("Risultato: %f", risultato);

    return 0;
}
