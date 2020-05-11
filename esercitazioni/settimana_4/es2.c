#include <stdio.h> 
#include <stdlib.h> 


int main () {
    int i = 10; 

    int j = 20; 

    char *p, *q;

    // Inserire codice qui senza (senza j = ...)
    p = (char*)&i;
    q = (char*)&j;
    
    //*q = *p; vietata ma funzionante
    
    for (int k=0; k < sizeof(i); ++k) {
        *(q + k) = *(p + k);
        }

    printf("%d == %d\n", i, j);
    
    
    
    }
