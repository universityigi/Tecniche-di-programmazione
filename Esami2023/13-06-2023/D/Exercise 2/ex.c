#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoLista porzioneDiListeR(TipoLista l1, TipoLista l2, int k1, int k2,int i) {
  if (k1>0)
    return cons(car(l1),porzioneDiListeR(cdr(l1),l2,k1-1,k2,i));
  else{
    if (i>0){
      return porzioneDiListeR(l1,cdr(l2),k1,k2,i-1);}
    else if (k2>0){
      return cons(car(l2),porzioneDiListeR(l1,cdr(l2),k1,k2-1,i));}
    else
      return listaVuota();}
}

TipoLista porzioneDiListe(TipoLista l1, TipoLista l2, int k) {
  return porzioneDiListeR(l1,l2,k,k,length(l2)-k);
}

int sum(TipoLista l,int k){
  int sum=0;
  int i = k;
  while(i>0){
    sum+= car(l);
    l = cdr(l);
    i--;}
  while(k>0){
    sum-= car(l);
    l = cdr(l);
    k--;}
  return sum;
}

TipoLista diffPorzioniDiListe(TipoLista* liste1, TipoLista* liste2, int n, int k) {
  if (n==0)
    return listaVuota();
  else
    return cons(sum(porzioneDiListe(*liste1,*liste2,k),k),diffPorzioniDiListe(liste1+1,liste2+1,n-1,k));
}
