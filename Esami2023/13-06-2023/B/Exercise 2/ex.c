#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoLista inserisciLista (TipoLista l1, TipoLista l2, int k) {
  if (k==0 && !estVuota(l2))
    return cons(car(l2),inserisciLista(l1,cdr(l2),k));
  else if (estVuota(l1))
    return listaVuota();
  else if (k>0)
    return cons(car(l1),inserisciLista(cdr(l1),l2,k-1));
  else
    return cons(car(l1),inserisciLista(cdr(l1),l2,k));
}

int max(TipoLista l){
  int max = 0;
  while (!estVuota(l)){
    if (car(l) >= max){
      max = car(l);}
    l = cdr(l);}
  return max;
}

TipoLista inverti(TipoLista l){
  TipoLista ris = listaVuota();
  while (!estVuota(l)){
    ris = cons(car(l),ris);
    l = cdr(l);}
  return ris;
}

TipoLista argmaxListeInserite(TipoLista* liste1, TipoLista* liste2, int n, int k){
  TipoLista ris = listaVuota();
  int i = 0;
  while (n>0){
    if (max(liste1[i]) == max(inserisciLista(liste1[i], liste2[i], k))){
      ris = cons(1,ris);}
    else{
      ris = cons(0,ris);}
    i++;
    n--;}
  return inverti(ris);
}
