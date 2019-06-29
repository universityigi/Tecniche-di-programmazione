#include <stdio.h>

int main()
{
    int R, a, b, x=0, y=0;
    printf("Inserisci la dimensione del raggio: ");
    scanf("%d", &R);
    a=b=R+1;
    for (int i=0; i<(R*2+1); i++)
    {
        y++;
        for (int j=0; j<(R*2+1); j++)
        {
            x++;
            if ((x-a)*(x-a)+(y-b)*(y-b)-R*R<=0)
            {
                printf("*");
            }else{
                printf("-");
            }
        }
        printf("\n");
        x=0;
    }
}
