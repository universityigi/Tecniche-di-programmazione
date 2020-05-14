#include "esercizio_1.h"

#include <stdio.h>
#include <stdlib.h>


// SOLUTION
void trasforma( Mat* src, int *vect ) {
	
	for (int r = 0; r < src->rows; ++r) {
		vect[r] = 0;
		for (int c = 0; c < src->rows - r && c < src->cols; ++c) {
			vect[r] += src->row_ptrs[r+c][c];
		}
	}
	
	
	
	
 /* int rows = src->rows, cols = src->cols;
  
  for( int r = 0; r < rows; r++ ) { 
    vect[r] = 0;  
    for( int i = 0; i < rows-r && i<cols; i++ ) {
      vect[r] = vect[r]+src->row_ptrs[r+i][i];   
    }    
	 
  }*/
}
