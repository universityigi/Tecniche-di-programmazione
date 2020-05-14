#include <stdio.h>


int main () {
    printf("Programma che costruisce un quadrato pieno\n");
    int a,lato_a,lato_b;
    printf ("Inserire il lato del quadrato: ");
    scanf("%d", &a);
    for (lato_a=1; lato_a<=a; lato_a++) {
        for (lato_b=1; lato_b<=a; lato_b++){
            printf ("*");           
            }
        printf("\n");
               
        }
       
    }
