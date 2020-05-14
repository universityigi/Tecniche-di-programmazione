#include "esercizio_2.h"

#include <stdio.h>
#include <stdlib.h>


// SOLUTION
static ListNode *newNode( Data d ) {
  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  n->next = NULL;
  n->info = d;
  return n;
}

ListNode *subset( ListNode *list ) {
  ListNode *first, *last;
  first = last = NULL;
  
  for( ; list != NULL; list = list->next )
  {
     int nextValue = -1;
     if ( list->next )
       nextValue = list->next->info;
      
     if( (list->info > nextValue) )
     {
       if ( first == NULL )
       {
         first = newNode(list->info);
         last = first;
       }
       else
       {
         last->next = newNode(list->info);
         last = last->next;
       }
     }
  }
  
  return first;
}

