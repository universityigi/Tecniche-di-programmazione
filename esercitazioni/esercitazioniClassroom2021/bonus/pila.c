#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pila.h"

Pila * pilaVuota() {
	Pila *p = (Pila *)malloc(sizeof(Pila));
	*p = NULL;
	return p;
}

bool estPilaVuota(Pila *p) {
	if (!p) {
		puts("errore: null input");
		exit(1);
	}
  return *p == NULL;
}

void inPila(Pila *p , T e) {
	if (!p) {
		puts("ERRORE: null input");
		exit(1);
	}
	TipoNodo *nuovo = (TipoNodo *)malloc(sizeof(TipoNodo));
	nuovo->info = e;
	nuovo->next = *p;
	*p = nuovo;
}

T outPila(Pila *p) {
	if (!p) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*p == NULL ){
		puts("ERRORE: pila vuota");
		exit(1);
	}
	TipoNodo *primo = *p;
	T primo_valore = primo->info;
	*p = (*p)->next;
	free(primo);

	return primo_valore;
}

T primoPila(Pila* p) {
	if (!p) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*p == NULL ){
		puts("ERRORE: pila vuota");
		exit(1);
	}
  return (*p)->info;
}
