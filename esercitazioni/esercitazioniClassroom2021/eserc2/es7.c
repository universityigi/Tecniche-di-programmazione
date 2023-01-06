#include <stdio.h>
int main() {
    float sum = 0;
    for (int i = 0; i < 10; ++i)
    {
    sum += 0.1f;
    }
    printf("%f", sum);
    return 0;
}