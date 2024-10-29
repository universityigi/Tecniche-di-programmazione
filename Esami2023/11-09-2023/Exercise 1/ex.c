#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* trasforma(Mat* m){
  Mat* m2 = mat_alloc(m->rows,m->cols);
  for (int i=0;i<m2->rows;i++){
    for (int j=0;j<m->cols;j++){
      m2->mat[i][j] = m->mat[i][j]-i+j;}}
  return m2;
}

int minx(Mat* m){
  int max = 0;
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      if( m->mat[i][j] > max){
        max = m->mat[i][j];}}}
  return max;
}

int quad(Mat* m, int start_i, int start_j){
  int min = minx(m);
  int n = (m->rows-1)/2; 
  Mat* m2 = mat_alloc(n,n);
  for (int i=0; i<n; i++){
    for (int j=0;j<n;j++){
      m2->mat[i][j] = m->mat[i+start_i][j+start_j];
      if (m2->mat[i][j]<=min){
        min = m2->mat[i][j];}}}
  return min;
}

double trasforma_e_min_quad(Mat* m) {
  int n = (m->rows/2) +1;
  Mat* m2 = trasforma(m);
  return quad(m2,0,n) + quad(m2,n,0) + quad(m2,0,0) + quad(m2,n,n);
}
