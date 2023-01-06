#ifndef INCSCL_H
#define INCSCL_H


// Insieme: implementazione funzionale con memoria condivisa

// Rappresentazione con SCL
typedef int T;

// Valore errore di tipo T (per iteratore)
#define TERRORVALUE -999999

struct NodoSCL {
    T info;
    struct NodoSCL* next;
};

typedef struct NodoSCL TipoNodo;
typedef TipoNodo* Insieme;

typedef Insieme* IteratoreInsieme;

// Funzioni primitive del tipo:
Insieme insiemeVuoto();
bool estVuoto(Insieme ins);
Insieme inserisci(Insieme ins, T e);
Insieme elimina(Insieme ins, T e);
bool membro(Insieme ins, T e);

// Iteratore:
IteratoreInsieme creaIteratoreInsieme(Insieme ins);
bool hasNext(IteratoreInsieme it);
T next(IteratoreInsieme it);

#endif
