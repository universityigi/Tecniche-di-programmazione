#include <stdio.h>
#include <stdlib.h>
#include "alberoBinario.h"

bool estFoglia(TipoAlbero a){
  return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

TipoAlbero somma_livello(TipoAlbero a, int liv){
  if (estVuoto(a)) return albBinVuoto();
  else{
    if (liv == 1){
      int sum = 0;
      TipoAlbero sx = sinistro(a);
      TipoAlbero dx = sinistro(a);
      if (!estVuoto(sinistro(a)) && estFoglia(sinistro(a))) {
        sum += radice(sinistro(a));
        sx = albBinVuoto();
      }
      if (!estVuoto(destro(a)) && estFoglia(destro(a))){
        sum += radice(destro(a));
        dx = albBinVuoto();
      }
      creaAlbBin(radice(a)+sum, sx, dx);
    }
    else
      return creaAlbBin(radice(a), somma_livello(sinistro(a), liv-1), somma_livello(destro(a), liv-1));
  }
}

int main(){
  TipoAlbero alb = creaAlbBin(1, creaAlbBin(2, creaAlbBin(4,NULL,NULL), creaAlbBin(5, NULL, NULL)),
                  creaAlbBin(3, creaAlbBin(6,NULL,NULL),
                  creaAlbBin(7, NULL, creaAlbBin(8, NULL, NULL))));
  stampaParentetica(alb); printf("\n");
  stampaParentetica(somma_livello(alb, 1));
}
