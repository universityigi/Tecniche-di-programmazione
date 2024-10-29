#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

int minValue(TipoAlbero a, int min){
  if (estVuoto(a))
    return min;
  else{
    if (radice(a)<min)
      min = radice(a);
    int sx = minValue(sinistro(a),min);
    int dx = minValue(destro(a), min);
    return sx < dx ? sx : dx;}
}

int maxValue(TipoAlbero a, int max){
  if (estVuoto(a))
    return max;
  else{
    if (radice(a)>max)
      max = radice(a);
    int sx = maxValue(sinistro(a),max);
    int dx = maxValue(destro(a),max);
    return sx > dx ? sx : dx;}
}

int sinistroMenoDestro(TipoAlbero a){
  if (estVuoto(a))
    return 0;
  else
    return maxValue(sinistro(a), radice(sinistro(a)))-minValue(destro(a), radice(destro(a)));
}
