#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scl.h"

int contieneElemento(TipoSCL scl, TipoInfoSCL e);
TipoSCL complemento(TipoSCL scl, TipoSCL elementiDaScartare);

//FUNZIONI UTENTE

void printscl_aux(TipoSCL scl)
{
	if (scl == NULL) return;
	printf("%d, ", scl->info);
	printscl_aux(scl->next);
}


void printscl(TipoSCL scl)
{
	printscl_aux(scl);
	printf("\n");
}

int main(){
  TipoSCL scl = NULL;
  printf("CONTIENE_ELEMENTO\t%d\n", contieneElemento(scl, 1));
  TipoSCL sclEliminare = NULL;
  printf("COMPLEMENTO\t"); printscl(complemento(scl, sclEliminare));
}

int contieneElemento(TipoSCL scl, TipoInfoSCL e){
  if(scl == NULL) return 0;
  else{
    if (scl->info == e)
      return 1;
    else
      return contieneElemento(scl->next, e);
  }
}

TipoSCL complemento(TipoSCL scl, TipoSCL elementiDaScartare){
  if(scl == NULL) return NULL;
  else{
    if(!contieneElemento(elementiDaScartare,scl->info)){
      TipoSCL nuovo = (TipoSCL) malloc(sizeof(tipoNodoSCL));
      nuovo->info = scl->info;
      nuovo->next = complemento(scl->next, elementiDaScartare);
      return nuovo;
    }
    else{
      return (scl->next, elementiDaScartare);
    }
  }
}
