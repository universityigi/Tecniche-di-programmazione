#include "esercizio2.h"
#include <stdlib.h>

Mat *createMat( int rows, int cols, int val )
{
  Mat *m = (struct Mat *)malloc(sizeof(Mat));

  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (int**)malloc(rows*sizeof(int *));

  for( int r = 0; r < rows; r++ )
    m->row_ptrs[r] = (int*)malloc(cols*sizeof(int));

  for( int r = 0; r < rows; r++ )
    for( int c = 0; c < cols; c++ )
      m->row_ptrs[r][c] = val;
    
  return m;
}

MatList* matrixRealization(int rows_cols_sum, int init_val)
{
  MatList *head, *n;
  head = n = (MatList*)malloc(sizeof(MatList));

  for( int r = 1, c = rows_cols_sum - 1; r < rows_cols_sum; r++, c-- )
  {
    Mat *m = createMat(r,c,init_val);
    n->next = (MatList*)malloc(sizeof(MatList));
    n = n->next;
    n->m = m;
    n->next = NULL;
  }

  n = head;
  head = head->next;
  free(n);
  
  return head;
}
