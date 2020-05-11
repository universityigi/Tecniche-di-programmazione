#include <stdio.h>


int main () {
    printf("Programma che costruisce un quadrato\n");
    int l,lato_a,lato_b;
    printf ("Inserire il lato del quadrato: ");
    scanf("%d", &l);
    for (lato_a=1; lato_a<=l; lato_a++) {
        for (lato_b=1; lato_b<=l; lato_b++){
            if (lato_a==1 || lato_a==l || lato_b==1 || lato_b==l)
            printf("*");
            else
            printf(" ");
            }
        printf("\n");
               
        }
       
    }
