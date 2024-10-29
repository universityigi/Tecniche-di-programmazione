#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

int sum(Mat *m){
  int sum=0;
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      sum += m->mat[i][j];}}
  return sum;
}

Mat* flip(Mat *m){
  Mat *result = mat_alloc(m->rows,m->cols);
  for (int i=0;i<result->rows;i++){
    for (int j=0;j<result->cols;j++){
      if (j%2!=0)
        result->mat[i][j] = m->mat[(result->rows)-(i+1)][j];
      else
        result->mat[i][j]= m->mat[i][j];}}
  return result;
}

Mat* quad(Mat *m,int start1,int start2){
  int n = m->rows/2;
  Mat *quad = mat_alloc(n,n);
  for (int i = 0;i<m->rows/2;i++){
    for (int j = 0;j<m->cols/2;j++){
      quad->mat[i][j] = m->mat[i+start1][j+start2];}}
  return quad;
}

int max(int* array, int n){
  int max = 0;
  int i = 0;
  while (i<n){
    if (array[i] > max){
      max = array[i];}
    i++;}
  return max;
}

int massimo_flip_colonna(Mat *m){
  int n = m->rows/2;
  Mat *k = flip(m);
  int* array = (int*)malloc(4*sizeof(int));
  array[0] = sum(quad(k,0,0));
  array[1] = sum(quad(k,0,n));
  array[2] = sum(quad(k,n,0));
  array[3] = sum(quad(k,n,n));
  return max(array,4);
}
