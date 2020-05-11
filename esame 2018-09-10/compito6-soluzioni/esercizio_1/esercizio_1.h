#pragma once

struct Mat {
  int cols; // numero di colonne
  int rows; // numero di righe
  int** row_ptrs; // puntatori alle righe
};

int massimo( Mat* src );
