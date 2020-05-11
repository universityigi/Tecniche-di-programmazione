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
    const int number_of_nodes = 2+rand()%10;
    ListNode* input_list      = generate(number_of_nodes);
    ListNode* input_list_copy = copy(input_list);

    // generate random index to erase
    const int index = 1+rand()%number_of_nodes-rand()%2;

    // print the generated tree
    printf("\nInput list: ");
    print(input_list);
    printf("Erase index: %d\n", index);
    fflush(stdout);

    // compute student's result
    ListNode* dest_list = erase(input_list, index);
    printf("\nOutput list: ");
    print(dest_list);
    fflush(stdout);

    // check if successful
    if (checkResult(input_list_copy, index, dest_list)) {
      printf("\nResult: SUCCESS\n");
      fflush(stdout);
      ++number_of_successful_tests;
    }
    else {
      printf("\nResult: FAILURE\n");
      fflush(stdout);
    }

    // free memory
    free(input_list);
    free(input_list_copy);
    printf("Current success rate: %0.02f\n", number_of_successful_tests*100.0f/number_of_tests);
    fflush(stdout);
    printf("\n*************************************************\n\n");
    fflush(stdout);
  }
  printf("FINAL SUCCESS RATE: %0.02f\n", number_of_successful_tests*100.0f/number_of_tests);
  fflush(stdout);
  return 0;
}

