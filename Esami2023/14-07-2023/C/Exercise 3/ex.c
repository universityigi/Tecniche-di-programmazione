#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoAlbero sommaDistMinAntenatoh(TipoAlbero a,int d,int min) {
  if (estVuoto(a))
    return albBinVuoto();
  else{
    int aux = d;
    if (radice(a)<min){
      d=0;
      min=radice(a);}
    return creaAlbBin(radice(a)+aux,sommaDistMinAntenatoh(sinistro(a),d+1,min),sommaDistMinAntenatoh(destro(a),d+1,min));}
}

TipoAlbero sommaDistMinAntenato(TipoAlbero a) {
  if (estVuoto(a))
    return albBinVuoto();
  else
    return sommaDistMinAntenatoh(a,0,radice(a));
}
