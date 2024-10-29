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

int length(TipoLista l){
  if (estVuota(l)) 
    return 0;
  return 1 + length(cdr(l));
}

int sommaLista_aux(int somma, TipoLista l){
  if (estVuota(l))
    return somma;
  else
    return somma + sommaLista_aux(car(l), cdr(l));
}

int sommaLista(TipoLista l){
  if (estVuota(l))
    return 0;
  else	
    return sommaLista_aux(car(l), cdr(l));
}
