#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

bool trova(int* array, int x, int dim){
  for(int k=0;k<dim;k++){
    if (array[k] == x){return true;}}
  return false;
}

int trvind(int* array, int x, int dim){
  int k;
  for(k=0;k<dim;k++){
    if (array[k] == x){return k;}}
  return k;
}

Mat * prima_gli_unici(Mat *m){
  int k = 0;
  int* array = (int*)malloc(sizeof(int)*(m->rows*m->cols));
  int* indice = (int*)malloc(sizeof(int)*(m->rows*m->cols));
  Mat* result = mat_alloc(m->rows,m->cols);
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      array[k] = m->mat[i][j];
      indice[k] = i;
      if (!trova(array,m->mat[i][j],k)){
        result->mat[i][j] = m->mat[i][j];}
      else{
        int index = trvind(array,m->mat[i][j],k);
        if (indice[index]%2==0){
          result->mat[i][j] = -2;}
        else{
          result->mat[i][j] = -1;}}
      k++;}}   
  return result;
}
