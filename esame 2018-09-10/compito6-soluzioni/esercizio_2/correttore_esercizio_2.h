#pragma once
#include "esercizio_2.h"

int emptyList(ListNode *list);
ListNode *initList();
void freeList( ListNode *list );
ListNode *addElem( ListNode *list );
ListNode *removeFirstElem( ListNode *list );
void printList(ListNode *list);
ListNode *generateRandomList( int size, int max );

int checkResult( ListNode *src, ListNode *dst);
