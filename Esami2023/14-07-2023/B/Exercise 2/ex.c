#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int prefisso(TipoLista l){
  if (estVuota(l))
    return 0;
  if (estVuota(cdr(l)))
    return 1;
  else{
    if (car(l) >= car(cdr(l)))
      return 1 + prefisso(cdr(l));
    else
      return 1;}
}

int somma(TipoLista l, int k){
  if (k<=0)
    return 0;
  else
    return car(l) + somma(cdr(l), k-1);
}

TipoLista successiviMenoPrefissoR(TipoLista l, int sum) {
  if (estVuota(l))
    return listaVuota();
  else 
    return cons(sommaLista(cdr(l))-sum,successiviMenoPrefissoR(cdr(l),sum));
}

TipoLista successiviMenoPrefisso(TipoLista l){
  return successiviMenoPrefissoR(l,somma(l,prefisso(l)));
}

int max(TipoLista l){
  if (estVuota(l))
    return 0;
  int max=car(l);
  while (!estVuota(l)){
    if (car(l)>max){
      max = car(l);}
    l = cdr(l);}
  return max;
}

int* maxSuccessiviMenoPrefisso(TipoLista* liste, int n){
  int* array = (int*)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++){
    array[i] = max(successiviMenoPrefisso(liste[i]));}
  return array;
}
