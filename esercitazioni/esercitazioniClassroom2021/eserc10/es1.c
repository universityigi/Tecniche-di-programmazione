#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "scl.h"
#include "coda.h"
#include "pila.h"

void print_pila(Pila* p);                   //stampa la pila
void stampa_sequenza_inversa(Pila* ris);    //ora ho una pila utilizzabile
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n);
bool check_palindrome(const char* s);
bool check_palindrome_r(const char* s);
int* rimuoviMinori(int* arr, int len);

void print_coda(Coda* c);
void stampa_sequenza(Coda* c);
int elemento_iesimo(Coda *c, int pos);
void avoid_stampa(Coda *c, int elem);
Coda * coda_circolare(Coda *c, int n);
Coda * elementi_pari(Coda *c);

int main(){
  //ESERCIZI SU PILE
  Pila *p = pilaVuota();
  stampa_sequenza_inversa(p);
  int rimuovere[] = {1, 2, 3};
  rimuovi_alcuni(p, rimuovere, 3);
  print_pila(p);
  printf("PALINDROME:\t%d\n",check_palindrome("abba"));
  printf("PALINDROME_R:\t%d\n",check_palindrome_r("accabbacca"));
  //ESERCIZI SU CODE
  Coda *c = codaVuota();
  stampa_sequenza(c);
  printf("ELEMENTO:\t%d\n", elemento_iesimo(c, 3));
  avoid_stampa(c, 3);
  print_coda(coda_circolare(c, 7));
  print_coda(elementi_pari(c));
  return 0;
}

//PILE
void print_pila(Pila* p){
  Pila* p2 = pilaVuota();
  while(!estPilaVuota(p)){
    printf("%d ",primoPila(p));
    inPila(p2, outPila(p));
  }
  printf("\n");
  while(!estPilaVuota(p2)){
    inPila(p, outPila(p2));
  }
}

void stampa_sequenza_inversa(Pila* ris){
  int a; scanf("%d",&a);
  while (a>=0){
    inPila(ris, a);
    scanf("%d",&a);
  }
  print_pila(ris);
  printf("\n");
}

void rimuovi_alcuni(Pila *p, const int *rimuovere, int n){
  Pila* ris = pilaVuota();
  while(!estPilaVuota(p)){
    T value = outPila(p);
    bool to_add = true;
    for (int i = 0; i < n; i++){
      if (value == rimuovere[i]) to_add = false;
    }
    if (to_add) inPila(ris, value);
  }
  while(!estPilaVuota(ris)){
    inPila(p, outPila(ris));
  }
}

bool check_palindrome(const char* s){
  if (strlen(s) % 2 != 0) return false;
  else{
    Pila* p = pilaVuota();
    for (int i = 0; i < strlen(s); i++){
      inPila(p, (int) s[i]);
    }
    print_pila(p);
    while (!estPilaVuota(p)){
      if (outPila(p) != (int) s[0])
        return false;
      else s = s + 1;
    }
    return true;
  }
}

bool palindrome_r_aux(const char* s, int l_index, int r_index){
  if (l_index >= r_index) return true;
  else{
    printf("%c == %c\n",s[l_index], s[r_index]);
    return (s[l_index] == s[r_index]) && palindrome_r_aux(s, l_index + 1, r_index - 1);
  }
}

bool check_palindrome_r(const char* s){
  if(strlen(s) % 2 != 0)
    return false;
  else
    return palindrome_r_aux(s, 0, strlen(s)-1);
}

int* rimuoviMinori(int* arr, int len){
  int* res;
  for (int i = 0; i < len; i++){
    
  }
  return res;
}

//CODE

void print_coda(Coda* c){
  Coda* ris = codaVuota();
  while(!estCodaVuota(c)){
    printf("%d ",primoCoda(c));
    inCoda(ris, outCoda(c));
  }
  printf("\n");
  while(!estCodaVuota(ris)){
    inCoda(c, outCoda(ris));
  }
}

void stampa_sequenza(Coda* c){
  int num; scanf("%d", &num);
  while (num >= 0){
    inCoda(c, num);
    scanf("%d", &num);
  }
  print_coda(c);
}

int elemento_iesimo(Coda *c, int pos){
  Coda* c2 = codaVuota();
  int result = -1;
  while (!estCodaVuota(c)){
    if (pos == 0)
      result = primoCoda(c);
    inCoda(c2, outCoda(c));
    pos = pos - 1;
  }
  while(!estCodaVuota(c2)){
    inCoda(c, outCoda(c2));
  }
  return result;
}

void avoid_stampa(Coda* c, int elem){
  Coda* ris = codaVuota();
  while(!estCodaVuota(c)){
    if (primoCoda(c) != elem)
      printf("%d ",primoCoda(c));
    inCoda(ris, outCoda(c));
  }
  printf("\n");
  while(!estCodaVuota(ris)){
    inCoda(c, outCoda(ris));
  }
}

Coda * coda_circolare(Coda *c, int n){
  Coda* ris = codaVuota();
  Coda* temp = codaVuota();
  for (int i = 0; i < n; i++){
    if (!estCodaVuota(c)){
      inCoda(temp, primoCoda(c));
      inCoda(ris, outCoda(c));
    }
    else{
      while(!estCodaVuota(temp))
        inCoda(c, outCoda(temp));
      inCoda(temp, primoCoda(c));
      inCoda(ris, outCoda(c));
    }
  }

  //RITORNO ALLA CODA ORIGINALE (colpa del side-effect)
  while(!estCodaVuota(c))
    inCoda(temp, outCoda(c));
  while(!estCodaVuota(temp))
    inCoda(c, outCoda(temp));
  return ris;
}

Coda * elementi_pari(Coda *c){
  Coda* ris = codaVuota();
  while(!estCodaVuota(c)){
    inCoda(ris, outCoda(c));
    if (!estCodaVuota(c))
      outCoda(c);
  }
  return ris;
}
