#include "mat.h"
#include "correttore_esercizio2.h"
#include "esercizio2.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    int rows_cols_sum = 0;
    int init_val = 0;
    getRandomInfo(&rows_cols_sum, &init_val);
    
    printf("src Info\n");
    printf("rows_cols_sum = %d     init_val = %d\n", rows_cols_sum, init_val);
    
    MatList* student_out = matrixRealization(rows_cols_sum, init_val);

    int cmp = checkIfGood(rows_cols_sum, init_val, student_out);
    if(cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    freeList(student_out);

  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  

  return 0;
}
