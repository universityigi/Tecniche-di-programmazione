#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Inserisci il valore del lato: ");
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        for (int i=0; i<N; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
