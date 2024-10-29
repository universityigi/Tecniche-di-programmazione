#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

float media(Mat *m){
  float sum=0.0;
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      sum += m->mat[i][j];}}
  return sum/(m->rows*m->cols);
}

Mat* submat(Mat* m, int start_i, int start_j){
  int n = m->rows/2;
  Mat* res = mat_alloc(n,n);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      res->mat[i][j] = m->mat[i+start_i][j+start_j];}}
  return res;
}

Mat* massima_sottomatrice(Mat *m){
  float max = 0.0;
  int n = m->rows/2;
  Mat* res = mat_alloc(n,n);
  for (int i=0;i<n+1;i++){
    for (int j=0;j<n+1;j++){
      Mat* current = submat(m,i,j);
      float k = media(current);
      if (k>max){
        max = k;
        res = current;}}}
  return res;
}
