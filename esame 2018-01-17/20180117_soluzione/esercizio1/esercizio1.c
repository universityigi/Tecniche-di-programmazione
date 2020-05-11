#include "esercizio1.h"
#include <stdlib.h>

int isPalindrome(CharList* src)
{
  int dim = 0;
  CharList* p = src;

  while( p != NULL )
    {
      dim++;
      p = p->next;
    }

  char *str = (char *)malloc(dim*sizeof(char));
  p = src;
  for( int i = 0; i < dim; i++, p = p->next )
    str[i] = p->c;
  
  int is_palindrome = 1;
  
  for(int i = 0, j = dim - 1; i < dim/2; i++, j--)
    {
      if( str[i] != str[j] )
        {
          is_palindrome = 0;
          break;
        }
    }
  
  free(str);
  return is_palindrome;
}
