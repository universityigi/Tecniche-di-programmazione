#include "esercizio_2.h"
#include "correttore_esercizio_2.h"
#include <stdio.h>
#include "stdlib.h"

int main()
{  
  int total_test_number = 10, successes = 0;

  for(int i = 0; i < total_test_number; ++i) 
  {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    int size = rand()%20 + 1, max = 50, m = rand()%10 + 1;
    if( i == 4 )
      size = 0;
    else if( i == 8 )
      size = 1;
    
    ListNode *src = generateRandomList( size, max );

    ListNode *dst = subset( src );
    
   
    printf("Input list\n");
    printList(src);
    printf("Output list\n");
    printList(dst);
   
    if( checkResult( src, dst)) 
    {
      printf("SUCCESS\n");
      successes++;
    }
    else
    {
      printf("FAILURE\n");
    }
    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    printf("\n*************************************************\n\n");
    
    freeList(src);
    freeList(dst);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  
  return 0;
}
