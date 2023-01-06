#include <stdio.h>
#include <math.h>

int main() {
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    printf("%d\n%d\n%d\n%d\n%d\n%d\n",sizeof(c),sizeof(s),sizeof(i),sizeof(l),sizeof(f),sizeof(d));
    return 0;
}