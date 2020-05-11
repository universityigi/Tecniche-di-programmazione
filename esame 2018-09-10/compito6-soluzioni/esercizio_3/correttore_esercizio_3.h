#pragma once
#include "esercizio_3.h"



// prints a list to stdout
void print(ListNode* list_);

// generates a list of fixed length with random values
ListNode* generate(int number_of_nodes_);

// creates a deep copy of a list
ListNode* copy(ListNode* node_);

// frees a list
void free(ListNode* list_);

// validate exercise (true: correct, false: incorrect)
int checkResult(ListNode* input_list_, int index_, ListNode* dest_list_);

