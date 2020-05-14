#include "esercizio3.h"
#include <stdlib.h>

void removeChar(char* input, char c, char* output)
{  
  if( *input == '\0' )
  {
     *output = '\0';
     return;
  }
  
  if( *input != c )
  {
    *output = *input;   
    removeChar(input + 1, c, output + 1);
  }
  else
    removeChar(input + 1, c, output);
}
