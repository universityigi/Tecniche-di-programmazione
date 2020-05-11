#include "correttore_esercizio_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>



int main(int argc, char** argv) {

  // configuration
  const int number_of_tests      = 10;
  int number_of_successful_tests = 0;

  // test loop
  for (int i = 0; i < number_of_tests; ++i) {
    srand(i+1);
    printf("Test number %d out of %d\n", i + 1, number_of_tests);
    fflush(stdout);
    
    // generate random lists
    const int number_of_nodes = 1+rand()%10;
    ListNode* lista1 = generate(number_of_nodes);
    ListNode* lista2 = generate(number_of_nodes);

    // print the generated tree
    printf("\nInput:\n");
    print(lista1);
    print(lista2);
    fflush(stdout);

    // compute student's result
    ListNode* lista_max = max(lista1, lista2);
    printf("\nOutput:\n");
    print(lista_max);
    fflush(stdout);

    // check if successful
    if (checkResult(lista1, lista2, lista_max)) {
      printf("\nResult: SUCCESS\n");
      fflush(stdout);
      ++number_of_successful_tests;
    }
    else {
      printf("\nResult: FAILURE\n");
      fflush(stdout);
    }

    // free memory
    free(lista1);
    free(lista2);
    free(lista_max);

    printf("Current success rate: %0.02f\n", number_of_successful_tests*100.0f/number_of_tests);
    fflush(stdout);
    printf("\n*************************************************\n\n");
    fflush(stdout);
  }
  printf("FINAL SUCCESS RATE: %0.02f\n", number_of_successful_tests*100.0f/number_of_tests);
  fflush(stdout);
  return 0;
}

