#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alberoBinario.h"
#include "lista.h"

//FUNZIONI DI ESERCITAZION

TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero somma_foglie(TipoAlbero a);
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int conta_dispari(TipoAlbero a);
int somma_singoli(TipoAlbero a);
TipoLista albero_lista(TipoAlbero a);
TipoLista percorso_lungo(TipoAlbero a);
TipoAlbero somma_sottoalbero(TipoAlbero a);
TipoAlbero scambia_foglie(TipoAlbero a);

//FUNZIONI UTENTE
bool estFoglia(TipoAlbero a){
  return (estVuoto(sinistro(a)) && estVuoto(destro(a)));
}

TipoInfoAlbero max(int a, int b){
  if (a>=b) return a;
  else return b;
}

int len_list(TipoLista l){
  if(estVuota(l))
    return 0;
  else
    return 1 + len_list(cdr(l));
}

int main(){
  TipoAlbero alb = creaAlbBin(1, creaAlbBin(2, creaAlbBin(4,NULL,NULL), creaAlbBin(5, NULL, NULL)),
                  creaAlbBin(3, creaAlbBin(6,NULL,NULL),
                  creaAlbBin(7, NULL, creaAlbBin(8, NULL, NULL))));
  printf("ALBERO=\t"), stampaParentetica(alb); printf("\n");
  printf("MAX=\t\t%d\n", trova_massimo(alb));
  printf("SOMMA_FOGLIE=\t%d\n", somma_foglie(alb));
  printf("CERCA_LIVELLO=\t%d\n", cerca_livello(alb, 4));
  printf("CONTA_DISPARI=\t%d\n", conta_dispari(alb));
  printf("SOMMA_SINGOLI\t%d\n", somma_singoli(alb));
  printf("PERCORSO_LUNGO=\t"); printlist(percorso_lungo(alb)); printf("\n");
  printf("SOMMA_SOTTOALBERO=\t"); stampaParentetica(somma_sottoalbero(alb)); printf("\n");
  printf("SCAMBIA_FOGLIE=\t"); stampaParentetica(scambia_foglie(alb)); printf("\n");
}

TipoInfoAlbero trova_massimo(TipoAlbero a){
  if (estVuoto(a)) return -1;
  else if (estFoglia(a)) return radice(a);
  else{
    int m1 = max(trova_massimo(destro(a)), trova_massimo(sinistro(a)));
    return max(radice(a), m1);
  }
}

TipoInfoAlbero somma_foglie(TipoAlbero a){
  if (estVuoto(a)) return 0;
  if (estFoglia(a)) return radice(a);
  else{
    return somma_foglie(destro(a)) + somma_foglie(sinistro(a));
  }
}

int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int liv){
  if (estVuoto(a)) return -1;
  else if (radice(a) == v) return liv;
  else{
    int sx = cerca_livello_aux(sinistro(a), v, liv+1);
    int dx = cerca_livello_aux(destro(a), v, liv+1);
    if (sx != -1)
      return sx;
    else
      return dx;
  }
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v){
  return cerca_livello_aux(a, v, 0);
}

int conta_dispari(TipoAlbero a){
  if (estVuoto(a)) return 0;
  else{
    int sum = radice(a);
    if (!estVuoto(sinistro(a)))
      sum += radice(sinistro(a));
    if (!estVuoto(destro(a)))
      sum += radice(destro(a));
    if(sum % 2 != 0)
      return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    else
      return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
  }
}

int somma_singoli(TipoAlbero a){
  if (estVuoto(a)) return 0;
  else if (estFoglia(a)) return 0;
  else if ((estVuoto(sinistro(a))&&!estVuoto(destro(a)))
            || (estVuoto(destro(a))&&!estVuoto(sinistro(a))))
      return 1;
  else return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

// TipoLista albero_lista(TipoAlbero a){  //IMPLEMENTARE (SERVE FORSE FUNZIONE AUSILIARIA)
//   if (estVuoto(a)) return listaVuota();
//   else if (estFoglia(a)){
//     if ()
//   }
// }

TipoLista percorso_lungo(TipoAlbero a){
  if (estVuoto(a))
    return listaVuota();
  else if (estFoglia(a))
    return cons(radice(a), percorso_lungo(sinistro(a)));
  else if (!estVuoto(sinistro(a))&&estVuoto(destro(a)))
    return cons(radice(a), percorso_lungo(sinistro(a)));
  else if (!estVuoto(destro(a))&&estVuoto(sinistro(a)))
    return cons(radice(a), percorso_lungo(destro(a)));
  else {
    TipoLista dx = cons(radice(a),percorso_lungo(destro(a)));
    TipoLista sx = cons(radice(a), percorso_lungo(sinistro(a)));
    if(len_list(dx) > len_list(sx))
      return dx;
      else
      return sx;
  }
}

TipoAlbero somma_sottoalbero(TipoAlbero a){
  if (estVuoto(a))
    return albBinVuoto();
  else if (estFoglia(a))
    return creaAlbBin(0, albBinVuoto(), albBinVuoto());
  else{
    if (!estVuoto(sinistro(a))&&estVuoto(destro(a)))
      return creaAlbBin(radice(somma_sottoalbero(sinistro(a))), sinistro(a), albBinVuoto());
    else if (!estVuoto(destro(a))&&estVuoto(sinistro(a)))
      return creaAlbBin(radice(somma_sottoalbero(destro(a))), albBinVuoto(), destro(a));
    else
      return creaAlbBin(radice(somma_sottoalbero(destro(a)))+ radice(somma_sottoalbero(sinistro(a))), albBinVuoto(), destro(a));
  }
}

TipoAlbero scambia_foglie(TipoAlbero a){
  if (estVuoto(a))
    return albBinVuoto();
  else if (estFoglia(sinistro(a)) && estFoglia(destro(a)))
    return creaAlbBin(radice(a), destro(a), sinistro(a));
  else if (!estVuoto(sinistro(a))&&estVuoto(destro(a)))
    return creaAlbBin(radice(a), scambia_foglie(sinistro(a)), albBinVuoto());
  else if (!estVuoto(destro(a))&&estVuoto(sinistro(a)))
    return creaAlbBin(radice(a), albBinVuoto(), scambia_foglie(destro(a)));
  else
    return creaAlbBin(radice(a), scambia_foglie(sinistro(a)), scambia_foglie(destro(a)));
}
