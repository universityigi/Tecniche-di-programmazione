#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int fibonacci(int n);
int factorial(int n);

int main(){
    // printf("I primi 3 numeri di fibonacci corrispondono a %d",fibonacci(10));
    printf("FACTORIAL:\t%d", factorial(5));
    printf("\n");
    return 0;
}

int fibonacci(int n){
    Pila* p = pilaVuota();
    T x;
    x.a = n; x.b = n-1;
    inPila(p,x);
    int ris;
    while(!estPilaVuota(p)){
        T val;
        if (primoPila(p).a == 0|| primoPila(p).b == 0){     //CASO BASE 1

        }
        else if (primoPila(p).a == 1|| primoPila(p).b == 1) //CASO BASE 2
        {

        }
        else if (n > 0){                                    //CASO RICORSIVO
            val.a = n-2; val.b = n-1;
            n-=2;
        }
        else{                                               //CASO DI CADUTA
            printf("%d\n",outPila(p).a);
        }
    }
    return res;
}

int factorial(int n){
    Pila* p = pilaVuota();
    T x; x.a = n;
    inPila(p, x);
    int ris = -1;
    while(!estPilaVuota(p)){
        T val;
        if (primoPila(p).a == 0){
            printf("caso base\n");
            outPila(p);
            ris = 1;
        }
        else if (ris == -1){
            printf("caso ricorsivo\n");
            val.a = primoPila(p).a - 1;
            inPila(p, val);
        }
        else if (ris > 0){
            printf("caduta pila\n");
            ris *= outPila(p).a;
        }
    }
    return ris;
}
