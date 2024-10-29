#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

int indice(int* array,int k, int dim){
  int indice = dim-1;
  while(indice>=0){
    if (array[indice] == k){
      return indice;}
    indice--;}
  return indice;
}

bool trovato(int* array,int k, int dim){
  int indice = dim-1;
  while(indice>=0){
    if (array[indice] == k){
      return true;}
    indice--;}
  return false;
}

Mat* ultimi_gli_unici(Mat *m){
  int k=0;
  int* valori = (int*)malloc(sizeof(int)*m->rows*m->cols);
  int* array = (int*)malloc(sizeof(int)*m->rows*m->cols);
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      valori[k] = m->mat[i][j];
      array[k] = i;
      k++;}}
  Mat* m2 = mat_alloc(m->rows,m->cols);
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      int value = m->mat[i][j];
      int index = indice(valori, value, k);
      if (index == i * m->cols + j)
        m2->mat[i][j] = m->mat[i][j];
      else{
        if(array[index]%2==0)
          m2->mat[i][j] = -1;
        else
          m2->mat[i][j] = -2;}}}
  return m2;
}
