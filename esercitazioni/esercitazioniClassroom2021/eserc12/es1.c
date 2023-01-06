#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alberoBinario.h"
#include "lista.h"

int singleChildSum(TipoAlbero a);
int livelli_completi(TipoAlbero a);
TipoLista listaNodiFoglia(TipoAlbero a);
TipoAlbero taglia_livello(TipoAlbero a, int livello);

//FUNZIONI AUSILIARIE
int livelli_completi_aux(TipoAlbero a);

//FUNZIONI UTENTE
bool estFoglia(TipoAlbero a){
  return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

int somma_sottoalbero(TipoAlbero a){
  if(estVuoto(a)) return 0;
  else{
    int sum = radice(a);
    if (!estVuoto(sinistro(a)))
      sum += somma_sottoalbero(sinistro(a));
    if (!estVuoto(destro(a)))
      sum += somma_sottoalbero(destro(a));
    return sum;
  }
}

int main(){
  TipoAlbero alb = creaAlbBin(1, creaAlbBin(2, creaAlbBin(4,NULL,NULL), creaAlbBin(5, NULL, NULL)),
                  creaAlbBin(3, creaAlbBin(6,NULL,NULL),
                  creaAlbBin(7, NULL, creaAlbBin(8, NULL, NULL))));
  printf("TEST ALBERI con "); stampaParentetica(alb); printf("\n");
  printf("SINGLE_CHILD_SUM\t%d\n", singleChildSum(alb));
  printf("LIVELLI_COMPLETI\t%d\n", livelli_completi(alb));
  printf("LISTA_NODI_FOGLIA\t"); printlist(listaNodiFoglia(alb)); printf("\n");
  printf("TAGLIA_LIVELLO\t"); stampaParentetica(taglia_livello(alb, 2)); printf("\n");
  return 0;
}

int singleChildSum(TipoAlbero a){
  if (estVuoto(a) || estFoglia(a)) return 0;
  else{
    if(!estVuoto(sinistro(a))){
      if(estVuoto(destro(a)))
        return radice(a) + singleChildSum(sinistro(a));
      else
        return singleChildSum(sinistro(a)) + singleChildSum(destro(a));
    }
    else{
      if(estVuoto(sinistro(a)))
        return radice(a) + singleChildSum(destro(a));
      else
        return singleChildSum(sinistro(a)) + singleChildSum(destro(a));
    }
  }
}


int livelli_completi_aux(TipoAlbero a){
  if(estVuoto(a) || estFoglia(a))
    return 0;
  else{
    if (!estVuoto(sinistro(a))&&!estVuoto(destro(a)))
      return 1+livelli_completi_aux(sinistro(a))+livelli_completi(destro(a));
    else
      return livelli_completi(sinistro(a))+livelli_completi(destro(a));
  }
}

int livelli_completi(TipoAlbero a){
  if(estVuoto(a))
    return -1;
  else
    return livelli_completi_aux(a);
}

TipoLista listaNodiFoglia_aux(TipoAlbero a, TipoLista l){
  if (estFoglia(a)) return cons(radice(a), l);
  else{
    if(!estVuoto(destro(a))){
      l = listaNodiFoglia_aux(destro(a),l);
    }
    if(!estVuoto(sinistro(a))){
      l = listaNodiFoglia_aux(sinistro(a),l);
    }
    return l;
  }
}

TipoLista listaNodiFoglia(TipoAlbero a){
  if (estVuoto(a))
    return listaVuota();
  else{
    TipoLista l = listaVuota();
    l = listaNodiFoglia_aux(a, l);
    return l;
  }
}

TipoAlbero taglia_livello(TipoAlbero a, int livello){
  if(estVuoto(a)) return albBinVuoto();
  else{
    if(livello > 0)
      return creaAlbBin(radice(a), taglia_livello(sinistro(a), livello -1), taglia_livello(destro(a),livello-1));
    else{
      return creaAlbBin(somma_sottoalbero(a), albBinVuoto(), albBinVuoto());
    }
  }
}
