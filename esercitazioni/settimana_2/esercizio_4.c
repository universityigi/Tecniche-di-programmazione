#include <stdio.h>


int main () {
    printf ("Programma che calcola i primi N numeri della serie di Fibonacci\n");
    int N, i, successivo=0, attuale=1, precedente=0;
    printf ("Inserire quanti numeri di Fibonacci visualizzare: ");
    scanf ("%d", &N);
    successivo = attuale + precedente;
    if (N==0)
    printf ("La serie non presenta numeri da visualizzare");
    else
    printf ("La serie di Fibonacci è:");
    for (i=0; i<N; i++) {
        printf ("%d ", successivo);
        successivo = attuale + precedente;
        precedente = attuale;
        attuale = successivo;        
        }
    
    printf ("\nIl programma è concluso\n");
    }
