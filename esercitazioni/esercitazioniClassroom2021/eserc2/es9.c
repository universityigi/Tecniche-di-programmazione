#include <stdio.h>

int main(){
    int a = 0;
    int b = 10;
    int *p_a = &a;
    int *p_b = &b;
    int dist = p_a - p_b;
    printf("%p %p", p_a, p_b);
    *(p_b + dist) = *p_b;
    printf("\n%d == %d\n", a, b);
    return 0;
}