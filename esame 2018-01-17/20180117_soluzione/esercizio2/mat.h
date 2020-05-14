#pragma once

typedef struct Mat
{
  int cols;       // numero di colonne
  int rows;       // numero di righe
  int** row_ptrs; // puntatori alle righe
} Mat;


typedef struct MatList
{
  Mat *m;
  struct MatList* next;
} MatList;


