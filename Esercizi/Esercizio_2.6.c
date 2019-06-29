#include <stdio.h>
#include <math.h>

int main()
{
    int N,bit,sum=0,exp=1;
    printf("Inserire il numero di BIT del numero: ");
    scanf("%d", &N);
    for (int i=1; i<=N; i++)
    {
        printf("Inserisci il bit n°%d qui di seguito: ",i);
        scanf("%d",&bit);
        if (i>=2)
        {
            exp*=2;
        }

        sum+=bit*exp;
    }
    printf("Risultato conversione in decimale: %d\n",sum);
    return 0;
}
