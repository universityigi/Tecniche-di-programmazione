#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

// Valore di errore
static TipoInfoAlbero ERRORE_InfoAlbBin='*';

// Implementazioni del tipo astratto
TipoAlbero albBinVuoto(){
  return NULL;
}

TipoAlbero creaAlbBin(TipoInfoAlbero info, TipoAlbero sx, TipoAlbero dx){
  TipoAlbero a = (TipoAlbero) malloc(sizeof(TipoNodoAlbero));
  a->info = info;
  a->sinistro = sx;
  a->destro = dx;
  return a;
}

bool estVuoto(TipoAlbero a){
  return (a == NULL);
}

TipoInfoAlbero radice(TipoAlbero a){
  if (a == NULL) {
    printf ("accesso albero vuoto \n");
    return ERRORE_InfoAlbBin;} 
  else{
    return a->info;}
}

TipoAlbero sinistro(TipoAlbero a){
  if (a == NULL) {
    printf ("accesso albero vuoto \n");
    return NULL;} 
  else{
    return a->sinistro;}
}

TipoAlbero destro(TipoAlbero a){
  if (a == NULL) {
    printf ("accesso albero vuoto \n");
    return NULL;}
  else{
    return a->destro;}
}

// Funzioni esterne

// Stampa
void stampaInfoAlbero(TipoInfoAlbero c){
  printf("%d", c);
}

void stampaParentetica(TipoAlbero a){
  if (estVuoto(a)) {
    printf("()");}
  else{
  printf("( ");
  stampaInfoAlbero(radice(a));
  printf(" ");
  stampaParentetica(sinistro(a));
  printf(" ");
  stampaParentetica(destro(a));
  printf(" )");}
}

void stampa_albero_aux(TipoAlbero a, int livello){
  for (int i = 0; i < livello; ++i)
    putchar(' ');
  putchar('-');
  if (estVuoto(a)){
    puts("");
    return;}
  printf(" %d\n", radice(a));
  stampa_albero_aux(sinistro(a), livello + 1);
  stampa_albero_aux(destro(a), livello + 1);
}

void stampaAlbero(TipoAlbero a){
  stampa_albero_aux(a, 0);
  puts("");
}

// Lettura da file
void leggiParentesi(FILE *file_albero){
  char c = ' ';
  while (c!='(' && c!=')')
    c = fgetc(file_albero);
}

TipoAlbero leggiAlberoStringaAux(TipoAlbero a, const char **str){
  // Inizio albero
  if (**str != '(') {
    fprintf(stderr, "Incorretta stringa parentetica\n");
    return albBinVuoto();}
  ++(*str);
  // Se vuoto
  bool vuoto = **str == ')';
  if (**str == ')') {
    ++(*str);
    return albBinVuoto();}
  // Leggi valore
  int info;
  int read_chars;
  sscanf(*str, "%d%n", &info, &read_chars);
  *str += read_chars;
  // Leggi sottoalberi
  TipoAlbero left, right;
  leggiAlberoStringaAux(left, str);
  leggiAlberoStringaAux(right, str);
  // Fine albero
  if (**str != ')') {
    fprintf(stderr, "Incorretta stringa parentetica\n");
    return albBinVuoto();}
  ++(*str);
  return creaAlbBin(info, left, right);
}

TipoAlbero leggiAlberoStringa(TipoAlbero a, const char *str) {
  const char *s = str;
  return leggiAlberoStringaAux(a, &s);
}
