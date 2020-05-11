#pragma once
#include "esercizio_3.h"



// prints a list to stdout
void print(ListNode* list_);

// generates a list of fixed length with random values
ListNode* generate(const int& number_of_nodes_);

// frees a list
void free(ListNode* list_);

// validate exercise (true: correct, false: incorrect)
bool checkResult(ListNode* list1_, ListNode* list2_, ListNode* list_max_);

