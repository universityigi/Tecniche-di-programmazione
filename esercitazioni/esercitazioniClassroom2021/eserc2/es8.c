#include <stdio.h>

int main(){
    int i = 10;
    int j = -1;
    char *p, *q;
    p = &i;
    q = &j;
    int z = (int) *p;
    *q = z;
    printf("%d == %d\n", i, j);
}