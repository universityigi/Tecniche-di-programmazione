#pragma once
#include "esercizio_1.h"

Mat *allocMatrix(int rows, int cols);
void freeMatrix(Mat* src);
Mat *randomMat( int rows, int cols, int max );
void printMatrix(Mat* src);

void inizializzaVector(int v[], int dim);
void printVector(int v[], int dim);

int checkResult( Mat* src, int *vect );
