#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int N1, N2;
    printf("Eseguirò l'mcm tra due numeri che inserirai\nInserisci un primo numero: ");
    scanf("%d", &N1);
    printf("Inserisci un secondo numero numero: ");
    scanf("%d", &N2);
    int min;
    if (N1<N2){
        min=N1;
    }else{
        min=N2;
    }
    int div;
    for(int a=1; a <= N1*N2; a++)
	{
	if (a%N1==0 && a%N2==0)
		{
		printf("%d\n",a);
		break;
		}
	}


    return 0;

}
