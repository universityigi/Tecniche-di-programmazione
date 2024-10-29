#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

typedef struct{
  int somma;
  int nodiPari;
} Risultato;

Risultato cammino_pariR(TipoAlbero a) {
  if (estVuoto(a)){
    Risultato r ={0,0};
    return r;}  	
  Risultato sx = cammino_pariR(sinistro(a));
  Risultato dx = cammino_pariR(destro(a));
  Risultato migliore = sx;
  if (dx.nodiPari > sx.nodiPari || (sx.nodiPari == dx.nodiPari && dx.somma > sx.somma))
    migliore = dx;
  migliore.somma+=radice(a);
  if (radice(a)%2==0)
    migliore.nodiPari += 1;
  return migliore;
}

int cammino_pari(TipoAlbero a) {	
  Risultato r = cammino_pariR(a);
  return r.somma;
}
