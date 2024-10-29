#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int somma(TipoLista l, int elem){
  if (estVuota(l))
    return 0;
  if (estVuota(cdr(l)))
    return car(l) + elem;
  else
    return car(l) + car(cdr(l));
}

TipoLista sommeDueADueR(TipoLista l, int elem){
  if (estVuota(l))
    return listaVuota();
  if (estVuota(cdr(l)))
    return cons(somma(l, elem), listaVuota());
  else
    return cons(somma(l, elem), sommeDueADueR(cdr(cdr(l)), elem));
}

TipoLista sommeDueADue(TipoLista l){
  if (estVuota(l))
    return listaVuota();
  else
    return sommeDueADueR(l,car(l));
}

double mean(TipoLista l){
  return (double)sommaLista(l)/(double)length(l);
}

double* mediaSommeDueADue(TipoLista* liste, int n){
  int i=0;
  double* result = (double*)malloc(sizeof(double)*n);
  while (i<n){
    result[i] = mean(sommeDueADue(liste[i]));
    i++;}
  return result;
}
