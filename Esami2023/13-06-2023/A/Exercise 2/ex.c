#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"

TipoLista aggiungiInCoda(TipoLista l, T e){
  if (l == NULL){
    TipoLista nuovoNodo = (TipoLista)malloc(sizeof(TipoNodo));
    nuovoNodo->info = e;
    nuovoNodo->next = NULL;
    return nuovoNodo;} 
  else{
    l->next = aggiungiInCoda(l->next, e);
    return l;}
}	

void modificaLista(TipoLista* l, int k) {
  if (l==NULL || k==0){
    return;}
  else{
      T aux = (*l)->info;
      *l = aggiungiInCoda(*l,aux);
      *l = (*l)->next;
      return modificaLista(&(*l),k-1);}   	
}

double somma(TipoLista l){
  double sum =0;
  int i=1;
  while (!estVuota(l)){
    sum += car(l)*i;
    i++;
    l = cdr(l);}
  return sum;
}

double mediaSommaPesataModificaListe(TipoLista* liste, int* v, int n){
  double media = 0.0;
  int i=0;
  while (i<n){
    modificaLista(&(liste[i]),v[i]);
    i++;}
  int j=0;
  double sum =0;
  while (j<n){
    sum += somma(liste[j]);
    j++;}
  media = sum/n;
return media;	
}
