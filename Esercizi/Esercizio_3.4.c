#include <stdio.h>

int main()
{
    float x, A=0, B;
    printf("Inserisci un numero (0 per terminare): ");
    while(scanf("%f", &B)!=0.0)
    {
        if(B==0)
            break;
        if(B<A && B!=0)
            A=B;
        printf("Inserisci un numero (0 per terminare): ");
    }
    printf("Il numero minore inserito è: %f",A);
    return 0;
}
