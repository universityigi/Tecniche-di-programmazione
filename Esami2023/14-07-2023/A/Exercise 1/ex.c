#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* trasposta(Mat* m){
  Mat* m2 = mat_alloc(m->cols,m->rows);
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      m2->mat[j][i] = m->mat[i][j];}}
  return m2;
}

Mat* submat(Mat* m, int start_i, int start_j){
  int n = m->rows/2;
  Mat* m2 = mat_alloc(n,n);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      m2->mat[i][j] = m->mat[i+start_i][j+start_j];}}
  return m2;
}

int somma(Mat* m){
  int sum=0;
  for (int i=0;i<m->rows && i < m->cols;i++){
    sum += m->mat[i][i];}
  return sum;
}

Mat* trasponi_e_massima_diagonale(Mat* m){
  int n = m->rows/2;
  m = trasposta(m);
  int indice=0;
  int k=0;
  int max=-1;
  int num =  (m->rows - n + 1) * (m->cols - n + 1);;
  Mat** matrici = (Mat**)malloc(sizeof(Mat*)*(num));
  int* array = (int*)malloc(sizeof(int)*(num));
  for (int i=0;i<m->rows-n+1;i++){
    for (int j=0; j<m->cols-n+1;j++){
      matrici[k] = submat(m,i,j);
      array[k] = somma(matrici[k]);
      if (array[k]>max){
        max = array[k];
        indice = k;}
      k++;}}
  return matrici[indice];
}
