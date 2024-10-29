#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoAlbero limita_alberoR(TipoAlbero a, int k, int sum) {
  if (estVuoto(a))
    return albBinVuoto();
  else{
    if (sum+radice(a) <= k)
      return creaAlbBin(radice(a),limita_alberoR(sinistro(a),k,sum+radice(a)),limita_alberoR(destro(a),k, sum+radice(a)));
    else
      return creaAlbBin(0,limita_alberoR(sinistro(a),k,sum+radice(a)),limita_alberoR(destro(a),k,sum+radice(a)));}
}		

TipoAlbero limita_albero(TipoAlbero a, int k){
  return limita_alberoR(a,k,0);
}
