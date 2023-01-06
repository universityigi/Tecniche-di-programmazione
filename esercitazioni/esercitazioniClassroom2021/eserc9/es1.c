#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

TipoLista init(T *vec, int len);
TipoLista doubledCopy(TipoLista list);
TipoLista multipleSublist( TipoLista list, unsigned int m );
TipoLista subList(TipoLista list, int start, int end);
TipoLista interleave(TipoLista l1, TipoLista l2);

int main(){
  int array[] = {1,2,3,4,5};
  TipoLista list1 = init(array, 5);
  printf("LISTA =\t\t"); printlist(list1);
  printf("LISTA_D =\t"); printlist(doubledCopy(list1));
  printf("LISTA_MULT = \t"); printlist(multipleSublist(list1, 2));
  printf("LISTA_SUB = \t"); printlist(subList(list1, 1, 3));
  printf("LISTA_INT = \t"); printlist(interleave(list1, list1));
  return 0;
}

TipoLista init(T *vec, int len){
  if (len == 0) return listaVuota();
  else return cons(*vec, init(vec+1, len-1));
}


TipoLista doubledCopy(TipoLista list){
  if (estVuota(list)) return listaVuota();
  else{
    T elem = car(list);
    return cons(elem,(cons(elem, doubledCopy(cdr(list)))));
  }
}

TipoLista multipleSublist( TipoLista list, unsigned int m ){
  if (estVuota(list)) return listaVuota();
  T elem = car(list);
  if (elem % m == 0) return cons(elem, multipleSublist(cdr(list), m));
  else return multipleSublist(cdr(list), m);
}

TipoLista subList(TipoLista list, int start, int end){
  if (estVuota(list) || end == 0) return listaVuota();
  else if (start == 0) return cons(car(list), subList(cdr(list), start, --end));
  else return subList(cdr(list), --start, --end);
}

TipoLista interleave(TipoLista l1, TipoLista l2){
  if (estVuota(l1)) return listaVuota();
  else return cons(car(l1), interleave(l2, cdr(l1)));
}
