#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

bool isFoglia(TipoAlbero a){
  return (estVuoto(destro(a)) && estVuoto(sinistro(a)));
}

int minimo(TipoAlbero a, int min, bool k){
  if (estVuoto(a))
    return min;
  else{
    if (radice(a)<min && k){
      min = radice(a);}
    int minSx = minimo(sinistro(a), min, true);
    int minDx = minimo(destro(a), min, true);
    return minSx <= minDx ? minSx : minDx;}
}

int distMinimo(TipoAlbero a, int min, int dist){
  if (estVuoto(a) || isFoglia(a) || (radice(a)==min && minimo(sinistro(a),100, true) != min && minimo(destro(a),100, true) != min))
    return dist;
  else{
    int sx = distMinimo(sinistro(a), min, dist+1);
    int dx = distMinimo(destro(a), min, dist+1);
    return minimo(sinistro(a),100, true) == min ? sx : dx;}
}

void diffMinFogliaMaxAntenatoR(TipoAlbero a, int max, int distMax, int aux) {
  if (estVuoto(a))
    return;
  else{
    if (radice(a)>max){
      max = radice(a);
      aux = 1;}
    else
      aux +=1;
    a->info=distMax+distMinimo(a,minimo(a,100, false),0);
    distMax = aux;
    diffMinFogliaMaxAntenatoR(sinistro(a), max, distMax, aux);
    diffMinFogliaMaxAntenatoR(destro(a), max, distMax, aux);}
}

void diffMinFogliaMaxAntenato(TipoAlbero a){
  if (!estVuoto(a))
    diffMinFogliaMaxAntenatoR(a,radice(a),0,0);
}
