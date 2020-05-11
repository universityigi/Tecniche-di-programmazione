#include "esercizio_2.h"

#include <stdio.h>
#include <stdlib.h>



ListNode *newNode(Data d) {
  ListNode *n = (ListNode *)malloc(sizeof(ListNode));
  n->next     = NULL;
  n->info     = d;
  return n;
}

ListNode* subset(ListNode *list) {
  ListNode* first = NULL;
  ListNode* last  = NULL;
  int precValue   = 0;

  // scan complete list
  if (list != NULL) {
    first     = newNode(list->info);
    last      = first;
		list      = list->next;
    precValue = last->info;
  }

  // assemble return list
  for( ; list != NULL; list = list->next ) {    
    if( (list->info < precValue) ) {
      last->next = newNode(list->info);
      last       = last->next;
    }
    precValue = list->info;
  }
  
  // done
  return first;
}

