#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int sum(TipoLista l){
  if (estVuota(l))
    return 0;
  else
    return car(l)+sum(cdr(l));
}

TipoLista minimiLocali(TipoLista l){
  if (estVuota(l) || estVuota(cdr(l)) || estVuota(cdr(cdr(l)))){
    return listaVuota();}
  else{
    if (car(cdr(l)) <= car(l) && car(cdr(l)) <= car(cdr(cdr(l))))
      return cons(car(cdr(l)), minimiLocali(cdr(l)));
    else
      return minimiLocali(cdr(l));}     
}

int massimaSommaMinimi(TipoLista* liste, int n){
  int max=0;
  for (int i=0;i<n;i++){
    if (sum(minimiLocali(liste[i]))>max){
      max = sum(minimiLocali(liste[i]));}}
  return max;
}
