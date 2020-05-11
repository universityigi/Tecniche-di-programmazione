#include "correttore_esercizio_1.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int total_test_number = 10, successes = 0;

  for(int i = 0; i < total_test_number; ++i) 
  {
    printf("Test number %d out of %d\n", i + 1, total_test_number);

    int rows = rand()%7 + 1, cols = rand()%7 + 1;
    if(i == 4 )
      rows = 1;
    else if( i == 6 )
      cols = 1;
    else if( i == 8 )
      rows = cols = 1;
    
    Mat *src = randomMat( rows, cols, 100 );
    printf("src Mat\n");
    printMatrix(src);

    int res=massimo( src );
    printf("massimo trovato\n");
    printf("%d\n",res);
   
    if( checkResult( src,res )) 
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
    
    freeMatrix(src);
  }
  
  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  
  return 0;
}
