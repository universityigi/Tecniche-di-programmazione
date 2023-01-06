#include<stdlib.h>
#include<stdio.h>
#include"insf_scl.h"

// O(1)
Insieme insiemeVuoto() {
  return NULL;
}

// O(1)
bool estVuoto(Insieme ins) {
    return ins == NULL;
}

// O(n)
Insieme inserisci(Insieme ins, T e) {
    if (!membro(ins,e)) {
        TipoNodo* n = (TipoNodo*) malloc(sizeof(TipoNodo));
        n->info = e;
        n->next = ins;
        return n;
    }
    else
        return ins;
}

// O(n)
Insieme elimina(Insieme ins, T e) {
    if (!membro(ins,e))
        return ins;
    else if (ins->info == e) {
      return ins->next; // non si deve deallocare memoria
    }
    else {
        TipoNodo* n = (TipoNodo*) malloc(sizeof(TipoNodo));
        n->info = ins->info;
        n->next = elimina(ins->next,e);
        return n;
    }
}

// O(n)
bool  membro(Insieme ins, T e) {
    if (estVuoto(ins))
        return false;
    else
        return ins->info==e || membro(ins->next, e);
}

// O(1)
IteratoreInsieme creaIteratoreInsieme(Insieme ins) {
  IteratoreInsieme it = (IteratoreInsieme) malloc (sizeof(Insieme));
  *it = ins;
  return it;
}

// O(1)
bool hasNext(IteratoreInsieme it) {
    return *it!=NULL;
}

// O(1)
T next(IteratoreInsieme it) {
    T r = TERRORVALUE;
    if (*it!=NULL) {
        r = (*it)->info;
        *it = (*it)->next;
    }
    else
        printf("ERRORE Iteratore non valido.\n");
    return r;
}
