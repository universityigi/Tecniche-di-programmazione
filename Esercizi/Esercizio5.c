#include <stdio.h>
#include <math.h>
//* DA FINIRE *//
int main()
{
    int n1, n2;
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);
    for (int i=0; i<n1 && n1%i==0; i++)
    {
        printf("%d",i);
    }

    return 0;
}
