#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    char c;
    short s;
    int i;
    long g;
    float f;
    double d;
    
    printf ("char   -> indirizzo %p, dimensione %ld byte\n", &c, sizeof(c));
    printf ("short  -> indirizzo %p, dimensione %ld byte\n", &s, sizeof(s));
    printf ("int    -> indirizzo %p, dimensione %ld byte\n", &i, sizeof(i));
    printf ("long   -> indirizzo %p, dimensione %ld byte\n", &g, sizeof(g));
    printf ("float  -> indirizzo %p, dimensione %ld byte\n", &f, sizeof(f));
    printf ("double -> indirizzo %p, dimensione %ld byte\n", &d, sizeof(d));
    
    }
