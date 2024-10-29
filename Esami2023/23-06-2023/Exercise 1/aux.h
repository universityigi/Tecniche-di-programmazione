#pragma once

// Questa è la struttura Mat
typedef struct {
  int rows;
  int cols;
  float **mat;
} Mat;

// Dichiarazione della funzione da scrivere
float somma_diag(Mat* mat, int row, int col);

/* Funzioni a disposizione dello studente */
Mat * mat_alloc(int rows, int cols); // Alloca una matrice
void mat_print(const Mat *m);        // Stampa una matrice
void mat_free(Mat *m);               // Dealloca una matrice
