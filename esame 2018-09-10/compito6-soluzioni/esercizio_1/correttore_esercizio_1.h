#pragma once
#include "esercizio_1.h"

Mat *allocMatrix(int rows, int cols);
void freeMatrix(Mat* src);
Mat *randomMat( int rows, int cols, int max );
void printMatrix(Mat* src);
int checkResult( Mat* src, int res );
