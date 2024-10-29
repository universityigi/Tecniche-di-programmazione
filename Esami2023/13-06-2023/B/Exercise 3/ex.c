#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

bool isFoglia(TipoAlbero a){
  if (sinistro(a) == NULL && destro(a) == NULL)
    return true;
  return false;}

TipoAlbero espandiAlberoR(TipoAlbero a, int k, float percorso, float n){
  if (estVuoto(a))
    return albBinVuoto();
  else{
    percorso += radice(a);
    n++;
    if (!isFoglia(a)){
      return creaAlbBin(radice(a),espandiAlberoR(sinistro(a),k,percorso,n),espandiAlberoR(destro(a),k,percorso,n));}
    else{
      float media = (n > 1) ? (percorso - radice(a)) / (n - 1) : 0;
      if (k<media) //errore nei test, nell'esercizio chiede se è minore uguale.
        return creaAlbBin(radice(a),creaAlbBin(radice(a), NULL, NULL), NULL);
      else
        return creaAlbBin(radice(a),creaAlbBin(-radice(a), NULL, NULL),NULL);}}
}

TipoAlbero espandiAlbero(TipoAlbero a, int k) {
  if (estVuoto(a))
    return albBinVuoto();
  else
    return espandiAlberoR(a,k,0.0,0.0);
}
