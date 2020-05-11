#include "esercizio_1.h"

#include <stdio.h>
#include <stdlib.h>



int massimo(Mat* src) {

  // variables
  int rows = src->rows;
  int cols = src->cols;
  double somma_max     = 0;
  double somma_colonna = 0;
  int colonna_max      = 0;

  // look for maximum column
  for(int c = 0; c < cols; c++) {
	  somma_colonna = 0;
	  for(int r = 0; r < rows; r++) {
		  somma_colonna += src->row_ptrs[r][c];
    }
	  if (c == 0 || somma_colonna > somma_max) {
	    somma_max = somma_colonna;
	    colonna_max = c;
	  }
  }

  // compute maximum value of that column
  int max = 0;
  for(int r = 0; r < rows; r++) {
	  if (src->row_ptrs[r][colonna_max] > src->row_ptrs[max][colonna_max]) {
		  max = r;
    }
  }

  // done
  return src->row_ptrs[max][colonna_max];
}

