#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

float mean(Mat* m){
  int sum = 0;
  for (int i=0; i<m->rows;i++){
    for (int j=0; j<m->cols;j++){
      sum += m->mat[i][j];}}
  return sum/(m->rows * m->cols);
}

int max(float* array,int n){
  int i=0;
  int max=0;
  int index = 0;
  while (i<n){
    if (array[i]>max){
      max = array[i];
      index = i;}
    i++;}
  return index;
}

Mat* quad(Mat* m,int start_i, int start_j){
  Mat* m2 = mat_alloc(m->rows/2,m->cols/2);
  for (int i=0; i<m->rows/2;i++){
    for (int j=0; j<m->cols/2;j++){
      m2->mat[i][j] = m->mat[i+start_i][j+start_j];}}
  return m2;
}

Mat* inverti(Mat* m){
  Mat* m2 = mat_alloc(m->rows,m->cols);
  for (int i=0; i<m->rows;i++){
    for (int j=0; j<m->cols;j++){
      if (m->mat[i][j]%2==0 && i<j){
        m2->mat[i][j] = -m->mat[i][j];}
      else{
        if (m->mat[i][j]%2!=0 && i>=j){
          m2->mat[i][j] = -m->mat[i][j];}
        else{
          m2->mat[i][j] = m->mat[i][j];}}}}
  return m2;
}

Mat* inverti_e_max_quad(Mat* m) {
  int n = m->rows/2;  
  Mat** array = (Mat**)malloc(sizeof(Mat*)*4);
  array[0] = quad(inverti(m),0,0);
  array[1] = quad(inverti(m),0,n);
  array[2] = quad(inverti(m),n,0);
  array[3] = quad(inverti(m),n,n);
  float* medie = (float*)malloc(sizeof(float)*4);
  medie[0] = mean(array[0]);
  medie[1] = mean(array[1]);
  medie[2] = mean(array[2]);
  medie[3] = mean(array[3]);
  int i = max(medie,4);
  return array[i];
}
