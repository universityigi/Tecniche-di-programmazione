/*****************************
* Tipo astratto pila.        *
*                            *
* Realizzazione side-effect. *
*****************************/
#pragma once

#include <stdbool.h>
#include "scl.h"

typedef TipoNodo * Pila;


Pila * pilaVuota();                // nuova pila vuota
bool estPilaVuota(Pila *c);        // controlla se vuota
void inPila(Pila *p , T e);        // push; inserisce in testa
T outPila(Pila* p);                // pop; rimuove dalla testa
T primoPila(Pila* p);              // valore del primo
