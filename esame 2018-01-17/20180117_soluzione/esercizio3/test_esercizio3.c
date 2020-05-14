#include "correttore_esercizio3.h"
#include "esercizio3.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  
  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    char c;
    int size = 0;
    char* string = getInfo(i, &c);
    printf("src String\n");
    printString(string);
    char* string_copy = copyString(string, &size);

    printf("char to remove:  %c\n", c);
    
    char* student_solution = (char*)calloc(' ',size*sizeof(char));

    removeChar(string_copy, c, student_solution);

    int cmp = checkIfGood(string, c, student_solution);
    if(cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");

    free(string_copy);
    free(student_solution);

  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  

  return 0;
}
