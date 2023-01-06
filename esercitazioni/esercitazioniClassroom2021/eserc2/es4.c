#include <stdio.h>
#include <math.h>

int main() {
    int a;
    long b;
    int size_int = sizeof(int) * 8 - 1;
    int size_long = sizeof(long) * 8 - 1;
    printf("%d\t%d\n", size_int, size_long);
    a = pow(2,size_int) - 1;
    b = pow(2,size_long) - 1;
    printf("il massimo numero per int è: %d\nil massimo numero per long è: %ld\n", a, b);
    return 0;
}