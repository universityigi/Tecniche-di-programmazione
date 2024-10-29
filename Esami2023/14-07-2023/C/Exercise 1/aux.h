#pragma once

// Questa è la struttura Mat
typedef struct {
  int rows;
  int cols;
  int **mat;
} Mat;

/* Funzioni a disposizione dello studente */
Mat * mat_alloc(int rows, int cols); // Alloca una matrice
void mat_print(const Mat *m);        // Stampa una matrice
void mat_free(Mat *m);               // Dealloca una matrice

// Dichiarazione della funzione da scrivere
Mat* inverti_e_max_quad(Mat* m);
