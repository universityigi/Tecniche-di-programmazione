#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int * allocaInt(){
    int * p = (int *)malloc(sizeof(int));
    return p;
}
void printInt(int *i1, int *i2){
    printf("%d\t%d\n",*i1, *i2);
}
void soluzioneEquazione(int a, int b, int c) {
    double sol1 = ((-b)+(sqrt(pow(b,2)-(4*a*c)))) / 2*a;
    double sol2 = ((-b)+(sqrt(pow(b,2)-(4*a*c)))) / 2*a;
    printf("sol1 = %0.3lf\tsol2 = %0.3lf\n",sol1,sol2);
}
int main(){
    printf("%d\n",*(allocaInt()));
    int i, j;
    i = 10;
    j = 20;
    printInt(&i,&j);
    soluzioneEquazione(1, 0, -4);
    return 0;
}