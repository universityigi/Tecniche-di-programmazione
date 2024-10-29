#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoLista inverti(TipoLista l,TipoLista ris){
  if (estVuota(l))
    return ris;
  else{
    ris = cons(car(l),ris);
    return inverti(cdr(l),ris);}
}

int sumcr(TipoLista l,int sum){
  if (estVuota(l))
    return sum;	
  else{
    if (estVuota(cdr(l)) || car(l)>=car(cdr(l))){
      sum += car(l);
      return sumcr(cdr(l),sum);}
    else
      return sum+car(l);}
}

TipoLista precedentiMenoSuffissoR(TipoLista l, int sum, int k) {
  if (estVuota(l))
    return listaVuota();
  else{ 
    int aux = sum;
    sum+=car(l);
    return cons(aux-k,precedentiMenoSuffissoR(cdr(l),sum,k));}
}

TipoLista precedentiMenoSuffisso(TipoLista l){
  if (estVuota(l))
    return listaVuota();
  else
    return precedentiMenoSuffissoR(l,0, sumcr(inverti(l,listaVuota()),0));
}

double media(TipoLista l){
  if (estVuota(l))
    return 0.0;
  else
    return (double)sommaLista(l)/(double)length(l);}

double* mediaPrecedentiMenoSuffisso(TipoLista* liste, int n){
  int i = 0;
  double* result = (double*)malloc(sizeof(double) * n);
  while (i<n){
    result[i] = media(precedentiMenoSuffisso(liste[i]));
    i++;}
  return result;
}
