#pragma once


//! ritorna un array di dimensione size-1 che contiene la copia
//! di tutti gli elementi in v (di dimensione size), ad esclusione
//! dell'elemento in posizione pos
//! v viene cancellato
float* removeElementAt(float* v, int pos, int size);

//! ritorna l'indice dell'elemento piu' vicino a (cx, xy)
//! se nessun punto e' piu vicino di una distanza massima dmax, ritorna -1
//! distanza = sqrt( (x[i]-cx)*(x[i]-cx)+(y[i]-cy)*(y[i]-cy))
//! x: array di coordinate x
//! y: array di coordinate y
//! cx: coordinata x del punto
//! cy: coordinata x del punto
//! dmax: distanza massima da misurare
int nearestElement(float* x, float* y, int size, float cx, float cy, float dmax);


//! px e py vengono "riempiti" con puntatori ad array di dimensione size
//! ciascun elemento degli array e' inizializzato con un valore random tra 0 e scale
//! suggerimento: usare la funzione drand48() in stdlib
//! ritorna size
int initFlags(float** px, float** py, int size, float scale);

//! PER LA PROSSIMA ESERCITAZIONE
//! px e py vengono riempiti con puntatori ad array conteneti coordinate x e y letti da un file "filename"
//! riorna la dimensione degli array allocati
int loadFromFile(float** px, float** py, char* filename);
