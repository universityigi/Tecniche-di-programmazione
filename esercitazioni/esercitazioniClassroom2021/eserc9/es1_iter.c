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

TipoLista append(T elem, TipoLista list){
    if (estVuota(list)) return cons(elem, list);
    else return cons(car(list), append(elem, cdr(list)));
}

TipoLista init(T *vec, int len){
    TipoLista list = listaVuota();
    for (int i = 0; i<len; i++){
        list = append(vec[i], list);
    }
    return list;
}


TipoLista doubledCopy(TipoLista list){
    TipoLista ret = listaVuota();
    while(!estVuota(list)){
        T elem = car(list);
        ret = append(elem, ret);
        ret = append(elem, ret);
        list = cdr(list);
    }
    return ret;
}

TipoLista multipleSublist( TipoLista list, unsigned int m ){
    TipoLista ret = listaVuota();
    while(!estVuota(list)){
        T elem = car(list);
        if (elem % m == 0) ret = append(elem, ret);
        list = cdr(list);
    }
    return ret;
}

TipoLista subList(TipoLista list, int start, int end){
    TipoLista ret = listaVuota();
    while (start > 0){
        list = cdr(list);
        start--;
        end --;
    }
    for (int i = end; i>0; i--){
        ret = append(car(list), ret);
        list = cdr(list);
    }
    return ret;
}

TipoLista interleave(TipoLista l1, TipoLista l2){
    TipoLista ret = listaVuota();
    while (!estVuota(l1)){
        T e1 = car(l1);
        T e2 = car(l2);
        ret = append(e1, ret);
        ret = append(e2, ret);
        l1 = cdr(l1);
        l2 = cdr(l2);
    }
    return ret;
}
