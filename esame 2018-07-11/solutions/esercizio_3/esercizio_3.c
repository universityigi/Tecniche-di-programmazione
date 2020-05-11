#include "esercizio_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>



// SOLUTION
ListNode* max(ListNode* lista1, ListNode* lista2) {

  //ds termination criterion
  if (lista1 == 0 || lista2 == 0) {
    return 0;
  }

  //ds create new node (PD)
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));

  //ds set higher value
  if (lista1->info > lista2->info) {
    node->info = lista1->info;
  } else {
    node->info = lista2->info;
  }

  //ds set next element and return
  node->next = max(lista1->next, lista2->next);
  return node;
}

