#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

float somma_diag(Mat *mat, int row, int col) {
  float sum = 0.0;
  int i=row;
  int j = col;
  int i2= row;
  int j2 = col;
  if (row>mat->rows-1 || row<0 || col>mat->cols-1 || col<0)
    return sum;
  else{
    while (i>=0 && j>=0){
      sum += mat->mat[i][j];
      i-=1;
      j-=1;}
    while (i2<mat->rows && j2<mat->cols){
      sum += mat->mat[i2][j2];
      i2+=1;
      j2+=1;}
    return sum - mat->mat[row][col];}
}
