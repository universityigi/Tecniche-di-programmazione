#pragma once

#include <stdbool.h>

// Tipo info dell'albero
typedef int TipoInfoAlbero;

// Albero con strutture collegate
typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

// Funzioni tipo astratto albero binario
TipoAlbero albBinVuoto();
TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx);
bool estVuoto(TipoAlbero a);
TipoInfoAlbero radice(TipoAlbero a);
TipoAlbero sinistro(TipoAlbero a);
TipoAlbero destro(TipoAlbero a);

// Funzioni esterne
void stampaInfoAlbero(TipoInfoAlbero c);
void stampaParentetica(TipoAlbero a);
void stampaAlbero(TipoAlbero a);

/** Esercizio da svolgere **/
int cammino_pari(TipoAlbero a);
