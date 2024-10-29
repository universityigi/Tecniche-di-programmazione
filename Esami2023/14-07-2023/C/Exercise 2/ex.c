#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int sum(TipoLista l){
  if (estVuota(l))
    return 0;
  else
    return car(l) + sum(cdr(l));
}

float mean(int i, TipoLista l){
  if (estVuota(l))
    return 0;
  else
    return i/length(l);
}

TipoLista mediaMenoMaxR(TipoLista l,int max) {
  if (estVuota(l))
    return listaVuota();
  else{
    int aux = max;
    if (car(l)>max){
      max = car(l);}
    return cons(aux-int(mean(sum(cdr(l)),cdr(l))),mediaMenoMaxR(cdr(l), max));}
}

TipoLista mediaMenoMax(TipoLista l) {
  return mediaMenoMaxR(l,0);
}

int* massimiElementi(TipoLista* liste, int n){
  int len = length(liste[0]);
  int* array = (int*)malloc(sizeof(int)*len);
  TipoLista* ris = (TipoLista*)malloc(sizeof(TipoLista)*n);
  for (int z = 0; z < n; z++){
    ris[z] = mediaMenoMax(liste[z]);}
  for (int i = 0; i < len; i++){
    int max = car(ris[0]);
    for (int k = 0; k < n; k++){
      if (ris[k] != NULL && car(ris[k]) >= max){
        max = car(ris[k]);}
      ris[k] = cdr(ris[k]);}
    array[i] = max;}
  return array;
}
