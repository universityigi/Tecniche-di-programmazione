#include "aux.h"

TipoLista ruotaR(TipoLista l, T e) {
  if (estVuota(l))
    return listaVuota();
  else{
    if (cdr(l) == NULL)
      return cons(e, listaVuota());
    else
      return cons(car(cdr(l)), ruotaR(cdr(l), e));}
}	

TipoLista ruota(TipoLista l){
  if (estVuota(l))
    return listaVuota();
  else
    return ruotaR(l,car(l));
}

TipoLista copia(TipoLista l){
  if (estVuota(l))
    return listaVuota();
  else
    return cons(car(l),copia(cdr(l)));
}

TipoLista combinazione(TipoLista lucchetto, int password) {
  if (lucchetto==NULL)
    return listaVuota();
  else{
    while (car(lucchetto) != password){
      lucchetto = ruota(lucchetto);}
    TipoLista nuova = copia(lucchetto);
    return nuova;}
}
