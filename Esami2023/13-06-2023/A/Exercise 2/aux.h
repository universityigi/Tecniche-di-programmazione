#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int T;
struct NodoSCL{
  T info;
  struct NodoSCL *next;};

typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

// Interfaccia lista
TipoLista listaVuota();             // crea lista vuota
bool estVuota(TipoLista l);         // controllo se vuota
TipoLista cons(T e, TipoLista l);   // creo lista aggiungendo in testa
T car(TipoLista l);                 // leggo valore del primo
TipoLista cdr(TipoLista l);         // ritorno la coda della lista
int length(TipoLista l);            // ritorna la lunghezza della lista
int sommaLista(TipoLista l);        // ritorna la somma degli elementi di una lista
void printlist(TipoLista l);
void freelist(TipoLista l);

// Dichiarazione esercizi
void modificaLista(TipoLista* l, int k);
double mediaSommaPesataModificaListe(TipoLista* liste, int* v, int n);
