#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int numPari(TipoAlbero a){
  if (estVuoto(a))
    return 0;
  else{
    if ((a->info)%2==0)
      return 1 + numPari(sinistro(a)) + numPari(destro(a));
    else
      return numPari(sinistro(a)) + numPari(destro(a));}
}

int sumNodi(TipoAlbero a){
  if (estVuoto(a))
    return 0;
  else
    return a->info + sumNodi(sinistro(a)) + sumNodi(destro(a));
}

TipoAlbero maxMenoMinPari(TipoAlbero a) {
  if (estVuoto(a))
    return albBinVuoto();
  else{
    if (numPari(sinistro(a))>=numPari(destro(a)))
      return creaAlbBin(sumNodi(sinistro(a))-sumNodi(destro(a)),maxMenoMinPari(sinistro(a)),maxMenoMinPari(destro(a)));
    else
      return creaAlbBin(sumNodi(destro(a))-sumNodi(sinistro(a)),maxMenoMinPari(sinistro(a)),maxMenoMinPari(destro(a)));}
}
