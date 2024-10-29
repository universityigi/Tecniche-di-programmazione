#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

void cambiaNodoDalCamminoR(TipoAlbero a, int k, int sum) {
  if (estVuoto(a))
    return;
  else{
    int aux = sum;
    sum+=radice(a);
    if (aux%k==0)
      a->info = radice(a)+k;
    else
      a->info = radice(a)-k;
      cambiaNodoDalCamminoR(sinistro(a),k,sum);
      cambiaNodoDalCamminoR(destro(a),k,sum);} 	
}

void cambiaNodoDalCammino(TipoAlbero a, int k) {
  return cambiaNodoDalCamminoR(a,k,0);
}
