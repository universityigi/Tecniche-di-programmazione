#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoLista convoluzioneR(TipoLista l, int k,int sum, int i){
  if (estVuota(l))
    return listaVuota();
  else{
    while (i<k){
      sum+=car(l);
      if (cdr(l)==NULL){
        return cons(sum,convoluzioneR(NULL,k,0,0));}
    l = cdr(l);
    i++;}
  return cons(sum,convoluzioneR(l,k,0,0));}	
}

TipoLista convoluzione(TipoLista l, int k){
  return convoluzioneR(l,k,0,0);
}

int max(TipoLista l){
  int max=0;
  while (!estVuota(l)){
    if (car(l)>max)
      max = car(l);
      l = cdr(l);}
  return max;
}

int* maxPooling(TipoLista* liste, int* v, int n){
  int* result = (int*)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++){
    result[i] = max(convoluzione(liste[i],v[i]));}
  return result;
}
