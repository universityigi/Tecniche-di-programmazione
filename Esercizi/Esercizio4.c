#include <stdio.h>
#include <math.h>

int main()
{
    int N,a=1,b=1,somma=0;
    printf("Inserisci la lunghezza della serie di Fibonacci: ");
    scanf("%d",&N);
    for(int i =1; i<=N; i++)
    {
        somma=a+b;
        if (i!=N)
        {
            printf("%d, ",somma);
        }
        else
        {
            printf("%d",somma);
        }
        a=b;
        b=somma;
        somma=0;

    }
    printf("\n");
    return 0;
}
