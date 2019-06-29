#include <stdio.h>

int main()
{
    int N, M, A=0, B=2,clock=0,C=0;
    printf("Inserisci il primo numero N: ");
    scanf("%d",&N);
    printf("Inserisci il secondo numero M: ");
    scanf("%d",&M);
    while(N%M!=0)
    {
        printf("Inserisci il secondo numero M: ");
        scanf("%d",&M);
    }
    for(int i=0; i<N*M; i++)
    {
        for(int a=0; a<N; a++)
        {
            for(int b=0; b<M; b++)
            {
                if(A!=2 && clock==0 && B>0)
                {
                    B=B--;
                    printf("*");
                    A=A++;
                }
                else if (B!=2 && clock==0 && A>0)
                {
                    A=A--;
                    printf("-");
                    B=B++;
                }
                else if (B!=2 && clock==1 && A==2)
                {
                    A=0;
                    printf("-");
                    B=B++;
                }
                else if (A!=2 && clock==1 && B==2)
                {
                    B=0;
                    printf("-");
                    A=A++;

                }
                C=C++;

            }

        }
        if (clock==0)
            clock=1;
            else
            clock=0;
        printf("\n");
    }
}
