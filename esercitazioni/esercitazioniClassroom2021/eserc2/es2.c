#include <stdio.h>
#include <math.h>

int main() {
    unsigned char b;
    short s;
    int i;
    long l;
    float f;
    double d;
    char c;
    printf("inserisci unsigned char: ");b = getchar();
    printf("Inserisci short: "); scanf("%hd",&s);
    printf("Inserisci int: "); scanf("%d",&i);
    printf("Inserisci long: "); scanf("%ld",&l);
    printf("Inserisci float: "); scanf("%f",&f);
    printf("Inserisci double: "); scanf("%lf",&d);
    printf("inserisci char: ");c = getchar();
    printf("\n \'%c\' %hd %d %ld %f %lf \'%c\'",b,s,i,l,f,d,c);
    return 0;
}