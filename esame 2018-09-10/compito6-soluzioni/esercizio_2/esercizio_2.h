#pragma once

typedef int Data;

typedef struct ListNode ListNode;
struct ListNode 
{
  Data info;
  ListNode *next;
};

ListNode *subset( ListNode *list );
