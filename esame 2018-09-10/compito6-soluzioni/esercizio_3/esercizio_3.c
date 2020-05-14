#include "esercizio_3.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>



void erase_aux(ListNode* current_node, ListNode* previous_node_, int index) {

  // escape for an invalid call
  if (current_node == NULL) {
    return;
  }

  // if we have the matching element
  if (index == 0) {
    
    // connect previous with next (if existing)
    if (previous_node_ != NULL) {

      // connect previous with next (if existing)
      if (current_node->next != NULL) {
        previous_node_->next = current_node->next;

      // otherwise finalize list
      } else {
        previous_node_->next = NULL;
      }
    }

  // keep searching 
  } else {
    erase_aux(current_node->next, current_node, index-1);
  }
}

ListNode* erase(ListNode* list, int index) {

  // handle invalid call: invalid index
  if (index < 0 || list == NULL) {
    return list;
  }

  // bookkeep head and check if it needs to be removed
  ListNode* head = list;
  if (index == 0) {
    head = head->next;
  }

  // call helper function
  erase_aux(list->next, list, index-1);

  // done
  return head;
}

