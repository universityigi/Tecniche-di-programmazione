#pragma once

// Questa è la struttura Mat
typedef struct {
  int rows;
  int cols;
  double **mat;
} Mat;

/* Funzioni a disposizione dello studente */
Mat * mat_alloc(int rows, int cols); // Alloca una matrice
void mat_print(const Mat *m);        // Stampa una matrice
void vec_print(int *vec,int size);   // Stampa un array
void mat_free(Mat *m);               // Dealloca una matrice

// Dichiarazione della funzione da scrivere
int cambia_segno_e_massima_somma(Mat* m);
