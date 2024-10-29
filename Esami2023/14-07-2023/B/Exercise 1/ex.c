#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "aux.h"

Mat* inverti(Mat* m){
  Mat* m2 = mat_alloc(m->rows,m->cols);
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      if ((i+j)%2!=0)
        m2->mat[i][j] = -m->mat[i][j];
      else
        m2->mat[i][j] = m->mat[i][j];}}
  return m2;
}

int maxquad(Mat* m){
  int max=-1000;
  int sum=0;
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      if (i<j && i+j<m->cols-1){
        sum+= m->mat[i][j];}}}
  if (sum>max){
    max = sum;}
  sum=0;
  for ( int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      if (i<j && i+j>m->cols-1){
        sum += m->mat[i][j];}}}
  if (sum>max){
    max = sum;}
  sum=0;
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      if (i>j && i+j<m->cols-1){
        sum+= m->mat[i][j];}}}
  if (sum>max){
    max = sum;}
  sum=0;
  for (int i=0;i<m->rows;i++){
    for (int j=0;j<m->cols;j++){
      if (i>j && i+j>m->cols-1){
        sum+= m->mat[i][j];}}}
  if (sum>max){
    max = sum;}
  return max;
}

int cambia_segno_e_massima_somma(Mat* m) {
  Mat* m2 = mat_alloc(m->rows,m->cols);
  m2 = inverti(m);
  return maxquad(m2);
}
