#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

TipoLista inFondo(TipoLista l);
TipoLista invertiInParte(TipoLista l, int inizio);

int main(){
  return 0;
}

tipoLista append(TipoLista l, TipoInfoLista e){
  if (estVuota(l)) return cons(e, listaVuota());
  else
    return cons(cdr(l), car(l))
}

TipoLista inFondo(TipoLista l){
  if(estVuota(l)) return listaVuota();
  else{
    return append(inFondo(cdr(l)), car(l));
  }
}

TipoLista invertiInParte(TipoLista l, int inizio){
  if(estVuota(l)) return listaVuota();
  else{
    if(inizio > 0)
      return cons(car(l), invertiInParte(cdr(l), inizio - 1));
    else
      return cons(car(l), inFondo(cdr(l)));
  }
}
