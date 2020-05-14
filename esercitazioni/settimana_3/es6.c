#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main () {
    
    unsigned char b = 'a';
    short s = 2;
    int i = 200;
    long l = 3000;
    float f = 3.5;
    double d = 6.0;
    char c = 'g';
    
    printf ("1) %ld\n", b + 10l);
    printf ("2) %ld\n", (b + i) * l);
    printf ("3) %f\n", (b + i) * l + f);
    printf ("4) %f\n", s/f + sin(d));
    printf ("5) %d\n", c == 'b');
    printf ("6) %f\n", l + 1.5f);
    printf ("7) %d\n", i < 10);
    }
