#include "char_list.h"
#include "correttore_esercizio1.h"
#include "esercizio1.h"
#include <stdlib.h>
#include <stdio.h>

int main() {

  int total_test_number = 10, successes = 0;

  int i;
  for(i = 0; i < total_test_number; ++i) {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    CharList* src = getCharList(i);
    CharList* src_copy = copyCharList(src);
    
    printf("src CharList\n");
    printCharList(src);

    int student_isPalindrome = isPalindrome(src_copy);

    int cmp = checkIfGood(src, student_isPalindrome);
    if(cmp > 0) {
      printf("SUCCESS\n");
      successes++;
    }
    else {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    freeCharList(src);
    freeCharList(src_copy);

  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));

  

  return 0;
}
