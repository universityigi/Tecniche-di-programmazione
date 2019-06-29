#include <stdio.h>

int main()
{
    int a, b, dist;
    dist = (&b - &a);
    printf("La distanza tra a e b è: %d byte", (unsigned)dist);
    *(&b - dist)=34;
    printf("Valore a: %d", a);
    return 0;

}
