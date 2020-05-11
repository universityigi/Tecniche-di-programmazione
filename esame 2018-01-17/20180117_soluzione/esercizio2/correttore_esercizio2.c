#include "correttore_esercizio2.h"
#include <stdlib.h>
#include <stdio.h>

void printMatrix(Mat* src) {
  if(src == NULL){
    printf("NULL\n");
    return;
  }
  int rows = src->rows;
  int cols = src->cols;
  for(int r=0; r<rows; ++r) {
    for(int c=0; c<cols; ++c) {
      printf("%d ", src->row_ptrs[r][c]);
    }
    printf("\n");
  }
  fflush(stdout);
}


void printList(MatList* src) {
  int list_elem = 0;
  while(src!=NULL) { 
    printf("List Elem %d\n", list_elem);
    ++list_elem;
    printMatrix(src->m);
    src = src->next;
  }
  printf("\n");
}


void freeMatrix(Mat* src) {
  if(!src)
    return;
  int rows = src->rows;
  //  int cols = src->cols;
  for(int r=0; r<rows; ++r)
    free(src->row_ptrs[r]);

  free(src);
}

void freeList(MatList* src) {
  if(!src)
    return;
  MatList* head = src;

  while(src != NULL){
    src = src->next;
    freeMatrix(head->m);
    free(head);
    head = src;
  }
}


Mat* allocMatrixCorrettore(int rows, int cols, int val) {
  Mat* matrix = (Mat*)malloc(sizeof(Mat));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->row_ptrs = (int**)malloc(rows*sizeof(int*));
  for(int r=0; r<rows; ++r){
    matrix->row_ptrs[r] = (int*)malloc(cols*sizeof(int));
    for(int c = 0; c < cols; ++c)
      matrix->row_ptrs[r][c] = val;
  }
  return matrix;
}


MatList* pushBackMadre(MatList* l, Mat* m){
  MatList* new_element=(MatList*)malloc(sizeof(MatList));
  new_element->next=NULL;
  new_element->m = m;
  
  if (l==NULL){
    return new_element;
  }
  MatList* aux=l;
  while(aux->next!=NULL){
    aux=aux->next;
  }
  aux->next=new_element;
  return l;
}

void getRandomInfo(int* rows_cols_sum, int *init_val) {
  *rows_cols_sum = rand() % 10;
  *init_val = rand() % 4;
}


MatList* matrixRealizationSolution(int rows_cols_sum, int init_val) {
  if(rows_cols_sum < 1)
    return NULL;

  MatList* solution = NULL;
  for(int r = 1; r < rows_cols_sum; ++r){
    int c = rows_cols_sum-r;
    Mat* m = allocMatrixCorrettore(r, c, init_val);
    solution = pushBackMadre(solution, m);
  }

  return solution;
}

int matrixCompare(Mat* m1, Mat* m2){
  if((!m1 && m2) ||
     (m1 && !m2))
    return 0;
  if(m1->rows != m2->rows ||
     m1->cols != m2->cols)
    return 0;
  for(int r = 0; r < m1->rows; ++r)
    for(int c = 0; c < m1->cols; ++c)
      if(m1->row_ptrs[r][c] != m2->row_ptrs[r][c])
        return 0;

  return 1;
}

int checkIfGood(int rows_cols_sum, int init_val, MatList* student_out){

  MatList* good_out = matrixRealizationSolution(rows_cols_sum, init_val);
  printf("Expected Result\n");
  printList(good_out);
  printf("Computed Result\n");
  printList(student_out);
  fflush(stdout);
  
  if(!good_out && !student_out)
    return 1;
  if(good_out && !student_out) {
    freeList(good_out);
    return 0;
  }
  if(!good_out && student_out)
    return 0;

  MatList* good_head = good_out;
  
  while(good_out != NULL) {
    if(student_out == NULL) {
      freeList(good_head);
      return 0;
    }
    int matrix_comparison = matrixCompare(good_out->m, student_out->m);
    if(!matrix_comparison){
      freeList(good_head);
      return 0;
    }
    good_out = good_out->next;
    student_out = student_out->next;
    if(!good_out && student_out){
      freeList(good_head);
      return 0;
    }
      
  }
  
  
  freeList(good_head); 
  return 1; 
}

