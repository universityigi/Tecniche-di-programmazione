#include "aux.h"

TipoLista listaVuota(){
  return NULL;
}

bool estVuota(TipoLista l){
  return (l == NULL);
}

TipoLista cons(T e, TipoLista l){
  TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo));
  nuovo->info = e;
  nuovo->next = l;
  return nuovo;
}

T car(TipoLista l){
  if (l == NULL){
    printf(" ERRORE : lista vuota \n ");
    exit(1);}
  return l->info;
}

TipoLista cdr(TipoLista l){
  if (l == NULL){
    printf(" ERRORE : lista vuota \n ");
    exit(1);}
  return l->next;
}

void printlist_aux(TipoLista l){
  if (estVuota(l)) return;
  printf("%d, ", car(l));
  printlist_aux(cdr(l));
}

void printlist(TipoLista l){
  if (estVuota(l))
    printf("()");
  else
    printlist_aux(l);
  printf("\n");
}

void freelist(TipoLista l){
  if (l == NULL)
    return;
  freelist(l->next);
  free(l);
}

int largest_factor_aux(int i, int d){
  if (i % d == 0) return d;
  return largest_factor_aux(i, d - 1);
}

int largest_factor(int i){
  if (i <= 0) return 0;
  if (i == 1) return 1;
  return largest_factor_aux(i, i - 1);
}
