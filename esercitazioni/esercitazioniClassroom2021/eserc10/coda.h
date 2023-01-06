/*****************************
* Tipo astratto coda.        *
*                            *
* Realizzazione side-effect. *
*****************************/
#pragma once

#include <stdbool.h>

#include "scl.h"

typedef TipoNodo * Coda;

Coda * codaVuota();             // nuova coda vuota
bool estCodaVuota(Coda *c);     // controlla se vuota
void inCoda(Coda *c , T e);     // inserisce in coda
T outCoda(Coda *c);             // rimuove dalla testa
T primoCoda(Coda *c);           // valore del primo
