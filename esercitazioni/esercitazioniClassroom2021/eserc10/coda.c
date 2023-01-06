#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "coda.h"


Coda * codaVuota() {
	Coda *c = (Coda *)malloc(sizeof(Coda));
	*c = NULL;
	return c;
}

bool estCodaVuota(Coda *c) {
	if (!c) {
		puts("errore: null input");
		exit(1);
	}
  return *c == NULL;
}

void inCoda(Coda *c , T e) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL) {
		*c = (TipoNodo *)malloc(sizeof(TipoNodo));
		(*c)->info = e;
		(*c)->next = NULL;
	} else {
		inCoda(&((*c)->next), e);
	}
}

T outCoda(Coda *c) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL ){
		puts("ERRORE: coda vuota");
		exit(1);
	}
	TipoNodo *primo = *c;
	T primo_valore = primo->info;
	*c = (*c)->next;
	free(primo);

	return primo_valore;
}

T primoCoda(Coda* c) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL ){
		puts("ERRORE: coda vuota");
		exit(1);
	}
  return (*c)->info;
}
