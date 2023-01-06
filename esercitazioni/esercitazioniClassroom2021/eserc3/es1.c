#include <stdio.h>
#include <stdlib.h>

int main() {
    void* p =  malloc(2*sizeof(int));
    int* min = (int *) p;
    *min = 1000000;
    int* input = min + 1;
    scanf("%d",input);
    while (*input != 0) {
        scanf("%d",input);
        if (*input != 0 && *input < *min){
            *min = *input;
        }
    }
    free(p); p= NULL;
    printf("minimo : %d", *min);
    return 0;
}
