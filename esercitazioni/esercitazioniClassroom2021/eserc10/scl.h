/*******************************************
* Struttura collegata lineare.             *
*                                          *
* Non utilizzare direttamente.             *
* Preferire le funzioni dei tipi astratti, *
*******************************************/
#pragma once

typedef int T;

struct NodoSCL {
	T info;
	struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
