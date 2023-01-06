#include <stdio.h>
#include <stdlib.h>
#include "alberoBinario.h"


void stampa_array(int* arr, int len){
  for (int i = 0; i<len; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void riempi_array(TipoAlbero a, int* arr, int liv){
  if(estVuoto(a)) return;
  if(!estVuoto(sinistro(a))){
    arr[liv+1]+= 1;
    riempi_array(sinistro(a), arr, liv+1);
  }
  if(!estVuoto(destro(a))){
    arr[liv+1]+= 1;
    riempi_array(destro(a), arr, liv+1);
  }
}

int max(int* arr, int l, int localMax){
  for(int i= 0 ; i<l; i++){
    if (arr[i] > arr[localMax])
      localMax = i;
  }
  return localMax;
}

int max_albero(TipoAlbero a){
  int arr[] = {1,0,0,0,0,0,0,0,0,0,0};
  riempi_array(a, arr, 0);
  stampa_array(arr, 11);
  return max(arr, 11, 0);
}

int main(){
  TipoAlbero alb = creaAlbBin(1, creaAlbBin(2, creaAlbBin(4,NULL,NULL), creaAlbBin(5, NULL, NULL)),
                  creaAlbBin(3, creaAlbBin(6,NULL,NULL),
                  creaAlbBin(7, NULL, creaAlbBin(8, NULL, NULL))));
  printf("\nMAX_ALBERO\t%d\n",max_albero(alb));
  return 0;
}
