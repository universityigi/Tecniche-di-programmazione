#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int nodiDispari(TipoAlbero(a)){
  if (estVuoto(a))
    return 0;
  else{
    if (radice(a)%2!=0){
      return 1 + nodiDispari(sinistro(a)) + nodiDispari(destro(a));}
    return nodiDispari(sinistro(a)) + nodiDispari(destro(a));}
}

int minNodo(TipoAlbero(a), int min){
  if (estVuoto(a))
    return min;
  else{
    if (radice(a)<min){
      min = radice(a);}
    int sx = minNodo(sinistro(a),min);
    int dx = minNodo(destro(a),min);
    if (sx<=dx)
    return sx<min ? sx : min;
    else
      return dx<min ? dx : min;}
}

int maxNodo(TipoAlbero(a), int max){
  if (estVuoto(a))
    return max;
  else{
    if (radice(a)>max){
      max = radice(a);}
    int sx = maxNodo(sinistro(a),max);
    int dx = maxNodo(destro(a),max);
    if (sx>=dx)
      return sx>max ? sx : max;
    else
    return dx>max ? dx : max;}
}

void diffSommaMinMaxDispari(TipoAlbero a) {
  if (estVuoto(a))
    return;
  else{
    if (nodiDispari(sinistro(a)) >= nodiDispari(destro(a)))
      a->info = (minNodo(sinistro(a),100)+maxNodo(sinistro(a),-100))-(minNodo(destro(a),100)+maxNodo(destro(a),-100));
    else
      a->info = (minNodo(destro(a),100)+maxNodo(destro(a),-100))-(minNodo(sinistro(a),100)+maxNodo(sinistro(a),-100));
    diffSommaMinMaxDispari(sinistro(a));
    diffSommaMinMaxDispari(destro(a));}
}
